#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<iomanip>
#include<cstring>
#include<algorithm>

#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define MAXSIZE 1000			//˳�����ܴﵽ����󳤶�

using namespace std;
typedef int Status; //Status �Ǻ�������ֵ���ͣ���ֵ�Ǻ������״̬���롣
typedef int ElemType; //ElemType Ϊ�ɶ�����������ͣ�����Ϊint����

typedef struct {
	//ͼ����Ϣ����
	string id;    //ͼ��ISBN
	string name;   //ͼ������
	double price;   //ͼ��۸�
} Book;

typedef struct {
	//ͼ����˳��洢�ṹ����ΪSqList
	Book *elem = NULL;                   //�洢�ռ�Ļ���ַ
	int length;                   //ͼ����е�ǰͼ�����
} SqList;


Status InitList_Sq(SqList &L) { //�㷨2.1 ˳���ĳ�ʼ��
	//����һ���յ�˳���L
	L.elem = new Book[MAXSIZE]; //Ϊ˳������һ����СΪMAXSIZE������ռ�
	if (!L.elem)
		exit(OVERFLOW); //�洢����ʧ���˳�
	L.length = 0; //�ձ���Ϊ0
	return OK;
}


//�������� 
Status Input_Sq(SqList &L) {
	//˳��������
	/**************begin************/
	int i = 0;
	string head_1, head_2, head_3;

	if (!L.elem)
		InitList_Sq(L);
	fstream file;
	file.open("book.txt");
	if (!file) {
		cout << "����δ�ҵ��ļ���" << endl;
		exit(ERROR); // 0
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		file >> L.elem[i].id >> L.elem[i].name >> L.elem[i].price;
		i++;
	}
	cout << "���� book.txt ��Ϣ���\n\n";
	L.length = i;
	file.close();

	return OK;  // 1
	/**************end************/
}


// 2 
Status BubbleSort_Sq(SqList L) {
	//ͼ��˳����ռ۸���ð������
	/**************begin************/
	for(int i =0;i<L.length;i++){
        for(int j=i+1;j<L.length;j++){
            if(L.elem[i].price < L.elem[j].price){
                Book temp = L.elem[i];
                L.elem[i]=L.elem[j];
                L.elem[j]=temp;
            }
        }
    }
	return OK;
	/**************end************/
}


// 3 
Status RevisePrice_Sq(SqList &L) {
	//�޸ļ۸�
	/**************begin************/
	double sum=0,ave=0;
    for(int i=0;i<L.length;i++){
        sum+=L.elem[i].price;
    }
    ave=sum/L.length;
    for(int i=0;i<L.length;i++){
        if(L.elem[i].price<ave){
            L.elem[i].price=(L.elem[i].price)*1.2;
        }else{
            L.elem[i].price=(L.elem[i].price)*1.1;
        }
    }
    cout<<fixed<<setprecision(2)<<ave<<endl;
	return OK;
	/**************end************/
}


// 4 
Status Reverse_Sq(SqList &L) {
	//����洢˳���
	/**************begin************/
	int n;
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>L.elem[i].id>>L.elem[i].name>>L.elem[i].price;
       L.length++;
   }
   for(int i=0;i<L.length/2;i++){
       Book temp=L.elem[i];
       L.elem[i]=L.elem[n-1-i];
       L.elem[n-1-i]=temp;
   }

	return OK;
	/**************end************/
}


// 5 
Status HighestPrice_Sq(SqList L) {
	//���Ҽ۸���ߵ�ͼ�鲢
	/**************begin************/
	int i;
    float hp=L.elem[0].price;          //��������hp�洢��߼۸�
    for(i=0;i<=L.length-1;i++)        //��һ�˱����������߼۸�hp
        if(hp<L.elem[i+1].price)
            hp=L.elem[i+1].price;
    int n=0;                         //��������n�洢��߼۸�������Ŀ
    for(i=0;i<=L.length-1;i++)        //�ڶ��˱����������߼۸�������Ŀn
        if(hp==L.elem[i].price)
            n++;
    cout<<n<<endl;
    for(i=0;i<=L.length-1;i++)        //�����n����߼۸�������Ϣ
        if(hp==L.elem[i].price)
            cout<<L.elem[i].id<<" "<<L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;

	return OK;
	/**************end************/
}


