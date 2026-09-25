class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st;
        for(int i=0;i<operations.size();i++){
            if(operations[i]=="C"){
                st.pop();
            }
            else if(operations[i]=="D"){
                st.push(st.top()*2);
            }
            else if(operations[i]=="+"){
                int first = st.top();st.pop();
                int second=st.top();
                int sum=first+second;
                st.push(first);
                st.push(sum);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }


        int sum_total=0;
        while(!st.empty()){
            sum_total+=st.top();
            st.pop();
        }

        return sum_total;
    }
};