
// CHJY_Ninth.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCHJY_NinthApp:
// �йش����ʵ�֣������ CHJY_Ninth.cpp
//

class CCHJY_NinthApp : public CWinApp
{
public:
	CCHJY_NinthApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCHJY_NinthApp theApp;