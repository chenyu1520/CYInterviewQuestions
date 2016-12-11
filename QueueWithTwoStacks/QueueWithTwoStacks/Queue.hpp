//
//  Queue.hpp
//  QueueWithTwoStacks
//
//  Created by chenyu on 2016/12/10.
//  Copyright © 2016年 ChenYu. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#pragma once
#include <stdio.h>
#include <stack>
#include <exception>

using namespace std;

template <typename T>
class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    //在队列末尾插入元素
    void appendTail(const T& node);
    //删除队列头元素
    T deleteHead();
    
private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue(void)
{
}

template <typename T>
CQueue<T>::~CQueue(void)
{
}

template<typename T> void CQueue<T>::appendTail(const T& element)
{
    stack1.push(element);
}

template <typename T>
T CQueue<T>::deleteHead()
{
    if (stack2.size() <= 0) {
        if (stack1.size() > 0) {
            while (!stack1.empty()) {
                T& data = stack1.top();
                stack2.push(data);
                stack1.pop();
            }
        }
    }
    
    if (stack2.size() == 0) {
        throw exception();
    }
    
    T head = stack2.top();
    stack2.pop();
    
    return head;
}

#endif /* Queue_hpp */
