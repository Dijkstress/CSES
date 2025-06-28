#include<bits/stdc++.h>
using namespace std;

// I have to count the smaller numbers i.e arr[i]<curr_smaller

typedef long long ll;

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n+1);
    for(int i=1;i<=n;i++){
        int input;
        cin>>input;
        arr[input]=i;
    }
    int ans=1;
    for(int i=1;i<n;i++){
        if(arr[i+1]<arr[i])ans++;
    }
    cout<<ans;
}

int main(){
    solve();
    return 0;
}