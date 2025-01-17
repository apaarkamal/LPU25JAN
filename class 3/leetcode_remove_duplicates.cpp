#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		int i = 0, j = 1, n = nums.size();
		while (i < n && j < n) {
			// j to run until it finds a new element
			while (j < n && nums[j] == nums[j - 1]) {
				j++;
			}
			// that means j is on a new number
			if (j == n) break;

			i++;
			nums[i] = nums[j];
			j++;
		}
		return i + 1;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> nums;
	// 0,0,1,1,1,2,2,3,3,4
	nums.push_back(0);
	nums.push_back(0);

	Solution H;
	cout << H.removeDuplicates(nums) << '\n';;

	for (auto x : nums) {
		cout << x << " ";
	}

}