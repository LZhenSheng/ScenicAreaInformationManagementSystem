#pragma once


// MainDlg 对话框

class MainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MainDlg)

public:
	MainDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MainDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_Main };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl* mMainListCtrl;
	void FreshData(CString User);
	afx_msg void OnBnClickedButton1();
	void Add_messge(CString rests, CString time, CString timeFormat, int sum, int flag);
	afx_msg void OnBnClickedButtondelete();
	afx_msg void OnBnClickedButtoncom();
};
