class Solution {
public:
    bool validPalindrome(string s) {
       int left = 0;
       int right = s.size() - 1;
       
       while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                // Your excellent logic is preserved here!
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
       }
       return true;
    }

private: // C++ style private section
    bool isPalindrome(const string& s, int left, int right) { // Fixed types
        while (left < right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};