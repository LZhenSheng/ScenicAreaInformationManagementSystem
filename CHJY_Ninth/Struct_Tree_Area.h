
#include<iostream>
#include<stack>      
using namespace std;
//���۶������Ļ��ڵ� 
typedef struct comment{
	char name[100];
	char timeFormat[100];
	char content[100];
	int category;
}Comment;
typedef Comment* CComment;
//���۶������Ľڵ� 
typedef struct node{
	char name[100];
	char timeFormat[100];
	char content[100];
	int category;
	struct node* lChild;
	struct node* rChild;
}PNode;
typedef PNode* PPNode;
//�����ṹ�� 
typedef struct _graph {
	char vexs[100][100];//
	int vexnum;
	int edgnum;
	int matrix[100][100];//��ϵ����
	int price[100];//����۸�
	PPNode comment;//���۶�����
	int personNum[100];//���������ֲ�
	int commentNum;//
} Graph, *PGraph;
typedef struct buyPicket{
	char timeFormat[100];
	char sceneName[100];
	char time[100];
	int person;
	int sceneNum;
	char sceneSpotName[100][100];
	int flag;
}Picket;
typedef struct buyPicketHistory{
	int curNum;
	Picket picket[100];
}BuyPicketHistory,*PBuyPicketHistory;