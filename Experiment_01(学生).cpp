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
#define MAXSIZE 1000			//顺序表可能达到的最大长度

using namespace std;
typedef int Status; //Status 是函数返回值类型，其值是函数结果状态代码。
typedef int ElemType; //ElemType 为可定义的数据类型，此设为int类型

typedef struct {
	//图书信息定义
	string id;    //图书ISBN
	string name;   //图书名字
	double price;   //图书价格
} Book;

typedef struct {
	//图书表的顺序存储结构类型为SqList
	Book *elem = NULL;                   //存储空间的基地址
	int length;                   //图书表中当前图书个数
} SqList;


Status InitList_Sq(SqList &L) { //算法2.1 顺序表的初始化
	//构造一个空的顺序表L
	L.elem = new Book[MAXSIZE]; //为顺序表分配一个大小为MAXSIZE的数组空间
	if (!L.elem)
		exit(OVERFLOW); //存储分配失败退出
	L.length = 0; //空表长度为0
	return OK;
}


//（给出） 
Status Input_Sq(SqList &L) {
	//顺序表的输入
	/**************begin************/
	int i = 0;
	string head_1, head_2, head_3;

	if (!L.elem)
		InitList_Sq(L);
	fstream file;
	file.open("book.txt");
	if (!file) {
		cout << "错误！未找到文件！" << endl;
		exit(ERROR); // 0
	}
	file >> head_1 >> head_2 >> head_3;
	while (!file.eof()) {
		file >> L.elem[i].id >> L.elem[i].name >> L.elem[i].price;
		i++;
	}
	cout << "输入 book.txt 信息完毕\n\n";
	L.length = i;
	file.close();

	return OK;  // 1
	/**************end************/
}


// 2 
Status BubbleSort_Sq(SqList L) {
	//图书顺序表按照价格降序冒泡排序
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
	//修改价格
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
	//逆序存储顺序表
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
	//查找价格最高的图书并
	/**************begin************/
	int i;
    float hp=L.elem[0].price;          //辅助变量hp存储最高价格
    for(i=0;i<=L.length-1;i++)        //第一趟遍历：求出最高价格hp
        if(hp<L.elem[i+1].price)
            hp=L.elem[i+1].price;
    int n=0;                         //辅助变量n存储最高价格的书的数目
    for(i=0;i<=L.length-1;i++)        //第二趟遍历：求出最高价格的书的数目n
        if(hp==L.elem[i].price)
            n++;
    cout<<n<<endl;
    for(i=0;i<=L.length-1;i++)        //输出这n本最高价格的书的信息
        if(hp==L.elem[i].price)
            cout<<L.elem[i].id<<" "<<L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;

	return OK;
	/**************end************/
}


// 6 
Status FindFavorite_Sq(SqList L) {
	//最爱图书的查找
	/**************begin************/
	int m;    //查找m次
    cin>>m;
    Book s[m];
    int i,j;
    for(i=0;i<m;i++)
        cin>>s[i].name;              //输入待查的书名
    for(i=0;i<m;i++)            //依次查找m本书
    {
        int num=0;                //查询第i本书，初始化num为0
        for(j=0;j<L.length;j++){
            if(L.elem[j].name==s[i].name)      //计算同名书的数目num
                num++;
        }
        if(num==0)                          //num为0，即未查找到该书
            cout<<"Sorry，there is no your favourite!"<<endl;
        else
        {
            cout<<num<<endl;                 //输出同名书的数目
                for(j=0;j<L.length;j++)          //一趟遍历：输出同名书的信息
                    if(L.elem[j].name==s[i].name)
                        cout<<L.elem[j].id<<" "<<L.elem[j].name<<" "<<fixed<<setprecision(2)<<L.elem[j].price<<endl;
        }
    }

	return OK;
	/**************end************/
}


// 7 
Status FindLocate_Sq(SqList L) {
	//查找最佳位置图书
	/**************begin************/
	int m;
    cin>>m;
    int s[m];
    for(int i=0;i<m;i++){
        cin>>s[i];
    }
    for(int i=0;i<m;i++){
        //注意有可能输入0
        if (s[i] < 1 || s[i] > L.length) {  
            cout << "Sorry，the book on the best position doesn't exist!"<< endl;  
        }else{  
    cout << L.elem[s[i] - 1].id << " " << L.elem[s[i] - 1].name << " " << fixed << setprecision(2) << L.elem[s[i] - 1].price << endl; }
    }

	return OK;
	/**************end************/
}


