#include "Matrice.h"
#include "Matrice.cpp"

int main() {
    cout<<"creo matrice"<<endl;
    Matrice<int> matrice(3, 3);
    //stampa della matrice (attualmente vuota)
    cout<<"stampo matrice"<<endl;
    matrice.print_mat();
    /*cout<<"inserisco 4 in posizione 0,0"<<endl;
    matrice.set_pos(4, 0,0);
    cout<<"stampo matrice"<<endl;
    matrice.print_mat();

    //int val[] = {1, 2, 3};
    //matrice.set_mat(val);
    //matrice.print_mat();
    cout<<"elimino matrice"<<endl;
    matrice.cancella();
*/

    return 0;

}