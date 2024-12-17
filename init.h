#ifndef _INIT_H
#define _INIT_H
#include<stdio.h>
#include<stdlib.h>

typedef unsigned long int WeightType;
typedef unsigned char CharType;

typedef struct{
    CharType ch;
    WeightType weight;
    int idx, parent, LChild, RChild;
}HTNode; // huffman tree node, 一共六个成员变量

#define NChar 256

#endif