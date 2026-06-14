class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int j=s.size()-1;
        for(int i=0;i<n/2;i++){
            swap(s[i],s[j]);
            j--;
        }
    }
};