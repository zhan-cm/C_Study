#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node//����һ���ṹ�� 
{
	int data;
	struct node* next;
 } Node;


//��ʼ�������� 
Node* InitList(){
	Node* head =(Node*)malloc(sizeof(Node));
	head->data=0;
	head->next=NULL;
	return head;
} 
//������-ͷ�巨 
int insertHead(Node* L,int e){
	Node* p = (Node*)malloc(sizeof(Node));
	p->data=e;
	p->next=L->next;
	L->next=p; 
	return 1;
}
//��������
void printList(Node* L){
	//Node* p=L;-------����д�Ļ�
	//��һ�α���p->data ����Ľṹʽͷ�ڵ��dataֵ�����Բ�Ҫ�������� 
	Node* p=L->next;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
} 
//������-β�巨--�ҵ�β�ڵ� 
Node* get_tail(Node* L){
	Node* p =L;
	while(p->next!=NULL){
		p=p->next;
	}
	return p;
}
//������-β�巨 
Node* insertTail(Node* tail,int e){
	Node* p = (Node*)malloc(sizeof(Node));
	p->data=e;
	tail->next=p;
	p->next=NULL;
	return p;
} 
//������-��ָ��λ�ò�������
int insertNode(Node* L,int pos,int e){
	//���ҵ�Ҫ����λ�õ�ǰһ��
	Node* p=L;
	int i=0;
	while(i<pos-1){
		p=p->next;
		i++;
		if(p==NULL){
			return 0;
		}
	} 
	Node* q = (Node*)malloc(sizeof(Node));
	q->data=e;
	q->next=p->next;
	p->next=q;
	return 1;
} 
//������-ɾ���ڵ�
int deleteNode(Node* L,int pos){
	Node* p=L;
	int i=0;
	while(i<pos-1){
		p=p->next;
		i++;
		if(p==NULL){
			return 0;
		}
	}
	if(p->next==NULL){
		return 0;
	}
	Node* q= p->next;
	p->next=q->next;
	free(q);
	return 1;
} 
//������-��ȡ������-����ͷ�ڵ� 
int  Nodelen(Node* L){
	Node* p =L;
	int len = 0;
	while(p!=NULL){
		p=p->next;
		len++;
	} 
	return len;
} 
//������-�ͷ�����
void freeList(Node* L){
	Node* p = L->next;
	Node* q;
	while(p!=NULL){
		q=p->next;
		free(p);//��һ���ͷŵ���L->next����ŵĵ�ַ�����Ұָ�� 
		p=q;
	}
	L->next=NULL;//������Ҫ���¸�ֵNULL 
} 
//������-ʹ��˫ָ���ҵ�������k���ڵ�--����ָ��˼�� 
int findNodeFS(Node* L,int k){
	Node* fast=L;
	Node* slow=L;
	for(int i=0;i<k;i++){
		fast=fast->next;
	}
	while(fast!=NULL){
		fast=fast->next;
		slow=slow->next;
	}
	printf("������%d���ڵ��ֵΪ��%d\n",k,slow->data);
} 
//������-ɾ������ֵ��ͬ�Ľڵ� 
int removeNode(Node* L,int n){
	Node* p = L;
	int index;//��Ϊ�����±�ʹ��
	int* q=(int*)malloc(sizeof(int)*(n+1));
	 
	//��ʼ������--��ÿһ��Ԫ�ص���ֵ0 
	for(int i=0;i<n+1;i++){
		*(q+i)=0;
	}
	while(p->next!=NULL){
		index=abs(p->next->data);
		if(*(q+index)==0){
			*(q+index)=1;
			p=p->next;
		}else{
			Node* nb = p->next;
			p->next=nb->next;
			free(nb);
		}
	}
	free(q);
}
//������-��ת���� --��ָ������ 
Node* reverseList(Node* L){
	Node* first=NULL;
	Node* second=L->next;
	Node* third;
	while(second!=NULL){
		Node* third=second->next;
		second->next=first;
		first=second;
		second=third;
		
	}
	Node* newhead = InitList();
	newhead->next=first;
	
	return newhead;
}
//������-ɾ�������м�ڵ�--���ÿ���ָ��˼��-��ָ����������ָ����һ����ֱ����ָ��ָ��NULL 
int deletemidList(Node* L){
	Node* fast=L->next;
	Node* slow=L;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	Node* p= slow->next;
	slow->next=p->next;
	free(p);
	return 1;
} 	
//������-��������
void reOrderList(Node* head){
	Node* fast= head->next;
	Node* slow= head;
	while(fast!=NULL&&fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	Node* first=NULL;
	Node* second=slow->next;
	slow->next=NULL;
	Node* third=NULL;
	while(second!=NULL){
		third = second->next;
		second->next = first;
		first = second;
		second=third;
	}
	Node* p1=head->next;
	Node* q1 = first;
	Node *p2,*q2;
	while(p1!=NULL&&q1!=NULL){
		p2=p1->next;
		q2=q1->next;
		
		p1->next=q1;
		q1->next=p2;
		
		p1=p2;
		q1=q2;
	}
	
} 
int main(void)
{
	Node* list = InitList();
	Node* tail = get_tail(list); 
	//insertHead(list,20);
	//insertHead(list,30);
	tail = insertTail(tail,21);
	tail = insertTail(tail,-15);
	tail = insertTail(tail,-15);
	tail = insertTail(tail,7);
	tail = insertTail(tail,15);
	tail = insertTail(tail,60);
	tail = insertTail(tail,70);
	/*
	printList(list);
	printf("\n");
	insertNode(list,2,15);
	printList(list);
	printf("\n");
	deleteNode(list,2);
	printList(list);
	printf("\n");
	printf("%d\n",Nodelen(list));
	freeList(list);
	printf("%d\n",Nodelen(list));
	*/
	/*
	printList(list);
	findNodeFS(list,3);
	*/
	printList(list);
	printf("\n");
	removeNode(list,21);
	printList(list); 
	printf("\n");
	
	Node* reverse = reverseList(list);
	printList(reverse);
	
	return 0;
}