// 8 
Status Insert_Sq(SqList &L) {
	//新图书的入库
	/**************begin************/
	int n;
    cin>>n;
    char id[20];
    char name[50];
    float price;
    cin>>id>>name>>price;
    if(n<1||n>L.length){
        cout<<"Sorry，the position to be inserted is invalid!"<<endl;
    }else{
        for(int i=L.length;i>n-1;i--)      //全部后移，留出空位
        	L.elem[i]=L.elem[i-1];
        	L.elem[n-1].id=id;  
        	L.elem[n-1].name=name;
        	L.elem[n-1].price=price;
        L.length++;            //插入完成，图书个数+1
        for(int i=0;i<L.length;i++)
            cout<<L.elem[i].id<<" "<<L.elem[i].name<<" "<<fixed<<setprecision(2)<<L.elem[i].price<<endl;

    }

	return OK;
	/**************end************/
}


// 9 
Status Delete_Sq(SqList &L) {
	//旧图书的出库
	/**************begin************/
	int m;
    cin>>m;
    if(m<1||m>L.length){
         cout<<"Sorry，the position to be deleted is invalid!";
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
{//查找书号是否在图书信息表L中
	int i;
    for(i=0;i<L.length;i++)
        if(L.elem[i].id==id)
            return OK;
    return ERROR;
}
int DupRemoval_Sq(SqList &L) {
	//图书去重
	/**************begin************/
	if(L.length==0){
		cout<<"图书表为空，无需查重！"<<endl;
		return OK; 
	}

	int i;
	SqList L2;
	InitList_Sq(L2);
    for(i=0;i<L.length;i++)
    {
        if(SearchList(L2,L.elem[i].id))  //如果当前书号没有出现在L2中，则将该图书信息插入L2中
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
	//顺序表的输出
	/**************begin************/
	if (!L.elem)
		InitList_Sq(L);

	cout << "当前图书系统信息（顺序表）读出:\n";
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
			case 0://创建顺序表
				if (InitList_Sq(L))
					cout << "成功建立顺序表\n\n";
				else
					cout << "顺序表建立失败\n\n";
				break;
			case 1: // 图书信息表输入
				if (Input_Sq(L))
					cout << "图书信息表输入成功\n\n";
				else
					cout << "图书信息表输入失败\n\n";
				break;
			case 2://图书信息表排序
				if (BubbleSort_Sq(L))
					cout << "图书信息表排序成功\n\n";
				else
					cout << "图书信息表排序失败\n\n";
				break;
			case 3://图书信息表修改 
				if (RevisePrice_Sq(L))
					cout << "图书信息表修改成功\n\n";
				else
					cout << "图书信息表修改失败\n\n";
				break;
			case 4://图书信息表逆序存储
				if (Reverse_Sq(L))
					cout << "图书信息表逆序存储成功\n\n";
				else
					cout << "图书信息表逆序存储失败\n\n";
				break;
			case 5://最贵图书的查找
				if (HighestPrice_Sq(L))
					cout << "最贵图书查找成功\n\n";
				else
					cout << "最贵图书查找失败\n\n";
				break;
			case 6://最爱图书的查找
				if (FindFavorite_Sq(L))
					cout << "最爱图书查找成功\n\n";
				else
					cout << "最爱图书查找失败\n\n";
				break;
			case 7://最佳位置图书查找
				if (FindLocate_Sq(L))
					cout << "佳位置图书查找成功\n\n";
				else
					cout << "最佳位置图书查找失败\n\n";
				break;
			case 8://新图书入库
				if (Insert_Sq(L))
					cout << "新图书入库成功\n\n";
				else
					cout << "新图书入库失败\n\n";
				break;
			case 9://旧图书出库
				if (Delete_Sq(L))
					cout << "旧图书出库成功\n\n";
				else
					cout << "旧图书出库失败\n\n";
				break;
			case 10://图书去重
				if (DupRemoval_Sq(L))
					cout << "图书去重成功\n\n";
				else
					cout << "图书去重失败\n\n";
				break;
			case 11: //顺序表的输出
				Output_Sq(L);
				break;
		}
	}
	return 0;
}
