#include <QApplication>
#include <QtWidgets>
#include "repository.h"
#include "service.h"
#include "gui.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    RepoLogs repo{"logs.txt"};
    ServiceLogs service{repo};
    GUI gui{service};
    gui.show();
    return QApplication::exec();
}
