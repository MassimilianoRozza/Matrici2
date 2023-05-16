//
// Created by max on 08/05/23.
//

#include "Matrice.h"
using namespace std;

//================================================== COSTRUTTORE

template<typename T, int RIGHE, int COLONNE>
Matrice<T, RIGHE, COLONNE>::Matrice() {
    if(RIGHE > 0 && COLONNE > 0){
        this->righe = RIGHE;
        this->colonne = COLONNE;
        //creo la matrice e l'inizializzo
        cout << "ciclo per creare le colonne"<<endl;
        for(int i = 0; i < this->righe; ++i) {
            for (int j = 0; j < this->colonne; ++j) {
                mat[i][j] = 0;
            }
        }
    } else{
        cerr<<"Errore dimensione della matrice"<<endl;
        this->righe = 0;
        this->colonne = 0;
    }
}

//==================================================== METODI
template<typename T, int RIGHE, int COLONNE>
void Matrice<T, RIGHE, COLONNE>::print_mat() const {
    for (int i = 0; i < this->righe; ++i) {
        for (int j = 0; j < this->colonne; ++j) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\n\n";
}

template<typename T, int RIGHE, int COLONNE>
int Matrice<T, RIGHE, COLONNE>::num_elem_mat()const {
    return righe*colonne;
}

//=================================== SETTER
template<typename T, int RIGHE, int COLONNE>
int Matrice<T, RIGHE, COLONNE>::set_mat(const T *valori){
    int dim = num_elem_mat();
    int pos=0;
    for (int i = 0; i < righe; ++i) {
        for(int j = 0; j < colonne; ++j) {
            try{
                mat[i][j] = valori[pos];
            }catch(const std::runtime_error& e) {
                cerr << "probabile errore nelle dimensioni del vettore argomento"<<endl;
                cerr << "inseriti " << pos << "valori"<<endl;
                cerr << "TIPO DI ERRORE: " << e.what() <<endl;
                return 1;
            }catch(const std::exception& e) {
                cerr << "probabile errore nelle dimensioni del vettore argomento"<<endl;
                cerr << "inseriti " << pos << "valori"<<endl;
                cerr << "TIPO DI ERRORE: " << e.what() <<endl;
                return 1;
            }
            pos++;
        }
    }
    return 0;
}


template<typename T, int RIGHE, int COLONNE>
void Matrice<T, RIGHE, COLONNE>::set_pos(const T num,const int r,const int c){
    mat[r][c] = num;
}

template<typename T, int RIGHE, int COLONNE>
int Matrice<T, RIGHE, COLONNE>::set_n_pos(const T*valori, const int dim){
    int a = 0;
    if (dim > righe*colonne){return 1;}
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            if (a == dim) {
                return 0;
            } else{
                mat[i][j] = valori[a];
                a++;
            }
        }
    }
    return 0;
}

template<typename T, int RIGHE, int COLONNE>
int Matrice<T, RIGHE, COLONNE>::set_mat_file(const char* nome_file) {
    fstream file;
    file.open(nome_file, fstream::in);

    //se il file è stato aperto correttamente
    if (!file.is_open()) {
        return 1;
    }

    string riga;
    while(getline(file, riga)){
        cout << riga << endl;
    }

    //chiusura del file
    file.close();
    return 0;
}
//=================================== GETTER

template<typename T, int RIGHE, int COLONNE>
T Matrice<T, RIGHE, COLONNE>::get_pos(int r, int c)const{
    return mat[r][c];
}

//=================================== OPERATORI

template<typename T, int RIGHE, int COLONNE>
int Matrice<T, RIGHE, COLONNE>::operator<<(const T &valore) {
    int pos = 0;
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            try {
                mat[i][j] = valore[pos];
            }catch (const runtime_error& e) {
                return 1;
            } catch (const exception& e) {
                return 1;
            }
        }
    }
    return 0;
}