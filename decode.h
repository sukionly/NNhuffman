#ifndef _DECODE_H
#define _DECODE_H
#include "init.h"
#include <stdio.h>

void decodeFile(FILE *fp, FILE *out, HTNode *HT, int NLeaf);

void decodeFile(FILE *in, 
                FILE *out, 
                HTNode *HT, // Huffman Tree 
                int NLeaf 
                ){
    // TODO: decode the file
    CharType ch;
    HTNode Current = HT[NLeaf*2-2];
    while (fread(&ch, sizeof(CharType), 1, in) == 1) {
        for (int i = 7; i >= 0; i--) {
            if ((ch >> i) & 1) {
                Current = HT[Current.RChild];
            } else {
                Current = HT[Current.LChild];
            }
            if(Current.LChild == -1 && Current.RChild == -1){
                fputc(Current.ch, out);
                Current = HT[NLeaf*2-2]; // reset the current node to the root
            }
        }
    }
    
}
#endif