#include <iostream>
#define max 10
using namespace std;

void insDim(int & );
void compilaMat(int[][max], int, int);
void stampaMat(int[][max], int, int);
void eliminariga(int[][max], int & , int);
void eliminacolonna(int[][max], int, int & );
void ordinariga(int[][max], int, int);
void ricerca(int[][max], int, int, bool & , int, int & , int & );

int main() {

  int matrice[max][max];
  int righe;
  int colonne;
  int cercato;
  bool trovato;
  int risr;
  int risc;
  cout << "Inserisci il numero di righe: ";
  insDim(righe);
  cout << "Inserisci il numero di colonne: ";
  insDim(colonne);
  cout << endl;
  compilaMat(matrice, righe, colonne);
  cout << "La tua matrice:\n";
  stampaMat(matrice, righe, colonne);
  //Eliminazione riga o colonna
  eliminariga(matrice, righe, colonne);
  cout << "\nLa tua matrice:\n";
  stampaMat(matrice, righe, colonne);
  eliminacolonna(matrice, righe, colonne);
  cout << "\nLa tua matrice:\n";
  stampaMat(matrice, righe, colonne);
  //ordinamento riga
  ordinariga(matrice, righe, colonne);
  cout << "\nLa tua matrice:\n";
  stampaMat(matrice, righe, colonne);
  //ricerca
  cout << "\nInserisci elemento da cercare nella matrice: ";
  cin >> cercato;
  ricerca(matrice, righe, colonne, trovato, cercato, risr, risc);
  if (trovato) {
    cout << "La prima posizione in cui si trova " << cercato << " e\': " << risr << " " << risc;
  } else {
    cout << "Non trovato";
  }

  cout << endl;
  system("pause");
  return 0;
}

void insDim(int & dim) {
  do {
    cin >> dim;
    if (dim <= 0 || dim > max) {
      cout << "Errore, reinserisci: ";
    }
  } while (dim <= 0 || dim > max);
}

void compilaMat(int m[][max], int righe, int colonne) {
  for (int i = 0; i < righe; i++) {
    for (int j = 0; j < colonne; j++) {
      cout << "Inserisci elemento in posizione (" << i << ", " << j << "): ";
      cin >> m[i][j];
    }
    cout << endl;
  }
}

void stampaMat(int m[][max], int righe, int colonne) {
  for (int i = 0; i < righe; i++) {
    for (int j = 0; j < colonne; j++) {
      cout << m[i][j] << '\t';
    }
    cout << endl;
  }
}

void eliminariga(int m[][max], int & righe, int colonne) {
  int indice;
  cout << "\nInserisci l'indice della riga da eliminare: ";
  cin >> indice;

  if (indice < 0 || indice > righe - 1) {
    cout << "Impossibile eliminare la riga di indice " << indice << endl;
  } else {
    //[indice][var]
    for (indice; indice < righe; indice++) {
      for (int i = 0; i < colonne; i++) {
        m[indice][i] = m[indice + 1][i];
      }
    }
    righe--;
  }
}

void eliminacolonna(int m[][max], int righe, int & colonne) {
  int indice;
  cout << "\nInserisci l'indice della colonna da eliminare: ";
  cin >> indice;

  if (indice < 0 || indice > colonne - 1) {
    cout << "Impossibile eliminare la colonna di indice " << indice << endl;
  } else {
    //[var][indice]
    for (indice; indice < colonne; indice++) {
      for (int i = 0; i < righe; i++) {
        m[i][indice] = m[i][indice + 1];
      }
    }
    colonne--;
  }
}

void ordinariga(int m[][max], int righe, int colonne) {
  int indice;
  int posmin;
  int temp;
  cout << "\nInserisci l'indice della riga da ordinare: ";
  cin >> indice;

  if (indice < 0 || indice > righe - 1) {
    cout << "Impossibile ordinare la riga di indice " << indice << endl;
  } else {
    for (int i = 0; i < colonne - 1; i++) {
      posmin = i;
      for (int j = i + 1; j < colonne; j++) {
        if (m[indice][j] < m[indice][i]) {
          posmin = j;
        }
      }
      temp = m[indice][i];
      m[indice][i] = m[indice][posmin];
      m[indice][posmin] = temp;
    }
  }
}

void ricerca(int m[][max], int righe, int colonne, bool & trovato, int elem, int & riga, int & colonna) {
  trovato = false;

  for (int i = 0; i < righe; i++) {
    for (int j = 0; j < colonne; j++) {
      if (m[i][j] == elem) {
        trovato = true;
        riga = i;
        colonna = j;
        return;
      }
    }
  }

}
