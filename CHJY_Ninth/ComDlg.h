
#include "Struct_Tree_Area.h"



#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// ComDlg 对话框

class ComDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ComDlg)

public:
	ComDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ComDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_Com };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	CListCtrl *mComListContrl;
	void FreshData(int index, CString strC);
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	//获取评价的位置 


	int getIndex(int left, int right);
	PPNode structTree(CComment * user, int left, int right);
	// 增加评论
	void updateComment(PGraph G, int n, char name[], char timeFormat[], char content[]);
	void addComment(PGraph G, int n);
	// 初始化评论
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
