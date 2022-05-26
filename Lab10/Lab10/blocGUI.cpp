#include "blocGUI.h"

void BlocGUI::initializeGUIComponents() {
	QHBoxLayout* lyMain = new QHBoxLayout;
	this->setLayout(lyMain);


	//left part of the window
	//pentru aceasta parte setam layout vertical
	QWidget* left = new QWidget;
	QVBoxLayout* lyLeft = new QVBoxLayout;
	left->setLayout(lyLeft);

	//componente pentru functionalitatea de adaugare a unei melodii
	//folosim un QFormLayout pentru detaliile de adaugare a unei melodii
	QWidget* form = new QWidget;
	QFormLayout* lyForm = new QFormLayout;
	form->setLayout(lyForm);
	editApartament = new QLineEdit;
	editApartament->setStyleSheet("background-color: white");
	editNume = new QLineEdit;
	editNume->setStyleSheet("background-color: white");
	editSup = new QLineEdit;
	editSup->setStyleSheet("background-color: white");
	editTip = new QLineEdit;
	editTip->setStyleSheet("background-color: white");
	editNewName = new QLineEdit;
	editNewName->setStyleSheet("background-color: white");

	lblApartament->setStyleSheet("font: bold Times New Roman");
	lblNume->setStyleSheet("font: bold Times New Roman");
	lblSup->setStyleSheet("font: bold Times New Roman");
	lblTip->setStyleSheet("font: bold Times New Roman");
	lblNewName->setStyleSheet("font: bold Times New Roman");

	lyForm->addRow(lblApartament, editApartament);
	lyForm->addRow(lblNume, editNume);
	lyForm->addRow(lblSup, editSup);
	lyForm->addRow(lblTip, editTip);
	lyForm->addRow(lblNewName, editNewName);

	btnAddApartment = new QPushButton("Add apartment");
	btnDeleteApartment = new QPushButton("Delete apartment");
	btnUpdateApartment = new QPushButton("Update apartment");
	btnSearchApartment = new QPushButton("Search");
	btnUndo = new QPushButton("Undo");
	btnNotificationCRUD = new QPushButton("Notification CRUD");
	btnNotificationRO = new QPushButton("Notification ReadOnly");


	lyLeft->addWidget(form);

	btnReloadData = new QPushButton("Reload data");
	lyLeft->addWidget(btnAddApartment);
	lyLeft->addWidget(btnDeleteApartment);
	lyLeft->addWidget(btnUpdateApartment);
	lyLeft->addWidget(btnSearchApartment);
	lyLeft->addWidget(btnUndo);
	lyLeft->addWidget(btnReloadData);
	lyLeft->addWidget(btnNotificationCRUD);
	lyLeft->addWidget(btnNotificationRO);

	QWidget* middle = new QWidget;
	QVBoxLayout* lyMiddle = new QVBoxLayout;
	middle->setLayout(lyMiddle);
	QWidget* midForm = new QWidget;
	QFormLayout* lyMidForm = new QFormLayout;
	midForm->setLayout(lyMidForm);

	//filter
	QLabel* fltLabel = new QLabel("Filter by:");
	lyMidForm->addWidget(fltLabel);
	cbFilter = new QComboBox;
	cbFilter->addItem("type");
	cbFilter->addItem("surface");
	lyMidForm->addWidget(cbFilter);
	filterInput = new QLineEdit;
	btnFilter = new QPushButton("Filter");
	lyMidForm->addWidget(filterLabel);
	lyMidForm->addWidget(filterInput);
	lyMidForm->addWidget(btnFilter);

	//sort
	QLabel* sortLabel = new QLabel("Sort by:");
	lyMidForm->addWidget(sortLabel);
	cbSort = new QComboBox;
	cbSort->addItem("name");
	cbSort->addItem("surface");
	cbSort->addItem("type+surface");
	lyMidForm->addWidget(cbSort);
	btnSort = new QPushButton("Sort");
	lyMidForm->addWidget(btnSort);

	lyMiddle->addWidget(midForm);

	QWidget* right = new QWidget;
	QVBoxLayout* lyRight = new QVBoxLayout;
	right->setLayout(lyRight);

	int noLines = 10;
	int noColumns = 4;
	this->tableApartments = new QTableWidget{ noLines, noColumns };

	//setam header-ul tabelului
	QStringList tblHeaderList;
	tblHeaderList << "Apartment" << "Name" << "Surface" << "Type";
	this->tableApartments->setHorizontalHeaderLabels(tblHeaderList);

	//optiune pentru a se redimensiona celulele din tabel in functie de continut
	this->tableApartments->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	lyRight->addWidget(tableApartments);
	lyMain->addWidget(left);
	lyMain->addWidget(middle);
	lyMain->addWidget(right);

}
void BlocGUI::reloadApartmentsList(vector<Locatar> locatari) {
	this->tableApartments->clearContents();
	this->tableApartments->setRowCount(locatari.size());

	int lineNumber = 0;
	for (auto& l : locatari) {
		this->tableApartments->setItem(lineNumber, 0, new QTableWidgetItem(QString::number(l.get_apartament())));
		this->tableApartments->setItem(lineNumber, 1, new QTableWidgetItem(QString::fromStdString(l.get_nume())));
		this->tableApartments->setItem(lineNumber, 2, new QTableWidgetItem(QString::number(l.get_suprafata())));
		this->tableApartments->setItem(lineNumber, 3, new QTableWidgetItem(QString::fromStdString(l.get_tip())));
		lineNumber++;
	}
}

