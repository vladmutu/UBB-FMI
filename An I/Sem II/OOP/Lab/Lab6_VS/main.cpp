#include "teste.h"
#include "ui.h"
#include "service.h"
#include "repository.h"
#include <stdlib.h>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
using namespace std;

int main() {
    allTests();
    /*MasinaRepo repo;
    ServiceMasina service(repo);
    UI ui(service);*/
    //ui.run();
    _CrtDumpMemoryLeaks();
    return 0;
}
