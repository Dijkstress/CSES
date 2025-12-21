#include<bits/stdc++.h>
using namespace std;

using ll = long long;

template<class T, auto F>
struct AggStack{
    stack<pair<T,T>> S;

    void push(T val){
        if(S.empty()){
            S.push({val,val});
        }else{
            S.push({val,F(val,S.top().second)});
        }
    }

    T top(){
        return S.top().first;
    }

    T pop(){
        T ret = S.top().first;
        S.pop();
        return ret;
    }

    bool empty(){
        return S.empty();
    }

    ll size(){
        return S.size();
    }

    T get(){
        return S.top().second;
    }

    void swap(AggStack<T,F> & ST){
        S.swap(ST.S);
    };
};

template<class T, auto F>
struct AggQueue{
    AggStack<T,F> In,Out;

    void push(T val){
        In.push(val);
    }

    T pop(){
        if(Out.empty()){
            while(!In.empty()){
                Out.push(In.pop());
            }
        }
        return Out.pop();
    }

    T get(){
        if(In.empty()) return Out.get();
        if(Out.empty()) return In.get();

        return F(In.get(),Out.get());
    }
};

void solved_using_prefix_suffix(vector<ll> &arr,ll k,ll n){
    vector<ll> prefix_ors(n);
    for(int i=0;i<n;i++){
        if(i%k==0){
            prefix_ors[i]=arr[i];
        }else{
            prefix_ors[i]=prefix_ors[i-1]|arr[i];
        }
    }

    vector<ll> suffix_ors(n);
    suffix_ors[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--){
        if(i%k==k-1){
            suffix_ors[i]=arr[i];
        }else{
            suffix_ors[i]=suffix_ors[i+1]|arr[i];
        }
    }
    
    ll ans=0;
    for(int i=k-1;i<n;i++){
        ll curr=prefix_ors[i] | suffix_ors[i-k+1];
        ans^=curr;
    }
    cout<<ans<<endl;
}

void solved_using_aggregated_queue(vector<ll> &arr,ll k,ll n){
    AggQueue<ll, [](ll a, ll b) {
        return a | b;
    }>Q;

    int i=0;
    int ans=0;
    for(int j=0;j<n;j++){
        Q.push(arr[j]);

        if(j-i+1<k) continue;
        
        ans^=Q.get();
        Q.pop();
        i++;
    }

    cout<<ans<<endl;
} 

int main(){
    ll n,k;
    cin>>n>>k; 
    ll x,a,b,c;
    cin>>x>>a>>b>>c;
    vector<ll> arr(n);
    arr[0] = x;
    for(ll i=1;i<n;i++){
        arr[i]=(a*arr[i-1]+b)%c;
    }
    solved_using_aggregated_queue(arr,k,n);

    return 0;
}