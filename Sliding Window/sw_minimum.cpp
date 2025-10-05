#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(vector<ll> &arr,ll k,ll n){
    ll ans=0;
    deque<ll>dq;

    for(ll i=0;i<n;i++){
        if(!dq.empty() && dq.front()<=i-k){
            dq.pop_front();
        }

        if(!dq.empty() && arr[dq.back()]>=arr[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        if(i>=k-1){
            ans^=arr[dq.front()];
        }
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