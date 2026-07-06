#include <iostream>
using namespace std;
void combination(string s){
    int l=s.length();
    for(int i=1;i<(1<<l);i++){
        string com="";
        for(int j=0;j<l;j++){
            if(i&(1<<j)){
                com+=s[j];
            }
        }
        cout << com << endl;
    }
}
int main(){
    string s;
    getline(cin,s);
    combination(s);
    return 0;
}