// com_all_Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "com_all_Dlg.h"
#include "afxdialogex.h"
#include "CHJY_NinthDlg.h"
#include "time.h"
//#include "ComDlg.h"

// com_all_Dlg �Ի���

IMPLEMENT_DYNAMIC(com_all_Dlg, CDialogEx)

com_all_Dlg::com_all_Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(com_all_Dlg::IDD, pParent)
{

}

com_all_Dlg::~com_all_Dlg()
{
}

void com_all_Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(com_all_Dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &com_all_Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &com_all_Dlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// com_all_Dlg ��Ϣ�������


void com_all_Dlg::OnBnClickedButton2()//���
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		SetDlgItemText(IDC_EDIT_com_a,_T(""));

}


void com_all_Dlg::OnBnClickedButton1()//����
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString all;
	GetDlgItemText(IDC_EDIT_com_a,all);
	CCHJY_NinthDlg *pDlg = (CCHJY_NinthDlg *)GetParent();
	CString User_com;
	User_com=pDlg->User_Main;
		CString time_now;
		time_t now ;
		struct tm *tm_now ;
		time(&now) ;
		tm_now = localtime(&now) ;
		//printf("now datetime: %d-%d-%d %d:%d:%d\n",
		//tm_now->tm_year+1900, tm_now->tm_mon+1, tm_now->tm_mday, tm_now->tm_hour, tm_now->tm_min, tm_now->tm_sec) ;
		CString Str;
		time_now+="(";
		Str.Format(_T("%d"),tm_now->tm_year+1900);
		time_now+=Str;
		time_now+=".";
		Str.Format(_T("%d"),tm_now->tm_mon+1);
		time_now+=Str;	
		time_now+=".";
		Str.Format(_T("%d"),tm_now->tm_mday);
		time_now+=Str;
		time_now+=")";
		time_now+=all;
		User_com+=":";
		User_com+=time_now;
	pDlg->Add_Com_messge(User_com);
	
	MessageBox(_T("����ɹ���"), _T("��ʾ")); 
	//CDialog::OnCancel;
}
