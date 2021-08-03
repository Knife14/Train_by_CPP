/*
title：替换空格
writer：山客
date：2021.8.3
example：
输入：s = "We are happy."
输出："We%20are%20happy."
*/

class Solution {
public:
    string replaceSpace(string s) {
        string res;

        for (auto &c: s){
            if(c == ' '){
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }
            else{
                res.push_back(c);
            }
        }

        return res;
    }
};
