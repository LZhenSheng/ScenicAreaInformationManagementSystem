#pragma once
#include "afxwin.h"


// HelDlg �Ի���

class HelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(HelDlg)

public:
	HelDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~HelDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_Hel };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit mHelEdit;
};
