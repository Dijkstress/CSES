#include<bits/stdc++.h>
using namespace std;

// I have to count the smaller numbers i.e arr[i]<curr_smaller

typedef long long ll;

ll countRounds(vector<ll> arr,ll n){
    vector<ll> indices(n);
    for(ll i=0;i<n;i++){
        indices[arr[i]]=i;
    }
    ll ans=1;
    for(ll i=0;i<n;i++){
        if(indices[i+1]<indices[i])ans++;
    }
    return ans;
}

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    while(m--){
        ll a,b;
        cin>>a>>b;
        ll temp=arr[a-1];
        arr[a-1]=arr[b-1];
        arr[b-1]=temp;
        cout<<countRounds(arr,n)<<endl;
    }
   
}

int main(){
    solve();
    return 0;
}