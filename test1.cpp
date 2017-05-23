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
				Minima<rrr_vector<>,rrr_vector<>::rank_1_type,rrr_vector<>::select_1_type> m(taille,sequencee,"r",true,1);
		
				rrr_vector<> b = m.getBitVectors()[0];//{1,1,0,1,0,0,1};
				//rrr_vector<>::rank_1_type r(&b);
				//cout<<"rank rrr :"<<r(6);

				cout<<"test rank save"<<m.getRankVector()[0](5);
				//m.rank_function(b,3);
				int i =m.getMinima1(m.getSampleLevel(),5,9,0,m.getSelectVector(),m.getRankVector());
				cout<< "res minima : "<<i<<"\n";
					
			}
			if (option =="s"){
				optionValide=true;
				Minima<sd_vector<>,sd_vector<>::rank_1_type,sd_vector<>::select_1_type> m(taille,sequencee,"s",true,1);
			int i =m.getMinima1(m.getSampleLevel(),5,9,0,m.getSelectVector(),m.getRankVector());
				cout<< "res minima : "<<i<<"\n";

			}
			if (option =="b"){
				optionValide=true;
				Minima<bit_vector,rank_support_v<1>,bit_vector::select_1_type> m(taille,sequencee,"b",true,1);
				//bit_vector b = m.getBitVectors()[0];//{1,1,0,1,0,0,1};
				//m.rank_function(b,5);


cout<< "test function 1="<<m.getSampleLevel().size()<<"\n";


cout<< "test function 10="<<m.getBitVectors().size()<<"\n";
				


				for(int i=0;i<m.getSampleLevel().size();i++)
					cout<<m.getSampleLevel()[i]<<"\n";



				for (int i =0;i<m.getBitVectors().size();i++)
					cout<<m.getBitVectors()[i]<<"\n";

				cout<< "size bit vec : "<<m.getBitVectors().size()<<"\n";
				cout<< "size list seq : "<<m.getSampleLevel().size()<<"\n";

				
				int i =m.getMinima1(m.getSampleLevel(),5,9,0,m.getSelectVector(),m.getRankVector());
				cout<< "res minima : "<<i<<"\n";

			cout<<"test rank save"<<m.getRankVector()[0](5);



				
			}
			cout<< "test division"<<10%6;


			if(!optionValide)
				cout<<"option incorect \n";

	


		}


return 1;
}
