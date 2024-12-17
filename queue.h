/*
    实现一个HTNode结构体的队列操作，以便构建哈夫曼树
*/
#ifndef _QUEUE_H
#define _QUEUE_H
#include "init.h"

typedef struct{
    int tag; // 0: empty, 1: not empty
    int front;
    int rear;
    int length;
    HTNode elem[NChar];
}Queue; // huffman node queue

int InitQueue(Queue *Q);
int InQueue(Queue *Q, HTNode x); // 入队
int outQueue(Queue *Q, HTNode *x); // 出队

int InitQueue(Queue *Q){
    if(!Q)
        return 1;
    Q->tag = 0;
    Q->front = Q->rear = 0;
    Q->length = 0;
    return 0;
}

int InQueue(Queue *Q, HTNode x){
    if(Q->front == Q->rear && Q->tag == 1)
        return 1;
    Q->elem[Q->rear] = x;
    Q->rear = (Q->rear + 1) % NChar;
    Q->length++;
    Q->tag = 1;
    return 0;
}

int outQueue(Queue *Q, HTNode *x){
    if(Q->tag == 0)
        return 1;
    *x = Q->elem[Q->front];
    Q->length--;
    Q->front = (Q->front + 1) % NChar;
    if(Q->front == Q->rear)
        Q->tag = 0;
    return 0;
}
#endif