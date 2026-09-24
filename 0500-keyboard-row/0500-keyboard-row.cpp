int getRow(char c) {
    string row1 = "qwertyuiop";
    string row2 = "asdfghjkl";
    string row3 = "zxcvbnm";

    c = tolower(c);
    if (row1.find(c) != string::npos) return 1;
    if (row2.find(c) != string::npos) return 2;
    return 3;
}

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        for (auto &word : words) {
            int row = getRow(word[0]);
            bool valid = true;
            for (char c : word) {
                if (getRow(c) != row) {
                    valid = false;
                    break;
                }
            }
            if (valid) result.push_back(word);
        }
        return result;
    }
};
