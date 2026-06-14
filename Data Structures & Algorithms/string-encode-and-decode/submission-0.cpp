class Solution {
public:
    string encode(vector<string>& strs) {
        string result = "";
        for(const string& str : strs) {
            result += to_string(str.length()) + "#" + str;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        int i = 0;
        
        while(i < s.length()) {
            int j = i;
            // FIX 1: Use single quotes for a single char
            while(s[j] != '#') { 
                j++;
            }
            
            // FIX 2: Use .substr() instead of .substring()
            int length = stoi(s.substr(i, j - i)); 
            
            string str = s.substr(j + 1, length);
            result.push_back(str);
            i = j + length + 1;
        }
        return result;
    } // FIX 3: Added missing closing brace for the decode function
};