//
// Created by eric on 06/09/19.
//

#ifndef CORRECTIONCOMMERCE_MAGASIN_H
#define CORRECTIONCOMMERCE_MAGASIN_H

#include <array>
#include "Produit.h"
#include <time.h> //for delay
#include <zconf.h>
#include <vector>

using namespace std;
class Magasin {
private:


    float solde;

    int saisiem;

public:
    vector<Produit*> produits;
    Magasin();
    void ajouterProduit(const string &nom,const float prixachat,const float prixvente);
    void acheterProduit(const int reference,const int nbexemplaires);
    void vendreProduit(const int reference,const int nbexemplaires);
    void ajouterLivre(const float prixachat,const float prixvente,const string &nom,const string &auteur,const string &editeur);
    void ajouterCd(const float prixachat, const float prixvente, const string &nom, const string &auteur, const string &interprete,
                   const vector<string> &pistes);

    virtual ~Magasin();


    void bilan();

    float getSolde() const;

    void interaction();

    void submenu(const string &type);

    const string saisie(const string &type);

    int saisieprix(const string &type);

    const vector<string> saisielistetitre();

    int choixproduit(const string &type);

    int choixqte();

   const vector<Produit*> searchEngine(const int type, const string &saisie) const;

    int choiceEngine();


    void afficherResults(vector <Produit*> results) const;

    int getIndice(Produit *p);
};






#endif //CORRECTIONCOMMERCE_MAGASIN_H
