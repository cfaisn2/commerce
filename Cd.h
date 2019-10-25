//
// Created by eric on 19/09/19.
//

#ifndef CORRECTIONCOMMERCE_CD_H
#define CORRECTIONCOMMERCE_CD_H

#include <array>
#include <string>
#include "Produit.h"
using  namespace std;
class Cd: public Produit {

private:
    string auteur;
    string interprete;
    vector<string> pistes;
public:
    Cd(const float prixachat, const float prixvente, const string &nom, const string &auteur, const string &interprete,
       const vector<string> &pistes);

    void afficherDescription() const override;

};


#endif //CORRECTIONCOMMERCE_CD_H
