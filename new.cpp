#include <iostream>
#include <vector>

using namespace std;
// int dice(int n,vector<int> &dp){
// 	if(n<=1){
// 		return dp[n]=1;
// 	}
// 	if(dp[n]!=0) return dp[n];
// 	int count=0;

// 	for(int i=1;i<=6;i++){
// 		if(n-i>=0){
// 			count+=dice(n-i,dp);
// 		}
// 	}
// 	return dp[n]=count;
// }
int dice(int N,vector<int> &dp){
    for(int n=0;n<=N;n++){
        if(n<=1){
		    dp[n]=1;
            continue;
        }

        else if(n<=6){
            dp[n]=2*dp[n-1];
        }
        else {
            dp[n]=2*dp[n-1]-dp[n-7];
        }
	    // for(int i=1;i<=6;i++){
		//     if(n-i>=0){
		// 	    count+=dp[n-i];
		//     }
	    // }
    }
    return dp[N];
}

int diceModified(int n,int d,vector<int> &dp){
	if(n<=1){
		return dp[n]=1;
	}
	if(dp[n]!=0) return dp[n];
	int count=0;

	for(int i=1;i<=6;i++){
		if(n-i>=0&&d-1>0){
			count+=diceModified(n-i,d-1,dp);
		}
	}
	return dp[n]=count;
}
int main()
{
	
	// fibo();
	//maze();
	// minCost();
	int n,d;
	cin>>n>>d;

	vector<int> dp(n+1,0);
	cout<<dice(n,dp)<<endl;
    for(int i=0;i<n+1;i++){
        cout<<dp[i]<<" ";
    }
	return 0;
}