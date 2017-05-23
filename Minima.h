//#ifndef DEF_MINIMA
//#define DEF_MINIMA
#include <string>
#include <vector>

#include <iostream>
#include <sdsl/bit_vectors.hpp>
#include <functional>

using namespace std;
using namespace sdsl;


template<class bv,class rankv,class selectv>

class Minima {


	private:
		
		size_t size;
		std::vector<bv> bitVectors;
		std::vector<std::vector<int>> sampleLevel;
		bool sparce;
		string mode;
		int taille;
		int nbBitVector;
		int sample; 

		public :

		Minima(int t,int seq[],string mod);

		int getTaille();

		void setTaille(int t);

		int getNbBitVector();

		void setNbBitVector(int i);


		void initt(int &i);

		size_t getSize();

		int* getSequence();

		void copieSequence(int seq[],int seq2[],int taille);

		void printt();


		vector<bv> getBitVectors();

		std::vector<std::vector<int>>  getSampleLevel();

	string getSparce();

	void copyBitVector(std::vector<bit_vector> &bit,int nb);



;

