/*
title: 青蛙跳台阶
writer: 山客
date: 2021.4.2
key：斐波那契数列、动态规划
problem：
一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
example:
输入：n = 7
输出：21
*/

const long long mod = 1000000007;

class Solution {
public:
    int numWays(int n) {
    	long long a = 1;
    	long long b = 1;

    	for (int i = 0; i < n; i++){
    		int tmp = (a + b) % mod;
    		a = b;
    		b = tmp;
    	}

    	return a;
    }
};
