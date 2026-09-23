class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int> outdeg(n);
        
        //Build reverse graph and also calculating the outdegree for each node
        for (int u = 0; u < n; u++) {
            outdeg[u] = graph[u].size();
            for (int v : graph[u]) {
                rev[v].push_back(u);
            }
        }
        
        queue<int> q;
        vector<int> safe(n, 0);
        
        for (int i = 0; i < n; i++) {
            if (outdeg[i] == 0) {
                q.push(i);
                safe[i] = 1;
            }
        }
        
        //Multi-source BFS
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : rev[v]) {
                outdeg[u]--;
                if (outdeg[u] == 0 && !safe[u]) {
                    safe[u] = 1;
                    q.push(u);
                }
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < n; i++) if (safe[i]) ans.push_back(i);
        return ans;
    }
};
