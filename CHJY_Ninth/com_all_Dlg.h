#pragma once


// com_all_Dlg �Ի���

class com_all_Dlg : public CDialogEx
{
	DECLARE_DYNAMIC(com_all_Dlg)

public:
	com_all_Dlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~com_all_Dlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_com_all };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
