#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// BuyDlg 对话框

class BuyDlg : public CDialogEx
{
	DECLARE_DYNAMIC(BuyDlg)

public:
	BuyDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~BuyDlg();


// 对话框数据
	enum { IDD = IDD_DIALOG_Buy };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
		CListCtrl* mBuyListCtrl;
//		bool ConnectMySQL(CString User, CString Password);
		void FreshData(CString User);
		//CListCtrl* mBuyList;
		//CCheckListBox m_ListFiles;
		CComboBox mBuyComboBox_lx;
		CComboBox mBuyComboBox_jq;
		afx_msg void OnBnClickedButton2();
		CCheckListBox mBuy_CheckList;
		afx_msg void OnBnClickedButton1();
		afx_msg void OnBnClickedButton3();
		int  price(CString Namw);
		CComboBox mCOMBO_Buy_year;
		CComboBox mCOMBO_Buy_month;
		CComboBox mCOMBO_Buy_day;
		afx_msg void OnCbnSelchangeComboBuymonth();
		afx_msg void OnCbnSelchangeComboBuyjq();
		afx_msg void OnCbnSelchangeComboBuytype();
		void InsertSort(int  a[], int n,CString key[]) ;
};
