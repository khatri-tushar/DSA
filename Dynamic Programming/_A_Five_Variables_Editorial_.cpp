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


//===============================================\\

int fibMEM(int n,vector<int> &dp){
	if(n==0||n==1){
		return dp[n]=n;
	}
	if(dp[n]!=-1) return dp[n];

	int a=fibMEM(n-1,dp); 
	int b=fibMEM(n-2,dp);
	return dp[n]=a+b;
}
int fibTAB(int N,vector<int> &dp){
	for(int n=0;n<=N;n++){
		if(n==0||n==1){
			dp[n]=n;
			continue;
		}

		int a=dp[n-1];//fibMEM(n-1,dp);
		int b=dp[n-2];//fibMEM(n-2,dp);
		dp[n]=a+b;
	}
	return dp[N];
}

void fibo(){
	int n;
	cin>>n;
	vector<int> dp(n+1,-1);
	
	cout<<fibMEM(n,dp)<<endl;
	// cout<<fibTAB(n,dp)<<endl;
	print(dp);
}
//=============================================

int mazePathMEM(int sr,int sc,int dr,int dc,vector<vector<int>>&dp)
{
	if(sr==dr&&sc==dc){
		return dp[sr][sc]=1;
	}
	if(dp[sr][sc]!=0){
		return dp[sr][sc];
	}
	int count=0;
	if(sr+1<=dr){
		count =mazePathMEM(sr+1,sc,dr,dc,dp);
	}
	if(sc+1<=dc){
		count+=mazePathMEM(sr,sc+1,dr,dc,dp);
	}
	if(sr+1<=dr&&sc+1<=dc){
		count+=mazePathMEM(sr+1,sc+1,dr,dc,dp);
	}
	return dp[sr][sc]=count;
}

int mazePathTAB(int sr,int sc,int dr,int dc,vector<vector<int>>&dp)
{
	for(int sr=dr;sr>=0;sr--){
		for(int sc=dc;sc>=0;sc--){
			if(sr==dr&&sc==dc){
				dp[sr][sc]=1;
				continue;
			}
			// if(dp[sr][sc]!=0){
			// 	return dp[sr][sc];
			// }
			int count=0;
			if(sr+1<=dr){
				count =dp[sr+1][sc];//mazePathMEM(sr+1,sc,dr,dc,dp);
			}
			if(sc+1<=dc){
				count+=dp[sr][sc+1];//mazePathMEM(sr,sc+1,dr,dc,dp);
			}
			if(sr+1<=dr&&sc+1<=dc){
				count+=dp[sr+1][sc+1];//mazePathMEM(sr+1,sc+1,dr,dc,dp);
			}
			dp[sr][sc]=count;
		}
	}
	return dp[0][0];
}
int mazeJumpMEM(int sr,int sc,int dr,int dc,vector<vector<int>>&dp){
	if(sr==dc&& sc==dc){
		return dp[sr][sc]=1;
	}
	if(dp[sr][sc]!=0){
		return dp[sr][sc];
	}
	int count =0;
	for(int jump=1;jump+sr<=dr;jump++){
		count+=mazeJumpMEM(sr+jump,sc,dr,dc, dp);
	}
	for(int jump=1;jump+sc<=dc;jump++){
		count+=mazeJumpMEM(sr,sc+jump,dr,dc, dp);
	}
	for(int jump=1;jump+sr<=dr&&sc+jump<=dc;jump++){
		count+=mazeJumpMEM(sr+jump,sc+jump,dr,dc, dp);
	}
	return dp[sr][sc]=count;
}

int mazeJumpTAB(int sr,int sc, int dr,int dc, vector<vector<int>> &dp){
	for(int sr=dr;sr>=0;sr--){
		for(int sc=dc;sc>=0;sc--){
			if(sr==dc&& sc==dc){
				dp[sr][sc]=1;
				continue;
			}
			// if(dp[sr][sc]!=0){
			// 	return dp[sr][sc];
			// }

			int count =0;
			
			for(int jump=1;jump+sr<=dr;jump++){
				count+=dp[sr+jump][sc];//mazeJumpMEM(sr+jump,sc,dr,dc, dp);
			}
			for(int jump=1;jump+sc<=dc;jump++){
				count+=dp[sr][sc+jump];//mazeJumpMEM(sr,sc+jump,dr,dc, dp);
			}
			for(int jump=1;jump+sr<=dr&&sc+jump<=dc;jump++){
				count+=dp[sr+jump][sc+jump];//mazeJumpMEM(sr+jump,sc+jump,dr,dc, dp);
			}
			dp[sr][sc]=count;//return dp[sr][sc]=count;
		}
	}
}
int maze(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> dp(n, vector<int>(m, 0)); // int[][] dp = new int[n][m];

	// cout<<mazePathMEM(0,0,n-1,m-1,dp)<<endl;
	// cout<<mazePathTAB(0,0,n-1,m-1,dp)<<endl;

	cout<<mazeJumpMEM(0,0,n-1,m-1,dp)<<endl;
	cout<<mazeJumpTAB(0,0,n-1,m-1,dp)<<endl;
	print2(dp);

}


//====================================================/
int minCostMEM(int sr,int sc,int dr,int dc,vector<vector<int>> &grid,vector<vector<int>> &dp){
	if(sr==sc&&dr==dc){
		return dp[sr][sc]=1;
	}
	if(dp[sr][sc]!=1e8) return dp[sr][sc];
	int a=1e8,b=1e8;
	if(sr+1<=dr){
		a=minCostMEM(sr+1,sc,dr,dc,grid,dp);
	}
	if(sc+1<=dc){
		b=minCostMEM(sr,sc+1,dr,dc,grid,dp);
	}
	int ans=min(a,b);
	return dp[sr][sc]=ans+grid[sr][sc];
}

int minCost(vector<vector<int>> &grid){
	int n=grid.size();
	int m=grid[0].size();
	vector<vector<int>> dp(n,vector<int>(m,1e8));

	return minCostMEM(0,0,n-1,m-1,grid,dp);	
}


//====================================================/
int staircase(int n){
	if(n==0){
		return 1;
	}
	int ans=0;
	if(n-1>=0){
		ans+=staircase(n-1);
	}
	if(n-2>=0){
		ans+=staircase(n-2);
	}
	if(n-3>=0){
		ans+=staircase(n-3);
	}
	return ans;
}



int main()
{
	
	// fibo();
	//maze();
	minCost();
	return 0;
}