// 6 
Status FindFavorite_Sq(SqList L) {
	//�ͼ��Ĳ���
	/**************begin************/
	int m;    //����m��
    cin>>m;
    Book s[m];
    int i,j;
    for(i=0;i<m;i++)
        cin>>s[i].name;              //������������
    for(i=0;i<m;i++)            //���β���m����
    {
        int num=0;                //��ѯ��i���飬��ʼ��numΪ0
        for(j=0;j<L.length;j++){
            if(L.elem[j].name==s[i].name)      //����ͬ�������Ŀnum
                num++;
        }
        if(num==0)                          //numΪ0����δ���ҵ�����
            cout<<"Sorry��there is no your favourite!"<<endl;
        else
        {
            cout<<num<<endl;                 //���ͬ�������Ŀ
                for(j=0;j<L.length;j++)          //һ�˱��������ͬ�������Ϣ
                    if(L.elem[j].name==s[i].name)
                        cout<<L.elem[j].id<<" "<<L.elem[j].name<<" "<<fixed<<setprecision(2)<<L.elem[j].price<<endl;
        }
    }

	return OK;
	/**************end************/
}


// 7 
Status FindLocate_Sq(SqList L) {
	//�������λ��ͼ��
	/**************begin************/
	int m;
    cin>>m;
    int s[m];
    for(int i=0;i<m;i++){
        cin>>s[i];
    }
    for(int i=0;i<m;i++){
        //ע���п�������0
        if (s[i] < 1 || s[i] > L.length) {  
            cout << "Sorry��the book on the best position doesn't exist!"<< endl;  
        }else{  
    cout << L.elem[s[i] - 1].id << " " << L.elem[s[i] - 1].name << " " << fixed << setprecision(2) << L.elem[s[i] - 1].price << endl; }
    }

	return OK;
	/**************end************/
}


// 8 
Status Insert_Sq(SqList &L) {
	//��ͼ������
	/**************begin************/
	int n;
    cin>>n;
    char id[20];
    char name[50];
    float price;
    cin>>id>>name>>price;
    if(n<1||n>L.length){
        cout<<"Sorry��the position to be inserted is invalid!"<<endl;
    }else{
        for(int i=L.length;i>n-1;i--)      //ȫ�����ƣ�������λ
        	L.elem[i]=L.elem[i-1];
        	L.elem[n-1].id=id;  
        	L.elem[n-1].name=name;
        	L.elem[n-1].price=price;
        L.length++;            //������ɣ�ͼ�����+1
        for(int i=0;i<L.length;i++)
            cout<<L.elem[i].id<<" "<<L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;

    }

	return OK;
	/**************end************/
}


// 9 
Status Delete_Sq(SqList &L) {
	//��ͼ��ĳ���
	/**************begin************/
	int m;
    cin>>m;
    if(m<1||m>L.length){
         cout<<"Sorry��the position to be deleted is invalid!";
    }else{
        for(int i=m-1;i<L.length-1;i++){
            L.elem[i]=L.elem[i+1];
        }
        L.length--;
        for(int i=0;i<L.length;i++){
            cout<<L.elem[i].id<<" "<<L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;
    	}
    }

	return OK;
	/**************end************/
}


