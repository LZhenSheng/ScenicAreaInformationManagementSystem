
// CHJY_NinthDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "CHJY_NinthDlg.h"
#include "afxdialogex.h"
#include "LonDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CCHJY_NinthDlg �Ի���




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


// CCHJY_NinthDlg ��Ϣ�������

BOOL CCHJY_NinthDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	User_Main="";

	mMainTabCtrl = (CTabCtrl *)GetDlgItem(IDC_TAB);
	mMainTabCtrl->InsertItem(0, _T(" ������ "));
	mMainTabCtrl->InsertItem(1, _T("  ��Ʊ  "));
	mMainTabCtrl->InsertItem(2, _T(" ������ "));
	mMainTabCtrl->InsertItem(3, _T("  ��ѯ  "));
	mMainTabCtrl->InsertItem(4, _T("  ����  "));



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



		







	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCHJY_NinthDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}

	////����ͼƬ����start
	    CBitmap m_bmp;      //���λͼ����
		CDC m_dc;           //DC����
		//����λͼ
    CBitmap bmp;
    bmp.LoadBitmap(MAKEINTRESOURCE(IDB_BITMAP_bk1));
    //���λͼ
    m_bmp.Attach(bmp);
    //��������DC
    CDC* pDc = GetDC();
    m_dc.CreateCompatibleDC(pDc);
    //����֮���ͷ�
    ReleaseDC(pDc);
    //��λͼ����ѡ��DC��
    m_dc.SelectObject(&m_bmp);
    //ʹ������Ч,����OnPaint�����ͻᱻ����,ʹ֮��������
    Invalidate(FALSE);
	 //��ͼDC
        CPaintDC dc(this);
        CRect rect = 0;
        GetClientRect(&rect);
        //����λͼ
        BITMAP bm;
        m_bmp.GetBitmap(&bm);
        dc.StretchBlt(0, 0, rect.Width(), rect.Height(),&m_dc, 0, 0, bm.bmWidth, bm.bmHeight, SRCCOPY);
        //CDialogEx::OnPaint();
		//����ͼƬ����end



}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCHJY_NinthDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCHJY_NinthDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	mLonDlg.DoModal();


}


void CCHJY_NinthDlg::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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

