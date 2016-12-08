//
//  BinaryTree.hpp
//  ConstructBinaryTree
//
//  Created by chenyu on 2016/12/8.
//  Copyright © 2016年 ChenYu. All rights reserved.
//
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 著作权所有者：何海涛

#ifndef BinaryTree_hpp
#define BinaryTree_hpp

#include <stdio.h>
#pragma once

struct BinaryTreeNode
{
    int                    m_nValue;
    BinaryTreeNode*        m_pLeft;
    BinaryTreeNode*        m_pRight;
};

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
void PrintTreeNode(BinaryTreeNode* pNode);
void PrintTree(BinaryTreeNode* pRoot);
void DestroyTree(BinaryTreeNode* pRoot);

#endif /* BinaryTree_hpp */
