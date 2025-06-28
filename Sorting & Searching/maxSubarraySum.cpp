#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll maxSubSum(vector<ll> v, ll n){
    ll sum=INT_MIN, currSum=INT_MIN;
    for(ll i=0;i<n;i++){
        currSum=max(v[i],currSum+v[i]);
        sum=max(currSum,sum);
    }

    return sum;
}

int main(){

    ll n;
    cin>>n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    cout<<maxSubSum(v,n);

    return 0;

}