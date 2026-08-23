class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>> pq; // max heap

        for (int num : arr) {
            pq.push({abs(num - x), num});
            if (pq.size() > k) {
                pq.pop(); // remove farthest
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        sort(result.begin(), result.end()); // final ascending order
        return result;
    }
};
