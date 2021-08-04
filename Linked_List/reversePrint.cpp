/*
title：从尾到头打印链表
writer：山客
date：2021.8.4
example：
输入：head = [1,3,2]
输出：[2,3,1]
*/


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
    	ListNode* curr;

    	std::vector<int> v;
    	std::stack<int>  s;

    	curr = head;

    	while(curr){
    		s.push(curr->val);
    		curr = curr->next;
    	}

    	while(!s.empty()){
    		v.push_back(s.top());
    		s.pop();
    	}

    	return v;
    }
};
