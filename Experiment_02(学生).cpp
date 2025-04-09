#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;
typedef int Status;		//Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType;	//ElemType 为可定义的数据类型，此设为int类型

typedef struct {
	//图书信息定义
	string id;		//ISBN
	string name;	//书名
	double price;	//定价
} Book;

typedef struct LNode {
	//图书信息表的链式存储结构
	Book data; 			//结点的数据域
	struct LNode *next; //结点的指针域
} LNode, *LinkList; 	//LinkList为指向结构体LNode的指针类型

string head_1, head_2, head_3;
int length; //链表的表长，即图书表中图书个数


Status InitList_L(LinkList &L) {
	//构造一个空的单链表L
	L = new LNode; //生成新结点作为头结点，用头指针L指向头结点
	L->next = NULL; //头结点的指针域置空
	return OK;
}

//（给出）
Status CreateList_R(LinkList &L, int n) { //后插法创建单链表
	/**************begin************/
	//正位序输入n个元素的值，建立带表头结点的单链表L
	LinkList p, r;
	L = new LNode;
	L->next = NULL; //先建立一个带头结点的空链表
	r = L; //尾指针r指向头结点
	length = 0;
	fstream file; //打开文件进行读写操作
	file.open("book.txt");
	if (!file) {
		cout << "未找到相关文件，无法打开！" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) { //将文件中的信息运用后插法插入到链表中
		p = new LNode;//生成新结点
		file >> p->data.id >> p->data.name >> p->data.price;//输入元素值赋给新结点*p的数据域
		p->next = NULL;
		r->next = p;//将新结点*p插入尾结点*r之后
		r = p;//r指向新的尾结点*p
		length++; //同时对链表长度进行统计
	}
	file.close();

	return OK;
	/**************end************/
}


