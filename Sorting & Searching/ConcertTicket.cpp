#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    multiset<int> tickets;
    vector<int> user(m);
    for(int i=0;i<n;i++){
        int input;
        cin>>input;
        tickets.insert(input);
    }

    for(int i=0;i<m;i++){
        cin>>user[i];
    }

    for(auto it : user){
        auto idx = tickets.upper_bound(it);
        if(idx==tickets.begin()){
            cout<<-1<<endl;
        }else{
            idx--;
            tickets.erase(idx);
            cout<<*idx<<endl;
        }
    }
    return 0;
}