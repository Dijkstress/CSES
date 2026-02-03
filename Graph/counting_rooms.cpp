#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &graph){
    int n=graph.size();
    int m=graph[0].size();
    vis[row][col]=1;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for(auto dir : directions){
        int newRow=row+dir.first;
        int newCol=col+dir.second;
        if(newRow>=0 && newRow<n && newCol>=0 && newCol<m && !vis[newRow][newCol] && graph[newRow][newCol]=='.'){
            dfs(newRow,newCol,vis,graph);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>> graph(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
        }
    }
    int count=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    for(int row=0;row<n;row++){
        for(int col=0;col<m;col++){
            if(!vis[row][col] && graph[row][col]=='.'){
                dfs(row,col,vis,graph);
                count++;
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
