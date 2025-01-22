class Solution {
    void dfs(int node,int &timer,int parent,vector<int> &low,vector<int> &disc,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj,vector<vector<int>> &result){
        vis[node] = true;
        low[node] = disc[node] = timer++;
        for(auto nbr:adj[node]){
            if(nbr == parent) continue;
            if(!vis[nbr]){
                dfs(nbr,timer,node,low,disc,vis,adj,result);
                low[node] = min(low[node],low[nbr]);
                if(low[nbr] > disc[node]){
                    result.push_back({node,nbr});
                }
            }
                else{
                    low[node] = min(low[node],disc[nbr]);
                }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int>>adj;
        for(int i = 0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        int timer = 0;
        vector<int> disc(n,-1);
        vector<int> low(n,-1);
        int parent = -1;
        vector<vector<int>> result;
        unordered_map<int,bool>vis;
        for(int i= 0; i<n; i++){
            if(!vis[i]){
                dfs(i,timer,parent,low,disc,vis,adj,result);
            }
        }
        return result;
    }
};
