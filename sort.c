#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define max 100
#define str_len 30

void sortstring(char* str[], int n);

int main(void) {
	int n;
	char* str[max];

	printf("请输入字符串个数：");
	scanf_s("%d", &n);
	while (getchar() != '\n'); // 清空输入缓冲区

	printf("请输入字符串：\n");
	for (int i = 0; i < n; i++) {
		str[i] = (char*)malloc(str_len * sizeof(char));
		if (str[i] == NULL) {
			printf("内存分配失败！\n");
			return 1;
		}
		fgets(str[i], str_len, stdin);  // ✅ 安全输入
		// 去掉 fgets 自带的换行符
		str[i][strcspn(str[i], "\n")] = '\0';
	}

	sortstring(str, n);

	printf("排序后的结果为：\n");
	for (int i = 0; i < n; i++) {
		printf("%s\n", str[i]);
		free(str[i]);  // 释放内存
	}

	system("pause");
	return 0;
}

// 冒泡排序（升序）
void sortstring(char* str[], int n) {
	char* temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (strcmp(str[j], str[j + 1]) > 0) {  // >0 升序
				// 交换指针（高效）
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
}