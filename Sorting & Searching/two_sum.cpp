#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    map<int,int> mp;
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        int diff=k-input;
        if(mp.count(diff)){
            cout<<i+1<<" "<<mp[diff]+1<<endl;
            return 0;
        }
        mp[input]=i;

    }

    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}