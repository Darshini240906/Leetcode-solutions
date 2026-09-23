class Solution {
public:
    bool dfs(int u, vector<vector<int>>& graph, vector<int>& state) {
        if (state[u] == 1) return false;
        if (state[u] == 2) return true;
        
        state[u] = 1;
        for (int v : graph[u]) {
            if (!dfs(v, graph, state)) return false;
        }
        state[u] = 2;
        return true;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> state(n, 0);
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            if (dfs(i, graph, state)) ans.push_back(i);
        }
        return ans;
    }
};
