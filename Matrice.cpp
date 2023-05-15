//
// Created by max on 08/05/23.
//

#include "Matrice.h"

//================================================== COSTRUTTORE

template<typename T>
Matrice<T>::Matrice(int r, int c) {
    if(r > 0 && c > 0){
        //creo la matrice e l'inizializzo
        *mat = new T[r];
        this->righe = r;
        this->colonne = c;

        for (int i = 0; i < this->righe; ++i) {
            mat[i] = new T[this->colonne];
            for (int j = 0; j < this->colonne; ++j) {
                mat[i][j] = 0;
            }
        }
    } else{
        cerr<<"Errore dimensione della matrice"<<endl;
    }
}
template<typename T>
Matrice<T>::~Matrice(){
    for (int i = 0; i < righe; ++i) {
        delete[] mat[i];
    }
    delete[] *mat;
}



//==================================================== METODI
template<typename T>
void Matrice<T>::print_mat() {
    for (int i = 0; i < this->righe; ++i) {
        for (int j = 0; j < this->colonne; ++j) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n\n";
}

template<typename T>
int Matrice<T>::num_elem_mat() {
    return righe*colonne;
}

template<typename T>
void Matrice<T>::cancella(){
    for (int i = 0; i < righe; ++i) {
        delete[] mat[i];
    }

    delete[] *mat;
}

//=================================== SETTER
template<typename T>
int Matrice<T>::set_mat(const T *valori){
    int dim = sizeof(valori);///sizeof(valori[0]);
    if(num_elem_mat()>=dim){
        dim = min(dim, num_elem_mat());
        int pos=0;
        for (int i = 0; i < righe; ++i) {
            for(int j = 0; j < colonne; ++j) {
                pos++;
                mat[i][j] = valori[pos];
                if(pos==dim)return 0;
            }
        }
        return 0;
    }else{
        return 1;
    }
}

template<typename T>
void Matrice<T>::set_pos(T num, int r, int c){
    mat[r][c] = num;
}