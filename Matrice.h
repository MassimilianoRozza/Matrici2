// La classe è incompleta perciò alcuni metodi sono commentati.

#ifndef MATRICI2_MATRICE_H
#define MATRICI2_MATRICE_H
#include "iostream"
#include <fstream>
#include "cstring"
#include "filesystem"

using namespace std;

//classe per gestire matrici
template<typename T, int RIGHE, int COLONNE>
class Matrice {
public:
    //=================================== COSTRUTTORE + DISTRUTTORE
    Matrice();

    //=================================== METODI

    //ritorna il numero di posizione della matrice come righe*colonne
    int num_elem_mat()const;

    //metodo per stampare a terminale la matrice
    void print_mat()const;

    //=================================== SETTER

    //prende in ingresso un vettore con n elementi
    //dove n=r*c dimensione della matrice
    int set_mat(const T *valori);

    //prende in ingresso un valore da inserire e due int
    //che definiscono la posizione nella matrice
    void set_pos(T num, int r, int c);

    //prende in ingresso un vettore e la dimensione dello stesso
    //e inserisce i valori contenuti nel vettore a partire dalla
    //posizione (0,0) della matrice
    int set_n_pos(const T*valori, int dim);

    //prende in ingresso il nome di un file e ne legge il contenuto
    //per caricarlo nella matrice ingnorando la formattazione del file:
    //se nel file sono inseriti più valori di quelli inseribili nella
    //matrice restituisce non esegue l'assegnazione
    int set_mat_file(const char* nome_file);

    //int set_mat_term();
    //=================================== GETTER

    //restituisce il valore contenuto in posizione (r,c)
    T get_pos(int r, int c)const;

    //=================================== OPERATORI

    //Matrice &operator+(const Matrice<T, RIGHE, COLONNE> &addendo) const;

    //Matrice &operator+(const double &addendo)const ;

    //Matrice &operator+(const int &addendo)const ;

    //Matrice &operator*(const Matrice<T, RIGHE, COLONNE>) const;



private:
    const int righe = RIGHE, colonne = COLONNE;
    T mat[RIGHE][COLONNE];
};

#endif //MATRICI2_MATRICE_H
