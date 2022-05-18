#include "gui.h"


#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Repository repo;
    service srv(repo);
    GUI w(srv);
    w.show();
    return a.exec();
}