void NotificationWindow::initializeNotifGUI() {
	QHBoxLayout* lyMain = new QHBoxLayout;
	this->setLayout(lyMain);
	QWidget* left = new QWidget;
	QVBoxLayout* lyLeft = new QVBoxLayout;
	left->setLayout(lyLeft);

	editApartament = new QLineEdit;
	editApartament->setStyleSheet("background-color: white");
	editRandomNumber = new QLineEdit;
	editRandomNumber->setStyleSheet("background-color: white");
	editHTML = new QLineEdit;
	editHTML->setStyleSheet("background-color: white");

	lblApartament->setStyleSheet("font: bold Times New Roman");
	lblRandom->setStyleSheet("font: bold Times New Roman");
	lblHTML->setStyleSheet("font: bold Times New Roman");

	

	btnAddApartment = new QPushButton("Add apartment");
	btnAddRandom = new QPushButton("Add random");
	btnClear = new QPushButton("Clear list");
	btnExport = new QPushButton("Export Data");
	btnReloadData = new QPushButton("Reload Data");

	lyLeft->addWidget(lblApartament);
	lyLeft->addWidget(editApartament);
	lyLeft->addWidget(btnAddApartment);
	
	lyLeft->addWidget(lblRandom);
	lyLeft->addWidget(editRandomNumber);
	lyLeft->addWidget(btnAddRandom);

	lyLeft->addWidget(lblHTML);
	lyLeft->addWidget(editHTML);
	lyLeft->addWidget(btnExport);

	lyLeft->addWidget(btnClear);
	lyLeft->addWidget(btnReloadData);


	QWidget* right = new QWidget;
	QVBoxLayout* lyRight = new QVBoxLayout;
	right->setLayout(lyRight);

	int noLines = 10;
	int noColumns = 4;
	//this->tableApartments = new QTableWidget{ noLines, noColumns };
	this->lst = new QListWidget;

	//setam header-ul tabelului
	//QStringList tblHeaderList;
	//tblHeaderList << "Apartment" << "Name" << "Surface" << "Type";
	//this->tableApartments->setHorizontalHeaderLabels(tblHeaderList);

	////optiune pentru a se redimensiona celulele din tabel in functie de continut
	//this->tableApartments->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

	//lyRight->addWidget(tableApartments);
	lyRight->addWidget(lst);
	lyMain->addWidget(left);
	lyMain->addWidget(right);
}

void BlocGUI::connectSignalsSlots() {
	QObject::connect(btnAddApartment, &QPushButton::clicked, this, &BlocGUI::guiAddApartment);
	QObject::connect(btnDeleteApartment, &QPushButton::clicked, this, &BlocGUI::guiDeleteApartment);
	QObject::connect(btnUpdateApartment, &QPushButton::clicked, this, &BlocGUI::guiUpdateApartment);
	QObject::connect(btnSearchApartment, &QPushButton::clicked, this, &BlocGUI::guiSearchApartment);
	QObject::connect(btnUndo, &QPushButton::clicked, this, &BlocGUI::guiUndo);

	QObject::connect(btnReloadData, &QPushButton::clicked, [&]() {
		this->reloadApartmentsList(srv.get_all());
		});

	QObject::connect(btnFilter, &QPushButton::clicked, this, &BlocGUI::guiFilter);
	QObject::connect(btnSort, &QPushButton::clicked, this, &BlocGUI::guiSort);
	QObject::connect(btnNotificationCRUD, &QPushButton::clicked, [&]() {
		NotificationWindow* notifWnd = new NotificationWindow{ this->srv, this->notif };
		notifWnd->show();
		});
	QObject::connect(btnNotificationRO, &QPushButton::clicked, [&]() {
		NotifReadOnlyGUI* notifRO = new NotifReadOnlyGUI{srv, notif};
		notifRO->show();
		});

}


