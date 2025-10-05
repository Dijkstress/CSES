#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(vector<ll> &arr,ll k,ll n){
    ll currSum=0,ans=0;
    for(ll i=0;i<k;i++){
        currSum+=arr[i];
    }
    ans^=currSum;
    for(ll i=k;i<n;i++){
        currSum+=arr[i]-arr[i-k];
        ans^=currSum;
    }
    cout<<ans<<endl;
}

int main(){
    ll n,k;
    cin>>n>>k;
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> arr(n);
    arr[0] = x;
    for(ll i=1;i<n;i++){
        arr[i]=(a*arr[i-1]+b)%c;
    }
    solve(arr,k,n);

    return 0;
}