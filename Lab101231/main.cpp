#include "lab10.h"
#include "report.h"
#include "locatar.h"
#include "blocGUI.h"
#include "repo.h"
#include "service.h"
#include "validator.h"
#include <QtWidgets/QApplication>

void test_all();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	Repo rep;
	LocatarValidator val;
	Bloc serv{ rep, val };
	NotifGUI notif{ serv };
	BlocGUI gui{ serv, notif };
	
    gui.show();
    return a.exec();
}

void test_all()
{
	test_repo();
	test_add();
	test_delete_locatar();
	test_update();
	test_find();
	test_sort_by_name();
	test_filter_by_type();
	test_filter_by_surface();
	test_sort_by_surface();
	test_sort_combined();
	test_addToNotif();
	test_addRandomToNotif();
	test_emptyNotif();
	test_report();
	test_undo();
}