void BlocGUI::guiAddApartment() {
	try {
		//preluare detalii din QLineEdit-uri
		int ap = editApartament->text().toInt();
		string nume = editNume->text().toStdString();
		int sup = editSup->text().toInt();
		string tip = editTip->text().toStdString();

		//optional - golim QLineEdit-urile dupa apasarea butonului
		editApartament->clear();
		editNume->clear();
		editSup->clear();
		editTip->clear();
		editNewName->clear();

		this->srv.add(ap, nume, sup, tip);
		this->reloadApartmentsList(this->srv.get_all());

		//afisam un mesaj pentru a anunta utilizatorul ca melodia s-a adaugat
		QMessageBox::information(this, "Info", QString::fromStdString("Apartment succesfully added."));

	}
	catch (RepoExceptions& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_message()));
	}
	catch (ValidationException& ve) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(ve.getErrorMsg()));
	}
}

void BlocGUI::guiDeleteApartment() {
	try {
		//preluare detalii din QLineEdit-uri
		int ap = editApartament->text().toInt();

		//optional - golim QLineEdit-urile dupa apasarea butonului
		editApartament->clear();
		editNume->clear();
		editSup->clear();
		editTip->clear();
		editNewName->clear();

		this->srv.delete_locatar(ap);
		this->reloadApartmentsList(this->srv.get_all());

		//afisam un mesaj pentru a anunta utilizatorul ca melodia s-a sters
		QMessageBox::information(this, "Info", QString::fromStdString("Apartment succesfully deleted."));

	}
	catch (RepoExceptions& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_message()));
	}
}

void BlocGUI::guiUpdateApartment() {
	try {
		//preluare detalii din QLineEdit-uri
		int ap = editApartament->text().toInt();
		string nume = editNewName->text().toStdString();

		//optional - golim QLineEdit-urile dupa apasarea butonului
		editApartament->clear();
		editNume->clear();
		editSup->clear();
		editTip->clear();
		editNewName->clear();

		this->srv.update(ap, nume);
		this->reloadApartmentsList(this->srv.get_all());

		//afisam un mesaj pentru a anunta utilizatorul ca melodia s-a adaugat
		QMessageBox::information(this, "Info", QString::fromStdString("Apartment succesfully updated."));

	}
	catch (RepoExceptions& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_message()));
	}
}

void BlocGUI::guiSearchApartment() {
	try {
		QWidget* searchResult = new QWidget;
		QFormLayout* lyForm = new QFormLayout;
		QTableWidget* searchTable = new QTableWidget{ 1, 4 };
		QStringList tblHeaderList;
		tblHeaderList << "Apartment" << "Name" << "Surface" << "Type";
		searchTable->setHorizontalHeaderLabels(tblHeaderList);
		int ap = editApartament->text().toInt();

		editApartament->clear();
		editNume->clear();
		editSup->clear();
		editTip->clear();
		editNewName->clear();

		Locatar l = srv.find(ap);
		searchTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
		searchTable->setItem(0, 0, new QTableWidgetItem(QString::number(l.get_apartament())));
		searchTable->setItem(0, 1, new QTableWidgetItem(QString::fromStdString(l.get_nume())));
		searchTable->setItem(0, 2, new QTableWidgetItem(QString::number(l.get_suprafata())));
		searchTable->setItem(0, 3, new QTableWidgetItem(QString::fromStdString(l.get_tip())));
		lyForm->addWidget(searchTable);
		searchResult->setLayout(lyForm);
		searchResult->show();
	}
	catch (RepoExceptions& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_message()));
	}
}

void BlocGUI::guiUndo() {
	try {

		editApartament->clear();
		editNume->clear();
		editSup->clear();
		editTip->clear();
		editNewName->clear();

		this->srv.undo();
		this->reloadApartmentsList(this->srv.get_all());

		//afisam un mesaj pentru a anunta utilizatorul ca melodia s-a adaugat
		QMessageBox::information(this, "Info", QString::fromStdString("Undo succesfully done."));

	}
	catch (RepoExceptions& re) {
		QMessageBox::warning(this, "Warning", QString::fromStdString(re.get_message()));
	}
}

