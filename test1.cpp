#include "Minima.hpp"


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
				Minima<rrr_vector<>,int,int> m(taille,sequencee,"r",true,1);
		
				rrr_vector<> b = m.getBitVectors()[0];//{1,1,0,1,0,0,1};
				//rrr_vector<>::rank_1_type r(&b);
				//cout<<"rank rrr :"<<r(6);
				//m.rank_function(b,3);
				
					
			}
			if (option =="s"){
				optionValide=true;
				Minima<sd_vector<>,int,int> m(taille,sequencee,"s",true,2);
			}
			if (option =="b"){
				optionValide=true;
				Minima<bit_vector,rank_support_v<1>,int> m(taille,sequencee,"b",true,1);
				//bit_vector b = m.getBitVectors()[0];//{1,1,0,1,0,0,1};
				//m.rank_function(b,5);

				for (int i =0;i<m.getBitVectors().size();i++)
					cout<<m.getBitVectors()[i]<<"\n";

				for(int i=0;i<m.getSampleLevel().size();i++)
					cout<<m.getSampleLevel()[i]<<"\n";

				int i =m.getMinima(m.getSampleLevel(),4,15,0,m.getBitVectors());
				cout<< "res minima : "<<i;
			}

			if(!optionValide)
				cout<<"option incorect \n";

			cout<<min(1,2);


		}


return 1;
}
