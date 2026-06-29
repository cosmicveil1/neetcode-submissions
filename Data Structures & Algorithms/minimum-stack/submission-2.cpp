class MinStack {
private:
    stack<long long> st;
    long long mini;

public:
    MinStack() {
        mini = LLONG_MAX;
    }

    void push(int val) {
        if(st.empty()) {
            mini = val;
            st.push(val);
        }
        else if(val >= mini) {
            st.push(val);
        }
        else {
            st.push(2LL * val - mini);
            mini = val;
        }
    }

    void pop() {
        if(st.empty()) return;

        long long x = st.top();
        st.pop();

        if(x < mini)
            mini = 2 * mini - x;

        if(st.empty())
            mini = LLONG_MAX;
    }

    int top() {
        if(st.empty()) return -1;

        long long x = st.top();
        return (x >= mini) ? x : mini;
    }

    int getMin() {
        if(st.empty()) return -1;
        return mini;
    }
};