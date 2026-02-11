#include <stdio.h>
int invert(int a);
int prime(int a);
int main(void){
	for (int i = 3; i <= 10000; i++){
		int re_i = invert(i);
		if (prime(i) && prime(re_i)) printf("%dÊÇÄæËØÊý\n", i);
	}
	char c;
	while ((c = getchar()) != '\n');
	return 0;
}
int invert(int a){
	int x, y = 0;
	while (a){
		x = a % 10;
		a /= 10;
		y = y * 10 + x;
	}
	return y;
}
int prime(int a){
	for (int i = 2; i <= a / 2; i++){
		if (a%i == 0){
			return 0;
		}
	}
	return 1;
}