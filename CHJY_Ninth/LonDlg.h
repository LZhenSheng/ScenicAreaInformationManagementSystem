#pragma once
#include "LonDlg_1.h"

// LonDlg 对话框

class LonDlg : public CDialogEx
{
	DECLARE_DYNAMIC(LonDlg)

public:
	LonDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~LonDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_Lon };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

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
