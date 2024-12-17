#ifndef _COUNTER_H
#define _COUNTER_H
#include "init.h"
#include <stdio.h>

void parseFile(FILE *fp, WeightType *count, WeightType *FileLength);//parse the file and count the frequency of each character

void parseFile( FILE *fp, // input file 
                WeightType *count, // count the frequency of each character
                WeightType *FileLength // count the length of the file
                ){
    CharType ch;
    //TODO: parse the file and count the frequency of each character
    if (fp == NULL || count == NULL || FileLength == NULL) {
        return; // 检查指针有效性
    }
    *FileLength = 0; // 初始化文件长度

    // 解析文件并统计每个字符的频率
    while (fread(&ch, 1, 1, fp) == 1) {
        count[ch]++;
        (*FileLength)++; // 增加文件长度计数
    }
}
#endif