#pragma once

#include <QWidget>
#include <QHeaderView>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qlineedit.h>
#include <vector>
#include <string>
#include <qlabel.h>
#include <QFormLayout>
#include "validator.h"
#include <qboxlayout.h>
#include "service.h"
#include <QMessageBox>
#include <QDialog>
#include <QTableWidget>
#include <unordered_map>
#include "filter.h"

class GUI : public QWidget
{
    Q_OBJECT

private:

    service& srv;
    QWidget* output_widget = new QWidget;
    filter* filter = nullptr;
    QHBoxLayout* main_layout = new QHBoxLayout;
    QVBoxLayout* new_layout = new QVBoxLayout;
    QTableWidget* output_list;
    QPushButton* add_button;
    QPushButton* delete_button;
    QPushButton* modify_button;
    QPushButton* undo_button;

    std::string sort_field;
    int sort_reversed = 0;

   void layout_initialization();

   void event_connection();

   void new_action();

   void reload_list();

   void add_action();

   void delete_action();

   void undo_action();

   void modify_action();

   static void clearLayout(QLayout *layout);

public:
    GUI(service& srv);
    ~GUI();
};
