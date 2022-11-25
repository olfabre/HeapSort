/************************************************************************/
/* Auteur : S. Gueye                        							*/
/* TP : Tri par tas					                                    */
/* Date dernière maj : 08/12/2019					                    */
/************************************************************************/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "tri.h"

using namespace std;


/****************************************/
/* Objectif : Echange
/* Complexité : 0(1)
/****************************************/
tas::tas(int max)
{
	this->max = max;
	T = new int[max];	
	n = 0;
}

/****************************************/
/* Objectif : Constructeur
/* Complexité : 0(n)
/****************************************/
tas::tas(char* filename){
	ifstream file(filename);
	int nb,tmp;
	
	file >> nb;

	T = new int[nb];	
	n = 0;
	for(int i = 0; i < nb ; i++){
		file >> tmp;
		
		insertion(tmp);
		
	}
	file.close();

}


/****************************************/
/* Objectif : Echange
/* Complexité : 0(1)
/****************************************/
void tas::echange(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}


/****************************************/
/* Objectif : Affichage
/* Complexité : 0(n)
/****************************************/
void tas::affiche()
{
	cout << "T =";
	for(int i = 0; i < n; i++)
		cout << " " <<  T[i];
	cout << endl;
}

/****************************************/
/* Objectif : Insertion d'un entier x
/* Complexité : 0(log(n))
/****************************************/
void tas::insertion(int x)
{
  int indiceAjout = n;
  int indicePere = ((indiceAjout - 1 ) / 2);

 // 
  if (indiceAjout < max){

if (indicePere < indicePere)
		// on trouve 
		T[indice] = x;
		if ()

		++n;
	// On affecte la clé dans le tableau
	//T[indice] = x;
  }else{
	cout << "Message d'erreur: taille maximale du tableau atteinte";
  }




   
		
   



  
}

/****************************************/
/* Objectif : Reorganiser en un tas à partir de l'élément T[j]
/* Complexité : 0(log(n))
/****************************************/
void tas::reorganiser(int j)
{
	// !!! A FAIRE !!! //
}

/****************************************/
/* Objectif : renvoie de l'élément de la valeur minimale et réorganisation du tableau
/* Complexité : 0(log(n))
/****************************************/
int tas::suppression()
{
    // !!! A FAIRE !!! //
    return(0);
}

/****************************************/
/* Objectif : Tri du tableau T
/* Complexité : 0(nlog(n))
/****************************************/
void tas::tri()
{
    // !!! A FAIRE !!! //
}

