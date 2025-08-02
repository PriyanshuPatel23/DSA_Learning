#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    public:
        bool checkCycle(int src,unordered_map<int,bool>& vis, int parent,vector<int> adj[]) {
        vis[src] = true;
        
        for(auto nbr: adj[src]) {
            if(nbr == parent) {
                continue;
            }
            if(!vis[nbr]) {
                bool ans = checkCycle(nbr, vis, src, adj);
                if(ans == true) {
                    return true;
                }
            }
            else if(vis[nbr]==1 ) {
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        unordered_map<int,bool> vis;
        for(int i=0;i<V;i++) {
            if(!vis[i]) {
                int parent = -1;
                bool isCyclic = checkCycle(i, vis, parent,adj);
                if(isCyclic == true) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
     int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}