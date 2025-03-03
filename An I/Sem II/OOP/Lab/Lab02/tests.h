//
// Created by vladm on 3/13/2024.
//header file pentru functiile de test
#pragma once
#ifndef LAB02_TESTS_H
#define LAB02_TESTS_H

#endif //LAB02_TESTS_H

/*
 * functie de test pentru crearea unui electrocasnic
 */
void testCreateElectronic();

/*
 * functie de test pentru validator electrocasnic
 */
void testValidateElectronic();

/*
 * functie de test pentru adaugarea in repo a unui electrocasnic
 */
void testAdd();

/*
 * functie de test pentru marirea dimeansiunii vectorului dinamic
 */
void testResize();

/*
 *functie de test pentru crearea unei liste
 * care sa fie goala
 */
void testCreateEmpty();

/*
 * functie de test pentru stergerea unui element din lista de electrocasnice
 */
void testDelete();

/*
 * functie de test pentru service adaugare electrocasnic
 */
void testAddElectronicService();

/*
 * functie de test service pentru actualizarea unui element din lista
 */
void testUpdateElectronicService();

/*
 * functie de test service pentru stergerea unui electrocasnic din lista
 */
void testDeleteElectronicService();

/*
 * functie de test pentru actualizarea cantitatii unui electrocasnic
 */
void testUpdateQuantity();

/*
 * functie de test pentru destroy list
 */
void testDestroy();

/*
 * functie de rularea a tuturor testelor
 */
void runAllTests();