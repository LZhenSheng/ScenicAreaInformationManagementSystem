#pragma once
#include "afxwin.h"


// FindDlg �Ի���

class FindDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FindDlg)

public:
	FindDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FindDlg();
// �Ի�������
	enum { IDD = IDD_DIALOG_Find };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	void FreshData(CString User);
	afx_msg void OnCbnSelchangeComboFindjqname();
	virtual BOOL OnInitDialog();
	CComboBox mFindCombBox_jq;
	CComboBox mFindCombBox_fs;
	CComboBox mFindCombBox_vs;
	CComboBox mFindComboBox_vt;
	afx_msg void OnBnClickedButtonFindrou();
	//ComDlg *pDlg;
	
	afx_msg void OnCbnSelchangeComboFindtjfs();
};

