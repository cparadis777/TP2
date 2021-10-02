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

#include <iostream>
#include <string>
#include "validationFormat.h"
#include "Reference.h"

using namespace util;
using namespace biblio;
using namespace std;


void
entreeUtilisateur (void)
{
  string titre;
  string auteur;
  int annee;
  string identifiant;
  bool auteurValide = false;
  bool anneeValide = false;
  bool identifiantValide = false;

  cout << "Veuillez entrer le titre de l'ouvrage" << endl;
  getline (cin, titre);

  do
    {
      cout << "Veuillez entrer le nom de l'auteur ou les noms des auteurs de l'ouvrage:" << endl;
      getline (cin, auteur);
      auteurValide = util::validerFormatNom (auteur);
      if (auteurValide == 0)
        {
          cout << "Le nom de l'auteur ou les noms d'auteurs entrés sont invalides." << endl;
        }
    }
  while (auteurValide != 1);

  do
    {
      cout << "Veuillez entrer l'année de publication de l'ouvrage:" << endl;

      cin >> annee;

      if (!cin)
        {
          cout << "Veuillez entrer un nombre entier." << endl;
          cin.clear ();
        }
      else
        {
          if (annee > 0)
            {
              anneeValide = true;
            }
          else
            {
              cout << "L'annee de publication est invalide." << endl;
            }
        }
      cin.ignore (10000, '\n');
    }
  while (anneeValide != 1);

  do
    {
      cout << "Veuillez entrer le code ISSN ou ISBN de l'ouvrage:" << endl;

      getline (cin, identifiant);
      string typeIdentifiant = identifiant.substr (0, 4);

      if (typeIdentifiant == "ISBN")
        {
          if (util::validerCodeIsbn (identifiant))
            {
              identifiantValide = true;
            }
          else
            {
              cout << "Le code ISBN entré n'est pas valide." << endl;
            }
        }
      else if (typeIdentifiant == "ISSN")
        {
          if (util::validerCodeIssn (identifiant))
            {
              identifiantValide = true;
            }
          else
            {
              cout << "Le code ISSN entré n'est pas valide." << endl;
            }
        }
      else
        {
          cout << "L'identifiant entré n'est ni un code ISBN, ni un code ISSN." << endl;
        }
    }
  while (identifiantValide != 1);

  biblio::Reference reference (titre, auteur, annee, identifiant);
  cout << reference.reqReferenceFormate () << endl;
  std::string modificationAnnee;
  cout << "L'année de la référence est: " << reference.reqAnnee () << ". Désirez vous la modifier? O/N" << endl;
  cin >> modificationAnnee;
  if (modificationAnnee == "O")
    {
      anneeValide = false;
      do
        {
          cout << "Veuillez entrer l'année de publication de l'ouvrage:" << endl;

          cin >> annee;

          if (!cin)
            {
              cout << "Veuillez entrer un nombre entier." << endl;
              cin.clear ();
            }
          else
            {
              if (annee > 0)
                {
                  anneeValide = true;
                }
              else
                {
                  cout << "L'annee de publication est invalide." << endl;
                }
            }
          cin.ignore (10000, '\n');
        }
      while (anneeValide != 1);
      reference.modifierAnnee (annee);
      cout << reference.reqReferenceFormate () << endl;
    }
}


int
main (int argc, char** argv)
{
  entreeUtilisateur ();
  return 0;
}

