//
//  main.cpp
//  10_NumberOf1InBinary
//
//  Created by chenyu on 2016/12/18.
//  Copyright © 2016年 ChenYu. All rights reserved.
//

#include <iostream>

//错误的写法，输入负数会导致死循环
int NumberOf1_Solution1(int n) {
    int count = 0;
    while (n) {
        if ((n & 1) == 1) {
            count++;
        }
        
        n = n >> 1;
    }
    
    return count;
}

int NumberOf1_Solution2(int n) {
    int count = 0;
    int flag = 1;
    while (flag) {
        if (n & flag) {
            count++;
        }
        
        flag = flag << 1;
    }
    
    return count;
}

//遍历次数最少的写法
int NumberOf1_Solution3(int n) {
    int count = 0;
    while (n) {
        ++count;
        n = (n - 1) & n;
    }
    
    return count;
}

void Test(int number, unsigned int expected)
{
    int actual = NumberOf1_Solution2(number);
    if(actual == expected)
        printf("Solution2: Test for %d passed.\n", number);
    else
        printf("Solution2: Test for %d failed.\n", number);
    
    actual = NumberOf1_Solution3(number);
    if(actual == expected)
        printf("Solution3: Test for %d passed.\n", number);
    else
        printf("Solution3: Test for %d failed.\n", number);
    
    printf("\n");
}

int main(int argc, const char * argv[]) {
    // 输入0，期待的输出是0
    Test(0, 0);
    
    // 输入1，期待的输出是1
    Test(1, 1);
    
    // 输入10，期待的输出是2
    Test(10, 2);
    
    // 输入0x7FFFFFFF，期待的输出是31
    Test(0x7FFFFFFF, 31);
    
    // 输入0xFFFFFFFF（负数），期待的输出是32
    Test(0xFFFFFFFF, 32);
    
    // 输入0x80000000（负数），期待的输出是1
    Test(0x80000000, 1);
    return 0;
}
