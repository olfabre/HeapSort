/************************************************************************/
/* Auteur : S. Gueye                        							*/
/* TP : Tri par tas					                                    */
/* Date dernière maj : 08/12/2019					                    */
/************************************************************************/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

#include "tri.h"

int main(int argc,char** argv)
{
	if(argc < 2)
		cout << "Nombre d'arguments insuffisants" << endl;
	else{
		tas heap(argv[1]);
		heap.affiche();
		heap.tri();
		heap.affiche();
	}

	return(1);
}
/*



*/