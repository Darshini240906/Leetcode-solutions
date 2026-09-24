class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size(), n = img[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        
        vector<int> dirs = {-1, 0, 1};
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = 0, count = 0;
                for (int dx : dirs) {
                    for (int dy : dirs) {
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n) {
                            sum += img[ni][nj];
                            count++;
                        }
                    }
                }
                res[i][j] = sum / count;
            }
        }
        
        return res;
    }
};
