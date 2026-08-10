#include<iostream>
#include<string>
#include<vector>
using namespace std;
int solve(string n1,string n2){
	int r=n1.length(),c=n2.length();
	vector<int> p1(r+1,0),p2(c+1,0);
	for(int i=1;i<=r;i++){
		p1[i]=(p1[i-1]+(n1[i-1]-'0'))%10;
	}
	for(int i=1;i<=c;i++){
		p2[i]=(p2[i-1]+(n2[i-1]-'0'))%10;
	}
	if(p1[r]!=p2[c]){
		return -1;
	}
	vector<vector<int>> dp(r+1,vector<int>(c+1,0));
	for(int row=1;row<=r;row++){
		for(int col=1;col<=c;col++){
			if(p1[row]==p2[col]){
				dp[row][col]=1+dp[row-1][col-1];
			}else{
				dp[row][col]=max(dp[row-1][col],dp[row][col-1]);
			}
		}
	}
	return dp[r][c];
}
int main(){
	cin.tie(0);
	int tc;
	cin>>tc;
	while(tc--){
		string n1,n2;
		cin>>n1>>n2;
		cout<<solve(n1,n2)<<endl;
	}
	return 0;
}