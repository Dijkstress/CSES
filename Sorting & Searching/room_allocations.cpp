#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve( vector<pair<pair<ll,ll>,ll>> bookings, ll n){

    sort(bookings.begin(),bookings.end());
    ll room=0;
    vector<ll> allocated(n);
    set<pair<ll,ll>> allocations;

    for(ll i=0;i<n;i++){
        ll arrival = bookings[i].first.first;
        ll departure = bookings[i].first.second;
        ll idx = bookings[i].second;
        auto it = allocations.begin();
        if(!allocations.empty() && it->first<arrival){
            ll reusedRoom =it->second;
            allocations.erase(it);
            allocations.insert({departure,reusedRoom});
            allocated[idx]=reusedRoom;
        }else{
            room++;
            allocations.insert({departure,room});
            allocated[idx]=room;            
        }
    }

    cout << room << endl;
    for (ll i = 0; i < n; i++) {
        cout << allocated[i] << " ";
    }
    cout << endl;

}

int main(){
    ll n;
    cin>>n;
    vector<pair<pair<ll,ll>,ll>> bookings(n);
    for(ll i=0;i<n;i++){
       bookings[i].second=i;
       cin>>bookings[i].first.first>>bookings[i].first.second;
    }
    solve(bookings,n);
}