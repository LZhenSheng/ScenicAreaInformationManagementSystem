#pragma once
#include "LonDlg_1.h"

// LonDlg �Ի���

class LonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LonDlg)

public:
	LonDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LonDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_Lon };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonres();
	CString m_strUser;
	CString m_strPassword; 
	bool ConnectMySQL(CString User, CString Password);
	afx_msg void OnBnClickedButtonLon();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
};
