#include<bits/stdc++.h>
using namespace std;

// need to learn set and lower bound concept

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> tickets(n);
    vector<int> prices(m);
    for(int i=0;i<n;i++){
        cin>>tickets[i];
    }
    sort(tickets.begin(),tickets.end());
    for(int i=0;i<m;i++){
        cin>>prices[i];
    }
    sort(prices.begin(),prices.end());
    int p1=0,p2=0;
    while(p1<n && p2<m){
        if(tickets[p1]<=prices[p2]){
            cout<<tickets[p1]<<endl;
            p1++;p2++;
        }else if(tickets[p1]>prices[p2]){
            p2++;
        }
    }
    return 0;
}