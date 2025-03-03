//
// Created by vladm on 5/10/2024.
//
#include <cassert>
#include "test.h"
#include "Lista.h"
#include "IteratorLP.h"
#include <exception>

void run(){
    try{
        throw std::exception();
        assert(false);
    } catch (std::exception& e) {
        assert(true);
    }
};