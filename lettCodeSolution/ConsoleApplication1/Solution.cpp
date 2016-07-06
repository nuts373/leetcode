#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	int removeDuplicates(vector<int>& nums){
		if (nums.empty()) return 0;
		int index = 0;
		for (int i = i; i < nums.size(); i++){
			if (nums[index] != nums[i])
				nums[++index] = nums[i];
		}
	}
	int removeDuplicates2(vector<int>& nums){
		if (nums.size() <= 2) return nums.size();
		int index = 2;
		for (int i = 2; i < nums.size(); i++){
			if (nums[i] != nums[index - 2])
				nums[index++] = nums[i];
		}
		return index;
	}
	int search(const vector<int>& nums, int target){
		int first = 0, last = nums.size();
		while (first != last){
			const int mid = first + (last - first) / 2;
			if (nums[mid] == target)
				return mid;
			if (nums[first] <= nums[mid]){
				if (nums[first] <= target && target < nums[mid])
					last = mid;
				else
					first = mid + 1;
			}
			else{
				if (nums[mid] < target && target <= nums[last - 1])
					first = mid + 1;
				else
					last = mid;
			}
		}
		return -1;
	}
};

int main(){
	Solution solution;
	vector<int> input{ 4, 5, 6, 7, 0, 1, 2 };
	cout << solution.search(input, 7) << endl;
}