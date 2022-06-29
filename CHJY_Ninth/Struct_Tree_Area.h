
#include<iostream>
#include<stack>      
using namespace std;
//评论二叉树的基节点 
typedef struct comment{
	char name[100];
	char timeFormat[100];
	char content[100];
	int category;
}Comment;
typedef Comment* CComment;
//评论二叉树的节点 
typedef struct node{
	char name[100];
	char timeFormat[100];
	char content[100];
	int category;
	struct node* lChild;
	struct node* rChild;
}PNode;
typedef PNode* PPNode;
//景区结构体 
typedef struct _graph {
	char vexs[100][100];//
	int vexnum;
	int edgnum;
	int matrix[100][100];//关系矩阵
	int price[100];//景点价格
	PPNode comment;//评论二叉树
	int personNum[100];//景区人数分布
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