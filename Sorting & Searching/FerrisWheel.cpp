#include<bits/stdc++.h>
using namespace std;

// try to fit the heaviest and the lightest kid in the same gondola

int main(){
    int n,w;
    cin>>n>>w;
    vector<int> arr(n);
    int count=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    int start=0,end=n-1;
    while(start<=end){
        int totalWeight=arr[start]+arr[end];
        if(totalWeight<=w){
            count++;
            start++;end--;
        }else{
            count++;
            end--; // else put the heaviest in a gondola and decrement end
        }
    }
    cout<<count<<endl;
    return 0;
}