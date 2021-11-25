/*
  ---------------------------------------------------------------------------
  Fichier     : crible.cpp
  Nom du labo : Labo_crible_GroupeO
  Auteur(s)   : Emilie Bressoud & Bastien Pillonel
  Date        : 19.11.2021
   But         : Fichier de définitions des sous-programmes utilisés pour la
                demonstration du crible d'Eratosthène
  Modifs      : Leandro S.M et Miguel J. 2021-11-25
                - Ajout d'une fonction crible qui prend en charge des booléens

  Remarque(s) : Les nombres non premiers sont mis à zéro lors du criblage.

  Compilateur : MingW-w64 g++ 11.2.0 et Apple Clang 13.0.0
  ---------------------------------------------------------------------------
*/

#include "crible.h"
#include "tableauC.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Déclaration des variables et constantes
const char           CROIX    =  'X',
                     CERCLE   =  'O';

const unsigned       ESPACEMENT_CRIBLE_AFFICHAGE         =  2,
                     ESPACEMENT_NOMBRE_PREMIER_AFFICHAGE =  4;

const string         MSG_AFFICHAGE_NBR_PREMIER_1   =  "Il y a ",
                     MSG_AFFICHAGE_NBR_PREMIER_2   =  " nombre premier",
                     MSG_AFFICHAGE_NBR_PREMIER_2_PL=  " nombres premiers";

// Rempli un tableau avec la liste des entier naturel de 1 à n entier (taille)
void listeEntierNaturel(unsigned tab[], unsigned taille){
   for(unsigned i = taille; i > 0; --i){
      remplirTableau(tab, i, taille);
      --taille;
   }
}

// Crible le tableau d'entier naturel selon la méthode d'Eratosthène
void criblerTableau(unsigned tab[], unsigned taille){
   unsigned pos   =  0,
            multiple,
            positionMultiple;

   listeEntierNaturel(tab, taille);

   tab[pos] =  0; // Cas spécial pour le chiffre 1 mis à zéro d'office
   ++pos;

   // Pour toutes les positions du tableau dont l'élément est différent de 0
	// TODO Changer cette condition qui est fausse
   for(; (tab[pos] * tab[pos]) <= taille; ++pos){
      if(tab[pos] != 0){
         multiple =  tab[pos];

         // On cherche tout ces multiples sauf lui même
         for(unsigned i = 2; (i * multiple) <= taille; ++i){
            positionMultiple  = recherche(tab, taille, (i * multiple), pos);

            if(positionMultiple != taille)
               tab[positionMultiple]   =  0;    // Mise à 0 des multiples si ça
                                                // n'a pas déjà été fait
         }
      }
   }
}

unsigned nbre1er(const bool tableCrible[], size_t tailleTableCrible,
					  unsigned tablePremier[], size_t capaciteTablePremier) {
	unsigned nomberDePremier = 0u;

	// On itère à travers tout les éléments de la table de crible
	for (size_t i = 0ull; i < tailleTableCrible; ++i) {
		// Si la valeur actuelle n'a pas été retiré par le crible d'Eratosthenes
		if (tableCrible[i]) {
			// Ajouter le nombre to the list of primes and increment the num of prime
			tablePremier[nomberDePremier++] = unsigned(i) + 1u;
		}
	}

	return nomberDePremier;
}

// affiche les nombres par une croix ou cercle
void croixOuCercle(const unsigned tab[], bool isInit, unsigned pos){
   if(!isInit && tab[pos] == 0){
      cout << CROIX;
   }else{
      cout << CERCLE;
   }
}

// Affichage du crible
void afficheCrible(const string& MSG_AFFICHAGE, const unsigned tab[],
                   unsigned taille, bool isInit, unsigned colonne){

   cout  << MSG_AFFICHAGE;

   for(unsigned i = 0; i < taille; ++i){
      if(!(i % colonne))
         cout  << endl;

      cout  << setw(ESPACEMENT_CRIBLE_AFFICHAGE);

            croixOuCercle(tab, isInit, i);
   }
   cout  << endl  << endl;
}

// Calcule le total de nombres premier dans un tableau criblé
unsigned combienNombrePremier(const unsigned tab[], unsigned taille){
   unsigned compteur = 0;

   for(unsigned i = 0; i < taille; ++i){
      if(tab[i])
         ++compteur;
   }
   return compteur;
}

// Affiche les nombres premiers d'un tableau criblé
void afficheNombrePremier(const unsigned tab[], unsigned taille){
   cout  << MSG_AFFICHAGE_NBR_PREMIER_1   << combienNombrePremier(tab,taille)
         << ((combienNombrePremier(tab, taille) == 1)?
            MSG_AFFICHAGE_NBR_PREMIER_2 : MSG_AFFICHAGE_NBR_PREMIER_2_PL)
         << endl;
   //Lorsqu'il n'y en a qu'un seul nombre premier, s'affiche au
   // singulier

   for(unsigned i = 0; i < taille; ++i){
      if(tab[i])
         cout  << setw(ESPACEMENT_NOMBRE_PREMIER_AFFICHAGE) << tab[i];
   }
   cout  << endl  << endl;
}

