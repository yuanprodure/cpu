#include <stdio.h>
#include <string.h>
/*  双指针（i向后探寻重复字符，j始终停在下一个不重复字符应该插入的位置
void squeeze(char s[], char c) {
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != c) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}*/


void squeeze(char s[], char c){
	int n = strlen(s);
	for (int i = 0; i < n; i++){                                                      
		if (s[i] == c){
			for (int j = i; j < n - 1; j++){
				s[j] = s[j + 1];
			}
			n--;//用于最后的 s[n]='\0'
			i--;//防止露字母，因为后面的字符前移了
		}
		/*错误，如果放这里，不是重复字母也会--，逻辑错误
		n--;用于最后的 s[n]='\0'
		i--;防止露字母，因为后面的字符前移了
		*/
	}
	s[n] = '\0';
}

int main(void){
	char a[] = "squeeze";
	char c = 'e';
	squeeze(a, c);
	printf("去重后的字符为：%s", a);
	while (getchar() != '\n');
	return 0;
}