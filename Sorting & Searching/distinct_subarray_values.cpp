#include<bits/stdc++.h>
using namespace std;

void solve(vector<long long> arr,long long size){
    set<long long> unique;
    long long count=0;
    long long start=0,end=0;
    while(end<size){
        if(unique.find(arr[end])==unique.end()){
            unique.insert(arr[end]);
            count+=end-start+1;
            end++;
        }else{
            unique.erase(arr[start]);
            start++;
        }
    }
    cout<<count<<endl;
}

int main(){
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    solve(arr,n);
}

