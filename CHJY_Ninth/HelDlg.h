#pragma once
#include "afxwin.h"


// HelDlg 对话框

class HelDlg : public CDialogEx
{
	DECLARE_DYNAMIC(HelDlg)

public:
	HelDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~HelDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_Hel };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CEdit mHelEdit;
};
