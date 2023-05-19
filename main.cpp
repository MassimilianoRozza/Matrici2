/*
 * ERRERE: se si include solo Matrice.h si ha una serie di errori
 * "undefined reference to ..." per ogni funzione della classe
 * compreso il costruttore.
 * L'errore si presenta sia per la compilazione con g++ sia con la
 * compilazione tramite clion.
 * Per ricreare l'errore commentare la riga "#include "Matrice.cpp"
*/

#include "Matrice.h"
//per evitare errori è stata aggiunta la riga seguente
#include "Matrice.cpp"

/*
 * La compilazione con clion per aprire file nella stessa cartella
 * dell'eseguibile richiede di modificare il parametro
 * "working directory" nella configurazione di esecuzione.
 * In alternativa la compilazione da terminale risolve.
*/

int main() {

    cout << "creo matrice" << endl;
    Matrice<int, 3, 3> matrice;
    //stampa della matrice (attualmente vuota)
    cout << "stampo matrice" << endl;
    matrice.print_mat();

    cout << "inserisco 4 in posizione (0,0) e 5 in (1,1)" << endl;
    matrice.set_pos(4, 0, 0);
    matrice.set_pos(5, 2, 2);
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

    cout << "aggiorno valori della matrice da file" <<endl;
    matrice.set_mat_file("elementi.txt");

    matrice.print_mat();
    return 0;
}