#include "Matrice.h"
#include "Matrice.cpp"

int main() {
    cout << "creo matrice" << endl;
    Matrice<int, 3, 3> matrice;
    //stampa della matrice (attualmente vuota)
    cout << "stampo matrice" << endl;
    matrice.print_mat();

    cout << "inserisco 4 in posizione 0,0" << endl;
    matrice.set_pos(4, 0, 0);
    cout << "stampo matrice" << endl;
    matrice.print_mat();

    cout << "inserisco nelle prime 5 posizione della matrice 1, 3, 5, 7, 9" <<endl;
    int val[] = {1, 3, 5,
                 7, 9};
    int dim=sizeof(val)/sizeof(val[0]);
    matrice.set_n_pos(val, dim);
    matrice.print_mat();

    cout << "inserisco nella matrice i numeri da 1 a 9" <<endl;
    int val1[] = {1, 2, 3,
                 4,5,6,
                 7,8,9};
    matrice.set_mat(val1);
    matrice.print_mat();

    return 0;

}