#include <stdio.h>
#include <stdlib.h>
int peaches(int n){
	if (n == 10){
		return 1;
	}
	else
	{
		return (peaches(n + 1) + 1) * 2;
	}
}
int main(void){
	int nums=peaches(1);
	printf("ºï×ÓÕªÌÒÊıÊÇ£º%d", nums);
	system("pause");
}