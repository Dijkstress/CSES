#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> events;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
       events.push_back({a,+1});
       events.push_back({b,-1});
    }
    sort(events.begin(),events.end());
    ll ans=0,currAns=0;
    for(ll i=0;i<events.size();i++){
        currAns+=events[i].second;
        ans=max(currAns,ans);
    }
    cout<<ans<<endl;
}