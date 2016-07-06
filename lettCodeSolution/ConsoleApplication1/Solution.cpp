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
};