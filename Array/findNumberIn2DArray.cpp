/*
title：二维数组中的查找
writer：山客
date：2021.3.29
example：
输入：现有矩阵如下：
[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
给定 target = 5，返回 true。
给定 target = 20，返回 false。
*/

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        int l = matrix.size();

        if (l == 0){
            return false;
        }

        for (int i = 0; i < l; i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (target < matrix[i][j])
                    continue;
                if (target == matrix[i][j])
                    return true;
            }
        }

        return false;
    }
};
