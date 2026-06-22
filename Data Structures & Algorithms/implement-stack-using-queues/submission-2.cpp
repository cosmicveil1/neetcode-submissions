#include <queue>
using namespace std;

class MyStack {
private:
    // Move the queue here so it's accessible by all methods
    queue<int> q; 

public:
    MyStack() {
        // Constructor can be empty; q is automatically initialized
    }
    
    void push(int x) {
        q.push(x);
        int n = q.size();
        
        // Rotate n - 1 times to bring the newest element to the front
        for (int i = 0; i < n - 1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if (q.empty()) return -1; // Or handle error appropriately
        
        int top_element = q.front();
        q.pop();
        return top_element; // Must return the popped element
    }
    
    int top() {
        if (q.empty()) return -1;
        return q.front();
    }
    
    bool empty() {
        return q.empty(); 
    }
};