#pragma once


// RecDlg 对话框

class RecDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RecDlg)

public:
	RecDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~RecDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG3_Rec };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
