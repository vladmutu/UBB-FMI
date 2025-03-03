#include "Tractoare.h"
#include <QtWidgets/QApplication>
#include "repository.h"
#include "service.h"
#include "teste.h"
#include "GUI.h"
void runGUI(int argc, char* argv[]) {
    QApplication a(argc, argv);
    RepoTractoare repo{ "tractoare.txt" };
    ServiceTractoare service{ repo };
    GUI gui{ service };
    gui.show();
    a.exec();
}


int main(int argc, char *argv[])
{
    Teste t;
    t.runAll();
    runGUI(argc, argv);
    return 0;
}
