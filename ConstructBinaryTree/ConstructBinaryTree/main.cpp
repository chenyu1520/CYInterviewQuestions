//
//  main.cpp
//  ConstructBinaryTree
//
//  Created by chenyu on 2016/12/8.
//  Copyright © 2016年 ChenYu. All rights reserved.
//

#include <iostream>
#include <string>
#include "BinaryTree.hpp"

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0) {
        return NULL;
    }
    
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

BinaryTreeNode* ConstructCore(
    int* startPreorder, int* endPreorder,
    int* startInorder, int* endInorder
)
{
    //创建根节点
    int rootValue = startPreorder[0];
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;
    
    //判断是否只有一个节点
    if (startPreorder == endPreorder) {
        if (startInorder == endInorder && *startPreorder == *startInorder) {
            return root;
        } else {
            throw __cpp_exceptions;
        }
    }
    
    //在中序遍历中确定根节点的位置
    int* rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue) {
        ++rootInorder;
    }
    
    //判断在中序遍历数组中找到的是否是合法的根节点
    if (rootInorder == endInorder && *rootInorder != rootValue) {
        throw __cpp_exceptions;
    }
    
    //计算前序遍历中左子树的长度
    int leftLength = int(rootInorder - startInorder);
    //查找前序遍历中左子树的最后一个指针
    int* leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0) {
        //构建左子树
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1);
    }
    
    if (leftLength < endPreorder - startPreorder) {
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder);
    }
    
    return root;
}

// ====================测试代码====================
void Test(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);
    
    printf("The preorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", preorder[i]);
    printf("\n");
    
    printf("The inorder sequence is: ");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");
    
    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);
        
        DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

// 普通二叉树
//              1
//           /     \
//          2       3
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};
    
    Test("Test1", preorder, inorder, length);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Test1();
    return 0;
}
