class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0; 

        unordered_set<string> beginSet{beginWord}, endSet{endWord};
        int steps = 1;

        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller frontier
            if (beginSet.size() > endSet.size()) swap(beginSet, endSet);

            unordered_set<string> next;
            for (string word : beginSet) {
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if (endSet.count(word)) return steps + 1;
                        if (dict.count(word)) {
                            next.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = original;
                }
            }
            beginSet = next;
            steps++;
        }
        return 0;
    }
};
