#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

int main(){
    vector<char> vetor{'A','V','X','S','W','D','F','G','U','H','J','K','B','N','I','O','Q','E','A','R','Y','C','Q','Z','T','Z','\0','M',',','L','.',';',']','[','P'};
    vector<char> ABCDD{'A','B','C','D','E','F','G','H','I','J','K','L','N','M','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0',',','.',';','/','\'','\\',']','['};
    vector<char>::iterator p;

    map<char,char> m;
    map<char,char>::iterator mp;

    for(long unsigned int i=0; i<vetor.size(); i++){
        m[ABCDD[i]]=vetor[i];
    }

    /*for(mp=m.begin(); mp!=m.end();mp++) {
        cout << mp->first << " - "<< mp->second << endl;
    }
*/
    string entrada = "";

    string saida;
    
    while( getline(cin, entrada)){
        if(entrada==""||entrada==" ")
            break;
        for(char letra:entrada){
            if(letra!=' ')
                saida.push_back(m[letra]);
            else
                saida.push_back(' ');
        }
        
        cout << saida.c_str() << endl;

        entrada = "";
        saida.clear();

    }
}