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
tas::tas(char *filename)
{
	ifstream file(filename);
	int nb, tmp;

	file >> nb;

	T = new int[nb];
	n = 0;
	for (int i = 0; i < nb; i++)
	{
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
	for (int i = 0; i < n; i++)
		cout << " " << T[i];
	cout << endl;
}

/****************************************/
/* Objectif : Insertion d'un entier x
/* Complexité : 0(log(n))
/****************************************/
void tas::insertion(int x)
{
	// Algorithme insertion dans un tas (diapo 136 du cours)
	// Attention x >= 0
	// Tableau objet
	T[n] = x;
	int indice = n;
	while (indice >= 0 && T[indice] < T[((indice - 1) / 2)])
	{
		// on swape les valeurs
		echange(T[indice], T[(indice - 1) / 2]);
		indice = ((indice - 1) / 2);
	}
	// On incrémente
	n++;
}

/****************************************/
/* Objectif : Reorganiser en un tas à partir de l'élément T[j]
/* Complexité : 0(log(n))
/****************************************/
void tas::reorganiser(int j)
{
	// Algorithme réorganisation du tas (diapo 148 du cours)
	int indice = j;
	int m;
	while (indice <= (n / 2) - 1)
	{
		if (T[(2 * indice) + 1] < T[(2 * indice) + 2])
			m = (2 * indice) + 1;
		else
			m = (2 * indice) + 2;
		if (T[indice] > T[m])
		{
			echange(T[indice], T[m]);
			indice = m;
		}
		else
			indice = n;
	}
}

/****************************************/
/* Objectif : renvoie de l'élément de la valeur minimale et réorganisation du tableau
/* Complexité : 0(log(n))
/****************************************/
int tas::suppression()
{
	// Algorithme suppression basé sur le réorganisation (diapo 149 du cours)
	// Attention indice tableau démarre à 0
	int valeurMinimale = T[0];
	// Propriété Objet à décrémenter
	n--;
	T[0] = T[n];
	//--n;
	// reorganiser(n);
	reorganiser(0);
	return (valeurMinimale);
}

/****************************************/
/* Objectif : Tri du tableau T
/* Complexité : 0(nlog(n))
/****************************************/
void tas::tri()
{
	// Algorithme suppression basé sur le réorganisation (diapo 150 du cours)
	int valeurTemp = n;

	while (n > 1)
	{
		int valeurMinimale = suppression();
		T[n] = valeurMinimale;
	}
	n = valeurTemp;
}
