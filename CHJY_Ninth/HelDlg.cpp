// HelDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "HelDlg.h"
#include "afxdialogex.h"


// HelDlg �Ի���

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


// HelDlg ��Ϣ�������


BOOL HelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	//CString an;
	//an="233333";
	//SetDlgItemText(IDC_EDIT1,an);



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
