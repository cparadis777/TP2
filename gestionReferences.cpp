

#include <iostream>
#include <string>
#include "validationFormat.h"
#include "Reference.h"
#include "gestionReferences.h"


void
entreeUtilisateur (void)
{
  std::string titre;
  std::string auteur;
  int annee;
  std::string identifiant;

  while (util::validerFormatNom (titre) != true)
    {
      std::cout << "Veuillez entrer le titre de l'ouvrage" << std::endl;
      std::cin >> titre;



    }
}
