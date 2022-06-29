
// CHJY_NinthDlg.h : ͷ�ļ�
//
#include "ComDlg.h"
#include "BuyDlg.h"
#include "RecDlg.h"
#include "LonDlg.h"
#include "HelDlg.h"
#include "MainDlg.h"
#include "FindDlg.h"
#pragma once


// CCHJY_NinthDlg �Ի���
class CCHJY_NinthDlg : public CDialogEx
{
// ����
public:
	CCHJY_NinthDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CHJY_NINTH_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	private:

	CTabCtrl* mMainTabCtrl;

	ComDlg mComDlg;
	BuyDlg mBuyDlg;
	RecDlg mRecDlg;
	LonDlg mLonDlg;

	HelDlg mHelDlg;

	MainDlg mMainDlg;

	FindDlg mFindDlg;


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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

