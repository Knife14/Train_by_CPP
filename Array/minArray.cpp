/*
title: 旋转数组的最小数字
writer: 山客
date: 2021.4.2
example:
输入：[3,4,5,1,2]
输出：1

输入：[2,2,2,0,1]
输出：0
*/


class Solution {
public:
    int minArray(vector<int>& numbers) {
    	int high = numbers.size() - 1;
    	int low = 0;
    	
    	// 二分法
    	while(low < high){
    		int mid = low + (high - low) / 2;

    		// 鉴于原数组有序，旋转后阶段仍然有序
    		if (numbers[mid] < numbers[high]){
    			// 忽略右半边
    			high = mid;
    		}
    		else if (numbers[mid] > numbers[high]){
    			// 忽略左半边
    			low = mid + 1;
    		}
    		else {
    			// 存在重复值时，谨慎处理，high -= 1
    			high -= 1;
    		}
    	}

    	return numbers[low];
    }
};
