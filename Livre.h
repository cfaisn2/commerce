//
// Created by eric on 16/09/19.
//

#ifndef CORRECTIONCOMMERCE_LIVRE_H
#define CORRECTIONCOMMERCE_LIVRE_H

#include "Produit.h"


class Livre:public Produit {

private:
    string auteur;
    string editeur;


public:
Livre(const float prixachat,const float prixvente,const string &nom,const string &auteur,const string &editeur);

    const string &getAuteur() const;

    const string &getEditeur() const;

    void afficherDescription() const override ;

};


#endif //CORRECTIONCOMMERCE_LIVRE_H
