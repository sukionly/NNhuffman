#include "counter.h"
#include "encode.h"
#include "decode.h"

int main(){
    int i;
    // 修改为你的文件名
    FILE *fp = fopen("File\\test.jpg", "rb");
    FILE *out = fopen("tmpFile.txt.huf", "wb");
    if (fp == NULL) {
        printf("无法打开输入文件\n");
    }
    if (out == NULL) {
        printf("无法创建输出文件");
        fclose(fp);
        return -1;
    }

    // 统计文件中每个字符出现的次数
    WeightType count[NChar] = {0};
    WeightType FileLength = 0;
    parseFile(fp, count, &FileLength);

    // 对字符按出现次数排序
    CharType order[NChar];
    sort(count, order);
   
    // 哈夫曼树
    int NNode = 0, NLeaf = 0;
    // TODO: 计算NNode和NLeaf，即哈夫曼树的节点数和叶子节点数
    for(i = 0; i < NChar; i++){
        if(count[order[i]] > 0){
            NLeaf++;
        }
    }
    NNode = NLeaf * 2 - 1;


    // 构建哈夫曼树，以数组形式存储
    HTNode HT[NNode];
    createHT(HT, count, order, NLeaf);

    // 获取哈夫曼编码
    CharType HCode[256][256]; //[1] 存储符号，[2] 存储编码长度，[3] 存储编码

    getHCode(HT, HCode, NLeaf);

    fseek(fp, 0, SEEK_SET);

    // 压缩文件
    encodeFile(fp, out, HCode);
    fclose(fp);
    fclose(out);

    // 解压文件
    FILE *out1 = fopen("tmpFile.txt.huf", "rb");
    FILE *out2 = fopen("outputFile", "wb");
    decodeFile(out1, out2, HT, NLeaf);
    fclose(out1);
    fclose(out2); 
    return 0;
}