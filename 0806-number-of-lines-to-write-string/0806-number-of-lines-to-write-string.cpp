class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int>v;
        int line=1;
        int capacity=0;
        for(int i=0;i<s.size();i++){
            int size = widths[s[i] - 'a'];
            if(capacity + size >100){
                capacity= size;
                line++;
            }
            else{
                capacity+=size;}

        }

        v.push_back(line);
        v.push_back(capacity);


        return v;

    
    }
};