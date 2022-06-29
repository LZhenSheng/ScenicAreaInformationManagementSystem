// FindDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CHJY_Ninth.h"
#include "FindDlg.h"
#include "afxdialogex.h"
#include "ComDlg.h"
const int SCENESPOT=5;
// FindDlg �Ի���

IMPLEMENT_DYNAMIC(FindDlg, CDialogEx)

FindDlg::FindDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(FindDlg::IDD, pParent)
{

}

FindDlg::~FindDlg()
{
}

void FindDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_Find_jq_name, mFindCombBox_jq);
	DDX_Control(pDX, IDC_COMBO_Find_tj_fs, mFindCombBox_fs);
	DDX_Control(pDX, IDC_COMBO_Find_jd_qd, mFindCombBox_vs);
	DDX_Control(pDX, IDC_COMBO_Find_jd_zd, mFindComboBox_vt);
}


BEGIN_MESSAGE_MAP(FindDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_Find_jq_name, &FindDlg::OnCbnSelchangeComboFindjqname)
	ON_BN_CLICKED(IDC_BUTTON_Find_rou, &FindDlg::OnBnClickedButtonFindrou)
	ON_CBN_SELCHANGE(IDC_COMBO_Find_tj_fs, &FindDlg::OnCbnSelchangeComboFindtjfs)
END_MESSAGE_MAP()


// FindDlg ��Ϣ�������


void FindDlg::FreshData(CString User)
{
}



void FindDlg::OnCbnSelchangeComboFindjqname()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CCHJY_NinthDlg *pDlg = (CCHJY_NinthDlg *)GetParent()->GetParent();
  int index = mFindCombBox_jq.GetCurSel();       //����������ڵõ��û�ѡ����������б��еĵڼ��У���һ�еĻ�������0����������  
    CString strI;  
    strI.Format(_T("%d"),index);  
    CString strC;  
    mFindCombBox_jq.GetLBText(index,strC);        //�����кţ�������Եõ����е��ַ���  
    //strC += strI; 
	strC+="��δ���ţ�";
  	MessageBox(strC,_T("��ʾ"));
	mFindCombBox_jq.SetCurSel(0);

}


BOOL FindDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
		//CWnd *pWnd= GetDlgItem(IDD_DIALOG_Com);
		//pWnd->m_hWnd;//�õ�����Ӵ��ڵľ��
	//pDlg->cheshi();
	ComDlg *pDlg = (ComDlg *)GetParent()->GetParent();
	PGraph *pG;
	pG=pDlg->create_example_graph();
	///��������
	CString SCENENAME[5];
	SCENENAME[0]="������ͷկ";
	SCENENAME[1]="δ֪����0031";
	SCENENAME[2]="δ֪����0120";
	SCENENAME[3]="δ֪����0801";
	SCENENAME[4]="δ֪����0908"; //������Զ����򣡣�
	for(int i=SCENESPOT-1;i>=0;i--)
	{
		mFindCombBox_jq.AddString(SCENENAME[i]); 
	}
	mFindCombBox_jq.SetCurSel(0);//Ĭ��ѡ���һ��

	///�Ƽ���ʽ
		CString tj_fs[2];
	tj_fs[0]="001���·��";
	tj_fs[1]="002ȫ����";
	mFindCombBox_fs.AddString(tj_fs[0]); 
	mFindCombBox_fs.AddString(tj_fs[1]); 
	mFindCombBox_fs.SetCurSel(0);//Ĭ��ѡ���һ��


	//�������
	for(int i=0,j=0;i<pG[0]->vexnum;i++)
	{
		CString v_name;
		v_name=pG[0]->vexs[i];
		mFindCombBox_vs.AddString(v_name); 
	}
	mFindCombBox_vs.SetCurSel(0);//Ĭ��ѡ���һ��
	///�����յ�
	for(int i=0,j=0;i<pG[0]->vexnum;i++)
	{
		CString v_name;
		v_name=pG[0]->vexs[i];
		mFindComboBox_vt.AddString(v_name); 
	}
	mFindComboBox_vt.SetCurSel(0);//Ĭ��ѡ���һ��



	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void FindDlg::OnBnClickedButtonFindrou()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	int index_jq = mFindCombBox_jq.GetCurSel(); 
	int index_fs = mFindCombBox_fs.GetCurSel(); 
	int index_vs = mFindCombBox_vs.GetCurSel(); 
	int index_vt = mFindComboBox_vt.GetCurSel(); 
	ComDlg *pDlg = (ComDlg *)GetParent()->GetParent();
	PGraph *pG;
	pG=pDlg->create_example_graph();
	CString result;
	switch(index_fs)
	{
	case 0:

		result=pDlg->dijkstra(*pG[index_jq],index_vs,index_vt);//(*pG[NOWSCENESPOT],qishi,zhong)
		SetDlgItemText(IDC_EDIT_resu,result);//���չʾ
		break;
	case 1:
		result=pDlg->getHMD(*pG[index_jq]);
		//result=pDlg->dijkstra(*pG[index_jq],index_vs,index_vt);//(*pG[NOWSCENESPOT],qishi,zhong)
		SetDlgItemText(IDC_EDIT_resu,result);//���չʾ
		break;
	}








}


void FindDlg::OnCbnSelchangeComboFindtjfs()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������



}
