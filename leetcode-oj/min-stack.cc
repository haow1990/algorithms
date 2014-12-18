class MinStack {
public:
    stack<int> data;
    stack<int> minval;
    
    MinStack() {}
    
    void push(int x) {
        if (minval.empty() || x <= minval.top()) {
            minval.push(x);
        }
        data.push(x);
    }

    void pop() {
        if (data.empty()) {
            return;
        }
        if (minval.top() == data.top()) {
            minval.pop();
        }
        data.pop();
    }

    int top() {
        return data.top();
    }

    int getMin() {
        return minval.top();
    }
};
