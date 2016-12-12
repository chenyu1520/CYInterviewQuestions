//
//  main.cpp
//  08_MinNumberInRotatedArray
//
//  Created by chenyu on 2016/12/12.
//  Copyright © 2016年 ChenYu. All rights reserved.
//

#include <iostream>
#include <exception>

int MinInOrder(int *numbers, int index1, int index2) {
    int result = numbers[index1];
    for (int i = index1 + 1; index1 <= index2; index1++) {
        if (result > numbers[i]) {
            result = numbers[i];
        }
    }
    
    return result;
}

int Min(int* numbers, int length) {
    if (numbers == NULL || length <= 0) {
        printf("输入有误");
    }
    
    int index1 = 0;
    int index2 = length - 1;
    int indexMin = index1;
    while (numbers[index1] >= numbers[index2]) {
        
        //判断两个位置相邻时，index2 所指的位置就是最小数
        if ((index2 - index1) == 1) {
            indexMin = index2;
            break;
        }
        
        indexMin = (index1 + index2) / 2;
        
        //如果 index1，indexMin，index2 三个位置所指的数字都相等，则无法区分 indexMin 在前面的子数组还是在后面的子数组，所以需要单独查找
        if (numbers[index1] == numbers[indexMin] == numbers[index2]) {
            return MinInOrder(numbers, index1, index2);
        }
        
        if (numbers[indexMin] >= numbers[index1]) {
            index1 = indexMin;
        }
        
        if (numbers[indexMin] <= numbers[index2]) {
            index2 = indexMin;
        }
    }
    
    return numbers[indexMin];
}



int main(int argc, const char * argv[]) {
    
    return 0;
}
