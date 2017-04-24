#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class LireFichier  {

private:
        std::vector<int> list;

public:
        LireFichier(string fich) {
                ifstream fichier(fich, ios::in);
                //vector<int> list;
                int entier;
                if(fichier)
                {

                while(fichier>>entier){
                     list.push_back(entier);
                }
         
                        fichier.close();
                }
                else
                        cerr << "Impossible d'ouvrir le fichier !" << endl;

                //tableau[list.size()];
                cout<<list.size();
                for (int i=0;i<list.size();i++) {
                     //  tableau[i]=list[i];
                        cout<<list[i];
                }


                //cout<<sizeof(tableau)/sizeof(int);

        }

        vector<int> getList(){
                return list;
        }
   
};


 
int main()
{

     LireFichier l("chaine.txt");
     //cout<<l.getTableau()[0];


        return 0;
}
