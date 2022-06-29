
// CHJY_NinthDlg.h : 头文件
//
#include "ComDlg.h"
#include "BuyDlg.h"
#include "RecDlg.h"
#include "LonDlg.h"
#include "HelDlg.h"
#include "MainDlg.h"
#include "FindDlg.h"
#pragma once


// CCHJY_NinthDlg 对话框
class CCHJY_NinthDlg : public CDialogEx
{
// 构造
public:
	CCHJY_NinthDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CHJY_NINTH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

	private:

	CTabCtrl* mMainTabCtrl;

	ComDlg mComDlg;
	BuyDlg mBuyDlg;
	RecDlg mRecDlg;
	LonDlg mLonDlg;

	HelDlg mHelDlg;

	MainDlg mMainDlg;

	FindDlg mFindDlg;


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
	void FreshAll(CString User, CString Password);
	void Add_Main_messge(CString rests, CString time, CString timeFormat, int sum, int flag);
	void Add_Com_messge(CString com);

	CString User_Main;
};

