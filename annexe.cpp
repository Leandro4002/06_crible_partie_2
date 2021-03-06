/*
  ---------------------------------------------------------------------------
  Fichier     : annexe.cpp
  Nom du labo : Labo_crible_GroupeO
  Auteur(s)   : Emilie Bressoud & Bastien Pillonel
  Date        : 19.11.2021
  But         : Fichier de définition des sous-programme annexes

  Modifs      : Leandro S.M et Miguel J. 2021-11-25
                - Ajout de la fonction d'affichage 'put' pour afficher un tableau
                  d'entiers sur une seule ligne et de la fonction
                  'tableNonSigneeABool' pour convertir unsigned[] à bool[]

  Remarque(s) : -

  Compilateur : MingW-w64 g++ 11.2.0 et Apple Clang 13.0.0
  ---------------------------------------------------------------------------
*/

#include "annexe.h"
#include <iostream>
#include <limits>

using namespace std;

// Vidage buffer
void viderBuffer(){
   cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fin de programme
void finProgramme(const string& MSG_FIN){
   cout  << MSG_FIN;
   viderBuffer();
   exit(EXIT_SUCCESS);
}

void put(const unsigned tab[], size_t size){
	cout << '[';
	for(size_t i = 0ull; i < size; ++i){
		cout << tab[i];
		if(i != size - 1ull){
			cout << ", ";
		}
	}
	cout << ']';
}

void tableNonSigneeABool (bool tableBooleen[], const unsigned tableNonSignee[],
								  size_t tailleTableau) {
	for (size_t i = 0ull; i < tailleTableau; ++i) {
		tableBooleen[i] = bool(tableNonSignee[i]);
	}
}