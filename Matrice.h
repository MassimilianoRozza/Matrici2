//
// Created by max on 08/05/23.
//

#ifndef MATRICI2_MATRICE_H
#define MATRICI2_MATRICE_H
#include "iostream"
using namespace std;

template<typename T>
class Matrice {
public:
    //=================================== COSTRUTTORE + DISTRUTTORE
    Matrice(int r, int c);

    ~Matrice();
    //=================================== METODI
    void print_mat();

    int num_elem_mat();

    void cancella();
    //=================================== SETTER

    int set_mat(const T *valori);

    void set_pos(T num, int r, int c);

private:
    int righe{}, colonne{};
    T **mat;
};

#endif //MATRICI2_MATRICE_H
