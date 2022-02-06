#include "newfiles.h"
#include "D:\cplusplus\CodeWar\Utility.h"
#include "LinkedList/deleteNode.h"
#include "LinkedList/append.h"
#include "LinkedList/deleteList.h"
#include "LinkedList/push.h"
#include "LinkedList/reverseList.h"
#include "Stack/MyStack.h"
#include "Stack/StackNode.h"
#include "BST/MyBST.h"
#include "Problems/TwoSum.h"
#include "Problems/AddTwoNumbers.h"
#include "Problems/lengthOfLongestSubstring.h"
#include "Problems/longestPalindrome.h"

void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
void printListNode(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}
/* Function to get the middle of the linked list*/

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;
    // TO BE REMOVED
    //for (int i=0; i<20; i++);
    //cin>>T;
    T = 1;
    while(T--){
        struct Node *head = NULL,  *tail = NULL;
        //cin>>n;
        n = 5;
        for(i=1;i<=n;i++)
        {
            //cin>>l;
            l = i;
            append(&head, &tail, l);
        }
        int kk = 5;
        //cin>>kk;
        printList(head);


        head = deleteNode(head,kk);
        printList(head);
        head = deleteNodeRecursive(head, kk-1);
        printList(head);
        deleteList(head);
        ///* Use push_back() to construct below list 1->4->6->12->15 */
        Node *h = NULL;
        push_back(&h, 1);
        push_back(&h, 4);
        push_back(&h, 6);
        push_back(&h, 12);
        push_back(&h, 15);
        printList(h);
        ///* Use push_front() to construct below list 15->12->6->4->1 */
        Node *h2 = NULL;
        push_front(&h2, 1);
        push_front(&h2, 4);
        push_front(&h2, 6);
        push_front(&h2, 12);
        push_front(&h2, 15);
        printList(h2);
        ///*12->6->3->1*/
        ListNode *h3;
        push_front_listnode(&h3, 1);
        push_front_listnode(&h3, 3);
        push_front_listnode(&h3, 6);
        push_front_listnode(&h3, 12);
        //printListNode(h3);
        //reverseList(&h3);
        //printListNode(h3);
        //reverseList1(&h3);
        //printListNode(h3);
        //h3 = reverseList2(h3);
        //printListNode(h3);
        //h3 = reverseListRcursive(h3);
        //printListNode(h3);
    }
    /*Stack test*/
    MyStack *sq = new MyStack();
    int Q = 5;
    while(Q--){
    /*5->4->3->2->1*/
    sq->push(Q);
    }
    cout<<"MyStack pop:"<<sq->pop()<<" ";
    cout<<endl;

    StackNode* root;
    StackNode* sn = new StackNode;
    sn->push(&root, 10);
    sn->push(&root, 20);
    sn->push(&root, 30);

    cout << sn->pop(&root) << " popped from stack\n";

    cout << "Top element is " << sn->peek(root) << endl;

    NodeBST *rootBST;
    NodeBST *tmpBST;
    rootBST = NULL;
    int N = 5;

    for(int i=0;i<N;i++)
    {
        //int k;

        insert(&rootBST, i);
    }
    int r = 4;
    inorder(rootBST);
    cout<<endl;
    rootBST = deleteNode(rootBST,r);
    inorder(rootBST);
    cout<<endl;
    vector<int> v = {2, 7, 11, 15};
    cout<<"two sum:"<<endl;
    printv(twoSum(v, 9));
    cout<<"Add Two Number:"<<endl;
    ListNode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    //p1: 2->4->3
    push_back_listnode(&p1, 2);
    push_back_listnode(&p1, 4);
    push_back_listnode(&p1, 3);

    printListNode(p1);
    //p2: 5->6->4
    push_front_listnode(&p2, 4);
    push_front_listnode(&p2, 6);
    push_front_listnode(&p2, 5);
    printListNode(p2);
    p3 = addTwoNumbers(p1, p2);
    printListNode(p3);

    cout<<"lengthOfLongestSubstring 1:"<< lengthOfLongestSubstring("abcabcbb")<<endl;
    cout<<"lengthOfLongestSubstring 2:"<< lengthOfLongestSubstring("dvdf")<<endl;

    cout<<"longestPalindrome:"<<LongestPalindromicSubstring("babad")<<endl;
    return 0;
}