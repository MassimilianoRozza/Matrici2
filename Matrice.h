//
// Created by max on 08/05/23.
//

#ifndef MATRICI2_MATRICE_H
#define MATRICI2_MATRICE_H
#include "iostream"
#include <fstream>

using namespace std;

template<typename T, int RIGHE, int COLONNE>
class Matrice {
public:
    //=================================== COSTRUTTORE + DISTRUTTORE
    Matrice();

    //=================================== METODI
    void print_mat()const;

    int num_elem_mat()const;

    //=================================== SETTER

    //prende in ingresso un vettore con n elementi
    //dove n=r*c dimensione della matrice
    int set_mat(const T *valori);

    //prende in ingresso un valore da inserire due int
    //per la posizione nella matrice
    void set_pos(const T num, const int r, const int c);

    //prende in ingresso un vettore e la dimensione dello stesso;
    int set_n_pos(const T*valori, const int dim);

    int set_mat_file(const char* nome_file);
    //=================================== GETTER

    T get_pos(int r, int c)const;

    //=================================== OPERATORI

    int operator<<(const T &valore);



private:
    int righe, colonne;
    T mat[RIGHE][COLONNE];
};

#endif //MATRICI2_MATRICE_H
