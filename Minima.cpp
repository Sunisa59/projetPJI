#include <vector>
#include <iostream>
#include <sdsl/bit_vectors.hpp>
#include <functional>

//#include "Minima.h"

using namespace std;
using namespace sdsl;


template<class bv,class rankv,class selectv>

class Minima {


	private:
		
		size_t size;
		std::vector<bv> bitVectors;
		std::vector<std::vector<int>> sampleLevel;//stocker les minimum locaux de nieau 2ou...
		bool sparce;
		string mode;
		int taille;
		int nbBitVector;
		int sample; 

	public :

	Minima(int t,int seq[],string mod) {
		taille=t;
		cout<<"taille : "<<taille;
		//sequence[t];
		sparce=true;
		mode=mod;
		sample=3;

		//copieSequence(seq,sequence,taille);
		auto sequence = std::ref(seq);

		//taille = sizeof(sequence)/sizeof(int);

	vector<bit_vector> tab;
	vector<bool> desc;
	vector<int> prec;
	vector<int> current;
	vector<int> indiceBitVector;
	vector<int> precIndiceBitVector;
	vector<int> sampleList;
	bit_vector b;
	int indiceNiveau=0;
	int niveauMax=0;
	int nbVector = log2(taille);
	int nbVectorFinaux = log2(taille);
	bool premierNiveau = true;
	int startSample=0;
	int cptSample=16;

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
			sampleLevel.push_back(sampleList);
			tab.push_back(b);
			desc.push_back(true);
			indiceBitVector.push_back(0);
			precIndiceBitVector.push_back(0);
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

			cptSample--;

			//pour sampleLeve
			if (cptSample == -1){
				cout<<"taille de tab  bvt: "<<tab.size(),
				saveNumber(sequence,sampleLevel,tab);
				startSample+=sample;
				cptSample=sample;

			}

			while(premierNiveau==true) {

			//Pour mettre a jour le niveau max
			if (niveauMax<indiceNiveau)
				niveauMax=indiceNiveau;

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

						if (desc[indiceNiveau]==true ){
							cout <<"step 4 if" << endl;

							//miseajour(tab,desc,indiceNiveau,indiceBitVector);
							
							tab[indiceNiveau][indiceBitVector[indiceNiveau]] =1;
							desc[indiceNiveau]=false;
							
							if (sparce==false){
								if(indiceNiveau==0){
									precIndiceBitVector[indiceNiveau]=indiceBitVector[indiceNiveau];
									indiceBitVector[indiceNiveau]+=1;
								}
								else{
									precIndiceBitVector[indiceNiveau]=indiceBitVector[indiceNiveau];
									indiceBitVector[indiceNiveau]=precIndiceBitVector[indiceNiveau-1];
								}

								
							}
							else{
								indiceBitVector[indiceNiveau]+=1;
							}
							indiceNiveau+=1;


							if (current[indiceNiveau]==-1) {
								cout <<"step 5 if" << endl;
								current[indiceNiveau]=prec[indiceNiveau-1];
								if (sparce == false)
									indiceBitVector[indiceNiveau]=precIndiceBitVector[indiceNiveau-1];
							}

									else {
										prec[indiceNiveau]=current[indiceNiveau];
										current[indiceNiveau]=prec[indiceNiveau-1];
										//indiceBitVector[indiceNiveau]+=1;
									}

						}

						else{

							cout <<"step 4 else" << endl;
								if(indiceNiveau==0)
									indiceBitVector[indiceNiveau]+=1;
							premierNiveau=false;
						}
					}
					else{
						cout <<"step 3 else" << endl;
							if (sparce==false){
								if(indiceNiveau==0){
									precIndiceBitVector[indiceNiveau]=indiceBitVector[indiceNiveau];
									indiceBitVector[indiceNiveau]+=1;
								}
								else{
									precIndiceBitVector[indiceNiveau]=indiceBitVector[indiceNiveau];
									indiceBitVector[indiceNiveau]=precIndiceBitVector[indiceNiveau-1];
								}

								
							}
							else{
								indiceBitVector[indiceNiveau]+=1;
							}


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
		if (sparce==true){
			for (int i =0;i<nbVectorFinaux;i++) {

				cout<<"indice bit vector de niveau "<< i <<endl;
				cout<<"indice bit vector : "<< indiceBitVector[i] <<endl;
				tab[i].resize(indiceBitVector[i] +1);
				cout << tab[i] <<"\n"<< endl;
			}
		}
		
	}

		nbBitVector=nbVectorFinaux;
		cout<<"nb vector f : "<<nbBitVector<<"\n";

	copyBitVector(tab,nbVectorFinaux);
	
	for (int i =0;i<nbBitVector;i++)
		cout<<bitVectors[i]<<"\n";

	for (int i=0; i<sampleLevel.size();i++)
	cout<<sampleLevel[i];
	
	

	}

	void saveNumber(int seq[],std::vector<std::vector<int>> &list,std::vector<bit_vector> &bvt){
		for (int i=0;i<bvt.size();i++){
			for(int y=0;y<bvt[i].size();y++){
				if(bvt[i][y]==1){
					if(i==0)
						list[i].push_back(seq[y]);
					else
						list[i].push_back(list[i-1][y]);
				}

				
			}
			
		}
	}





	int getTaille() {
		return taille;
	}

	void setTaille(int i) {
		taille=i;
	}

	int getNbBitVector(){
		return nbBitVector;
	}

