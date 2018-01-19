//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// File:  eaaray.h
// Author :elonkou
// E-mail :elonkou@ktime.cc
// Date   :Thu 18 Jan 2018 11:51:24 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include "types.h"		//相关类型定义文件

typedef struct {
	Int data[10];
	int size = 10;
}Array;

status print(Array arr){
	for (int i=0;i<arr.size;i++){
		print("\t%d",arr[i]);
		if(i%10 == 0){
			printf("\n");
		}
	}
	return OK;
}
