#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse(n, -1), nse(n, n);
        stack<int> st;

        // Compute Previous Smaller Element (PSE)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                pse[i] = st.top();
            }
            st.push(i);
        }

        // Clear stack for NSE calculation
        while (!st.empty()) st.pop();

        // Compute Next Smaller Element (NSE)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nse[i] = st.top();
            }
            st.push(i);
        }

        // Calculate the sum of minimums of all subarrays
        long long total = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            total = (total + (1LL * left * right * arr[i]) % mod) % mod;
        }

        return total;
    }
};
