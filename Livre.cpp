//
// Created by eric on 16/09/19.
//

#include <iostream>
#include "Livre.h"

const string &Livre::getAuteur() const {
    return auteur;
}

const string &Livre::getEditeur() const {
    return editeur;
}

Livre::Livre(const float prixachat,const float prixvente,const string &nom,const string &auteur,const string &editeur)
:auteur(auteur),editeur(editeur),Produit(prixachat,prixvente,nom) {

}

void Livre::afficherDescription() const {
    Produit::afficherDescription();
    cout<<" "<<auteur<<" "<<editeur<<endl;
}
