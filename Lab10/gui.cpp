#include "gui.h"

void GUI::layout_initialization()
{
    setLayout(main_layout);

    QWidget* output_widget = new QWidget;
    QVBoxLayout* output_layout = new QVBoxLayout;

    output_widget->setLayout(output_layout);
    output_list = new QTableWidget;
    output_list->setRowCount(0);
    output_list->setColumnCount(4);
    output_list->setSelectionMode(QAbstractItemView::SingleSelection);
    output_list->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList temp_table_header;
    temp_table_header<<"Apartment"<<"Owner"<<"Type"<<"Area";
    output_list->setHorizontalHeaderLabels(temp_table_header);

    output_layout->addWidget(output_list);


    main_layout->addWidget(output_widget);

    QWidget* input_widget = new QWidget;
    QVBoxLayout* input_layout = new QVBoxLayout;

    input_widget->setLayout(input_layout);

    add_button = new QPushButton("Add");
    delete_button = new QPushButton("Delete");
    modify_button = new QPushButton("Modify");
    undo_button = new QPushButton("Undo");

    input_layout->addWidget(add_button);
    input_layout->addWidget(delete_button);
    input_layout->addWidget(modify_button);
    input_layout->addWidget(undo_button);

    main_layout->addWidget(input_widget);

    QWidget* new_widget = new QWidget;
    new_widget->setLayout(new_layout);
    main_layout->addWidget(new_widget);
}

void GUI::event_connection()
{

    QObject::connect(add_button, &QPushButton::clicked,this, &GUI::add_action);

    QObject::connect(delete_button, &QPushButton::clicked,this, &GUI::delete_action);

    QObject::connect(modify_button, &QPushButton::clicked,this, &GUI::modify_action);

    QObject::connect(undo_button, &QPushButton::clicked,this, &GUI::undo_action);

    auto header = output_list->horizontalHeader();

    QObject::connect(header, &QHeaderView::sectionClicked, [this](int logicalIndex){
        auto text = (output_list->horizontalHeaderItem(logicalIndex)->text()).QString::toStdString();
        if(this->sort_field == text){
            this->sort_reversed ^= 1;
        }
        else{
            sort_field = text;
        }
        this->reload_list();
    });
}


void GUI::reload_list()
{
    output_list->clearContents();
    auto tenant_list = srv.get_list(sort_field, sort_reversed);
    std::unordered_map<std::string, int> map;
    output_list->setRowCount(tenant_list.size());
    int i = 0;
    for(const auto& tenant: tenant_list){
        try{
            auto& temporary = map.at(tenant.get_type());
            temporary++;
        }catch(...){
            map.insert({tenant.get_type(), 1});
        }
        output_list->setItem(i,0, new QTableWidgetItem(QString::number(tenant.get_apartment())));
        output_list->setItem(i,1, new QTableWidgetItem(QString::fromStdString(tenant.get_owner())));
        output_list->setItem(i,2, new QTableWidgetItem(QString::fromStdString(tenant.get_type())));
        output_list->setItem(i,3, new QTableWidgetItem(QString::number(tenant.get_area())));
        i++;
    }
    clearLayout(new_layout);
    for(const auto& el: map){
        QPushButton* btn = new QPushButton(QString::fromStdString(el.first));
        int a = el.second;
        QObject::connect(btn, &QPushButton::clicked, [a, this](){
            QMessageBox::information(this, "Numbero cat doresti", QString::number(a));
        });
        new_layout->addWidget(btn);
    }
    main_layout->update();
}

