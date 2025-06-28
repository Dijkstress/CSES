#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

bool comp(const pair<ll,ll> &a, const pair<ll,ll> &b){
    return a.second<b.second;
}

int main(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>> events;
    for(int i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        events.push_back({a,b});
    }
    sort(events.begin(),events.end(),comp);

    int ans=0,end=0;
    for(auto it : events){
        if(it.first>=end){
            ans++;
            end=it.second;
        }
    }
    cout<<ans<<endl;
}