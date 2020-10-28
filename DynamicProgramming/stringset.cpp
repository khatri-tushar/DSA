#include <bits/stdc++.h> 

using namespace std;

void print(vector<int> &vec){
	for(int i:vec){
		cout<<i<<" ";
	}
	cout<<endl;
}
void print2(vector<vector<int>> &vec){
	for(vector<int> row:vec){
		print(row);
	}
	cout<<endl;
}
////////////////////////////////////////////////

void palinSubstring(string str, vector<vector<bool>> dp){
    int n=dp.size()
    for(int g=0;g<n;g++){
        for(int i=0,j=g;j<n;i++,j++){
            if(g==0){
                dp[i][j]=true;
            }
            else if(g==1){
                if(str[i]==str[j]){
                    dp[i][j]=true;
                }
            }
            else{
                if(str[i]==str[j]){
                    if(dp[i+1][j-1]==true){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
    }
}


int main()
{
    string str;
    cin>>str;
    int n=str.length();
    vector<vector<bool>> dp(n, vector<int>(n, false));
}