class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniquechars;
        int left=0;
        int right=0;
        int maxlen=0;
        for(int right=0;right<s.length();right++){
            while(uniquechars.count(s[right])){
                uniquechars.erase(s[left]);
                left++;
            }
           uniquechars.insert(s[right]);
           maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};
