#pragma once


// RecDlg �Ի���

class RecDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RecDlg)

public:
	RecDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~RecDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG3_Rec };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
