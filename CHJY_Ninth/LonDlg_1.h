#pragma once


// LonDlg_1 �Ի���

class LonDlg_1 : public CDialogEx
{
	DECLARE_DYNAMIC(LonDlg_1)

public:
	LonDlg_1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~LonDlg_1();

// �Ի�������
	enum { IDD = IDD_DIALOG_Lon_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	bool LonginWriteFile(CString Phone, CString Pass);
	bool IfExist(CString Phone, CString Pass);
	virtual BOOL OnInitDialog();
};
