#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long max_sum = 0, min_sum = 0;
        stack<int> s;

        // Calculate max_sum
        vector<int> left_max(n), right_max(n);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }
            left_max[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        s = stack<int>(); // Clear stack

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }
            right_max[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for (int i = 0; i < n; i++) {
            max_sum += (long long)nums[i] * (i - left_max[i]) * (right_max[i] - i);
        }

        // Calculate min_sum
        vector<int> left_min(n), right_min(n);
        s = stack<int>(); // Clear stack

        for (int i = 0; i < n; i++) {
            while (!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            left_min[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        s = stack<int>(); // Clear stack

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }
            right_min[i] = s.empty() ? n : s.top();
            s.push(i);
        }

        for (int i = 0; i < n; i++) {
            min_sum += (long long)nums[i] * (i - left_min[i]) * (right_min[i] - i);
        }

        return max_sum - min_sum;
    }
};
