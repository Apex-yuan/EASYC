//++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// FileName: eaaray.c	-- 动态数组的实现
// Author  : elonkou
// E-mail  : elonkou@ktime.cc
// Date    : Thu 18 Jan 2018 11:51:18 PM CST
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <stdio.h>
#include <stdlib.h>
#include "Array.h"		// 引入库函数

int main(int argc,char **argv){
	// 该函数用于Array库的测试
	int number = 666;		// 需要添加的数据

	
	// 使用案例,具体功能未被实现
	Array arr = InitArray();// 初始化动态数组
	//arrayAdd(arr,number);	// 添加元素到数组中
	PrintArray(arr,8);			// 打印数组所有元素,按照每行长度为5输出,默认为16
    status state = InsertArray(arr,99,4);
	
    PrintArray(arr,8);			// 打印数组所有元素,按照每行长度为5输出,默认为16
    state = InsertArray(arr,66,3);
	PrintArray(arr,16);			// 打印数组所有元素,按照每行长度为5输出,默认为16
    
    //state = InsertArray(arr,99,16);
	//PrintArray(arr,16);			// 打印数组所有元素,按照每行长度为5输出,默认为16
	return 0;
}

