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
		vector<rankv> rankVector;
		vector<selectv> selectVector;

	public :

	Minima(int t,int seq[],string mod,bool sparce,int samples) {
		taille=t;
		cout<<"taille : "<<taille;
		//sequence[t];
		sparce=sparce;
		mode=mod;
		sample=samples;

		//copieSequence(seq,sequence,taille);
		auto sequence = std::ref(seq);

		//taille = sizeof(sequence)/sizeof(int);

	vector<bit_vector> tab;
	vector<bool> desc;
	vector<bool> lastBit;
	vector<int> prec;
	vector<int> current;
	vector<int> indiceBitVector;
	//vector<int> precIndiceBitVector;
	vector<int> sampleList;
	bit_vector b;
	int indiceNiveau=0;
	int niveauMax=0;
	int nbVector = log2(taille)+1;
	int nbVectorFinaux = log2(taille)+1;
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
			//sampleLevel.push_back(sampleList);
			tab.push_back(b);
			desc.push_back(true);
			indiceBitVector.push_back(0);
			lastBit.push_back(true);
			//precIndiceBitVector.push_back(0);
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
									indiceBitVector[indiceNiveau]+=1;
								}
								else{
									indiceBitVector[indiceNiveau]=indiceBitVector[0]-1;
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
									indiceBitVector[indiceNiveau]=indiceBitVector[0]-1;

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
									indiceBitVector[indiceNiveau]+=1;
								}
								else{
									indiceBitVector[indiceNiveau]=indiceBitVector[indiceNiveau-1]-1;
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
		/**
		for (int i =0;i<nbVector;i++) {
			cout<<"indice bit vector : "<<indiceBitVector[i] <<endl;
			if(indiceBitVector[i]==0) {
				tab.pop_back();
				nbVectorFinaux-=1;
			}
		}
		*/

		//Pour le dernier bit
		for(int i=0; i<nbVectorFinaux;i++){
			cout<<"nb bit vec :"<<nbVectorFinaux <<"\n";
			/**
			if (i!=0){
				rank_support_v<1> b_rank(&tab[i-1]);
				cout<<"rank niveau"<<i-1<<	b_rank(tab[i-1].size());
			}
			*/
			if(i==0){

				if(desc[i]==true) {
					cout<<"valeur de niveau bit vector :"<<i <<"\n";
					cout<<"valeur de lindice bit vector :"<<indiceBitVector[i]<<"\n";
					cout<<"niveau lastbit = true :"<<i <<"\n";
					cout<<"prec  :"<<prec[i] <<"\n";
					cout<<"current  :"<<current[i] <<"\n";
					tab[i][indiceBitVector[i]] =1;
					prec[i+1]=current[i+1];
					current[i+1]=current[i];
					lastBit[i+1]=false;
				}
			}
			else {
				rank_support_v<1> b_rank(&tab[i-1]);

				if(b_rank(tab[i-1].size())>1){
					if (lastBit[i]==false){
						cout<<"lastbit de false  :"<<i <<"\n";
						if (sparce == true)
							indiceBitVector[i]+=1;
						if(prec[i]<current[i]){
							cout<<"niveau  :"<<i <<"\n";
							cout<<"prec  :"<<prec[i] <<"\n";
							cout<<"current  :"<<current[i] <<"\n";
							if(desc[i]==true){
								tab[i][indiceBitVector[i]-1] =1;
								prec[i+1]=current[i+1];
								current[i+1]=prec[i];
								lastBit[i+1]=false;
								desc[i]=false;
							}
							
						}
						else
							desc[i]=true;

					}

					if(desc[i]==true) {
						cout<<"valeur de niveau bit vector :"<<i <<"\n";
						cout<<"valeur de lindice bit vector :"<<indiceBitVector[i]<<"\n";
						cout<<"niveau lastbit = true :"<<i <<"\n";
						cout<<"prec  :"<<prec[i] <<"\n";
						cout<<"current  :"<<current[i] <<"\n";
						tab[i][indiceBitVector[i]] =1;
						prec[i+1]=current[i+1];
						current[i+1]=current[i];
						lastBit[i+1]=false;
					}
				}
			}
		}

			for (int i =0;i<nbVector;i++) {
			cout<<"indice bit vector : "<<indiceBitVector[i] <<endl;
			if(indiceBitVector[i]==0) {
				tab.pop_back();
				nbVectorFinaux-=1;
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
	


		saveNumber(sequence,sampleLevel,tab);
		saveRankVector(bitVectors,rankVector);
		saveSelectVector(bitVectors,selectVector);


	}

	/**sauvegarder les sequence de nombre en fonction de sample 
	int seq[] : la sequence de chiffre initial
	vector<std::vector<int>> &list : la liste de sequence de chiffre enregistrer
	vector<bit_vector> &bvt : les vecteur de bit
	*/
	void saveNumber(int seq[],std::vector<std::vector<int>> &list,std::vector<bit_vector> &bvt){
		
		int cpt=sample;
		vector<int> listbis2,listbis1;
		

		for(int z=0;z<bvt[0].size();z++)
			listbis1.push_back(seq[z]);
		list.push_back(listbis1);


		for (int i=0;i<bvt.size();i++){
			vector<int> listbis;
			
			for(int y=0;y<bvt[i].size();y++){
				if(bvt[i][y]==1){	
					if(i==0)
						listbis.push_back(seq[y]);
					else
						listbis.push_back(listbis2[y]);

				}
			}
			listbis2=listbis;
			cpt--;
		//	cout<<"cpt egal a :"<<cpt;
			if(cpt ==0){
				list.push_back(listbis);
				cpt=sample;
			}

			
			
		}
	}

	void saveRankVector(std::vector<bv> &bvt,vector<rankv> &rankVec){
		for(int i=0;i<bvt.size();i++){
		
				rankv rank(&bvt[i]);
				rankVec.push_back(rank);
			
		
		}
	}

	vector<rankv> getRankVector(){
		return rankVector;
	}

	int rank_test(bv v,int i){
			//rank_support_v<1> r(&b);
			//cout<<r(i);
			return v(i);
	}


	void saveSelectVector(std::vector<bv> &bvt,vector<selectv> &selectVec) {
		for(int i=0;i<bvt.size();i++){
	
				selectv b_sel(&bvt[i]);
				selectVec.push_back(b_sel);
		}

	}


	vector<selectv> getSelectVector(){
		return selectVector;
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

	vector<vector<int>>  getSampleLevel(){
		return sampleLevel;
	}

	std::vector<int> getSampleLevel1(int i){
		return sampleLevel[i];
	}


		int getMinima1(vector<vector<int>> seq,int deb,int fin,int k,vector<selectv> selectVtr,vector<rankv> rankVtr) {

		
			int kbis=k;

		//si on a pas la sequence de sample level
		if (kbis%sample!=0 && sample!=1 ){

			cout<<"sample if\n";
			int min1,min2;
			int iddeb,idfin;
			int debbis=deb;
			int finbis=fin;
			while (kbis%sample!=0){
				kbis--;
				iddeb=selectVtr[kbis](debbis+1);
				idfin=selectVtr[kbis](finbis+1);
				debbis=iddeb;
				finbis=idfin;
			
				if (kbis%sample==0){
					min1= seq[kbis/sample][iddeb];
					min2= seq[kbis/sample][idfin];

				}
			}
			if (rankVtr[k](deb+1)>=rankVtr[k](max(fin,0)) ){

				return min(min1,min2);
			}
			else{
					return min(min(min1,min2),getMinima1(seq,rankVtr[k](deb+1),(rankVtr[k](fin)-1),k+1,selectVtr,rankVtr));
						
				}
		
		}
		//sinon
		else{

			
	
				cout<<"sample else\n";

			if (rankVtr[k](deb+1)>=rankVtr[k](max(fin,0)) ){
				cout<<"valeure de k if :"<<k<<"\n";
				cout<<"valeur rank deb"<<rankVtr[k](deb+1)<<"\n";
				cout<<"valeur rank fin"<<(rankVtr[k](fin)-1)<<"\n";
				return min(seq[k/sample][deb],seq[k/sample][fin]);
			}
			else{
				cout<<"valeure de k else :"<<k<<"\n";
					cout<<"valeur rank deb"<<rankVector[k](deb+1)<<"\n";
					cout<<"valeur rank fin"<<(rankVector[k](fin)-1)<<"\n";
			return min(min(seq[k/sample][deb],seq[k/sample][fin]),getMinima1(seq,rankVtr[k](deb+1),(rankVtr[k](fin)-1),k+1,selectVtr,rankVtr));
			}
		
		}


	}

	int testfunction(vector<vector<int>> seq,int deb){
		//if (deb==0)
			return seq[0][deb];

		//return testfunction(seq,deb-1);
	}


	string getSparce(){
		return sparce;
	}

	void printBitVector(){
		for (int i =0;bitVectors.size();i++)
					cout<<bitVectors[i]<<"\n";
	}

	void printSampleLevel(){

				for(int i=0;i<sampleLevel.size();i++)
					cout<<sampleLevel[i]<<"\n";
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





};



