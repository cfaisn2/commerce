//
// Created by eric on 06/09/19.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include "Magasin.h"
#include "Livre.h"
#include "Cd.h"

Magasin::Magasin():solde(0) {

}


void Magasin::ajouterProduit(const string &nom, const float prixachat, const float prixvente)

    {

            produits.push_back(new Produit(prixachat,prixvente,nom));



}

void Magasin::ajouterLivre(const float prixachat, const float prixvente, const string &nom, const string &auteur,
                           const string &editeur) {



            produits.push_back(new Livre(prixachat,prixvente,nom,auteur,editeur));





}

void Magasin::ajouterCd(const float prixachat, const float prixvente, const string &nom, const string &auteur,
                        const string &interprete, const vector<string> &pistes) {


            produits.push_back(new Cd(prixachat,prixvente,nom,auteur,interprete,pistes));



}

void Magasin::acheterProduit(const int reference, const int nbexemplaires) {

    produits[reference]->augmenterQuantite(nbexemplaires);
    solde-=produits[reference]->getPrixachat();

}

void Magasin::vendreProduit(const int reference,const int nbexemplaires) {
    produits[reference]->diminuerQuantite(nbexemplaires);
    solde+=produits[reference]->getPrixachat();
}


float Magasin::getSolde() const {
    return solde;
}

void Magasin::bilan() {


    for(Produit* p:produits)
    {

            if(p==NULL)
                break;
            else
            cout<<p->getNom()<<" "<<p->getNbex()<<endl;




    }
}
void Magasin::interaction() {

    cout<<"1-opération Produit \n";
    cout<<"2-opération Livre \n";
    cout<<"3-opération CD \n";
    cout<<"4-Afficher un bilan\n";
    cout<<"5-Sortir"<<endl;
    cin>>saisiem;
    switch(saisiem)
    {

        case 1:

            this->submenu("produit");
            break;

        case 2:

            this->submenu("livre");
            break;
        case 3:

            this->submenu("cd");
            break;
        case 4:
            this->bilan();
            break;









    }
if(saisiem!=5)
interaction();
}

void Magasin::submenu(const string &type) {
    int saisie=0;


    cout<<"1-Vendre un "<<type<<"\n";
    cout<<"2-Acheter un "<<type<<"\n";
    cout<<"3-Afficher la description d'un "<<type<<"\n";
    cout<<"4-Ajouter un "<<type<<"\n";
    cout<<"5-Editer la description\n";
    cin>>saisie;
    switch(saisie)
    {
        case 1:
            vendreProduit(this->choixproduit(type),this->choixqte());
            break;

        case 2:
            acheterProduit(this->choixproduit(type),this->choixqte());
            break;

        case 3:
           produits[choixproduit(type)]->afficherDescription();
            break;

        case 4:
            if(type=="produit")
            {
                this->ajouterProduit(this->saisie("nom"),this->saisieprix("achat"),this->saisieprix("vente"));
            }else
            if(type=="livre")
            {
                this->ajouterLivre(this->saisieprix("achat"),this->saisieprix("vente"),this->saisie("nom"),this->saisie("editeur"),this->saisie("auteur"));
            }
            else{
                this->ajouterCd(this->saisieprix("achat"),this->saisieprix("vente"),this->saisie("nom"),this->saisie("auteur"),this->saisie("editeur"),this->saisielistetitre());
            }
            break;
        case 5:
            produits[choixproduit(type)]->editerDescription(this->saisie("nouvelle description"));
            break;



    }

    this->interaction();
}
int Magasin::choixproduit(const string &type) {
    int typed=0;
    vector<Produit*> results=searchEngine(choiceEngine(),saisie("recherche"));
    if(results[0]==NULL) {
        cout << "pas de résultats"<<endl;
        choixproduit(type);
    }
    afficherResults(results);
    cin>>typed;
    return getIndice(results[typed]);


}

int Magasin::choixqte() {
    int saisie=0;
    cout<<"Quelle quantité ?\n";
    cin>>saisie;
    return (int)saisie;
}


const string Magasin::saisie(const string &type) {
    string saisie="";
    cout<<"Veuillez saisir l'information pour "<<type<<"\n";
    cin.ignore();
    getline(cin,saisie);
    return saisie;



}

int Magasin::saisieprix(const string &type) {
    float prix=0;
    cout<<"Veuillez saisir prix "<<type<<"\n";
    cin>>prix;
    return (int)prix;



}

const vector<string> Magasin::saisielistetitre() {
    vector<string> listetitres;
    string saisie="";
    int i=0;
    while(saisie!="F")
    {
        cout<<"Veuillez saisir un titre ou (F) pour fin\n";
        cin>>saisie;
        listetitres.push_back(saisie);
    }

}

Magasin::~Magasin() {
    cout<<"destruct"<<endl;

    for(Produit *p:produits)
    {
        delete p;
        cout<<"destruction"<<endl;
    }

}

const vector<Produit*> Magasin::searchEngine(const int type,const string &saisie) const {
    vector<Produit*> results;


    for(Produit *p:produits)
    {

        if(type==1) {   int j=0;
            if (p->getNom() == saisie) {
                results.push_back(p);
                break;
            }
        }
        else
        {
            if (p->getNom().find(saisie) != std::string::npos) {
                results.push_back(p);

            }
        }
    }

    return results;
}

int Magasin::choiceEngine() {
    int saisie=0;
    cout<<"1- Recherche par nom"<<endl;
    cout<<"2- Recherche par mot "<<endl;
    cin>>saisie;
    return saisie;
}

void Magasin::afficherResults(vector<Produit*> results) const
{
    for(int i=0;i<results.size();i++)
    {
        if(results[i]==NULL)
        {
            break;
        }
        else
            cout<<i<<"- "<<results[i]->getNom()<<endl;
    }
}

int Magasin::getIndice(Produit *p)
{


    std::vector<Produit*>::iterator it=std::find_if(produits.begin(), produits.end(), [p](Produit* pr)
    { if (pr->getNom() == p->getNom())

        return pr;

    });


return distance(produits.begin(), it);
}
















