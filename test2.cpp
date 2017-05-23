#include "Minima.hpp"

int main(int argc, char const *argv[])
{

	int sequenceee[18];
	sequenceee[0] = 6;
	sequenceee[1] = 9;
	sequenceee[2] = 10;
	sequenceee[3] = 9;
	sequenceee[4] = 11;
	sequenceee[5] = 8;
	sequenceee[6] = 7;
	sequenceee[7] = 12;
	sequenceee[8] = 8;
	sequenceee[9] = 13;
	sequenceee[10] = 3;
	sequenceee[11] = 8;
	sequenceee[12] = 7;

	int taille = sizeof(sequenceee)/sizeof(int);

	string option;

		bool optionValide=false;
		string opt;

		while( !optionValide ) {
			cout<<"Entrer une option 'r' pour rrr_vector 's' pour sd_vector et 'b' pour bit_vector\n";
			cin>>option;
			if (option =="r"){
				optionValide=true;
				Minima<rrr_vector<>,int,int> m(13,sequenceee,"r",true,1);
				
					
			}
			if (option =="s"){
				optionValide=true;
				Minima<sd_vector<>,int,int> m(taille,sequenceee,"s",true,2);
			}
			if (option =="b"){
				optionValide=true;
				Minima<bit_vector,int,int> m(13,sequenceee,"b",true,2);

				for(int i=0;i<m.getSampleLevel().size();i++)
					cout<<m.getSampleLevel()[i]<<"\n";



				for (int i =0;i<m.getBitVectors().size();i++)
					cout<<m.getBitVectors()[i]<<"\n";

				int i =m.getMinima1(m.getSampleLevel(),0,12,0,m.getBitVectors());
				cout<< "res minima : "<<i<<"\n";

			}

			if(!optionValide)
				cout<<"option incorect \n";


		}


return 1;
}
