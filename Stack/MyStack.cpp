//
// Created by DeanSu on 2019/9/4.
//
/* The method push to push element into the stack */
#include "MyStack.h"
void MyStack :: push(int x)
{
    // Your Code
    int max = sizeof(arr)/ sizeof(int);
    if(top == max - 1){
        return;
    } else{
        arr[++top] = x;
    }
}
/*The method pop which return the element
  poped out of the stack*/
int MyStack :: pop()
{
    // Your Code
    //int max = sizeof(arr);
    if(top = -1){
        return 0;
    } else{
        return arr[top--];
    }
}
