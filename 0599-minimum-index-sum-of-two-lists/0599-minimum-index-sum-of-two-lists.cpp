class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> mp;
        unordered_map<string,int> sum_index;

        for(int i=0;i<list1.size();i++){
            mp[list1[i]] = i;
        }

        for(int i=0;i<list2.size();i++){
            if(mp.find(list2[i]) != mp.end()){
                sum_index[list2[i]] = mp[list2[i]] + i;
            }
        }

        
        int minSum = INT_MAX;
        for(auto &p : sum_index){
            minSum = min(minSum, p.second);
        }

    
        vector<string> result;
        for(auto &p : sum_index){
            if(p.second == minSum){
                result.push_back(p.first);
            }
        }

        return result;
    }
};
