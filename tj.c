#include <stdio.h>
int isnotrepeat(n){
	int prev, cur;
	prev = n % 10;
	n /= 10;
	while (n>0)
	{
		cur = n % 10;
		if (prev == cur)
			return 0;
		prev = cur;//为了比较相邻数，将高位数cur直接给prev,这样就不用p再模n了；（精妙之处)
		n /= 10;
	}
	return 1;
}
unsigned int getnotreat(n){
	while (1){
		if (isnotrepeat(n))
			return n;
		n++;
	}
}
int main(void){
	int n;
	printf("请输入数字n：\n");
	scanf_s("%d", &n);
	printf("%d的最小不重复整数是：%d", n, getnotreat(n));
	char c;
	//while ((c = getchar()) != '\n');
	return 0;
}