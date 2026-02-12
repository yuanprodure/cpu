#include <stdio.h>
#include <stdlib.h>
#define N 10
struct node
{
	int data;
	struct node* next;
}*h1=NULL,*h2=NULL;
void split(){
	//创建链表
	struct node* p;
	for (int i = 0; i < N; i++){
		p = (struct node*)malloc(sizeof(struct node));
		p->data = i + 1;
		p->next = h1;
		h1 = p;
	}
	//打印最初的链表
	while (p != NULL){
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
	//分解
	p = h1;//复位，while时弄到null了
	struct node* prev = NULL;//记录q的前驱，以便删除
	struct node* tailb = NULL;
	//struct node* h2 = NULL;错误，全局已经有h2=NULL
	int pos = 1;
	while (p != NULL){
		if (pos % 2 == 1){
			prev = p;
			p = p->next;
		}
		else
		{
			prev->next = p->next;//断开偶节点
			struct node* next = p->next;//保存下个节点
			p->next = NULL;
			if (h2 == NULL){
				h2 = tailb = p;
			}
			else{
				tailb->next = p;
				tailb = p;
				tailb->next = NULL;
				p = next;//错误!if语句里的p未更新
			}
			p = next;
		}
		pos++;
	}
	printf("分解后的h1（奇数位置）：");
	struct node *q = h1;
	while (q != NULL) {
		printf("%d ", q->data); // 用q->data，不是p->data！
		q = q->next;
	}
	printf("\n");

	// ========== 5. 打印分解后的h2（偶数位置：2→4→6→8→10） ==========
	printf("分解后的h2（偶数位置）：");
	q = h2;
	while (q != NULL) {
		printf("%d ", q->data); // 用q->data，不是p->data！
		q = q->next;
	}
	printf("\n");
}
int main(void){
	split();
	system("pause");
	return 0;
}
