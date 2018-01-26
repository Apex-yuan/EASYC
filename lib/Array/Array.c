//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  Array.c
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Thu 18 Jan 2018 11:51:24 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include "Array.h"

Array InitArray(){
    // 初始化一个动态数组,并且返回数组的指针
    Array arr = (Array)malloc(sizeof(array));
    arr->data = (Int*)malloc(sizeof(Int)*ARRAY_INIT_SIZE);
    arr->size = 0;
    // init the array data.
    //for(int i = 0;i<arr->size;i++){
        //arr->data[i] = 0;
    //}
    arr->max_size = ARRAY_INIT_SIZE;
    arr->last_pos = 0;
    return arr;
}

status IsFull(Array arr){
    int full = 0;
    if(arr->size >= arr->max_size){
        full = 1;
    }
    return full;
}

Array NewArray(Array arr,int newsize){
    // 如果数组越界,重新分配数组的地址
    // 返回新分配内存的数组指针
    // int newsize 为可选的参数
    //newsize = ((arr->max_size+newsize)/ARRAY_ADD_SIZE)*ARRAY_ADD_SIZE;
    newsize = ((ARRAY_ADD_SIZE+newsize)/ARRAY_ADD_SIZE)*ARRAY_ADD_SIZE;
    arr ->data = (Int*)realloc(arr->data,arr->max_size+newsize);
    for(int i = 0;i < newsize;i++){      // 对新添加的数据进行初始化
        arr->data[i+arr->max_size] = 0;
        printf("%d:",i+arr->max_size);
    }
    arr ->max_size += newsize;
    return arr;
}

status InsertArray(Array arr,Int data,int pos){
    // 接收传入的数据和位置,插入该参数
    // Array arr :为被操作的数组
    // Int data :为插入的元素
    // pos为新插入的元素的位置
    // pos若为0,则为继续在该数组上次操作的末尾进行操作
    int index = arr ->last_pos;     
    if(pos < 0){
        return T_OVERFLOW;
    }else if(pos > 0){
        index = pos;
    }
    // 检查数组是否越界并且对其进行重新分配内存
    if(IsFull(arr) || index >= arr->max_size){
        arr = NewArray(arr,index - arr->max_size+1);
    }
    if(index < arr->max_size){
        arr->data[index] = data;
        arr->size = (arr->size>index)?(arr->size):index+1;
    }else{
        return T_OVERFLOW;    // 重新分配内存失败
    }
    return T_OK;
}

void PrintArray(Array arr,int width){
    // 打印数组
    printf("\nArray-pos :%p\n",arr);
    printf("Array-apos :%p\n",arr->data);
    printf("Array-size:%d\n",arr->size);
    printf("Array-Maxs:%d\n",arr->max_size);
    printf("Array-data:\n\t{");
    if(arr->size != 0){
        printf("%d",arr->data[0]);
    }
    width = (width == 0)?ARRAY_INIT_SIZE:width;
	for (int i = 1;i < (arr->size);i++){
        printf(",%3d",arr->data[i]);
		if((i+1)%width == 0 && i!=0 && i!=arr->size-1){
			printf("\n\t");
		}
	}
    printf("}");
}
