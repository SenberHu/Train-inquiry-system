
// Train inquiry system.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTraininquirysystemApp:
// �йش����ʵ�֣������ Train inquiry system.cpp
//

class CTraininquirysystemApp : public CWinApp
{
public:
	CTraininquirysystemApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTraininquirysystemApp theApp;