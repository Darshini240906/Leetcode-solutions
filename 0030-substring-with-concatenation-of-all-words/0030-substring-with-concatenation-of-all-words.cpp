class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int n = s.size();
        if (n < totalLen) return res;

        unordered_map<string,int> target;
        for (auto &w : words) target[w]++;

        // try each starting offset within the first word-length
        for (int offset = 0; offset < wordLen; offset++) {
            unordered_map<string,int> window;   // single map, lives outside inner loop
            int left = offset;
            int wordCount = 0;

            for (int j = offset; j + wordLen <= n; j += wordLen) {
                string word = s.substr(j, wordLen);
                window[word]++;      // add current word
                wordCount++;

                // if window grew past totalLen worth of words, shrink from left
                if (wordCount > numWords) {
                    string leftWord = s.substr(left, wordLen);
                    window[leftWord]--;              // remove first word's count
                    if (window[leftWord] == 0) window.erase(leftWord);
                    left += wordLen;
                    wordCount--;
                }

                // window is exactly totalLen now -> compare
                if (wordCount == numWords && window == target) {
                    res.push_back(left);
                }
            }
        }
        return res;
    }
};