#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

#define OK 1
#define ERROR 0
#define OVERFLOW -2

using namespace std;
typedef int Status;		//Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType;	//ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

typedef struct {
	//ͼ����Ϣ����
	string id;		//ISBN
	string name;	//����
	double price;	//����
} Book;

typedef struct LNode {
	//ͼ����Ϣ�����ʽ�洢�ṹ
	Book data; 			//����������
	struct LNode *next; //����ָ����
} LNode, *LinkList; 	//LinkListΪָ��ṹ��LNode��ָ������

string head_1, head_2, head_3;
int length; //����ı�����ͼ�����ͼ�����


Status InitList_L(LinkList &L) {
	//����һ���յĵ�����L
	L = new LNode; //�����½����Ϊͷ��㣬��ͷָ��Lָ��ͷ���
	L->next = NULL; //ͷ����ָ�����ÿ�
	return OK;
}

//��������
Status CreateList_R(LinkList &L, int n) { //��巨����������
	/**************begin************/
	//��λ������n��Ԫ�ص�ֵ����������ͷ���ĵ�����L
	LinkList p, r;
	L = new LNode;
	L->next = NULL; //�Ƚ���һ����ͷ���Ŀ�����
	r = L; //βָ��rָ��ͷ���
	length = 0;
	fstream file; //���ļ����ж�д����
	file.open("book.txt");
	if (!file) {
		cout << "δ�ҵ�����ļ����޷��򿪣�" << endl;
		exit(ERROR);
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) { //���ļ��е���Ϣ���ú�巨���뵽������
		p = new LNode;//�����½��
		file >> p->data.id >> p->data.name >> p->data.price;//����Ԫ��ֵ�����½��*p��������
		p->next = NULL;
		r->next = p;//���½��*p����β���*r֮��
		r = p;//rָ���µ�β���*p
		length++; //ͬʱ�������Ƚ���ͳ��
	}
	file.close();

	return OK;
	/**************end************/
}


// 2
Status Sort_L(LinkList &L) {
	//��ͼ�鰴�ռ۸�������
	/**************begin************/
	//�����������ֻ��һ���ڵ����������� 
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
	//��������ͼ���ƽ���۸��޸ļ۸�
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
	//���ô�ͷ���ĵ�����L
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
	//���Ҽ۸���ߵ�ͼ��
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
	//���ҵ��ͼ��
	/**************begin************/
	if(!L||!L->next)return ERROR;
	string favoriteName;
	cout<<"����������ϲ����������";
	cin>>favoriteName;
	
	LinkList p = L->next;
	bool found = false;
	
	while(p){
		if(p->data.name==favoriteName){
			cout << "�ҵ�����ϲ����ͼ��:\n";
            cout << left << setw(15) << p->data.id << "\t"
                 << setw(20) << p->data.name << "\t"
                 << setw(10) << fixed << setprecision(2) << p->data.price << endl;
            found = true;
		}
		p=p->next;
	}
	if (!found) {
        cout << "δ�ҵ�����ϲ����ͼ�顣\n";
    }

	return OK;
	/**************end************/
}


// 7
Status Locate_L(LinkList L) {
	//�������λ�õ�ͼ��
	/**************begin************/
	if (!L || !L->next) return ERROR; // �������ֻ��һ���ڵ�

    int mid = length / 2;
    LinkList p = L->next;

    for (int i = 0; i < mid; i++) {
        p = p->next;
    }

    cout << "���λ�õ�ͼ����Ϣ:\n";
    cout << left << setw(15) << p->data.id << "\t"
         << setw(20) << p->data.name << "\t"
         << setw(10) << fixed << setprecision(2) << p->data.price << endl;
	return OK;
	/**************end************/
}


// 8
Status Insert_L(LinkList &L) {
	//����ͼ�����
	/**************begin************/
	Book newBook;
    cout << "��������ͼ���ISBN: ";
    cin >> newBook.id;
    cout << "��������ͼ�������: ";
    cin >> newBook.name;
    cout << "��������ͼ��ļ۸�: ";
    cin >> newBook.price;

    LinkList p = new LNode;
    p->data = newBook;
    p->next = L->next;
    L->next = p;

    length++; // ����������

	return OK;
	/**************end************/
}


