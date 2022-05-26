#pragma once
#include <vector>
#include <string>
#include <QtWidgets/QApplication>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QTableWidget>
#include <QMessageBox>
#include <QComboBox>
#include <QHeaderView>
#include <QList>
#include <QGroupBox>
#include <QRadioButton>
#include "service.h"
#include "vd.h"
#include <qlistwidget.h>
#include <qpainter.h>
#include<ddraw.h>
#include "observer.h"
using std::vector;
using std::string;
using std::to_string;


class NotifGUI : public Observable {
private:
	friend class NotificationWindow;
	Bloc& srv;
	//void initializeNotifGUI();
	//void connectNotifSignalsSlots();
	//void reloadNotifList(vector<Locatar> v);

	//QLabel* lblApartament = new QLabel{ "Apartment number:" };
	//QLabel* lblRandom = new QLabel{ "Number of random:" };
	//QLabel* lblHTML = new QLabel{ "HTML File:" };

	//QLineEdit* editApartament;
	//QLineEdit* editRandomNumber;
	//QLineEdit* editHTML;

	//QPushButton* btnAddApartment;
	//QPushButton* btnAddRandom;
	//QPushButton* btnClear;
	//QPushButton* btnExport;
	//QPushButton* btnReloadData;

	////QTableWidget* tableApartments;
	//QListWidget* lst;

public:
	//NotifGUI(Bloc& srv) : srv{ srv } {
	//	initializeNotifGUI();
	//	connectNotifSignalsSlots();
	//	reloadNotifList(srv.getNotifList());
	//	//this->show();
	//}

	NotifGUI(Bloc& srv) : srv{ srv } {};

	void addNotif(int ap);

	void addRandom(int nr);

	void clearNotif();

	void exportNotif(string file);



};

class NotificationWindow : public QWidget, public Observer {
	Bloc& srv;
	NotifGUI& notif;
	friend class NotifReadOnlyGUI;
	void initializeNotifGUI();
	void connectNotifSignalsSlots();
	void reloadNotifList(vector<Locatar> v);

	QLabel* lblApartament = new QLabel{ "Apartment number:" };
	QLabel* lblRandom = new QLabel{ "Number of random:" };
	QLabel* lblHTML = new QLabel{ "HTML File:" };

	QLineEdit* editApartament;
	QLineEdit* editRandomNumber;
	QLineEdit* editHTML;

	QPushButton* btnAddApartment;
	QPushButton* btnAddRandom;
	QPushButton* btnClear;
	QPushButton* btnExport;
	QPushButton* btnReloadData;

	//QTableWidget* tableApartments;
	QListWidget* lst;
public:
	NotificationWindow(Bloc& srv, NotifGUI& notif) : srv{ srv }, notif{ notif } {
		initializeNotifGUI();
		connectNotifSignalsSlots();
		reloadNotifList(srv.getNotifList());
		//this->show();
	}

	void update() override {
		 reloadNotifList(srv.getNotifList());
	}
	
};

class NotifReadOnlyGUI : public QWidget, public Observer {
private:
	Bloc& srv;
	NotifGUI& notif;
public:
	NotifReadOnlyGUI(Bloc& srv, NotifGUI& notif) : srv{ srv }, notif{ notif } {
		notif.addObserver(this);
	}
	void update() override {
		repaint();
		//notif. reloadNotifList(srv.getNotifList());
	}
	
	void paintEvent(QPaintEvent* ev) override {
		QPainter p{ this };
		int x, y;
		for (const auto& ap : srv.getNotifList()) {
			x = rand() % 100;
			y = rand() % 100;
			p.drawRect(x, y, 40, 20);
		}
	}
};

class BlocGUI : public QWidget {
private:
	Bloc& srv;
	NotifGUI& notif;
	//NotifReadOnlyGUI& notifRO;

	QLabel* lblApartament = new QLabel{ "Apartment number:" };
	QLabel* lblNume = new QLabel{ "Locatar's name:" };
	QLabel* lblSup = new QLabel{ "Surface:" };
	QLabel* lblTip = new QLabel{ "Type:" };
	QLabel* lblNewName = new QLabel{ "New Name:" };
	QLabel* filterLabel = new QLabel{ "Specific type/surface:" };

	QLineEdit* editApartament;
	QLineEdit* editNume;
	QLineEdit* editSup;
	QLineEdit* editTip;
	QLineEdit* editNewName;
	QLineEdit* filterInput;

	QPushButton* btnAddApartment;
	QPushButton* btnDeleteApartment;
	QPushButton* btnUpdateApartment;
	QPushButton* btnUndo;
	QPushButton* btnReloadData;
	QPushButton* btnSearchApartment;
	QPushButton* btnFilter;
	QPushButton* btnSort;
	QPushButton* btnNotificationCRUD;
	QPushButton* btnNotificationRO;

	QComboBox* cbSort;
	QComboBox* cbFilter;

	QTableWidget* tableApartments;


	void initializeGUIComponents();

	void connectSignalsSlots();
	void reloadApartmentsList(vector<Locatar> locatari);
public:
	BlocGUI(Bloc& srv, NotifGUI& notif) : srv{ srv }, notif{ notif } {
		initializeGUIComponents();
		connectSignalsSlots();
		reloadApartmentsList(srv.get_all());
	}
	void guiAddApartment();
	void guiDeleteApartment();
	void guiUpdateApartment();
	void guiSearchApartment();
	void guiUndo();
	void guiFilter();
	void guiSort();

};
