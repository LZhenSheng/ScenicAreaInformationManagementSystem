// LonDlg_1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "LonDlg_1.h"
#include "afxdialogex.h"
#include <fstream>
#include<iomanip>
using namespace std;

// LonDlg_1 �Ի���

IMPLEMENT_DYNAMIC(LonDlg_1, CDialogEx)

LonDlg_1::LonDlg_1(CWnd* pParent /*=NULL*/)
	: CDialogEx(LonDlg_1::IDD, pParent)
{

}

LonDlg_1::~LonDlg_1()
{
}

void LonDlg_1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LonDlg_1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &LonDlg_1::OnBnClickedButton1)
END_MESSAGE_MAP()


// LonDlg_1 ��Ϣ�������


void LonDlg_1::OnBnClickedButton1()///ע��
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

		CString phone,pass_0,pass_1;
		CString null_0;
		null_0="";
	GetDlgItemText(IDC_EDIT_phone,phone);
	GetDlgItemText(IDC_EDIT_pass_0,pass_0);
	GetDlgItemText(IDC_EDIT_pass_1,pass_1);
	BOOL compare_same=false;
	BOOL compare_lenth=false;

		if( !phone.Compare(_T("")))
		{
			MessageBox(_T("�˺Ų���Ϊ�գ���"),_T("��ʾ"));
			return;
		}
		if( !pass_0.Compare(_T(""))||!pass_1.Compare(_T("")))
		{
			MessageBox(_T("���벻��Ϊ�գ�"),_T("��ʾ"));
			return;
		}



	if(!pass_0.Compare(pass_1))
	{
		compare_same=true;
	}
	else
	{
		MessageBox(_T("���벻��ͬ�����������룡"),_T("��ʾ"));
		SetDlgItemText(IDC_EDIT_pass_0,null_0);
		SetDlgItemText(IDC_EDIT_pass_1,null_0);
		return;
	}

	if(pass_0.GetLength()>=8 && pass_0.GetLength()<=16)
	{
		compare_lenth=true;
	}
	else
	{
		MessageBox(_T("���볤�Ȳ���ȷ�����������룡"),_T("��ʾ"));
		SetDlgItemText(IDC_EDIT_pass_0,null_0);
		SetDlgItemText(IDC_EDIT_pass_1,null_0);
		return;
	}

	if(IfExist(phone,pass_0))
	{
		MessageBox(_T("�˺��Ѿ�ע�ᣡ"),_T("��ʾ"));
		return;
	}



	
	if(compare_same&&compare_lenth)
	{
		BOOL key=LonginWriteFile(phone,pass_0);
		if(key)
		{
		MessageBox(_T("ע��ɹ�"),_T("��ʾ"));
		SetDlgItemText(IDC_EDIT_phone,null_0);
		SetDlgItemText(IDC_EDIT_pass_0,null_0);
		SetDlgItemText(IDC_EDIT_pass_1,null_0);
		}
			else
			{
			MessageBox(_T("ע��ʧ�ܣ�"),_T("��ʾ"));
			}

	}




}


bool LonDlg_1::LonginWriteFile(CString Phone, CString Pass)
{

	FILE *fp = NULL;
   	fp = fopen("login.txt", "a+");

	char user[20];
	char key[16];
	int x=0;
	for(x=0;x<Phone.GetLength();x++)
	{
		user[x]=Phone.GetAt(x);
	}
	user[x]='\0';
	for(x=0;x<Pass.GetLength();x++)
	{
		key[x]=Pass.GetAt(x);
	}
	key[x]='\0';

  	fprintf(fp,"%s %s\n",user,key);


	  	fclose(fp);
		return true;





 
	return true;
}

typedef struct message{
	char name[100];//�û��� 
	char password[100];//�û����� 
	int flag;//�û���¼״̬ 
}User;
typedef User* UUser;

bool LonDlg_1::IfExist(CString Phone, CString Pass)
{

	FILE *fp = NULL;
	fp = fopen("login.txt", "r");

	UUser user=new struct message;
	while(!feof(fp))
	{
		fscanf(fp,"%s %s",user->name,user->password);
		CString a;
		a=user->name;
		if(!Phone.Compare(a))
		{
			fclose(fp);
			return true;
		}

	}
	fclose(fp);
	return false;
}


BOOL LonDlg_1::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
