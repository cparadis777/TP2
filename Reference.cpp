/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <string>
#include <iostream>
#include <sstream>

namespace biblio
{
    class Reference
            {
        private :
        std::string m_auteurs;
        std::string m_titre;
        int m_annee;
        std::string m_identifiant;
public:
        Reference(std::string p_auteurs, std::string p_titre,
        int p_annee, std::string p_identifiant);
        std::string reqReferenceFormate();
        void modifierAnnee(int p_nouvelleAnnee);};

    Reference::Reference(std::string p_auteurs, std::string p_titre,
            int p_annee, std::string p_identifiant)
            : m_auteurs(p_auteurs), m_titre(p_titre),
            m_annee(p_annee), m_identifiant(p_identifiant) {
    };

    std::string Reference::reqReferenceFormate() {
        std::ostringstream stream;
        stream << m_auteurs << ", " << m_titre << ", " << m_annee <<
                ", " << m_identifiant << ".";
        return stream.str();
    }

    void Reference::modifierAnnee(int p_nouvelleAnnee) {
        int nouvelleAnnee = p_nouvelleAnnee;
        if (nouvelleAnnee > 0) {
            m_annee = p_nouvelleAnnee;
            std::cout << "L'année a été modifiée avec succès!" << std::endl;
        } else {
            std::cout << "L'année entrée est invalide. "
                    "La référence n'a pas été modifiée" << std::endl;
        }
    }
}