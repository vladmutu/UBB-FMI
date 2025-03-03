#include "teste.h"
//#include "ui.h"
//#include "service.h"
//#include "repository.h"

#define _CRTDBG_MAP_ALLOC
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
//using namespace std;

int main() {
    allTests();
    /*MasinaRepo repo;
    Spalatorie spalatorie;
    ServiceMasina service(repo, spalatorie);
    UI ui(service);
    ui.run();
    */
    _CrtDumpMemoryLeaks();
}