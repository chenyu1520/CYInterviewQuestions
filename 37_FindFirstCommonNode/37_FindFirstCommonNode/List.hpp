//
//  List.hpp
//  37_FindFirstCommonNode
//
//  Created by Yu Chen on 2016/12/22.
//  Copyright © 2016年 Yu Chen. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};

ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintListNode(ListNode* pNode);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void AddToTail(ListNode** pHead, int value);
void RemoveNode(ListNode** pHead, int value);

#endif /* List_hpp */
