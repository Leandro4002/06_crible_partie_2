/*
  ---------------------------------------------------------------------------
  Fichier     : annexe.h
  Nom du labo : Labo_crible_GroupeO
  Auteur(s)   : Emilie Bressoud & Bastien Pillonel
  Date        : 19.11.2021
  But         : Fichier de déclaration des sous-programme annexes
  Modifs      : Leandro S.M et Miguel J. 2021-11-25
                - Ajout de la fonction d'affichage 'put' pour afficher un tableau
                  d'entiers sur une seule ligne et de la fonction
                  'tableNonSigneeABool' pour convertir unsigned[] à bool[]

  Remarque(s) : -

  Compilateur : MingW-w64 g++ 11.2.0 et Apple Clang 13.0.0
  ---------------------------------------------------------------------------
*/

#ifndef MAIN_CPP_ANNEXE_H
#define MAIN_CPP_ANNEXE_H

#include <string>

//-------------------------------------------------------------------
// viderBuffer
//-------------------------------------------------------------------
// Description: Vide le buffer de saisie
//
// Paramètres:
// Nom: -    Description:
//
// Retourne: -
//-------------------------------------------------------------------
void viderBuffer();

//-------------------------------------------------------------------
// finProgramme
//-------------------------------------------------------------------
// Description: Stop le programme et demande à l'utilisateur de presser
// enter pour fermer le programme.
//
// Paramètres:
// Nom: MSG_FIN    Description: Instruction de fermeture du programme
//
// Retourne: -
//-------------------------------------------------------------------
void finProgramme(const std::string& MSG_FIN);

//-------------------------------------------------------------------
// put
//-------------------------------------------------------------------
// Description: Affiche les éléments d'un tableau d'entiers.
//              Avec format [x, x, x]
// Paramètres:
// Nom:         tab[]   est le tableau à afficher
// Nom:         size    est la taille du tableau
//
// Retourne: -
//-------------------------------------------------------------------
void put(const unsigned tab[], size_t size);

//-------------------------------------------------------------------
// tableNonSigneeABool
//-------------------------------------------------------------------
// Description: Convertit un tableau non signé vers un tableau booléen
//              Toute valeur non nulle devient 1 et le autres 0
// Paramètres:
// Nom:         tableBooleen[]   tableau booleen vide utilisé comme resultat de
//                               fonction
// Nom:         tableNonSignee   tableau unsigned a traiter
// Nom:         tailleTableau    taille tu tableau non signé
//
// Retourne: -
//-------------------------------------------------------------------
void tableNonSigneeABool (bool tableBooleen[], const unsigned tableNonSignee[],
								  size_t tailleTableau);

#endif //MAIN_CPP_ANNEXE_H
