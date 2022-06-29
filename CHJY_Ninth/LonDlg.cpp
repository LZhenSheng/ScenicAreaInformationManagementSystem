// LonDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "LonDlg.h"
#include "afxdialogex.h"
#include "CHJY_NinthDlg.h"




typedef struct message{
	char name[100];//用户名 
	char password[100];//用户密码 
	int flag;//用户登录状态 
}User;
typedef User* UUser;
// LonDlg 对话框

IMPLEMENT_DYNAMIC(LonDlg, CDialogEx)

	LonDlg::LonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(LonDlg::IDD, pParent)
{

}

LonDlg::~LonDlg()
{
}

void LonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LonDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_res, &LonDlg::OnBnClickedButtonres)
	ON_BN_CLICKED(IDC_BUTTON_Lon, &LonDlg::OnBnClickedButtonLon)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// LonDlg 消息处理程序


void LonDlg::OnBnClickedButtonres()
{
	// TODO: 在此添加控件通知处理程序代码

	CString user,spwd;
	GetDlgItemText(IDC_EDIT_user,user);
	GetDlgItemText(IDC_EDIT_password,spwd);

			if(!user.Compare(_T("")))
		{
			MessageBox(_T("账号不能为空！"),_T("提示"));
			return;
		}
			if( !spwd.Compare(_T("")))
		{
			MessageBox(_T("密码不能为空！"),_T("提示"));
			return;
		}

	BOOL key=ConnectMySQL(user,spwd);
	if(key)
	{

		int clkMark=MessageBox(_T("登录成功"),_T("状态"));
		if(clkMark==IDOK)
		CDialog::OnOK();
		CCHJY_NinthDlg *pDlg = (CCHJY_NinthDlg *)GetParent();
		pDlg->FreshAll(user,spwd);

	}
	else
	{
		MessageBox(_T("用户名或密码不正确"),_T("登录失败"));
	}


}

bool LonDlg::ConnectMySQL(CString User, CString Password)
{

	UUser user=new struct message;
	FILE *fp = NULL;
	fp = fopen("login.txt", "r");

	while(!feof(fp))
	{
		fscanf(fp,"%s %s",user->name,user->password);
		CString a;
		a=user->name;
		CString b;
		b=user->password;


		if(!User.Compare(a)&& !Password.Compare(b))
		{
			fclose(fp);
			return true;
		}

	}



	return false;

}


void LonDlg::OnBnClickedButtonLon()
{
	// TODO: 在此添加控件通知处理程序代码
	LonDlg_1 mLon;
	mLon.DoModal();



}


void LonDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CDialog* pdlg=(CDialog*)AfxGetMainWnd();
	//pdlg->DestroyWindow();
	CDialogEx::OnClose();
}


BOOL LonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化,IDB_BITMAP_white001
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