	void setNbBitVector(int i){
		nbBitVector=i;
	}

	vector<bv> getBitVectors() {
		return bitVectors;
	}

	std::vector<std::vector<int>>  getSampleLevel(){
		return sampleLevel;
	}


/**
	int* getSequence(){
		return sequence;
	}
*/
	string getSparce(){
		return sparce;
	}

	void copieSequence(int seq[],int seq2[],int taille){
		seq2[taille];
		for (int i=0;i<taille;i++) {
			seq2[i]=seq[i];
		}
	}

	void copyBitVector(std::vector<bit_vector> &bit,int nb){
		if (mode=="r" || mode =="s") {
			for (int i=0;i<nb;i++) {
				bitVectors.push_back(bv (bit[i]));
			}
			
		}

		if (mode=="b") {
			for (int i=0;i<nb;i++) {
				bitVectors.push_back(bit[i]);
			}
		}

	}

	void rank(bv b){
			rankv(b); 
	}
};


int main(int argc, char const *argv[])
{

	int sequencee[18];
	sequencee[0] = 5;
	sequencee[1] = 5;
	sequencee[2] = 4;
	sequencee[3] = 2;
	sequencee[4] = 2;
	sequencee[5] = 4;
	sequencee[6] = 5;
	sequencee[7] = 4;
	sequencee[8] = 5;
	sequencee[9] = 3;
	sequencee[10] = 3;
	sequencee[11] = 1;
	sequencee[12] = 4;
	sequencee[13] = 3;
	sequencee[14] = 4;
	sequencee[15] = 6;
	sequencee[16] = 2;
	sequencee[17] = 4;
	int taille = sizeof(sequencee)/sizeof(int);

	string option;

		bool optionValide=false;
		string opt;

		while( !optionValide ) {
			cout<<"Entrer une option 'r' pour rrr_vector 's' pour sd_vector et 'b' pour bit_vector\n";
			cin>>option;
			if (option =="r"){
				optionValide=true;
				Minima<rrr_vector<>,int,int> m(taille,sequencee,"r");
				
					
			}
			if (option =="s"){
				optionValide=true;
				Minima<sd_vector<>,int,int> m(taille,sequencee,"s");
			}
			if (option =="b"){
				optionValide=true;
				Minima<bit_vector,int,int> m(taille,sequencee,"b");

			}

			if(!optionValide)
				cout<<"option incorect \n";


		}







/**
		string option;



		bool optionValide=false;

		while( !optionValide ) {
			cout<<"Entrer une option 'r' pour rrr_vector 's' pour sd_vector et 'b' pour bit_vector\n";
			cin>>option;
			if (option =="r")
				optionValide=true;
			if (option =="s")
				optionValide=true;
			if (option =="b")
				optionValide=true;

			if(!optionValide)
				cout<<"option incorect \n";

		}

		cout<<"option choisit : "<<option;
		//enregistrement des données
		Minima m;

		m.setTaille(taille);
		m.copieSequence(sequence,m.getSequence(),taille);
		m.setNbBitVector(nbVectorFinaux);

		cout<<m.getTaille()<<"\n";

		for (int i=0;i<taille;i++)
			cout<<m.getSequence()[i];


		cout<<"\n taille bit vector : "<<size_in_mega_bytes(tab[0])<<"\n";

		sd_vector<> b(tab[0]) ;

		cout<<"\n taille bit vector : "<<size_in_mega_bytes(b)<<" premier bit = " <<b[4]<<"\n";

		rrr_vector<> r(tab[0]) ;

		cout<<"\n taille bit vector : "<<size_in_mega_bytes(r)<<"\n";
	   
	*/

	/**

	string option;

		bool optionValide=false;
		string opt;

		while( !optionValide ) {
			cout<<"Entrer une option 'r' pour rrr_vector 's' pour sd_vector et 'b' pour bit_vector\n";
			cin>>option;
			if (option =="r"){
				optionValide=true;
				Minima<rrr_vector<>,int,int> m(taille,nbVectorFinaux,sequence,"r");
			}
			if (option =="s"){
				optionValide=true;
				Minima<sd_vector<>,int,int> m(taille,nbVectorFinaux,sequence,"s");
			}
			if (option =="b"){
				optionValide=true;
				Minima<bit_vector,int,int> m(taille,nbVectorFinaux,sequence,"b");
			}

			if(!optionValide)
				cout<<"option incorect \n";


		}


			

		cout<<"option choisit : "<<option<<"\n";
		//enregistrement des données

	Minima<rrr_vector<>,int,int> m(taille,nbVectorFinaux,sequence,"r");
	m.copyBitVector(tab,nbVectorFinaux);
	cout<<"la taille est : "<<m.getTaille()<<"\n";
	cout<<"la sequence : ";
	for (int i=0;i<m.getTaille();i++){
			cout<<m.getSequence()[i];
			
	}
	cout<<"\n";
	rrr_vector<> rrrb(tab[0]);
	cout<<"taille du vecteur de bit  : " <<size_in_bytes(m.getBitVectors());

	cout<<"\n";
*/

/**
	for (int i=0 ; i<nbVectorFinaux;i++)
			cout<<m.getBitVectors()[i]<<"\n";

		cout<<"\n mode = "<<m.getSparce();
		cout<<"True = "<<true;

		bool test = (m.getSparce()=="v");
		cout<<"sparce vrai ? : "<<test;
*/

	


	




	return 0;
}

