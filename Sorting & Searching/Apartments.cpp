#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> arr(n);
    vector<int> apartments(m);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<m;i++){
        cin>>apartments[i];
    }

    sort(arr.begin(),arr.end());
    sort(apartments.begin(),apartments.end());
    int p1=0,p2=0;
    int count=0;
    while(p1<n && p2<m){
        if(abs(arr[p1]-apartments[p2])<=k){
            p1++;p2++;count++;
        }else if(arr[p1]<apartments[p2]){
            p1++;
        }else{
            p2++;
        }
    }
    cout<<count<<endl;
    return 0;
}