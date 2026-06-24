#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> numberStack;
        stack<string> stringStack; // Using string stack to hold characters and words
        
        int i = 0;
        while (i < s.length()) {
            if (isdigit(s[i])) {
                int num = 0;
                while (isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                numberStack.push(num);
            } 
            else if (s[i] == ']') {
                // 1. Pop from stringStack until we hit "["
                string sub = "";
                while (!stringStack.empty() && stringStack.top() != "[") {
                    // Prepend because stack pops in reverse order
                    sub = stringStack.top() + sub; 
                    stringStack.pop();
                }
                
                // Pop the "[" off the stack
                if (!stringStack.empty()) stringStack.pop(); 
                
                // 2. Get the multiplier from numberStack
                int count = numberStack.top();
                numberStack.pop();
                
                // 3. Repeat the string
                string repeated = "";
                for (int c = 0; c < count; c++) {
                    repeated += sub;
                }
                
                // 4. Push it back onto the stringStack
                stringStack.push(repeated);
                i++;
            } 
            else {
                // Push letters and "[" directly onto the stack
                stringStack.push(string(1, s[i]));
                i++;
            }
        }
        
        // Final assembly: combine everything left in the stack
        string result = "";
        while (!stringStack.empty()) {
            result = stringStack.top() + result;
            stringStack.pop();
        }
        
        return result;
    }
};