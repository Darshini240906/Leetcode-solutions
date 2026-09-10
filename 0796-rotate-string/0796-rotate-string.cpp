class Solution {
public:
    bool rotateString(string s, string goal) {
        return (s+s).find(goal)!=string::npos && s.size()==goal.size();
    }
};