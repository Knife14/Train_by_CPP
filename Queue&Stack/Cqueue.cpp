/*
title：用两个栈实现队列
writer：山客
date：2021.3.30
example：
["CQueue","appendTail","deleteHead","deleteHead"]
[[],[3],[],[]]
输出：[null,null,3,-1]

输入：
["CQueue","deleteHead","appendTail","appendTail","deleteHead","deleteHead"]
[[],[],[5],[2],[],[]]
输出：[null,-1,null,null,5,2]
*/


class CQueue {
private:
	std::stack<int> Astack, Bstack;
public:
    CQueue() {
    	// 清空两个栈，确保初始化
    	while(!Astack.empty())
    		Astack.pop();
    	while(!Bstack.empty())
    		Bstack.pop();
    }
    
    void appendTail(int value) {
    	Astack.push(value);
    }
    
    int deleteHead() {
    	// 栈先进后出，队列先进先出
    	// 若B为空，则先将A栈弹出依次push进B中，实现“后进后出”
    	if(Bstack.empty()){
    		while(!Astack.empty()){
    			Bstack.push(Astack.top());
    			Astack.pop();
    		}
    	}
    	// 若B不为空，则将B栈顶的元素pop出，即为删除掉原栈A最先压入的元素
    	if(Bstack.empty()){
    		return -1;
    	} else {
    		int item = Bstack.top();
    		Bstack.pop();
    		return item;
    	}
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
