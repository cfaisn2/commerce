//
// Created by eric on 06/09/19.
//

#ifndef CORRECTIONCOMMERCE_PRODUIT_H
#define CORRECTIONCOMMERCE_PRODUIT_H

#include <string>

using namespace std;
class Produit {
private:

    float prixachat;
    float prixvente;
    int nbex;
    string nom;
    string description;
public:
    Produit();

    Produit(const float prixachat,const float prixvente, const string &nom);

    void editerDescription(const string &newdescription);

    void augmenterQuantite(const int nbexemplaires);

    void diminuerQuantite(const int nbexemplaires);

    virtual void afficherDescription() const;

    float getPrixachat() const;

    float getPrixvente() const;

    int getNbex() const;

    const string &getNom() const;

    const string &getDescription() const;


};


#endif //CORRECTIONCOMMERCE_PRODUIT_H
