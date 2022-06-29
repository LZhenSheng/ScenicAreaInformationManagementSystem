// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include "ComDlg.h"
#include "com_all_Dlg.h"


// MainDlg 对话框

IMPLEMENT_DYNAMIC(MainDlg, CDialogEx)

MainDlg::MainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MainDlg::IDD, pParent)
{

}

MainDlg::~MainDlg()
{
}

void MainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(MainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &MainDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_delete, &MainDlg::OnBnClickedButtondelete)
	ON_BN_CLICKED(IDC_BUTTON_com, &MainDlg::OnBnClickedButtoncom)
END_MESSAGE_MAP()


// MainDlg 消息处理程序


	
BOOL MainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	mMainListCtrl = (CListCtrl *)GetDlgItem(IDC_LIST_Main);


	LONG styles=GetWindowLong(mMainListCtrl->m_hWnd, GWL_STYLE); 
    SetWindowLong(mMainListCtrl->m_hWnd, GWL_STYLE, styles|LVS_REPORT);
	mMainListCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT);

	CRect rs;
	GetClientRect(&rs);
	int colWidth = rs.Width()/8;	//get col width

	mMainListCtrl->InsertColumn(0, _T("景点名称"), LVCFMT_LEFT, colWidth, 0);
	mMainListCtrl->InsertColumn(1, _T("购票时间"), LVCFMT_CENTER, colWidth*2, 1);
	mMainListCtrl->InsertColumn(2, _T("抵达时间"), LVCFMT_CENTER, colWidth*2, 2);
	mMainListCtrl->InsertColumn(3, _T("人数"), LVCFMT_CENTER, colWidth*2, 3);
	mMainListCtrl->InsertColumn(4, _T("状态"), LVCFMT_LEFT, colWidth, 4);


	//FreshData(_T(""));







	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void MainDlg::FreshData(CString User)
{

	ComDlg *pDlg = (ComDlg *)GetParent()->GetParent();
	PBuyPicketHistory buy;
	buy=pDlg->createPicket();
	//mMainListCtrl=(CListCtrl *)GetDlgItem(IDC_LIST_Buy);
	CString Str;
		for(int i=0;i<buy->curNum;i++)
	{
		//fscanf(file,"%s%s%s%d%d%d",buy->picket[i].sceneName,buy->picket[i].time,buy->picket[i].timeFormat,&buy->picket[i].flag,&buy->picket[i].person,&buy->picket[i].sceneNum);
		//for(int j=0;j<buy->picket[i].sceneNum;j++)
			//fscanf(file,"%s",buy->picket[i].sceneSpotName[j]);


	int index = mMainListCtrl->GetItemCount();
	int addRow = mMainListCtrl->InsertItem(index, _T(""));
	Str=buy->picket[i].sceneName;
	mMainListCtrl->SetItemText(addRow, 0,Str );

	Str=buy->picket[i].time;
	mMainListCtrl->SetItemText(addRow, 1,Str );

	Str=buy->picket[i].timeFormat;
	mMainListCtrl->SetItemText(addRow, 2,Str );



	Str.Format(_T("%d"), buy->picket[i].person);
	mMainListCtrl->SetItemText(addRow, 3, Str);
	if(buy->picket[i].flag==0)
	{
		Str="未开放";
	}else
	{
		Str="开放";
	}
	//Str.Format(_T("%d"), buy->picket[i].flag);
	mMainListCtrl->SetItemText(addRow, 4, Str);
	} 



}


void MainDlg::OnBnClickedButton1()//删除记录
{
	// TODO: 在此添加控件通知处理程序代码





}


void MainDlg::Add_messge(CString rests, CString time, CString timeFormat, int sum, int flag)
{


	int index = mMainListCtrl->GetItemCount();
	int addRow = mMainListCtrl->InsertItem(index, _T(""));
	CString Str;
	mMainListCtrl->SetItemText(addRow, 0,rests );
	mMainListCtrl->SetItemText(addRow, 1,time );
	mMainListCtrl->SetItemText(addRow, 2,timeFormat );
	Str.Format(_T("%d"),sum);
	mMainListCtrl->SetItemText(addRow, 3, Str);
	if(flag==0)
	{
		Str="未开放";
	}else
	{
		Str="开放";
	}
	mMainListCtrl->SetItemText(addRow, 4, Str);
	
}


void MainDlg::OnBnClickedButtondelete()
{
	// TODO: 在此添加控件通知处理程序代码

	int nId; 
	//首先得到点击的位置 
	POSITION pos=mMainListCtrl->GetFirstSelectedItemPosition(); 
	if(pos==NULL) 
	{ 
		MessageBox(_T("请至少选择一项"), _T("提示")); 
		return; 
	} 
	//得到行号，通过POSITION转化 
	nId=(int)mMainListCtrl->GetNextSelectedItem(pos); 

	//int index=mMainListCtrl->GetSelectedCount();
		int clkMark = MessageBox(_T("确定要删除吗"), _T("提示"),MB_OKCANCEL );

		if(clkMark ==IDOK) {
			mMainListCtrl->DeleteItem(nId);
		}



}


void MainDlg::OnBnClickedButtoncom()//进入评价
{
	// TODO: 在此添加控件通知处理程序代码

		int nId; 
	//首先得到点击的位置 
	POSITION pos=mMainListCtrl->GetFirstSelectedItemPosition(); 
	if(pos==NULL) 
	{ 
		MessageBox(_T("请至少选择一项"), _T("提示")); 
		return; 
	} 


	com_all_Dlg pdlg;
	pdlg.DoModal();

	//得到行号，通过POSITION转化 
	//nId=(int)mMainListCtrl->GetNextSelectedItem(pos); 
		//int index=mMainListCtrl->GetSelectedCount();
		//int clkMark = MessageBox(_T("确定要删除吗"), _T("提示"),MB_OKCANCEL );

		//if(clkMark ==IDOK) {
		//	mMainListCtrl->DeleteItem(nId);
		//}


}
