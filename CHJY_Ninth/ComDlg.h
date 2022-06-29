
#include "Struct_Tree_Area.h"



#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// ComDlg �Ի���

class ComDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ComDlg)

public:
	ComDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ComDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_Com };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	CListCtrl *mComListContrl;
	void FreshData(int index, CString strC);
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	//��ȡ���۵�λ�� 


	int getIndex(int left, int right);
	PPNode structTree(CComment * user, int left, int right);
	// ��������
	void updateComment(PGraph G, int n, char name[], char timeFormat[], char content[]);
	void addComment(PGraph G, int n);
	// ��ʼ������
	PPNode getComment(const char address[]);
	PGraph* create_example_graph(void);
	CString dijkstra(Graph G, int vs, int vt);
	void preOrder(PPNode p,int i);
	bool expend(int s);
	bool solve();//

	//PGraph* get_graph(void);
	PBuyPicketHistory createPicket();
	CString getHMD(Graph G);
	CComboBox mConComboBox;
	void cheshi(void);
	void Add_c_messge(CString com);
};
