#include <iostream>

#include "TestScurt.h"
#include "TestExtins.h"
#include "test.h"

int main(){
    testAll();
    std::cout<<"S-a terminat testul scurt!"<<std::endl;
    testAllExtins();
    std::cout<<"S-a terminat testul extins!"<<std::endl;
}
