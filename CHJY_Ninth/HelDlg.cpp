// HelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "HelDlg.h"
#include "afxdialogex.h"


// HelDlg 对话框

IMPLEMENT_DYNAMIC(HelDlg, CDialogEx)

HelDlg::HelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(HelDlg::IDD, pParent)
{

}

HelDlg::~HelDlg()
{
}

void HelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_EDIT1, mHelEdit);
}


BEGIN_MESSAGE_MAP(HelDlg, CDialogEx)
END_MESSAGE_MAP()


// HelDlg 消息处理程序


BOOL HelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//CString an;
	//an="233333";
	//SetDlgItemText(IDC_EDIT1,an);



	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
