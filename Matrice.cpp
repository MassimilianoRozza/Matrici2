#include "Matrice.h"
using namespace std;

//================================================== COSTRUTTORE

template<typename T, int RIGHE, int COLONNE>
Matrice<T, RIGHE, COLONNE>::Matrice() {
    if(RIGHE > 0 && COLONNE > 0){
        for(int i = 0; i < this->righe; ++i) {
            for (int j = 0; j < this->colonne; ++j) {
                mat[i][j] = 0;
            }
        }
    } else{
        cerr<<"Errore dimensione della matrice"<<endl;
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
            mat[i][j] = valori[pos];
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

    ifstream file(nome_file);       //apertura del file

    T out[num_elem_mat()];               //creazione del vettore per il caricamento dei dati

    if (file.is_open()) {               //se il file è stato aperto correttamente

        string line, subs;              //creo le stringhe per contenere la riga e il singolo valore

        int pos = 0;                    //inizializzo la posizione di scrittura nel vettore di caricamento dei valori

        while (getline(file, line)) {                       //leggo una riga e se è riuscito proseguo nel ciclo

            int inizio = 0, fine = line.find(' ');              //definisco e inizializzo i puntatori alla posizione del primo valore da caricare
            while(fine != string::npos){                           //finchè arrivo alla fine della stringa

                subs = line.substr(inizio, fine - inizio);  //estraggo una stringa contenente solo il valore

                inizio = fine+1;                                   //aggiorno la posizione d'inizio ricerca della stringa successiva

                //in base al tipo scelto per la matrice uso il corretto metodo di conversione
                if(typeid(T) == typeid(int)){       //int
                    out[pos++] = stoi(subs);
                }else if(typeid(T) == typeid(double)){    //double
                    out[pos++] = stod(subs);
                }else if( typeid(T) == typeid(float)){    //float
                    out[pos++] = (float)stod(subs);
                }

                fine = line.find(' ', inizio);              //aggiorno la posizione della fine della successiva stringa
            }

            subs = line.substr(inizio, fine-inizio);
            if(typeid(T) == typeid(int)){       //int
                out[pos++] = stoi(subs);
            }else if(typeid(T) == typeid(double)){    //double
                out[pos++] = stod(subs);
            }else if( typeid(T) == typeid(float)){    //float
                out[pos++] = (float)stod(subs);
            }
            set_n_pos(out, pos);
        }

        file.close();
        return 0;
    }else{
        printf("errore apertura file");
        return 1;
    }
    return 1;
}

/*
template<typename T, int RIGHE, int COLONNE>
int Matrice<T, RIGHE, COLONNE>::set_mat_term() {
    //promemoria per l'utente del tipo di matrice
    cout << "la matrice è di dimensione: " << righe << "*" << colonne <<endl;
    print_mat();
    cout << "quindi inserire massimo "<< num_elem_mat() <<" valori separati da uno spazio"<<endl;

    T num;                                 //definizione della var temporanea per la lettura dell'imput
    //ciclo nella matrice
    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j < colonne; ++j) {
            //per ogni posizione della matrice
            do {
                cin >> num;                     //leggo un input
            } while (typeid(num) != typeid(T));   //e continuo finché non è valido

            //assegno il valore alla posizione della matrice
            mat[i][j] = num;
        }
    }
    print_mat();
    return 0;
}*/

//=================================== GETTER

template<typename T, int RIGHE, int COLONNE>
T Matrice<T, RIGHE, COLONNE>::get_pos(int r, int c)const{
    return mat[r][c];
}

//=================================== OPERATORI

/*template<typename T, int RIGHE, int COLONNE>
Matrice<T, RIGHE, COLONNE> &Matrice<T, RIGHE, COLONNE>::operator+(const double &addendo)const {
    Matrice<T, RIGHE, COLONNE> out;

    for (int i = 0; i < righe; ++i) {
        for (int j = 0; j <colonne; ++j) {
            out.set_pos(mat[i][j]+(T)addendo,i, j);
        }
    }
    return out;
}*/

/*template<typename T, int RIGHE, int COLONNE>
 Matrice<T, RIGHE, COLONNE>::operator+(const Matrice<T, RIGHE, COLONNE> &addendo) {

}*/