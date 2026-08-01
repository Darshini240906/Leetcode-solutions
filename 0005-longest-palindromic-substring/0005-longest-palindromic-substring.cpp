class Solution {
public:

    int expand(string s, int left,int right){
        while(left>=0 && right<= s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        return right-left-1;
    }
    string longestPalindrome(string s) {
        int start =0;
        int end=0;
        int maxlength=-1;
        for(int i=0;i<s.size();i++){
            int len1=expand(s,i,i);
            int len2=expand(s,i,i+1);

            maxlength=max(len1,len2);

            if(maxlength>end-start){
                start = i-(maxlength-1)/2;
                end=i+maxlength/2;
            }

        }

        return s.substr(start,end-start+1);
    }
};