#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include "repository.h"
#include "service.h"
#include "gui.h"

void runGUI(int argc, char* argv[])
{
    QApplication a{argc, argv};
    RepoElevi repo{"elevi.txt"};
    EleviService service{repo};
    GUI gui{service};
    gui.show();
    a.exec();
}

int main(int argc, char *argv[]) {
    runGUI(argc, argv);
    return 0;
}
