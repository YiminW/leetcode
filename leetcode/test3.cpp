//
//  test3.cpp
//  leetcode
//
//  Created by 王益民 on 2020/10/25.
//

#include "test3.hpp"
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        int len = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int>myMap;
        
        for(; right < s.size(); right++){
            auto iter = myMap.find(s[right]);
            // >= left 不能忘
            if(iter != myMap.end() && iter -> second >= left){
                res = max(right - left, res);
                left = iter -> second + 1;
                myMap[s[right]] = right;
            }else{
                //+1 是个坑
                res = max(right - left + 1, res);
                myMap[s[right]] = right;
            }
        }

        return res;

    }
};
