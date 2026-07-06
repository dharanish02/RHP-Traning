//To check if a string contains all digits from 0 to 9
#include <iostream>
#include <string>
using namespace std;
void check(string s){
    int digits=0;
    for(char c:s){
        if(c>='0' && c<='9'){
            digits|=(1<<(c-'0'));
        }
    }
    cout << (digits == ((1 << 10) - 1) ? "Yes" : "No") << endl;
}
int main(){
    string st;
    getline(cin,st);
    check(st);
    return 0;
}
