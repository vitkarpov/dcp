class Solution {
  int helper(const vector<int>& nums, int start, int end) {
    if (start == end) {
      return nums[start];
    }
    int mid = (start + end) / 2;
    int leftMax = helper(nums, start, mid);
    int rightMax = helper(nums, mid + 1, end);

    int curr = 0;
    int leftCurrMax = 0;
    int rightCurrMax = 0;

    for (int i = mid - 1; i >= start; i--) {
      curr += nums[i];
      leftCurrMax = max(leftCurrMax, curr);
    }
    curr = 0;
    for (int i = mid + 1; i <= end; i++) {
      curr += nums[i];
      rightCurrMax = max(rightCurrMax, curr);
    }
    return max(max(leftMax, rightMax), leftCurrMax + nums[mid] + rightCurrMax);
  }

 public:
  int maxSubArray(vector<int>& nums) {
    return helper(nums, 0, nums.size() - 1);
  }
};
