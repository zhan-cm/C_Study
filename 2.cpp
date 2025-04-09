#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *prev,*next;
 }Node;
 //˫������-ͷ�巨
int insertHead(Node* L,int e){
	Node* p =(Node*)malloc(sizeof(Node));
	p->data=e;
	p->prev=L;
	p->next=L->next;
	if(L->next!=NULL){
		L->next->prev=p;
	}
	L->next=p;
	return 1;
} 
//˫������-β�巨
Node* insertTail(Node* tail,int e){
	Node *p = (Node*)malloc(sizeof(Node));
	p->data=e;
	p->prev=tail;
	tail->next=p;
	p->next=NULL;
	return p;
} 
//˫������-��ָ��λ�ò�������
void insertNode(Node* L,int pos,int e){
	Node* p = (Node*)malloc(sizeof(Node));
	p->data=e;
	for(int i=0;i<pos-1;i++){
		L=L->next;
		if(L==NULL){
			return;
		}
	}
	p->prev=L;
	p->next=L->next;
	L->next->prev=p;
	L->next=p;
	return;
} 
//˫������-ɾ���ڵ�
int deleteNode(Node* L,int pos){
	Node* p=L;
	Node* q;
	for(int i=0;i<pos-1;i++){
		p=p->next;
		if(p==NULL||p->next==NULL){
			return 1;
		}
	}
	q=p->next;
	p->next=q->next;
	q->next->prev=p;
	free(q);
} 
 int main(void){
 	
 }
