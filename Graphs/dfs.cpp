#include<bits/stdc++.h>
#define MAX 100000

using namespace std;

vector <int> adj[MAX];
int vis[MAX];

void dfs(int v){ 

    vis[v] = 1;

    for(int i = 0; i < (int) adj[v].size(); i++){ 

		if(vis[adj[v][i]] == 0){
            
			dfs(adj[v][i]);
		}
	}
}
