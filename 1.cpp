#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct node//定义一个结构体 
{
	int data;
	struct node* next;
 } Node;


//初始化单链表 
Node* InitList(){
	Node* head =(Node*)malloc(sizeof(Node));
	head->data=0;
	head->next=NULL;
	return head;
} 
//单链表-头插法 
int insertHead(Node* L,int e){
	Node* p = (Node*)malloc(sizeof(Node));
	p->data=e;
	p->next=L->next;
	L->next=p; 
	return 1;
}
//遍历链表
void printList(Node* L){
	//Node* p=L;-------这样写的话
	//第一次遍历p->data 输出的结构式头节点的data值，所以不要那样定义 
	Node* p=L->next;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
} 
//单链表-尾插法--找到尾节点 
Node* get_tail(Node* L){
	Node* p =L;
	while(p->next!=NULL){
		p=p->next;
	}
	return p;
}
//单链表-尾插法 
Node* insertTail(Node* tail,int e){
	Node* p = (Node*)malloc(sizeof(Node));
	p->data=e;
	tail->next=p;
	p->next=NULL;
	return p;
} 
//单链表-在指定位置插入数据
int insertNode(Node* L,int pos,int e){
	//先找到要插入位置的前一个
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
//单链表-删除节点
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
//单链表-获取链表长度-包含头节点 
int  Nodelen(Node* L){
	Node* p =L;
	int len = 0;
	while(p!=NULL){
		p=p->next;
		len++;
	} 
	return len;
} 
//单链表-释放链表
void freeList(Node* L){
	Node* p = L->next;
	Node* q;
	while(p!=NULL){
		q=p->next;
		free(p);//第一次释放掉的L->next所存放的地址变成了野指针 
		p=q;
	}
	L->next=NULL;//所以需要重新赋值NULL 
} 
//单链表-使用双指针找到倒数第k个节点--快慢指针思想 
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
	printf("倒数第%d个节点的值为：%d\n",k,slow->data);
} 
//单链表-删除绝对值相同的节点 
int removeNode(Node* L,int n){
	Node* p = L;
	int index;//作为数组下标使用
	int* q=(int*)malloc(sizeof(int)*(n+1));
	 
	//初始化数组--让每一个元素到赋值0 
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
//单链表-反转链表 --三指针运作 
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
//单链表-删除链表中间节点--运用快慢指针思想-快指针走两步慢指针走一步，直到快指针指向NULL 
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
//单链表-重新排序
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

