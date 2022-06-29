#pragma once


// com_all_Dlg 对话框

class com_all_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(com_all_Dlg)

public:
	com_all_Dlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~com_all_Dlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_com_all };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
