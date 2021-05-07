#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;
// O(n^2)
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        for(int i= 1; i < nums.size(); i++){
            for(int j = 0; j< i; j++){
                if(nums[i]+ nums[j] == target){
                    ret.push_back(i);
                    ret.push_back(j);
                }
            }
        }
        return ret;
    }
};

// 红黑树的时间复杂度：
// 1. 建树：nlg(n)
// 2. 查找：lg(n)
// 总：O(nlg(n))
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> map_nums;
        vector<int> ret;
        for(int i= 0; i < nums.size(); i++){
            if(map_nums.find(target - nums[i]) == map_nums.end())
            {
                map_nums.insert(pair<int, int>(nums[i], i));
            }
            else
            {
                return {i, map_nums[target - nums[i]]};
            }
        }
        return ret;
    }
};

// 哈希表：
// 1. 建表 O(n)
// 2. 查找 O(1)
// 总：O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map_nums;
        vector<int> ret;
        for(int i= 0; i < nums.size(); i++){
            if(map_nums.find(target - nums[i]) == map_nums.end())
            {
                map_nums.insert(pair<int, int>(nums[i], i));
            }
            else
            {
                return {i, map_nums[target - nums[i]]};
            }
        }
        return ret;
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution A;
    vector<int> ret = A.twoSum(nums, target);
    for(auto n : ret){
        cout << n << " ";
    }
    cout << endl;

    return 0;
}