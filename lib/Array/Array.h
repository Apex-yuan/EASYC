#include <stdio.h>
#include <stdlib.h>
#include "types.h"	              	//相关类型定义文件

#ifndef ARRAY_INFO
    #define ARRAY_INIT_SIZE 16      // 定义了动态数组的基本大小
    #define ARRAY_ADD_SIZE  16      // 定义了动态数组的性增加大小
#endif

typedef struct{
	int size;                   // 数组的长度
    int max_size;               // 数据的最大长度
    int last_pos;               // 记录写入或者删除的位置
	Int *data;                  // 核心存储数据
}*Array,array;


Array InitArray();
status IsFull(Array arr);
Array NewArray(Array arr,int newsize);
status InsertArray(Array arr,Int data,int pos);
void PrintArray(Array arr,int width);


//#include "Array.c"
