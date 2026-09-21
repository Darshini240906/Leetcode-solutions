class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (!dict.count(endWord)) return res;

        unordered_map<string, vector<string>> parents;
        unordered_set<string> current{beginWord};
        bool found = false;

        while (!current.empty() && !found) {
            unordered_set<string> next;
            for (auto &w : current) dict.erase(w);

            for (auto &word : current) {
                string temp = word;
                for (int i = 0; i < temp.size(); i++) {
                    char original = temp[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[i] = c;
                        if (dict.count(temp)) {
                            next.insert(temp);
                            parents[temp].push_back(word);
                            if (temp == endWord) found = true;
                        }
                    }
                    temp[i] = original;
                }
            }
            current = next;
        }

        if (found) {
            vector<string> path{endWord};
            backtrack(endWord, beginWord, parents, path, res);
        }
        return res;
    }

    void backtrack(string word, string beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path,
                   vector<vector<string>>& res) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            res.push_back(temp);
            return;
        }
        for (auto &p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parents, path, res);
            path.pop_back();
        }
    }
};
