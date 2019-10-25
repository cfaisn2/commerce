//
// Created by eric on 19/09/19.
//

#include <iostream>
#include <vector>
#include "Cd.h"

Cd::Cd(const float prixachat, const float prixvente, const string &nom, const string &auteur, const string &interprete,
       const vector<string> &pistes) : Produit(prixachat, prixvente, nom), auteur(auteur), interprete(interprete),
                                           pistes(pistes) {}

void Cd::afficherDescription() const {
    Produit::afficherDescription(); //Appel à la méthode affidescription de la super classe
    cout<<"auteur:"<<auteur<<endl;
    cout<<"Interprete:"<<interprete<<endl;
    for(string s:pistes)
    {
        if(s.empty())
        {
            break;
        }
        else
        cout<<s<<endl;
    }
}
