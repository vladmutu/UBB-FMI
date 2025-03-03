#include "Lab1011_Qt.h"
#include <QtWidgets/QApplication>
#include <QtWidgets>
#include "teste.h"
#include "ui.h"
#include "service.h"
#include "repository.h"
#include "GUI.h"
using namespace std;


void runGUI(int argc, char* argv[]) {
	QApplication a{ argc, argv };
	RepoFisier repo{ "masini.txt" };
	Spalatorie spalatorie;
	ServiceMasina service{ repo, spalatorie};
	GUI gui{ service };
	gui.show();
	a.exec();
}

int main(int argc, char *argv[])
{
    allTests();
	runGUI(argc, argv);
	return 0;
}
