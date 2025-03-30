#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<long long> st; // Store modified values to avoid overflow
    long long min;

    MinStack() {
        min = LLONG_MAX;
    }

    void push(int val) {
        if (st.empty()) {
            min = val;
            st.push(val);
        } else {
            if (val < min) {
                st.push((long long)2 * val - min);  // Avoid overflow
                min = val;
            } else {
                st.push(val);
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long x = st.top();
        st.pop();

        if (x < min) {
            min = 2 * min - x;  // Restore previous min safely
        }

        if (st.empty()) min = LLONG_MAX;  // Reset min when stack is empty
    }

    int top() {
        if (st.empty()) return -1;

        long long x = st.top();
        return (x < min) ? min : x;
    }

    int getMin() {
        if (st.empty()) return -1;
        return min;
    }
};