void GUI::add_action()
{
    QDialog* diag = new QDialog(this);
    diag->setModal(true);
    QVBoxLayout* diag_layout = new QVBoxLayout;
    diag->setLayout(diag_layout);

    QWidget* form = new QWidget;
    QFormLayout* form_layout = new QFormLayout;
    form->setLayout(form_layout);

    QLineEdit* apartment_txt = new QLineEdit;
    form_layout->addRow(new QLabel("Apartment: "), apartment_txt);

    QLineEdit* owner_txt = new QLineEdit;
    form_layout->addRow(new QLabel("Owner: "), owner_txt);

    QLineEdit* type_txt = new QLineEdit;
    form_layout->addRow(new QLabel("Type: "), type_txt);

    QLineEdit* area_txt = new QLineEdit;
    form_layout->addRow(new QLabel("Area: "), area_txt);

    QPushButton* add = new QPushButton("Add");

    diag_layout->addWidget(form);
    diag_layout->addWidget(add);


    QObject::connect(add, &QPushButton::clicked, [&](){
        int apartment, area;
        std::string owner, type;
        try{

            apartment = validator::validate_apartment(apartment_txt->text().toStdString());
            owner = validator::validate_owner(owner_txt->text().toStdString());
            type = validator::validate_type(type_txt->text().toStdString());
            area = validator::validate_area(area_txt->text().toStdString());

            this->srv.add(apartment, owner, type, area);
            reload_list();

        }
        catch(my_exception& ex){
            QMessageBox::warning(diag, "Warning", QString::fromStdString(ex.get_error()));
        }

    }
    );
    diag->exec();
}

void GUI::delete_action()
{
    auto row = output_list->currentRow();
    if(row == -1)
        QMessageBox::warning(this, "Warning", "No tenant was selected");
    else{
        auto ap = (output_list->item(row, 0))->text().toInt();
        try{
            srv.del(ap);
            reload_list();
        }
        catch(my_exception& ex){
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_error()));
        }
    }
}

void GUI::undo_action()
{
    try{
        srv.undo();
        reload_list();
    }
    catch(my_exception& ex){
        QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_error()));
    }
}

void GUI::modify_action()
{
    auto row = output_list->currentRow();
    if(row == -1)
        QMessageBox::warning(this, "Warning", "No tenant was selected");
    else{
        auto ap = (output_list->item(row, 0))->text().toInt();
        try{

            QDialog* diag = new QDialog(this);
            diag->setModal(true);
            QVBoxLayout* diag_layout = new QVBoxLayout;
            diag->setLayout(diag_layout);

            QWidget* form = new QWidget;
            QFormLayout* form_layout = new QFormLayout;
            form->setLayout(form_layout);

            QLineEdit* apartment_txt = new QLineEdit;
            form_layout->addRow(new QLabel("New Apartment: "), apartment_txt);

            QLineEdit* owner_txt = new QLineEdit;
            form_layout->addRow(new QLabel("New Owner: "), owner_txt);

            QLineEdit* type_txt = new QLineEdit;
            form_layout->addRow(new QLabel("New Type: "), type_txt);

            QLineEdit* area_txt = new QLineEdit;
            form_layout->addRow(new QLabel("New Area: "), area_txt);

            QPushButton* add = new QPushButton("Modify");

            diag_layout->addWidget(form);
            diag_layout->addWidget(add);

            apartment_txt->setText((output_list->item(row, 0))->text());
            owner_txt->setText((output_list->item(row, 1))->text());
            type_txt->setText((output_list->item(row, 2))->text());
            area_txt->setText((output_list->item(row, 3))->text());


            QObject::connect(add, &QPushButton::clicked, [&](){
                int apartment, area;
                std::string owner, type;

                try{

                    apartment = validator::validate_apartment(apartment_txt->text().toStdString());
                    owner = validator::validate_owner(owner_txt->text().toStdString());
                    type = validator::validate_type(type_txt->text().toStdString());
                    area = validator::validate_area(area_txt->text().toStdString());

                    this->srv.modify(ap, apartment, owner, type, area);
                    reload_list();
                    diag->close();

                }
                catch(my_exception& ex){
                    QMessageBox::warning(diag, "Warning", QString::fromStdString(ex.get_error()));
                }

            }
            );
            diag->exec();
        }
        catch(my_exception& ex){
            QMessageBox::warning(this, "Warning", QString::fromStdString(ex.get_error()));
        }
    }
}

void GUI::clearLayout(QLayout *layout)
{
       if (layout == NULL)
           return;
       QLayoutItem *item;
       while((item = layout->takeAt(0))) {
           if (item->layout()) {
               clearLayout(item->layout());
               delete item->layout();
           }
           if (item->widget()) {
              delete item->widget();
           }
           delete item;
       }
}

GUI::GUI(service& srv): srv{srv}
{
    layout_initialization();
    event_connection();
    reload_list();
}

GUI::~GUI()
{
}

