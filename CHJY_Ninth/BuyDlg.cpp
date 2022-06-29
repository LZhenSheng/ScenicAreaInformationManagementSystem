// BuyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "BuyDlg.h"
#include "afxdialogex.h"
#include "ComDlg.h"
#include "MainDlg.h"
#include "time.h"
#include "CHJY_NinthDlg.h"

//#define ListView_SetExtendedListViewStyle(m_lsCert.GetSafeHwnd(), mBuyListCtrl.GetExStyle() | LVS_EX_CHECKBOXES); 

// BuyDlg 对话框

IMPLEMENT_DYNAMIC(BuyDlg, CDialogEx)

	BuyDlg::BuyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(BuyDlg::IDD, pParent)
{

}

BuyDlg::~BuyDlg()
{
}

void BuyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_LIST_Buy, mBuyList);
	DDX_Control(pDX, IDC_COMBO_Buy_type, mBuyComboBox_lx);
	DDX_Control(pDX, IDC_COMBO_Buy_jq, mBuyComboBox_jq);
	DDX_Control(pDX, IDC_LIST_Buy_lb, mBuy_CheckList);


	DDX_Control(pDX, IDC_COMBO_Buy_year, mCOMBO_Buy_year);
	DDX_Control(pDX, IDC_COMBO_Buy_month, mCOMBO_Buy_month);
	DDX_Control(pDX, IDC_COMBO_Buy_day, mCOMBO_Buy_day);
}


BEGIN_MESSAGE_MAP(BuyDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &BuyDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &BuyDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &BuyDlg::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO_Buy_month, &BuyDlg::OnCbnSelchangeComboBuymonth)
	ON_CBN_SELCHANGE(IDC_COMBO_Buy_jq, &BuyDlg::OnCbnSelchangeComboBuyjq)
	ON_CBN_SELCHANGE(IDC_COMBO_Buy_type, &BuyDlg::OnCbnSelchangeComboBuytype)
END_MESSAGE_MAP()


// BuyDlg 消息处理程序


BOOL BuyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	// TODO:  在此添加额外的初始化

	//mBuyListCtrl = (CListCtrl *)GetDlgItem(IDC_LIST_Buy);

	//LONG styles=GetWindowLong(mBuyListCtrl->m_hWnd, GWL_STYLE); 
	//SetWindowLong(mBuyListCtrl->m_hWnd, GWL_STYLE, styles|LVS_REPORT);
	//mBuyListCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT);

	//CRect rs;
	//GetClientRect(&rs);
	//int colWidth = rs.Width()/8;	//get col width

	//mBuyListCtrl->InsertColumn(0, _T("景区"), LVCFMT_LEFT, colWidth, 0);
	//mBuyListCtrl->InsertColumn(1, _T("地点"), LVCFMT_CENTER, colWidth*2, 1);
	//mBuyListCtrl->InsertColumn(2, _T("距离"), LVCFMT_CENTER, colWidth*2, 2);
	//mBuyListCtrl->InsertColumn(3, _T("日期"), LVCFMT_CENTER, colWidth*2, 3);
	//mBuyListCtrl->InsertColumn(4, _T("状态"), LVCFMT_LEFT, colWidth, 4);
	//mBuyListCtrl->InsertColumn(5, _T("状态"), LVCFMT_LEFT, colWidth, 5);

	//初始化景区
	CString SCENENAME[5];
	SCENENAME[0]="贵州马头寨";
	SCENENAME[1]="未知地区0031";
	SCENENAME[2]="未知地区0120";
	SCENENAME[3]="未知地区0801";
	SCENENAME[4]="未知地区0908"; //这里会自动排序！！
	for(int i=0;i<5;i++)
	{
		mBuyComboBox_jq.AddString(SCENENAME[i]); 
	}
	mBuyComboBox_jq.SetCurSel(0);//默认选择第一个
	//初始化类型

	mBuyComboBox_lx.AddString(_T("自选")); 
	mBuyComboBox_lx.AddString(_T("价格")); 
	mBuyComboBox_lx.SetCurSel(0);//默认选择第一个

	//初始化时间
	CString time_001;
	for(int i=2019;i<=2020;i++)//年
	{
		time_001.Format(_T("%d"),i);
		mCOMBO_Buy_year.AddString(time_001); 
	}
	mCOMBO_Buy_year.SetCurSel(0);//默认选择第一个
	for(int i=1;i<=12;i++)//月
	{
		time_001.Format(_T("%d"),i);
		mCOMBO_Buy_month.AddString(time_001); 
	}
	mCOMBO_Buy_month.SetCurSel(11);//默认选择第12个
	for(int i=1;i<=31;i++)//日
	{
		time_001.Format(_T("%d"),i);
		mCOMBO_Buy_day.AddString(time_001);  
	}
	mCOMBO_Buy_day.SetCurSel(0);//默认选择第一个

	//人数默认选择1个
	SetDlgItemText(IDC_EDIT_Buy_sum,_T("1"));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}




void BuyDlg::FreshData(CString User)
{

}


