#pragma once
#include "MasinaService.h"
class ui {
    MasinaService& serv;
public:
    ui(MasinaService& serv): serv{serv}{
    }
    void run();
};



