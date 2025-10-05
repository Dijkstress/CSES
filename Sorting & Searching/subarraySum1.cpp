#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n, target;
    cin>>n>>target;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int start=0,end=0;
    int sum=0,ans=0;
    while(end<=n){
        sum+=arr[end];
        cout<<sum<<":";
        if(sum==target){
            ans++;
            sum-=arr[start];
            start++; 
        }else if(sum>target){
            sum-=arr[start];
            start++; 
        }
        end++;
    }
    cout<<ans<<endl;
    
    return 0;
}
