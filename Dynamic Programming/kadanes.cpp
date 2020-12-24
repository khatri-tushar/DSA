#include <bits/stdc++.h>
#define ll long long 
using namespace std;
ll solve(vector<ll> &vec,int n){
    ll csum=vec[0], gMax=vec[0];
    for(ll i = 1 ;i<n;i++){
        csum = max(csum+vec[i],vec[i]);
        gMax = max(gMax,csum);
    }
    return gMax;
}
int main(){
    int n;
    cin>>n;
    vector<ll> vec(n,0);
    for(int i =0 ;i<n; i++){
        cin>>vec[i];
    }
    cout<<solve(vec,n)<<endl;
}