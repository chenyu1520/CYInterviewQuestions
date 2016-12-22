//
//  main.cpp
//  47_AddTwoNumbers
//
//  Created by Yu Chen on 2016/12/22.
//  Copyright © 2016年 Yu Chen. All rights reserved.
//

//不使用+，-，*，／计算两个数相加

#include <iostream>

int Add(int num1, int num2) {
    int sum,carry;
    do {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        
        num1 = sum;
        num2 = carry;
    } while (carry != 0);
    
    return sum;
}

// ====================测试代码====================
void Test(int num1, int num2, int expected)
{
    int result = Add(num1, num2);
    if(result == expected)
        printf("%d + %d is %d. Passed\n", num1, num2, result);
    else
        printf("%d + %d is %d. Failed\n", num1, num2, result);
}

int main(int argc, const char * argv[]) {
    Test(1, 2, 3);
    Test(111, 899, 1010);
    
    Test(-1, 2, 1);
    Test(1, -2, -1);
    
    Test(3, 0, 3);
    Test(0, -4, -4);
    
    Test(-2, -8, -10);
    return 0;
}
