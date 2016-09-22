#include<iostream>
#include<vector>
#include<set>
#include<string>
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
	vector<int> countBits(int num){
		vector<int> result{ 0, 1 };
		vector<int> zero{ 0 };
		if (num == 0) return zero;
		if (num == 1) return result;
		int index = 2;
		for (int i = 2; i <= num; i++){
			if (i == index * 2){
				result.push_back(1);
				index *= 2;
			}
			else{
				result.push_back(result[i - index] + 1);
			}
		}
		return result;
	}
	int getSum(int a, int b){
		while (b!=0)
		{
			int carry = a^b;
			b = (a&b) << 1;
			a = carry;
		}
		return a;
	}
	vector<int> singleNumber(vector<int>& nums){
		int AxorB = 0;
		for (int i = 0; i < nums.size(); i++){
			AxorB ^= nums[i];
		}
		int mask = AxorB&(~(AxorB - 1));
		int A = 0, B = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (mask&nums[i])
				A ^= nums[i];
			else
				B ^= nums[i];
		}
		return vector<int>({ A, B });
	}
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
		set<int> s(nums1.begin(), nums1.end()), res;
		for (auto a : nums2){
			if (s.count(a)) res.insert(a);
		}
		return vector<int>(res.begin(), res.end());
	}
	char findTheDifference(string s, string t) {
		int ans[26] = { 0 };
		char ansstring;
		for (int i = 0; i < t.size(); i++)
		{
			if (i != (t.size()-1)) ans[s[i] - 'a']--;
			ans[t[i] - 'a']++;
		}
		for (int i = 0; i < 26; i++)
			if (ans[i] == 1)
				ansstring = 'a' + i;
		return ansstring;
	}
};

int main(){
	Solution solution;
	string s, t;
	s = "abcd";
	t = "abcde";
	cout << solution.findTheDifference(s,t) << endl;
	system("pause");
}