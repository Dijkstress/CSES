#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll solve(vector<ll> &arr, ll n){
    ll low=0,high=0;
    ll longestSeq=0;
    set<ll> st;
    while(high<n){
       int curr=arr[high];
        if(st.find(curr)==st.end()){
            st.insert(curr);
            high++;
        }else{
            st.erase(arr[low]);
            low++;
        }

       longestSeq=max(longestSeq,high-low);
    }

    return longestSeq;
}


int main(){
   ll n;
   cin>>n;
   vector<ll> arr(n);
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   cout<<solve(arr,n)<<endl;
}