#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isworking(int a[], int year, int month, int day);
char model(int days);
int isrear(int year);
int main(void){
	int a[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, year, month, day;
	printf("请输入年、月、日：");
	scanf_s("%d%d%d", &year, &month, &day);
	int days=isworking(a, year, month, day);
	char s[5] = { "打鱼", "打鱼", "打鱼", "晒网", "晒网" };
	printf(s[days % 5]);
	
}
int isrear(year){
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		return 1;
	}
	else
	{
		return 0;
	}
}
int isworking(int a[], int year, int month, int day){
	int days = 0;
	for (int i = 1990; i < year; i++){
		if (isrear(i)){
			days += 366;
		}
		else
		{
			days += 365;
		}
	}
	for (int j = 1; j < month; j++){
		if (j == 2 && (isrear(year)){
			days += 29;
		}else{
			days += a[j];
		}
	}
	return days + day;
}
	
}