#include "Minima.hpp"

int main(int argc, char const *argv[])
{

	int sequencee[18];
	sequencee[0] = 6;
	sequencee[1] = 9;
	sequencee[2] = 10;
	sequencee[3] = 9;
	sequencee[4] = 11;
	sequencee[5] = 8;
	sequencee[6] = 7;
	sequencee[7] = 12;
	sequencee[8] = 8;
	sequencee[9] = 13;
	sequencee[10] = 3;
	sequencee[11] = 8;
	sequencee[12] = 7;

	int taille = sizeof(sequencee)/sizeof(int);

	string option;

		bool optionValide=false;
		string opt;

		while( !optionValide ) {
			cout<<"Entrer une option 'r' pour rrr_vector 's' pour sd_vector et 'b' pour bit_vector\n";
			cin>>option;
			if (option =="r"){
				optionValide=true;
				Minima<rrr_vector<>,int,int> m(13,sequencee,"r",true,1);
				
					
			}
			if (option =="s"){
				optionValide=true;
				Minima<sd_vector<>,int,int> m(taille,sequencee,"s",true,2);
			}
			if (option =="b"){
				optionValide=true;
				Minima<bit_vector,int,int> m(taille,sequencee,"b",true,2);

			}

			if(!optionValide)
				cout<<"option incorect \n";


		}


return 1;
}
