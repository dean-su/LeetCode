cmake_minimum_required(VERSION 3.14)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeetCode main.cpp LinkedList/append.h LinkedList/append.cpp
        LinkedList/deleteNode.cpp LinkedList/deleteNode.h LinkedList/deleteList.cpp
        LinkedList/deleteList.h LinkedList/push.cpp LinkedList/push.h
        LinkedList/reverseList.cpp LinkedList/reverseList.h
        Stack/MyStack.cpp Stack/MyStack.h Stack/StackNode.cpp Stack/StackNode.h
        BST/MyBST.cpp BST/MyBST.h Problems/TwoSum.cpp Problems/TwoSum.h
        Problems/AddTwoNumbers.cpp Problems/AddTwoNumbers.h
        Problems/lengthOfLongestSubstring.cpp Problems/lengthOfLongestSubstring.h
        Problems/longestPalindrome.cpp Problems/lengthOfLongestSubstring.h)