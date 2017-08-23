//
//  main.cpp
//  26_StrPermutation
//
//  Created by chenyu on 2017/8/23.
//  Copyright © 2017年 chenyu. All rights reserved.
//

#include <iostream>

void permutation(char* pStr, char* pBegin) {
    if (*pBegin == '\0') {
        printf("%s\n",pStr);
    } else {
        for (char* pCh = pBegin; *pCh != '\0'; ++pCh) {
            //交换其他字符到第一个字符的位置
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            
            //固定第一个字符，剩余字符做全排列
            permutation(pStr, pBegin + 1);
            
            //做完全排列后交换回来
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }
    }
}

void permutation(char* pStr) {
    if (pStr == NULL) {
        return;
    }
    
    permutation(pStr, pStr);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char pStr[] = "abcd";
    permutation(pStr);
    return 0;
}
