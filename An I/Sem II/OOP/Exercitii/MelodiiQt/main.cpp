//#include <QApplication>
//#include <QPushButton>
//#include "repository.h"
//#include "service.h"
//#include "teste.h"
//#include "GUI.h"
//
//void runGui(int argc, char* argv[]) {
//    QApplication a(argc, argv);
//    RepoMelodii r{};
//    ServiceMelodii serv{r};
//    GUI gui{serv};
//    gui.show();
//    a.exec();
//}
//
//int main(int argc, char *argv[])
//{
//    runGui(argc, argv);
//    return 0;
//}

#include <iostream>

using namespace std;

int main() {
    string s = "niggas";
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < s.size(); j++)
            cout << s[(i + j) % s.size()] << ' ';
        cout << '\n';
    }
    return 0;
}