// 2
Status Sort_L(LinkList &L) {
	//将图书按照价格降序排序
	/**************begin************/
	//空链表或者是只有一个节点则无需排序 
	if(!L||!L->next)return ERROR;
	LinkList p,q;
	Book temp;
	for(p=L->next;p!=NULL;p=p->next){
		for(q=p->next;q!=NULL;q=q->next){
			if(p->data.price<q->data.price){
				temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
	return OK;
	/**************end************/
}


// 3
Status AveRevise_L(LinkList &L) {
	//计算所有图书的平均价格并修改价格
	/**************begin************/
	if(!L||!L->next)return ERROR;
	
	double sum = 0.0;
    int count = 0;
    LinkList p = L->next;

    while (p) {
        sum += p->data.price;
        count++;
        p = p->next;
    }

    double average = sum / count;
    p = L->next;

    while (p) {
        if (p->data.price < average) {
            p->data.price *= 1.10;
        }
        p = p->next;
    }


	return OK;
	/**************end************/
}


// 4
Status Reverse_L(LinkList &L) {
	//逆置带头结点的单链表L
	/**************begin************/
	LNode* prev = NULL;
	LNode* curr = L->next;
	LNode* next = NULL;
	while(curr!=NULL){
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}


	return OK;
	/**************end************/
}


// 5
Status HighestPrice_L(LinkList L) {
	//查找价格最高的图书
	/**************begin************/
	if (!L || !L->next) return ERROR;
	LinkList p= L->next;
	LinkList maxNode = p;
	while(p){
		if(p->data.price > maxNode->data.price){
			maxNode=p;
		}
		p=p->next;
	}
	return OK;
	/**************end************/
}

// 6
Status FindFavorite_L(LinkList &L) {
	//查找的最爱图书
	/**************begin************/
	if(!L||!L->next)return ERROR;
	string favoriteName;
	cout<<"请输入你最喜欢的书名：";
	cin>>favoriteName;
	
	LinkList p = L->next;
	bool found = false;
	
	while(p){
		if(p->data.name==favoriteName){
			cout << "找到你最喜欢的图书:\n";
            cout << left << setw(15) << p->data.id << "\t"
                 << setw(20) << p->data.name << "\t"
                 << setw(10) << fixed << setprecision(2) << p->data.price << endl;
            found = true;
		}
		p=p->next;
	}
	if (!found) {
        cout << "未找到你最喜欢的图书。\n";
    }

	return OK;
	/**************end************/
}


// 7
Status Locate_L(LinkList L) {
	//查找最佳位置的图书
	/**************begin************/
	if (!L || !L->next) return ERROR; // 空链表或只有一个节点

    int mid = length / 2;
    LinkList p = L->next;

    for (int i = 0; i < mid; i++) {
        p = p->next;
    }

    cout << "最佳位置的图书信息:\n";
    cout << left << setw(15) << p->data.id << "\t"
         << setw(20) << p->data.name << "\t"
         << setw(10) << fixed << setprecision(2) << p->data.price << endl;
	return OK;
	/**************end************/
}


// 8
Status Insert_L(LinkList &L) {
	//将新图书入库
	/**************begin************/
	Book newBook;
    cout << "请输入新图书的ISBN: ";
    cin >> newBook.id;
    cout << "请输入新图书的书名: ";
    cin >> newBook.name;
    cout << "请输入新图书的价格: ";
    cin >> newBook.price;

    LinkList p = new LNode;
    p->data = newBook;
    p->next = L->next;
    L->next = p;

    length++; // 更新链表长度

	return OK;
	/**************end************/
}


// 9
Status Delete_L(LinkList &L) {
	//出库旧图书
	/**************begin************/
	if (!L || !L->next) return ERROR; // 空链表或只有一个节点

    string deleteId;
    cout << "请输入要删除的图书的ISBN: ";
    cin >> deleteId;

    LinkList p = L;
    while (p->next) {
        if (p->next->data.id == deleteId) {
            LinkList temp = p->next;
            p->next = temp->next;
            delete temp;
            length--; // 更新链表长度
            cout << "图书删除成功。\n";
            return OK;
        }
        p = p->next;
    }

    cout << "未找到该图书。\n";

	return OK;
	/**************end************/
}


// 10
Status DupRemoval_L(LinkList &L) {
	//图书去重
	/**************begin************/
	if (!L || !L->next) return ERROR; // 空链表或只有一个节点

    LinkList p = L->next;
    while (p) {
        LinkList q = p;
        while (q->next) {
            if (q->next->data.id == p->data.id) {
                LinkList temp = q->next;
                q->next = temp->next;
                delete temp;
                length--; // 更新链表长度
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }

	return OK;
	/**************end************/
}


//（给出）
Status Output_L(LinkList L) {
	//链表的输出
	/**************begin************/
	cout << "当前图书系统信息（链表）读出:\n";
	LinkList p = L->next;
	while (p) {
		cout << left << setw(15) << p->data.id << "\t"
		     << setw(20) << p->data.name << "\t"
		     << setw(10) << fixed << setprecision(2) << p->data.price << endl;
		p = p->next;
	}
	cout << endl;

	return OK;
	/**************end************/
}


int main() {
	int a, n, choose;
	double price;
	Book e;
	LinkList L;
	LNode *p;
	
	
	cout << "0. 创建\n";
	cout << "1. 输入\n";
	cout << "2. 排序\n";
	cout << "3. 修改\n";
	cout << "4. 逆序存储\n";
	cout << "5. 最贵图书查找\n";
	cout << "6. 最爱图书查找\n";
	cout << "7. 最佳位置图书查找\n";
	cout << "8. 新图书入库\n";
	cout << "9. 旧图书出库\n";
	cout << "10.图书去重\n";
	cout << "11.输出\n";
	cout << "-1.退出\n\n";

	choose = -10;
	while (choose != -1) {
		cout << "请选择:";
		cin >> choose;
		switch (choose) {
			case 0://建立一个单链表
				if (InitList_L(L))
					cout << "成功建立链表!\n\n";
				else
					cout << "链表建立失败!\n\n";
				break;
			case 1: // 图书信息表输入
				if (CreateList_R(L, length))
					cout << "图书信息输入成功\n\n";
				else
					cout << "图书信息输入失败\n\n";
				break;
			case 2://图书信息表排序
				if (Sort_L(L))
					cout << "图书信息表排序成功\n\n";
				else
					cout << "图书信息表排序失败\n\n";
				break;
			case 3://图书信息表修改
				if (AveRevise_L(L))
					cout << "图书信息表修改成功\n\n";
				else
					cout << "图书信息表修改失败\n\n";
				break;
			case 4://图书信息表逆序存储
				if (Reverse_L(L))
					cout << "图书信息表逆序存储成功\n\n";
				else
					cout << "图书信息表逆序存储失败\n\n";
				break;
			case 5://最贵图书的查找
				if (HighestPrice_L(L))
					cout << "最贵图书查找成功\n\n";
				else
					cout << "最贵图书查找失败\n\n";
				break;
			case 6://最爱图书的查找
				if (FindFavorite_L(L))
					cout << "最爱图书查找成功\n\n";
				else
					cout << "最爱图书查找失败\n\n";
				break;
			case 7://最佳位置图书查找
				if (Locate_L(L))
					cout << "佳位置图书查找成功\n\n";
				else
					cout << "最佳位置图书查找失败\n\n";
				break;
			case 8://新图书入库
				if (Insert_L(L))
					cout << "新图书入库成功\n\n";
				else
					cout << "新图书入库失败\n\n";
				break;
			case 9://旧图书出库
				if (Delete_L(L))
					cout << "旧图书出库成功\n\n";
				else
					cout << "旧图书出库失败\n\n";
				break;
			case 10://图书去重
				if (DupRemoval_L(L))
					cout << "图书去重成功\n\n";
				else
					cout << "图书去重失败\n\n";
				break;
			case 11: //链表输出
				Output_L(L);
				break;
		}
	}
	return 0;
}
