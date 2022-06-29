
// CHJY_NinthDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "CHJY_NinthDlg.h"
#include "afxdialogex.h"
#include "LonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCHJY_NinthDlg 对话框




CCHJY_NinthDlg::CCHJY_NinthDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCHJY_NinthDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCHJY_NinthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCHJY_NinthDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCHJY_NinthDlg::OnBnClickedButton1)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &CCHJY_NinthDlg::OnTcnSelchangeTab)
END_MESSAGE_MAP()


// CCHJY_NinthDlg 消息处理程序

BOOL CCHJY_NinthDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	User_Main="";

	mMainTabCtrl = (CTabCtrl *)GetDlgItem(IDC_TAB);
	mMainTabCtrl->InsertItem(0, _T(" 主界面 "));
	mMainTabCtrl->InsertItem(1, _T("  购票  "));
	mMainTabCtrl->InsertItem(2, _T(" 评论区 "));
	mMainTabCtrl->InsertItem(3, _T("  查询  "));
	mMainTabCtrl->InsertItem(4, _T("  关于  "));



	CRect rs;
	mMainTabCtrl->GetClientRect(&rs);
	rs.top += 26;
	rs.bottom += 0;
	rs.left += 0;
	rs.right += 3;
	
	mMainDlg.Create(IDD_DIALOG_Main, GetDlgItem(IDC_TAB));
	mFindDlg.Create(IDD_DIALOG_Find, GetDlgItem(IDC_TAB));
	mBuyDlg.Create(IDD_DIALOG_Buy, GetDlgItem(IDC_TAB));
	mComDlg.Create(IDD_DIALOG_Com, GetDlgItem(IDC_TAB));
	mHelDlg.Create(IDD_DIALOG_Hel, GetDlgItem(IDC_TAB));

	mMainDlg.MoveWindow(&rs);
	mFindDlg.MoveWindow(&rs);
	mBuyDlg.MoveWindow(&rs);
	mComDlg.MoveWindow(&rs);
	mHelDlg.MoveWindow(&rs);

	mMainDlg.ShowWindow(true);
	mFindDlg.ShowWindow(false);
	mBuyDlg.ShowWindow(false);
	mComDlg.ShowWindow(false);
	mHelDlg.ShowWindow(false);

	mMainTabCtrl->SetCurSel(0);



		







	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCHJY_NinthDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCHJY_NinthDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	////背景图片绘制start
	    CBitmap m_bmp;      //存放位图对象
		CDC m_dc;           //DC对象
		//加载位图
    CBitmap bmp;
    bmp.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_bk1));
    //添加位图
    m_bmp.Attach(bmp);
    //创建兼容DC
    CDC* pDc = GetDC();
    m_dc.CreateCompatibleDC(pDc);
    //用完之后释放
    ReleaseDC(pDc);
    //把位图对象选入DC中
    m_dc.SelectObject(&m_bmp);
    //使窗口无效,这样OnPaint函数就会被触发,使之被画出来
    Invalidate(FALSE);
	 //画图DC
        CPaintDC dc(this);
        CRect rect = 0;
        GetClientRect(&rect);
        //缩放位图
        BITMAP bm;
        m_bmp.GetBitmap(&bm);
        dc.StretchBlt(0, 0, rect.Width(), rect.Height(),&m_dc, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
        //CDialogEx::OnPaint();
		//背景图片绘制end



}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCHJY_NinthDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCHJY_NinthDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	mLonDlg.DoModal();


}


void CCHJY_NinthDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int sel = mMainTabCtrl->GetCurSel();
	switch(sel)
	{
		case 0:
	mMainDlg.ShowWindow(true);
	mFindDlg.ShowWindow(false);
	mBuyDlg.ShowWindow(false);
	mComDlg.ShowWindow(false);
	mHelDlg.ShowWindow(false);
			break;

		case 1:
	mBuyDlg.ShowWindow(true);
	mMainDlg.ShowWindow(false);
	mFindDlg.ShowWindow(false);
	mComDlg.ShowWindow(false);
	mHelDlg.ShowWindow(false);
			break;
		
		case 2:
	mComDlg.ShowWindow(true);
	mMainDlg.ShowWindow(false);
	mFindDlg.ShowWindow(false);
	mBuyDlg.ShowWindow(false);
	mHelDlg.ShowWindow(false);
			break;


		case 3:
	mFindDlg.ShowWindow(true);
	mMainDlg.ShowWindow(false);
	mBuyDlg.ShowWindow(false);
	mComDlg.ShowWindow(false);
	mHelDlg.ShowWindow(false);
			break;

			case 4:
	mHelDlg.ShowWindow(true);
	mMainDlg.ShowWindow(false);
	mFindDlg.ShowWindow(false);
	mBuyDlg.ShowWindow(false);
	mComDlg.ShowWindow(false);
	
		break;
	}



	*pResult = 0;
}

void CCHJY_NinthDlg::FreshAll(CString User, CString Password)
{

	//MessageBox(User,Password);
	User_Main=User;
	CString Strc;
	Strc="";

	mComDlg.FreshData(0,Strc);
	mMainDlg.FreshData(User);
	mFindDlg.FreshData(User);
	mBuyDlg.FreshData(User);



}

void CCHJY_NinthDlg::Add_Main_messge(CString rests, CString time, CString timeFormat, int sum, int flag)
{
	mMainDlg.Add_messge(rests,time,timeFormat,sum,flag);

}
void CCHJY_NinthDlg::Add_Com_messge(CString com)
{
	mComDlg.Add_c_messge(com);
}

