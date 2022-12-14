/************************************************************************/
/* Auteur : Olivier Fabre                        							*/
/* TP : Tri par tas					                                    */
/* Date dernière maj : 2022					                    */
/************************************************************************/

/****************************************/
/* Classe Tas				*/
/****************************************/
class tas
{
	friend class evaluate;
	int *T;	 // tableau
	int max; // la plus grande clé
	int n;	 //
public:
	tas(int max = 100);
	tas(char *filename);
	void affiche();
	void echange(int &a, int &b);
	void insertion(int x);
	void reorganiser(int j);
	int suppression();
	void tri();
};
