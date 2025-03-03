#include "Practic_Sesiune_Mutu_Vlad.h"
#include <QtWidgets/QApplication>
#include "teste.h"
#include "repository.h"
#include "service.h"
#include "domain.h"
#include "GUI.h"
void runGUI(int argc, char* argv[])
{
    QApplication a(argc, argv);
    RepoUtilaje repo("utilaje.txt");
    ServiceUtilaje serv(repo);
    GUI gui(serv);
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
