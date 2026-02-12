#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
#define str_len 30
//me:建立字符串数组s，将字符串输入到s；进行冒泡排序，并使用字符串比较函数进行比较，满足条件就交换位置。
void sortstring(char* str[], int n);//char* str[]等价于char** str，str是指向指针的指针变量，用来接收指针数组的首地址，int a[]等价于int* a，也是同样的道理
int main(void){
	int n;
	char* str[max];//指针数组，需动态分配内存              char *s[5] = { "晒网", "打鱼", "打鱼", "打鱼", "晒网" };不需要分配，编译的时候“晒网”...已经有内存了，
	printf("请输入字符串个数：");
	scanf_s("%d", &n);                                       //然后会把其首地址存入s[0]
	while (getchar() != '\n'); //吸收换行符'\n'
	printf("请输入字符串：");
	for (int i = 0; i < n; i++){
		str[i] = (char*)malloc(str_len*sizeof(char));//动态分配内存！！！
		scanf_s("%s", str[i], str_len);
	}
	sortstring(str, n);
	printf("排序后的结果为：");
	for (int i = 0; i < n; i++){
		fprintf(stdout, "%s\n", str[i]);
		free(str[i]);  // 释放内存
	}
	system("pause");
	return 0;
}
void sortstring(char* str[], int n){
	for (int i = 0; i < n - 1; i++){
		int flag = 0;
		for (int j = 0; j < n - i - 1; j++){
			if (strcmp(str[j], str[j + 1])<0){
				char* temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
				flag = 1;
			}
		}
		if (flag == 0) break;
	}
}
