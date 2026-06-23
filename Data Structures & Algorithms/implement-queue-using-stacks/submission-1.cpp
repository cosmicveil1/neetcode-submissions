#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> s1, s2;

public:
    MyQueue() {
        // Constructor can remain empty
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        // First, make sure s2 has elements to pop. 
        // If it doesn't, shift everything from s1 to s2.
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        
        // Now capture the top element, pop it, and return it
        int val = s2.top();
        s2.pop();
        return val;
    }
    
    int peek() {
        // Same shifting logic as pop()
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        // The queue is only truly empty if BOTH stacks have no elements
        return s1.empty() && s2.empty();
    }
};