// FindDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "FindDlg.h"
#include "afxdialogex.h"
#include "ComDlg.h"
const int SCENESPOT=5;
// FindDlg 对话框

IMPLEMENT_DYNAMIC(FindDlg, CDialogEx)

FindDlg::FindDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(FindDlg::IDD, pParent)
{

}

FindDlg::~FindDlg()
{
}

void FindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_Find_jq_name, mFindCombBox_jq);
	DDX_Control(pDX, IDC_COMBO_Find_tj_fs, mFindCombBox_fs);
	DDX_Control(pDX, IDC_COMBO_Find_jd_qd, mFindCombBox_vs);
	DDX_Control(pDX, IDC_COMBO_Find_jd_zd, mFindComboBox_vt);
}


BEGIN_MESSAGE_MAP(FindDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_Find_jq_name, &FindDlg::OnCbnSelchangeComboFindjqname)
	ON_BN_CLICKED(IDC_BUTTON_Find_rou, &FindDlg::OnBnClickedButtonFindrou)
	ON_CBN_SELCHANGE(IDC_COMBO_Find_tj_fs, &FindDlg::OnCbnSelchangeComboFindtjfs)
END_MESSAGE_MAP()


// FindDlg 消息处理程序


void FindDlg::FreshData(CString User)
{
}



void FindDlg::OnCbnSelchangeComboFindjqname()
{
	// TODO: 在此添加控件通知处理程序代码
	//CCHJY_NinthDlg *pDlg = (CCHJY_NinthDlg *)GetParent()->GetParent();
  int index = mFindCombBox_jq.GetCurSel();       //这个函数用于得到用户选择的是下拉列表中的第几行，第一行的话，返回0，依次类推  
    CString strI;  
    strI.Format(_T("%d"),index);  
    CString strC;  
    mFindCombBox_jq.GetLBText(index,strC);        //根据行号，这个可以得到那行的字符串  
    //strC += strI; 
	strC+="暂未开放！";
  	MessageBox(strC,_T("提示"));
	mFindCombBox_jq.SetCurSel(0);

}


BOOL FindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
		//CWnd *pWnd= GetDlgItem(IDD_DIALOG_Com);
		//pWnd->m_hWnd;//得到这个子窗口的句柄
	//pDlg->cheshi();
	ComDlg *pDlg = (ComDlg *)GetParent()->GetParent();
	PGraph *pG;
	pG=pDlg->create_example_graph();
	///景区名称
	CString SCENENAME[5];
	SCENENAME[0]="贵州马头寨";
	SCENENAME[1]="未知地区0031";
	SCENENAME[2]="未知地区0120";
	SCENENAME[3]="未知地区0801";
	SCENENAME[4]="未知地区0908"; //这里会自动排序！！
	for(int i=SCENESPOT-1;i>=0;i--)
	{
		mFindCombBox_jq.AddString(SCENENAME[i]); 
	}
	mFindCombBox_jq.SetCurSel(0);//默认选择第一个

	///推荐方式
		CString tj_fs[2];
	tj_fs[0]="001最短路径";
	tj_fs[1]="002全景区";
	mFindCombBox_fs.AddString(tj_fs[0]); 
	mFindCombBox_fs.AddString(tj_fs[1]); 
	mFindCombBox_fs.SetCurSel(0);//默认选择第一个


	//景区起点
	for(int i=0,j=0;i<pG[0]->vexnum;i++)
	{
		CString v_name;
		v_name=pG[0]->vexs[i];
		mFindCombBox_vs.AddString(v_name); 
	}
	mFindCombBox_vs.SetCurSel(0);//默认选择第一个
	///景区终点
	for(int i=0,j=0;i<pG[0]->vexnum;i++)
	{
		CString v_name;
		v_name=pG[0]->vexs[i];
		mFindComboBox_vt.AddString(v_name); 
	}
	mFindComboBox_vt.SetCurSel(0);//默认选择第一个



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void FindDlg::OnBnClickedButtonFindrou()
{
	// TODO: 在此添加控件通知处理程序代码

	int index_jq = mFindCombBox_jq.GetCurSel(); 
	int index_fs = mFindCombBox_fs.GetCurSel(); 
	int index_vs = mFindCombBox_vs.GetCurSel(); 
	int index_vt = mFindComboBox_vt.GetCurSel(); 
	ComDlg *pDlg = (ComDlg *)GetParent()->GetParent();
	PGraph *pG;
	pG=pDlg->create_example_graph();
	CString result;
	switch(index_fs)
	{
	case 0:

		result=pDlg->dijkstra(*pG[index_jq],index_vs,index_vt);//(*pG[NOWSCENESPOT],qishi,zhong)
		SetDlgItemText(IDC_EDIT_resu,result);//结果展示
		break;
	case 1:
		result=pDlg->getHMD(*pG[index_jq]);
		//result=pDlg->dijkstra(*pG[index_jq],index_vs,index_vt);//(*pG[NOWSCENESPOT],qishi,zhong)
		SetDlgItemText(IDC_EDIT_resu,result);//结果展示
		break;
	}








}


void FindDlg::OnCbnSelchangeComboFindtjfs()
{
	// TODO: 在此添加控件通知处理程序代码



}
