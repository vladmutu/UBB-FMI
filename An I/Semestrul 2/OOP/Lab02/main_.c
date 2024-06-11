/*
 * main source file
 */
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "ui.h"
#include "tests.h"
/*
 *main file
 */
int main() {
    runAllTests();
    //run();
    _CrtDumpMemoryLeaks();
    return 0;
}