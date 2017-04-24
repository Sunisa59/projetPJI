
#include <vector>
#include <iostream>
//#include <cmath>
#include <sdsl/bit_vectors.hpp>

using namespace std;
using namespace sdsl;

//std::map<int,bit_vectors> tabBitVector;


/**bool compare(int a, int b, bool c) {
	if (a<b && c)
		return true;
	return false;
}
*/

void constructByteVector(int taille,vector<bit_vector> tab,bit_vector b) {
	//for (int i=0;i<taille;i++) {
		 tab.push_back(b);
	//}

}

bool compare(int a, int b) {
	return a<b;
}

void miseajour(vector<bit_vector> &tab,vector<bool>& desc,int indiceNiveau,vector<int>& indiceBitVector) {

	tab[indiceNiveau][indiceBitVector[indiceNiveau]] =1;
	desc[indiceNiveau]=false;
	indiceBitVector[indiceNiveau]+=1;
	indiceNiveau+=1;
}


	

	
int main() {

	int sequence[18];
	sequence[0] = 5;
	sequence[1] = 5;
	sequence[2] = 4;
	sequence[3] = 2;
	sequence[4] = 2;
	sequence[5] = 4;
	sequence[6] = 5;
	sequence[7] = 4;
	sequence[8] = 5;
	sequence[9] = 3;
	sequence[10] = 3;
	sequence[11] = 1;
	sequence[12] = 4;
	sequence[13] = 3;
	sequence[14] = 4;
	sequence[15] = 6;
	sequence[16] = 2;
	sequence[17] = 4;

int taille = sizeof(sequence)/sizeof(int);


	vector<bit_vector> tab;
	vector<bool> desc;
	vector<int> prec;
	vector<int> current;
	vector<int> indiceBitVector;
	bit_vector b;
	int indiceNiveau=0;
	int nbVector = log2(taille);
	int nbVectorFinaux = log2(taille);
	bool premierNiveau = true;

	int test = ~1;
	cout<<"test egal a : "<<test<<endl;


	if (taille ==0) {
		cout<<"La sequence de chiffre est vide"<<endl;
	}

	if (taille ==1) {
		b = {1};
		cout<<b<<endl;
	}

	if (taille>1) {

		


		//cout << "taille prec ; " << desc.size() <<endl;
		b = bit_vector(taille, 0);


		//Création de tous les vector de bit initialiser a 0 et de taille egal a la taille de la sequence
		for (int i=0; i<nbVector;i++){
			tab.push_back(b);
			desc.push_back(true);
			indiceBitVector.push_back(0);
			prec.push_back(-1);
			current.push_back(-1);
			cout << tab[i] << endl;
			cout << desc[i] << endl;
			cout <<"sequence  = " << sequence[i] << endl;
		}



		cout <<"valeur des vector de bit avant" << endl;
		for (int i =0;i<nbVector;i++) 
			cout << tab[i] << endl;


		for (int i=1; i<taille;i++) {
			indiceNiveau=0;
			premierNiveau=true;
			prec[indiceNiveau]=sequence[i-1];
			current[indiceNiveau]=sequence[i];

			while(premierNiveau==true) {
			cout <<"step i ======="<<i << endl;
			cout <<"step 1 if" << endl;
				if(prec[indiceNiveau]!=-1 && current[indiceNiveau]!=-1) {
					cout <<"step 2 if" << endl;
					cout <<"Niveau Vector bit:" <<indiceNiveau<< endl;
					cout <<"nombre compare prec:" <<prec[indiceNiveau]<< endl;
					cout <<"nombre compare current:" <<current[indiceNiveau]<< endl;
					cout <<"en descente:" <<desc[indiceNiveau]<< endl;
					if(prec[indiceNiveau]<current[indiceNiveau]){
						cout <<"step 3 if" << endl;

						if (desc[indiceNiveau]==true){
							cout <<"step 4 if" << endl;

							//miseajour(tab,desc,indiceNiveau,indiceBitVector);
							
							tab[indiceNiveau][indiceBitVector[indiceNiveau]] =1;
							desc[indiceNiveau]=false;
							indiceBitVector[indiceNiveau]+=1;
							indiceNiveau+=1;


							if (current[indiceNiveau]==-1) {
								cout <<"step 5 if" << endl;
								current[indiceNiveau]=prec[indiceNiveau-1];
							}
							else {
								prec[indiceNiveau]=current[indiceNiveau];
								current[indiceNiveau]=prec[indiceNiveau-1];
							}

						}

						else{

							cout <<"step 4 else" << endl;
							indiceBitVector[indiceNiveau]+=1;
							premierNiveau=false;
						}
					}
					else{
						cout <<"step 3 else" << endl;
						indiceBitVector[indiceNiveau]+=1;
						prec[indiceNiveau]=current[indiceNiveau];
						premierNiveau=false;
						desc[indiceNiveau]=true;
					}
				}
				else {
					cout <<"step 2 else" << endl;
					cout <<"Niveau Vector bit:" <<indiceNiveau<< endl;
					cout <<"nombre compare prec:" <<prec[indiceNiveau]<< endl;
					cout <<"nombre compare current:" <<current[indiceNiveau]<< endl;

					premierNiveau=false;
				}

					cout <<"\n\n" << endl;
			}
		}

		//suppression de vector de bit en trop
		for (int i =0;i<nbVector;i++) {
			cout<<"indice bit vector : "<<indiceBitVector[i] <<endl;
			if(indiceBitVector[i]==0) {
				tab.pop_back();
				nbVectorFinaux-=1;
			}
		}

		//Pour le dernier bit
		for(int i=0; i<nbVectorFinaux;i++){
			if(desc[i]==true) {
				tab[i][indiceBitVector[i]] =1;
				if(i+1<=nbVectorFinaux){
					prec[i+1]=current[i+1];
					current[i+1]=prec[i];

					if(prec[i+1]<current[i+1]){
						indiceBitVector[i+1]+=1;
						if (desc[i+1]==true){
							tab[i+1][indiceBitVector[i+1]-1] =1;
							desc[i+1]=false;

						}
					}
					else{
							indiceBitVector[i+1]+=1;
							desc[i+1]=true;
						}
				}
			}
		}

		cout <<"valeur des vector de bit apres \n" << endl;

		//redimensionner les vecteur de bit et afficher leur valeurs
		for (int i =0;i<nbVectorFinaux;i++) {

			cout<<"indice bit vector de niveau "<< i <<endl;
			cout<<"indice bit vector : "<< indiceBitVector[i] <<endl;
			tab[i].resize(indiceBitVector[i] +1);
			cout << tab[i] <<"\n"<< endl;
		}

		int a=100;


	   
		

	}


}
