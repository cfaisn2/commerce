//
// Created by eric on 06/09/19.
//

#include <iostream>
#include "Produit.h"
Produit::Produit(){

}

Produit::Produit(float prixachat, float prixvente, const string &nom) : prixachat(prixachat), prixvente(prixvente),
                                                                        nom(nom),description("pas de description"),nbex(0) {


}

float Produit::getPrixachat() const {
    return prixachat;
}

float Produit::getPrixvente() const {
    return prixvente;
}

int Produit::getNbex() const {
    return nbex;
}

const string &Produit::getNom() const {
    return nom;
}

const string &Produit::getDescription() const {
    return description;
}

void Produit::editerDescription(const string &newdescription) {
    description=newdescription;

}

void Produit::augmenterQuantite(const int nbexemplmaires) {
nbex+=nbexemplmaires;
}

void Produit::diminuerQuantite(const int nbexemplaires) {
nbex-=nbexemplaires;
}

void Produit::afficherDescription() const {
cout<<description<<endl;
}


