#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    ll n;
    cin>>n;
    vector<ll> vi(n);
    for(ll i=0;i<n;i++){
        cin>>vi[i];
    }

    sort(vi.begin(),vi.end());

    ll mid=n/2;
    ll avg=vi[mid];
    ll ans=0;
    for(ll i=0;i<n;i++){
        ans+=abs(vi[i]-avg);
    }
    cout<<ans<<endl;
    return 0;
}