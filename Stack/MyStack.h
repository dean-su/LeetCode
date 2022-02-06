//
// Created by DeanSu on 2019/9/4.
//

#ifndef LEETCODE_MYSTACK_H
#define LEETCODE_MYSTACK_H
class MyStack
{
private:
    int arr[1000];
    int top;
public:
    MyStack(){top=-1;}
    int pop();
    void push(int);
};
#endif //LEETCODE_MYSTACK_H
