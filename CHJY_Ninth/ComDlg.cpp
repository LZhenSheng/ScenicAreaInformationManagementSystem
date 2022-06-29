// ComDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "ComDlg.h"
#include "afxdialogex.h"


int total;       
const int INF=(~(0x1<<31));     
const int MAX=100; 
const int SCENESPOT=5;
int NOWSCENESPOT=0;

CComment *user=new CComment[100];
const char address[5][100]={"message1.txt","message2.txt","message3.txt","message4.txt","message5.txt"};
const int maxn=1000 ;     
int n, nex[maxn+3], mp[maxn+3][maxn+3]; 
PGraph *pG;
// ComDlg 对话框

IMPLEMENT_DYNAMIC(ComDlg, CDialogEx)

	ComDlg::ComDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ComDlg::IDD, pParent)

{

}

ComDlg::~ComDlg()
{
}

void ComDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST_com, mComListContrl);
	DDX_Control(pDX, IDC_COMBO1, mConComboBox);
}


BEGIN_MESSAGE_MAP(ComDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &ComDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// ComDlg 消息处理程序





void ComDlg::FreshData(int index,CString strC)
{

	PGraph *pG;
	pG=create_example_graph();
	mComListContrl = (CListCtrl *)GetDlgItem(IDC_LIST_com);
	CRect rs;
	GetClientRect(&rs);
	int colWidth = rs.Width();	//get col width
	strC+= "景区热门评论：";

	mComListContrl->DeleteColumn(0);
	mComListContrl->InsertColumn(0,strC, LVCFMT_LEFT, colWidth, 0);

	int column=mComListContrl->GetItemCount()-1;        
	while(column>=0)//清空行内容
	{	
		mComListContrl->DeleteItem(column);
		column--;
	}


	for(int i=0;i<pG[index]->commentNum;i++)//添加行
	{
		CString strsum;
		char s[200];
		sprintf(s,"%s:%s(%s)",user[i]->name,user[i]->content,user[i]->timeFormat);
		strsum=s;
		int index = mComListContrl->GetItemCount();
		int addRow = mComListContrl->InsertItem(index, _T(""));
		mComListContrl->SetItemText(addRow, 0, strsum);//addRow代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
	}

}


BOOL ComDlg::OnInitDialog()
{
	CString SCENENAME[5];
	SCENENAME[0]="贵州马头寨";
	SCENENAME[1]="未知地区0031";
	SCENENAME[2]="未知地区0120";
	SCENENAME[3]="未知地区0801";
	SCENENAME[4]="未知地区0908"; 
	//NOWSCENESPOT=
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化


	pG=create_example_graph();
	for(int i=0;i<SCENESPOT;i++)
	{
		mConComboBox.AddString(SCENENAME[i]); 
	}
	mConComboBox.SetCurSel(0);//默认选择第一个

	mComListContrl = (CListCtrl *)GetDlgItem(IDC_LIST_com);
	CRect rs;
	GetClientRect(&rs);
	int colWidth = rs.Width();	//get col width

	mComListContrl->InsertColumn(0, _T("贵州马头寨景区热门评论："), LVCFMT_LEFT, colWidth, 0);

	LOGFONT   logfont;//可以弄成类成员,全局变量,静态成员  
	CFont   *pfont1   =   mComListContrl->GetFont();  
	pfont1->GetLogFont(   &logfont   );  
	logfont.lfHeight   =logfont.lfHeight   *   1.5;   //这里可以修改字体的高比例
	logfont.lfWidth     =   logfont.lfWidth   *   1.5;   //这里可以修改字体的宽比例
	static   CFont   font1;  
	font1.CreateFontIndirect(&logfont);  
	mComListContrl->SetFont(&font1);  
	font1.Detach();


	//mComListContrl->InsertItem(0,_T("景区名称"));//开辟一个行，并且设置行的内容为i的内容
	for(int i=0;i<pG[0]->commentNum;i++)
	{
		CString strsum;

		char s[200];
		sprintf(s,"%s:(%s)%s",user[i]->name,user[i]->content,user[i]->timeFormat);
		strsum=s;
		int index = mComListContrl->GetItemCount();
		int addRow = mComListContrl->InsertItem(index, _T(""));
		mComListContrl->SetItemText(addRow, 0, strsum);//addRow代指在第几行插入数据，第二个参数代指第几列，第三个参数代指插入数据的值
	}




	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



void ComDlg::Add_c_messge(CString com)
{
	int index_0 = mComListContrl->GetItemCount();
	int addRow_0 = mComListContrl->InsertItem(index_0, _T(""));
	mComListContrl->SetItemText(addRow_0, 0, com);

}


void ComDlg::OnCbnSelchangeCombo1()//选择下拉框的某一行后触发事件
{
	// TODO: 在此添加控件通知处理程序代码
	//int index = mConComboBox.GetCurSel();       //这个函数用于得到用户选择的是下拉列表中的第几行，第一行的话，返回0，依次类推  
	// CString strI;  
	// strI.Format(_T("%d"),index);  //将行号转化为字符串形式
	//CString strC; //行的名称 
	//mConComboBox.GetLBText(index,strC);        //根据行号，这个可以得到那行的字符串  
	// strC += strI;  //字符串与行号合并
	//FreshData(index,strC);//获取行号、景区名称后，进行刷新,暂时未开放
	int index = mConComboBox.GetCurSel();       //这个函数用于得到用户选择的是下拉列表中的第几行，第一行的话，返回0，依次类推  
	CString strI;  
	strI.Format(_T("%d"),index);  
	CString strC;  
	mConComboBox.GetLBText(index,strC);        //根据行号，这个可以得到那行的字符串  
	//strC += strI; 
	strC+="暂未开放！";
	MessageBox(strC,_T("提示"));
	mConComboBox.SetCurSel(0);


	//preOrder(pG[index]->comment,index);



}




int ComDlg::getIndex(int left, int right)
{
	if((right-left)%2==0)
		return (left+right)/2;
	else
		return (left+right)/2+1;
}


PPNode ComDlg::structTree(CComment * user, int left, int right)
{	if(right<left)
return NULL;
int i=getIndex(left,right);
PPNode tree=new struct node;
strcpy(tree->name,user[i]->name);
strcpy(tree->timeFormat,user[i]->timeFormat);
strcpy(tree->content,user[i]->content);
tree->category=user[i]->category;
tree->lChild=structTree(user,left,i-1);
tree->rChild=structTree(user,i+1,right);
return tree;
}


// 刷新评论
void ComDlg::updateComment(PGraph G, int n, char name[], char timeFormat[], char content[])
{	FILE *file=fopen(address[n],"w");
for(int i=0;i<G->commentNum;i++)
{
	fprintf(file,"%s %s %s %d\n",user[i]->name,user[i]->timeFormat,user[i]->content,user[i]->category);
	//cout<<user[i]->name<<"sldjfsldaf";
}
fprintf(file,"%s %s %s %d\n",name,timeFormat,content,2);
fclose(file);
}


// 增加评论
void ComDlg::addComment(PGraph G, int n)
{	char name[100]="sdlfj";
char timeFormat[100]="sdlfj";
char content[100]="dskf";
int category=3;
PPNode GC=new struct node;
PPNode p=new struct node;
GC=G->comment;
while(GC->rChild!=NULL)
	GC=GC->rChild;
strcpy(p->name,name);
strcpy(p->timeFormat,timeFormat);
strcpy(p->content,content);
p->category=category;
p->rChild=NULL;
p->lChild=NULL;
GC->rChild=p;
cout<<GC->rChild->name;
updateComment(G,n,name,timeFormat,content); 
//	G->comment=getComment(address[n]);
//更新显示 
}


// 初始化评论
PPNode ComDlg::getComment(const char address[])
{	FILE *fp = NULL;
fp = fopen(address, "r");
fscanf(fp,"%d",&total);
for(int i=0;i<total;i++)
{
	user[i]=new struct comment;
	fscanf(fp,"%s",user[i]->name);
	fscanf(fp,"%s",user[i]->timeFormat);
	fscanf(fp,"%s",user[i]->content);
	fscanf(fp,"%d",&user[i]->category);
	cout<<user[i]->name<<" "<<user[i]->timeFormat<<" "<<user[i]->content<<endl;
} 
PPNode tree=new struct node;
tree=structTree(user,0,total-1);
return tree;
}


PGraph* ComDlg::create_example_graph(void)
{int num1,num2,num3;
FILE *file=fopen("sss.txt","r");
PGraph* graph=new PGraph[SCENESPOT];
for(int i=0;i<SCENESPOT;i++)
	graph[i]=new struct _graph;
for(int i=0; i<SCENESPOT; i++)
	fscanf(file,"%d%d",&(graph[i]->vexnum),&(graph[i]->edgnum));
for(int i=0;i<SCENESPOT;i++)
	for(int j=0;j<graph[i]->vexnum;j++)
		fscanf(file,"%d",&(graph[i]->price[j]));
for(int i=0;i<SCENESPOT;i++)
	for(int j=0;j<graph[i]->vexnum;j++)
		fscanf(file,"%d",&(graph[i]->personNum[j]));
for(int k=0; k<SCENESPOT; k++) 
{
	for(int i=0; i<graph[k]->vexnum; i++) 
	{
		fscanf(file,"%s",graph[k]->vexs[i]);
		for(int j=0; j<graph[k]->vexnum; j++) 
		{
			graph[k]->matrix[i][j]=INF;
			if(i==j)
				graph[k]->matrix[i][i]=0;
		}
	}
}
for(int k=0; k<SCENESPOT; k++)
{
	for(int i=0; i<graph[k]->edgnum;i++) 
	{
		fscanf(file,"%d%d%d",&num1,&num2,&num3);
		graph[k]->matrix[num1][num2]=num3;
		graph[k]->matrix[num2][num1]=num3;
	}
}
for(int i=0;i<SCENESPOT;i++)
{
	graph[i]->comment=getComment(address[i]);
	graph[i]->commentNum=total;
}
return graph;
}



CString ComDlg::dijkstra(Graph G, int vs,int vt) //(*pG[NOWSCENESPOT],qishi,zhong)
{
	int *prev=new int[G.vexnum],*dist=new int[G.vexnum];
	stack<int> st;
	int i,j,k;
	int min;
	int tmp;
	int flag[MAX];
	for (i = 0; i < G.vexnum; i++) 
	{
		flag[i] = 0;
		prev[i] = 0;
		dist[i] = G.matrix[vs][i];
	}
	flag[vs] = 1;
	dist[vs] = 0;
	for (i = 1; i < G.vexnum; i++) 
	{
		min = INF;
		for (j = 0; j < G.vexnum; j++) 
		{
			if (flag[j]==0 && dist[j]<min) 
			{
				min = dist[j];
				k = j;
			}
		}
		flag[k] = 1;
		for (j = 0; j < G.vexnum; j++) 
		{
			tmp = (G.matrix[k][j]==INF ? INF : (min + G.matrix[k][j]));
			if (flag[j] == 0 && (tmp  < dist[j]) )
			{
				dist[j] = tmp;
				prev[j] = k;
			}
		}
	}
	char time[100];
	sprintf(time,"%s",G.vexs[vs]);
	int m=vt;
	while((m=prev[m])!=0) 
	{
		st.push(m);
	}
	while(!st.empty()) 
	{
		sprintf(time,"%s->%s",time,G.vexs[st.top()]);
		st.pop();
	}
	sprintf(time,"%s->%s",time,G.vexs[vt]);


	//cout<<time;
	//printf("\n");
	CString Strc;
	Strc=time;
	Strc+="\n";

	return Strc;
}

void ComDlg::cheshi(void)
{
}



bool ComDlg::expend(int s)
{    
	memset(nex, -1, sizeof(nex));    
	int head = s, tail = s;
	for(int i=0; i<n; ++i)
	{    
		if(i==s) 
			continue;      
		if(mp[i][head])
		{           
			nex[i] = head;       
			head = i;    
		}        
		else
		{            
			int x = head, y = nex[head];            
			while(y != -1 && mp[y][i])
			{            
				x = y;        
				y = nex[y]; 
			}           
			nex[x] = i;
			if(y == -1)
				tail = i;      
		}    
	}    
	if(mp[tail][head])
	{
		nex[tail] = head;
		return true;
	}
	return false;
}
bool ComDlg::solve()//
{    
	for(int i=0; i<n; ++i)        
		if(expend(i))        
			return true;  
	return false;
}
CString ComDlg::getHMD(Graph G)//
{
	//cout<<"dlskjflsdajflds"<<endl;
	n=G.vexnum;        
	for(int i=0; i<n; ++i)            
		for(int j=0; j<n; ++j)                
			mp[i][j]=G.matrix[i][j]; 
	CString sum;
	if(n==1);
	else if(n==2 || !solve());
	else 
		for(int i=0,j=0; i<n; ++i, j=nex[j])             
			sum+=G.vexs[j]+(i==n-1?'\n':' ');
	if(sum.Compare(_T("")))
		sum="没找到";
	return sum;
}


void ComDlg::preOrder(PPNode p,int i)
{
	if(p==NULL)
		return;
	user[i]->category=p->category;
	strcpy(user[i]->name,p->name);
	strcpy(user[i]->content,p->content);
	strcpy(user[i]->timeFormat,p->timeFormat);
	i++;
	preOrder(p->lChild,i);
	preOrder(p->rChild,i);
} 

PBuyPicketHistory ComDlg::createPicket()
{
	FILE *file=fopen("tt.txt","r");
	PBuyPicketHistory buy=new struct buyPicketHistory;
	fscanf(file,"%d",&buy->curNum);
	for(int i=0;i<buy->curNum;i++)
	{
		fscanf(file,"%s%s%s%d%d%d",buy->picket[i].sceneName,buy->picket[i].time,buy->picket[i].timeFormat,&buy->picket[i].flag,&buy->picket[i].person,&buy->picket[i].sceneNum);
		for(int j=0;j<buy->picket[i].sceneNum;j++)
			fscanf(file,"%s",buy->picket[i].sceneSpotName[j]);
	} 
	return buy;
}