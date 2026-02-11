#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
	int id;
	char name[100];
	float score[3];
	float ave;
};
void Input(struct student s[]);
void Sort(struct student s[], int n);
void Print(struct student s[]);
int main(void){
	struct student s[5];
	Input(s);
	int n = 5;
	Sort(s, n);
	Print(s);
	system("pause > nul");
	return 0;
}
void Input(struct student s[]){
	for (int i = 0; i < 5; i++){
		printf("输入第%d个学生的信息：\n", i + 1);
		printf("学号：");
		scanf_s("%d", &s[i].id);
		//while (getchar() != '\n');//清除缓冲区
		printf("姓名：");
		scanf_s("%s", s[i].name,100);//vs对于字符串的输入需要指定长度
		//while (getchar() != '\n');
		printf("成绩：");
		scanf_s("%f%f%f", &s[i].score[0], &s[i].score[1], &s[i].score[2]);
		s[i].ave = (s[i].score[0] + s[i].score[1] + s[i].score[2]) / 3.0f;// ave是单精度浮点数，因此必须是3.0f,不能是3.0（默认double)
		printf("平均成绩：%f", s[i].ave);
		printf("\n");//每输入一个学生的信息就换行,两个print之间不换行
	}
}
void Sort(struct student s[],int n){
	for (int i = 0; i < n - 1; i++){
		int flag = 1;
		for (int j = 0; j < n - i - 1; j++){
			if (s[j].ave < s[j + 1].ave){
				struct student temp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag) break;
	}
}
void Print(struct student s[]){
	printf("\n---学生成绩表信息---：\n");
	for (int i = 0; i < 5; i++){
		printf("学生%d:\n", i + 1);
		printf("  学号: %d\n", s[i].id);
		printf("  姓名: %s\n", s[i].name);
		printf("  成绩: %.1f, %.1f, %.1f\n",s[i].score[0], s[i].score[1], s[i].score[2]);
		printf("  平均分: %.2f\n",s[i].ave);
		printf("\n");
	}
}