/*void updatePicket(PBuyPicketHistory buy)
{
int flag=1;
int person=3;
int sceneNum=3;
char sceneName[100]="sdlfjkas";
char time[100]="sdlfjkas";
char timeFormat[100]="sdlfjkas";
char sceneSpotName[100][100]={"景点一","经典二","景点三"};
buy->picket[buy->curNum].flag=flag;
buy->picket[buy->curNum].person=person;
buy->picket[buy->curNum].sceneNum=sceneNum;
strcpy(buy->picket[buy->curNum].sceneName,sceneName);
strcpy(buy->picket[buy->curNum].time,time);
strcpy(buy->picket[buy->curNum].timeFormat,timeFormat);
for(int i=0;i<sceneNum;i++)
strcpy(buy->picket[buy->curNum].sceneSpotName[i],sceneSpotName[i]);
buy->curNum++;
FILE *file=fopen("C:/Users/lenovo/Desktop/tt.txt","w");
fprintf(file,"%d\n",buy->curNum);
for(int i=0;i<buy->curNum;i++)
{
fprintf(file,"%s %s %s %d %d %d",buy->picket[i].sceneName,buy->picket[i].time,buy->picket[i].timeFormat,buy->picket[i].flag,buy->picket[i].person,buy->picket[i].sceneNum);
for(int j=0;j<buy->picket[i].sceneNum;j++)
fprintf(file," %s",buy->picket[i].sceneSpotName[j]);
fprintf(file,"\n");
} 
fclose(file);		
}*/

void BuyDlg::OnBnClickedButton2()//查询按钮
{
	// TODO: 在此添加控件通知处理程序代码

	//int index_jq = mBuyComboBox_jq.GetCurSel(); 
	//int index_fs = mBuyComboBox_lx.GetCurSel(); 
	//OnInitDialog();
	ComDlg *pDlg = (ComDlg *)GetParent()->GetParent();
	PGraph *pG;
	pG=pDlg->create_example_graph();

	//for(int i=0;i<mBuy_CheckList.GetCurSel();i++)
	{
		//mBuy_CheckList.DeleteString();
	}
	mBuy_CheckList.ResetContent();//刷新列表

	int pr;
	CString strI;
	for(int i=0;i<pG[0]->vexnum;i++)
	{
		CString v_name;
		v_name=pG[0]->vexs[i];
		pr=price(v_name);
		strI.Format(_T("%d"),pr); 
		v_name+="  ";
		v_name+=strI;
		v_name+="元/人";
		mBuy_CheckList.AddString(v_name);
	}



}

int  BuyDlg::price(CString Namw)
{	char name_rists[40];
int Price;
CString a;
FILE *fp = NULL;
fp = fopen("price.txt", "r");
while(!feof(fp))
{
	fscanf(fp,"%s",name_rists);
	fscanf(fp,"%d",&Price);
	a=name_rists;
	if(!a.Compare(Namw))
	{
		fclose(fp);
		return Price;
	}
}

return 0;
}



void BuyDlg::OnBnClickedButton1()//订购按钮
{
	// TODO: 在此添加控件通知处理程序代码
	//int nIndex;
	//mBuy_CheckList.GetCheck(nIndex);
	//m_CheckListBox.GetCheck(nIndex);
	//MessageBox(_T("订购成功！"));
	CString sum_001;
	CString Year,Month,Day;
	CString time_now;
	CString time_future;
	GetDlgItemText(IDC_EDIT_Buy_sum,sum_001);//获取景点名称
	if(!sum_001.Compare(_T("")))
	{
	
		MessageBox(_T("请输入人数！"), _T("提示"));
		return ;
	}

			/////获取系统时间
		time_t now ;
		struct tm *tm_now ;
		time(&now) ;
		tm_now = localtime(&now) ;
		//printf("now datetime: %d-%d-%d %d:%d:%d\n",
		//tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec) ;
		CString Str;
		Str.Format(_T("%d"),tm_now->tm_year+1900);
		time_now+=Str;
		time_now+="/";
		Str.Format(_T("%d"),tm_now->tm_mon+1);
		time_now+=Str;	
		time_now+="/";
		Str.Format(_T("%d"),tm_now->tm_mday);
		time_now+=Str;
				////////获取日期
		int index= mCOMBO_Buy_year.GetCurSel();
		mCOMBO_Buy_year.GetLBText(index,Year);
		//Year.Format(_T("%d"),index+1);

		index = mCOMBO_Buy_month.GetCurSel();
		Month.Format(_T("%d"),index+1);

		index = mCOMBO_Buy_day.GetCurSel();
		Day.Format(_T("%d"),index+1);




	int clkMark = MessageBox(_T("确定要订购吗"), _T("提示"));
	int selMark;
	selMark=0;
	int iSel=mBuy_CheckList.GetCount();

	if(clkMark ==IDOK) 
	{
		for(int i=0;i<iSel;i++)
		{
			//int ik=mBuy_CheckList.GetCheck(i);
			if(mBuy_CheckList.GetCheck(i)==1)
			{
				selMark=1;
			}
		}
		if(selMark == 0)
		{
			MessageBox(_T("请先选中要订购的条目！"), _T("提示"), MB_OK);
			return;
		}

		//CString sum_001;
		//GetDlgItemText(IDC_EDIT_Buy_sum,sum_001);
		int sum_int;
		sum_int = _ttoi(sum_001);//字符串转整型


		CString str_Name;
		GetDlgItemText(IDC_COMBO_Buy_jq,str_Name);//获取景点名称



		time_future+=Year;
		time_future+="/";
		time_future+=Month;
		time_future+="/";
		time_future+=Day;





		MainDlg *pDlg = (MainDlg *)GetParent()->GetParent();
		for(int i=0;i<iSel;i++)
		{
			//int ik=mBuy_CheckList.GetCheck(i);
			if(mBuy_CheckList.GetCheck(i)==1)
			{
				CString strC;  
				mBuy_CheckList.GetText(i,strC); //获取行下对应的字符串
				int index = mBuy_CheckList.GetCurSel()+1; 
				CCHJY_NinthDlg *pDlg = (CCHJY_NinthDlg *)GetParent()->GetParent();
				pDlg->Add_Main_messge(strC, time_now, time_future, sum_int, 0);//发送消息到主界面
				//pDlg->FreshAll(user,spw);
				//pDlg->Add_messge(strC, time_now, time_future, sum_int, 1);//发送消息到主界面
			}  

		}
		MessageBox(_T("订购成功！"),_T("提示"));
		return;
	}
}