void BlocGUI::guiFilter() {


	if (cbFilter->currentIndex() == 0)
	{
		string my_type = filterInput->text().toStdString();
		vector<Locatar> v = srv.filter_by_type(my_type).toStdVector();
		this->reloadApartmentsList(v);

	}
	if (cbFilter->currentIndex() == 1)
	{
		int my_surface = filterInput->text().toInt();
		vector<Locatar> v = srv.filter_by_surface(my_surface).toStdVector();
		this->reloadApartmentsList(v);

	}
}

void BlocGUI::guiSort() {
	if (cbSort->currentIndex() == 0) {
		// name
		vector<Locatar> v = srv.sort_by_name().toStdVector();
		this->reloadApartmentsList(v);
	}
	if (cbSort->currentIndex() == 1) {

		// surface
		vector<Locatar> v = srv.sort_by_surface().toStdVector();
		this->reloadApartmentsList(v);
	}
	if(cbSort->currentIndex()==2){
		//type+surface
		vector<Locatar> v = srv.sort_combined().toStdVector();
		this->reloadApartmentsList(v);
	}
}

void NotificationWindow::connectNotifSignalsSlots() {
	notif.addObserver(this);
	//QObject::connect(btnAddApartment, &QPushButton::clicked, this, &NotifGUI::addNotif);
	QObject::connect(btnAddApartment, &QPushButton::clicked, [&]() {
		int ap = editApartament->text().toInt();
		notif.addNotif(ap);
		editApartament->clear();
		this->reloadNotifList(this->srv.getNotifList());
		});
	//QObject::connect(btnAddRandom, &QPushButton::clicked, this, &NotifGUI::addRandom);
	QObject::connect(btnAddRandom, &QPushButton::clicked, [&]() {
		int nr = editRandomNumber->text().toInt();
		notif.addRandom(nr);
		editRandomNumber->clear();
		this->reloadNotifList(this->srv.getNotifList());
		});
	//QObject::connect(btnClear, &QPushButton::clicked, this, &NotifGUI::clearNotif);
	QObject::connect(btnClear, &QPushButton::clicked, [&]() {
		notif.clearNotif();
		this->reloadNotifList(this->srv.getNotifList());
		});
	//QObject::connect(btnExport, &QPushButton::clicked, this, &NotifGUI::exportNotif);
	QObject::connect(btnExport, &QPushButton::clicked, [&]() {
		string file = editHTML->text().toStdString();
		editHTML->clear();
		notif.exportNotif(file);
		QMessageBox::information(this, "Info", QString::fromStdString("Export succesfully done."));
		});
	QObject::connect(btnReloadData, &QPushButton::clicked, [&]() {
		this->reloadNotifList(srv.getNotifList());
		});
}

void NotificationWindow::reloadNotifList(vector<Locatar> locatari) {
	//this->tableApartments->clearContents();
	//this->tableApartments->setRowCount(locatari.size());
	this->lst->clear();

	/*int lineNumber = 0;
	for (auto& l : locatari) {
		this->tableApartments->setItem(lineNumber, 0, new QTableWidgetItem(QString::number(l.get_apartament())));
		this->tableApartments->setItem(lineNumber, 1, new QTableWidgetItem(QString::fromStdString(l.get_nume())));
		this->tableApartments->setItem(lineNumber, 2, new QTableWidgetItem(QString::number(l.get_suprafata())));
		this->tableApartments->setItem(lineNumber, 3, new QTableWidgetItem(QString::fromStdString(l.get_tip())));
		lineNumber++;
	}*/
	for (auto& l : locatari) {
		string data = to_string(l.get_apartament()) + "; " + l.get_nume() + "; " + to_string(l.get_suprafata()) + "; " + l.get_tip();
		QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(data));
		lst->addItem(item);
	}
}

void NotifGUI::addNotif(int ap) {
	//int ap = editApartament->text().toInt();
	srv.addToNotif(ap);

	/*editApartament->clear();
	this->reloadNotifList(this->srv.getNotifList());*/
	this->notify();

}

void NotifGUI::addRandom(int nr) {
	//int nr = editRandomNumber->text().toInt();
	srv.addRandomToNotif(nr);

	/*editRandomNumber->clear();
	this->reloadNotifList(this->srv.getNotifList());*/
	this->notify();

}

void NotifGUI::clearNotif() {
	srv.emptyNotif();
	//this->reloadNotifList(this->srv.getNotifList());
	this->notify();
}

void NotifGUI::exportNotif(string file) {
	/*string file = editHTML->text().toStdString();
	editHTML->clear();*/
	srv.exportNotif(file);
	//QMessageBox::information(this, "Info", QString::fromStdString("Export succesfully done."));
}