// 9
Status Delete_L(LinkList &L) {
	//�����ͼ��
	/**************begin************/
	if (!L || !L->next) return ERROR; // �������ֻ��һ���ڵ�

    string deleteId;
    cout << "������Ҫɾ����ͼ���ISBN: ";
    cin >> deleteId;

    LinkList p = L;
    while (p->next) {
        if (p->next->data.id == deleteId) {
            LinkList temp = p->next;
            p->next = temp->next;
            delete temp;
            length--; // ����������
            cout << "ͼ��ɾ���ɹ���\n";
            return OK;
        }
        p = p->next;
    }

    cout << "δ�ҵ���ͼ�顣\n";

	return OK;
	/**************end************/
}


// 10
Status DupRemoval_L(LinkList &L) {
	//ͼ��ȥ��
	/**************begin************/
	if (!L || !L->next) return ERROR; // �������ֻ��һ���ڵ�

    LinkList p = L->next;
    while (p) {
        LinkList q = p;
        while (q->next) {
            if (q->next->data.id == p->data.id) {
                LinkList temp = q->next;
                q->next = temp->next;
                delete temp;
                length--; // ����������
            } else {
                q = q->next;
            }
        }
        p = p->next;
    }

	return OK;
	/**************end************/
}


//��������
Status Output_L(LinkList L) {
	//��������
	/**************begin************/
	cout << "��ǰͼ��ϵͳ��Ϣ����������:\n";
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
	
	
	cout << "0. ����\n";
	cout << "1. ����\n";
	cout << "2. ����\n";
	cout << "3. �޸�\n";
	cout << "4. ����洢\n";
	cout << "5. ���ͼ�����\n";
	cout << "6. �ͼ�����\n";
	cout << "7. ���λ��ͼ�����\n";
	cout << "8. ��ͼ�����\n";
	cout << "9. ��ͼ�����\n";
	cout << "10.ͼ��ȥ��\n";
	cout << "11.���\n";
	cout << "-1.�˳�\n\n";

	choose = -10;
	while (choose != -1) {
		cout << "��ѡ��:";
		cin >> choose;
		switch (choose) {
			case 0://����һ��������
				if (InitList_L(L))
					cout << "�ɹ���������!\n\n";
				else
					cout << "������ʧ��!\n\n";
				break;
			case 1: // ͼ����Ϣ������
				if (CreateList_R(L, length))
					cout << "ͼ����Ϣ����ɹ�\n\n";
				else
					cout << "ͼ����Ϣ����ʧ��\n\n";
				break;
			case 2://ͼ����Ϣ������
				if (Sort_L(L))
					cout << "ͼ����Ϣ������ɹ�\n\n";
				else
					cout << "ͼ����Ϣ������ʧ��\n\n";
				break;
			case 3://ͼ����Ϣ���޸�
				if (AveRevise_L(L))
					cout << "ͼ����Ϣ���޸ĳɹ�\n\n";
				else
					cout << "ͼ����Ϣ���޸�ʧ��\n\n";
				break;
			case 4://ͼ����Ϣ������洢
				if (Reverse_L(L))
					cout << "ͼ����Ϣ������洢�ɹ�\n\n";
				else
					cout << "ͼ����Ϣ������洢ʧ��\n\n";
				break;
			case 5://���ͼ��Ĳ���
				if (HighestPrice_L(L))
					cout << "���ͼ����ҳɹ�\n\n";
				else
					cout << "���ͼ�����ʧ��\n\n";
				break;
			case 6://�ͼ��Ĳ���
				if (FindFavorite_L(L))
					cout << "�ͼ����ҳɹ�\n\n";
				else
					cout << "�ͼ�����ʧ��\n\n";
				break;
			case 7://���λ��ͼ�����
				if (Locate_L(L))
					cout << "��λ��ͼ����ҳɹ�\n\n";
				else
					cout << "���λ��ͼ�����ʧ��\n\n";
				break;
			case 8://��ͼ�����
				if (Insert_L(L))
					cout << "��ͼ�����ɹ�\n\n";
				else
					cout << "��ͼ�����ʧ��\n\n";
				break;
			case 9://��ͼ�����
				if (Delete_L(L))
					cout << "��ͼ�����ɹ�\n\n";
				else
					cout << "��ͼ�����ʧ��\n\n";
				break;
			case 10://ͼ��ȥ��
				if (DupRemoval_L(L))
					cout << "ͼ��ȥ�سɹ�\n\n";
				else
					cout << "ͼ��ȥ��ʧ��\n\n";
				break;
			case 11: //�������
				Output_L(L);
				break;
		}
	}
	return 0;
}