void BuyDlg::OnBnClickedButton3()//全选按钮
{
	// TODO: 在此添加控件通知处理程序代码
	int iSel=mBuy_CheckList.GetCount();
	for(int i=0;i<iSel;i++)
	{
		//if(mBuy_CheckList.GetCheck(i)==1)
		//mBuy_CheckList.SetCheck(i,0);
		mBuy_CheckList.SetCheck(i,1);

	}


}


void BuyDlg::OnCbnSelchangeComboBuymonth()
{
	// TODO: 在此添加控件通知处理程序代码

	mCOMBO_Buy_day.ResetContent();

	int year,month,day = 31;
	CString time_001;
	////////获取日期
	int index= mCOMBO_Buy_year.GetCurSel();
	year=index+1;
	index = mCOMBO_Buy_month.GetCurSel();
	month=index+1;

	if(month == 4||month==6||month==9||month==11)
	{
		day = 30;
	}
	if(month==2)
	{
		day = 28 + (year%4==0&&year%100!=0||year%400==0);
	}
		for(int i=1;i<=day;i++)//日
	{
		time_001.Format(_T("%d"),i);
		mCOMBO_Buy_day.AddString(time_001);  
	}
	mCOMBO_Buy_day.SetCurSel(0);//默认选择第一个

}


void BuyDlg::OnCbnSelchangeComboBuyjq()
{
	// TODO: 在此添加控件通知处理程序代码
		int index = mBuyComboBox_jq.GetCurSel();       //这个函数用于得到用户选择的是下拉列表中的第几行，第一行的话，返回0，依次类推  
	CString strI;  
	strI.Format(_T("%d"),index);  
	CString strC;  
	mBuyComboBox_jq.GetLBText(index,strC);        //根据行号，这个可以得到那行的字符串  
	//strC += strI; 
	strC+="暂未开放！";
	MessageBox(strC,_T("提示"));
	mBuyComboBox_jq.SetCurSel(0);
}


void BuyDlg::OnCbnSelchangeComboBuytype()
{
	// TODO: 在此添加控件通知处理程序代码

	if(mBuyComboBox_lx.GetCurSel()==1)
	{

		ComDlg *pDlg = (ComDlg *)GetParent()->GetParent();
		PGraph *pG;
		pG=pDlg->create_example_graph();

		//for(int i=0;i<mBuy_CheckList.GetCurSel();i++)
		{
			//mBuy_CheckList.DeleteString();
		}
		mBuy_CheckList.ResetContent();//刷新列表

		int pr;
		CString strI;
		CString strall[30];
		int a[30];
		for(int i=0;i<pG[0]->vexnum;i++)
		{
			CString v_name;
			v_name=pG[0]->vexs[i];
			pr=price(v_name);
			a[i]=pr;
			strI.Format(_T("%d"),pr); 
			v_name+="  ";
			v_name+=strI;
			v_name+="元/人";
			strall[i]=v_name;
			
		}
		InsertSort(a, pG[0]->vexnum,strall) ;

		for(int i=0;i<pG[0]->vexnum;i++)
		mBuy_CheckList.AddString(strall[i]);
	}
}
void BuyDlg::InsertSort(int  a[], int n,CString key[]) 
{
    int tmp = 0;
	CString tem;
    for (int i = 1; i < n; i++) {
        int j = i - 1;
        if (a[i] < a[j]) {
            tmp = a[i];tem=key[i];
            a[i] = a[j];key[i]=key[j];
            while (j-1>=0&&tmp <= a[j-1]) {//注意，原句为while (tmp <a[j-1])，
                a[j] = a[j-1];				// 这里会出现a[-1],且a[-1]=0. 所以这里不能排序一组含有负数的数组 
                key[j]=key[j-1];
				j--;
            }
            a[j] = tmp;
			key[j]=tem;
        }
    }
}