// 10 
int SearchList(SqList L,string id)
{//��������Ƿ���ͼ����Ϣ��L��
	int i;
    for(i=0;i<L.length;i++)
        if(L.elem[i].id==id)
            return OK;
    return ERROR;
}
int DupRemoval_Sq(SqList &L) {
	//ͼ��ȥ��
	/**************begin************/
	if(L.length==0){
		cout<<"ͼ���Ϊ�գ�������أ�"<<endl;
		return OK; 
	}

	int i;
	SqList L2;
	InitList_Sq(L2);
    for(i=0;i<L.length;i++)
    {
        if(SearchList(L2,L.elem[i].id))  //�����ǰ���û�г�����L2�У��򽫸�ͼ����Ϣ����L2��
        {
            continue;
        }
        L2.elem[L2.length]=L.elem[i];
        L2.length++;
    }
    cout<<L2.length<<endl;
     for(i=0;i<L2.length;i++)
        cout<<L2.elem[i].id<<" "<<L2.elem[i].name<<" "<<fixed<<setprecision(2)<<L2.elem[i].price<<endl;
	
	return OK;
	/**************end************/
}


Status Output_Sq(SqList L) {
	//˳�������
	/**************begin************/
	if (!L.elem)
		InitList_Sq(L);

	cout << "��ǰͼ��ϵͳ��Ϣ��˳�������:\n";
	for (int i = 0; i < L.length; i++)
		cout << left << setw(15) << L.elem[i].id << "\t"
		     << setw(20) << L.elem[i].name << "\t"
		     << setw(10) << fixed << setprecision(2) << L.elem[i].price << endl;
	cout << endl;

	return OK;
	/**************end************/
}

int main() {
	SqList L;
	int i = 0, temp, a, c, choose;
	double price;
	Book e;
	string head_1, head_2, head_3;
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
			case 0://����˳���
				if (InitList_Sq(L))
					cout << "�ɹ�����˳���\n\n";
				else
					cout << "˳�����ʧ��\n\n";
				break;
			case 1: // ͼ����Ϣ������
				if (Input_Sq(L))
					cout << "ͼ����Ϣ������ɹ�\n\n";
				else
					cout << "ͼ����Ϣ������ʧ��\n\n";
				break;
			case 2://ͼ����Ϣ������
				if (BubbleSort_Sq(L))
					cout << "ͼ����Ϣ������ɹ�\n\n";
				else
					cout << "ͼ����Ϣ������ʧ��\n\n";
				break;
			case 3://ͼ����Ϣ���޸� 
				if (RevisePrice_Sq(L))
					cout << "ͼ����Ϣ���޸ĳɹ�\n\n";
				else
					cout << "ͼ����Ϣ���޸�ʧ��\n\n";
				break;
			case 4://ͼ����Ϣ������洢
				if (Reverse_Sq(L))
					cout << "ͼ����Ϣ������洢�ɹ�\n\n";
				else
					cout << "ͼ����Ϣ������洢ʧ��\n\n";
				break;
			case 5://���ͼ��Ĳ���
				if (HighestPrice_Sq(L))
					cout << "���ͼ����ҳɹ�\n\n";
				else
					cout << "���ͼ�����ʧ��\n\n";
				break;
			case 6://�ͼ��Ĳ���
				if (FindFavorite_Sq(L))
					cout << "�ͼ����ҳɹ�\n\n";
				else
					cout << "�ͼ�����ʧ��\n\n";
				break;
			case 7://���λ��ͼ�����
				if (FindLocate_Sq(L))
					cout << "��λ��ͼ����ҳɹ�\n\n";
				else
					cout << "���λ��ͼ�����ʧ��\n\n";
				break;
			case 8://��ͼ�����
				if (Insert_Sq(L))
					cout << "��ͼ�����ɹ�\n\n";
				else
					cout << "��ͼ�����ʧ��\n\n";
				break;
			case 9://��ͼ�����
				if (Delete_Sq(L))
					cout << "��ͼ�����ɹ�\n\n";
				else
					cout << "��ͼ�����ʧ��\n\n";
				break;
			case 10://ͼ��ȥ��
				if (DupRemoval_Sq(L))
					cout << "ͼ��ȥ�سɹ�\n\n";
				else
					cout << "ͼ��ȥ��ʧ��\n\n";
				break;
			case 11: //˳�������
				Output_Sq(L);
				break;
		}
	}
	return 0;
}
