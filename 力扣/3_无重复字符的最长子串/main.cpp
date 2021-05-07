#include <set>
#include <queue>
#include <list>
#include <vector>
#include <iostream>
#include <string>

using namespace std;


// 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
// 输入: s = "abcabcbb"
// 输出: 3 
// 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

// 输入: s = "bbbbb"
// 输出: 1
// 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

// 输入: s = "pwwkew"
// 输出: 3
// 解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//      请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

// 输入: s = ""
// 输出: 0


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        set<char> ss;
        queue<char> qs;
        for(auto c : s){
            if(ss.find(c) == ss.end()){
                ss.insert(c);
                qs.push(c);
            }
            else{
                // 存在的话就，queue弹出，set弹出，直到把存在的这个char弹出，然后把string中的char插入Q和set
                char tempc = qs.pop();



            }
        }


        return ret;
    }
};

int main(){
    string s = "pwwkew";
    Solution A;
    int ret = A.lengthOfLongestSubstring(s);
    cout << ret << endl;
    return 0;
}