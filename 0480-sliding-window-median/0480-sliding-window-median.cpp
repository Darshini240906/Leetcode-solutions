class Solution {
private:
    priority_queue<int> small; // max heap
    priority_queue<int, vector<int>, greater<int>> large; // min heap

    unordered_map<int, int> delayed;

    int smallSize = 0;
    int largeSize = 0;

    void pruneSmall() {
        while (!small.empty()) {
            int num = small.top();

            if (!delayed.count(num) || delayed[num] == 0)
                break;

            delayed[num]--;
            if (delayed[num] == 0)
                delayed.erase(num);

            small.pop();
        }
    }

    void pruneLarge() {
        while (!large.empty()) {
            int num = large.top();

            if (!delayed.count(num) || delayed[num] == 0)
                break;

            delayed[num]--;
            if (delayed[num] == 0)
                delayed.erase(num);

            large.pop();
        }
    }

    void makeBalance() {

        if (smallSize > largeSize + 1) {

            large.push(small.top());
            small.pop();

            smallSize--;
            largeSize++;

            pruneSmall();
        }

        else if (smallSize < largeSize) {

            small.push(large.top());
            large.pop();

            smallSize++;
            largeSize--;

            pruneLarge();
        }
    }

    void insertNum(int num) {

        if (small.empty() || num <= small.top()) {
            small.push(num);
            smallSize++;
        }
        else {
            large.push(num);
            largeSize++;
        }

        makeBalance();
    }

    void eraseNum(int num) {

        delayed[num]++;

        if (num <= small.top()) {

            smallSize--;

            if (num == small.top())
                pruneSmall();
        }
        else {

            largeSize--;

            if (num == large.top())
                pruneLarge();
        }

        makeBalance();
    }

    double getMedian(int k) {

        pruneSmall();
        pruneLarge();

        if (k & 1)
            return (double)small.top();

        return ((double)small.top() +
                (double)large.top()) / 2.0;
    }

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        for (int i = 0; i < nums.size(); i++) {

            insertNum(nums[i]);

            if (i >= k)
                eraseNum(nums[i - k]);

            if (i >= k - 1)
                ans.push_back(getMedian(k));
        }

        return ans;
    }
};