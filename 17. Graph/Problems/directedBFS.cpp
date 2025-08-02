#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution{
    public:
        bool checkCyclic(int src, unordered_map<int, bool>& vis, unordered_map<int, bool>& dfsTrack, vector<int> adj[]) {
    vis[src] = true;
    dfsTrack[src] = true;

    for(auto nbr : adj[src]) {
        if(!vis[nbr]) {
            if(checkCyclic(nbr, vis, dfsTrack, adj)) return true;
        }
        else if(dfsTrack[nbr] == true) {
            return true;
        }
    }

    dfsTrack[src] = false;
    return false;
}

        bool isCyclic(int V, vector<int> adj[]) {
       unordered_map<int,bool> vis;
       unordered_map<int,bool> dfsTrack;
       
       for(int node=0; node<V; node++) {
           if(!vis[node]) {
               bool isCyclic = checkCyclic(node, vis, dfsTrack, adj);
               if(isCyclic) {
                   return true;
               }
           }
       }
       return false;
    }
};

int main() {
    int t;
    cin >> t;
    while(t--){
        int V,E;
        cin >> V >> E;
        
        vector<int> adj[V];
        
        for(int i = 0; i < E; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }
    return 0;
}