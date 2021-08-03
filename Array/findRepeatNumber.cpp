/*
title：数组中重复的数字
writer：山客
date：2021.3.29
example：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3
*/


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        map<int, bool> find;
        for (int num: nums){
            if(find[num])
                return num;
            find[num] = true;
        }
        return -1;
    }
};
