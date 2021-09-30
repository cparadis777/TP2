/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: etudiant
 *
 * Created on 30 septembre 2021, 15:54
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include "Reference.h"


using namespace std;
using namespace biblio;

/*
 *
 */
int main(int argc, char** argv) {
    string auteur = "Cedric";
    string titre = "Titre du livre";
    int annee = 2005;
    string identifiant = "ISBN 0000-0000-000-0";
    Reference entree(auteur, titre, annee, identifiant);
    //entree.modifierAnnee(2006);
    cout << entree.reqReferenceFormate() << endl;
    return 0;
}

