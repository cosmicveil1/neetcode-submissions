class MyQueue {
private:
    stack<int> input, output;

    void moveElements() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {
    }

    void push(int x) {
        input.push(x);
    }

    int pop() {
        moveElements();
        int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        moveElements();
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};