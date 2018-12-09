// SettingDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Train inquiry system.h"
#include "Train inquiry systemDlg.h"
#include "SettingDlg.h"
#include "afxdialogex.h"


// CSettingDlg 对话框

IMPLEMENT_DYNAMIC(CSettingDlg, CDialog)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSettingDlg::IDD, pParent)

	, No_1(_T(""))
	, No_2(_T(""))
	, No_3(_T(""))
	, No_4(_T(""))
	, No_5(_T(""))
	, No_6(_T(""))
	, No_7(_T(""))
{

}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_1, No_1);
	DDX_Text(pDX, IDC_EDIT_2, No_2);
	DDX_Text(pDX, IDC_EDIT_3, No_3);
	DDX_Text(pDX, IDC_EDIT_4, No_4);
	DDX_Text(pDX, IDC_EDIT_5, No_5);
	DDX_Text(pDX, IDC_EDIT_6, No_6);
	DDX_Text(pDX, IDC_EDIT_7, No_7);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialog)
END_MESSAGE_MAP()


// CSettingDlg 消息处理程序

    //  this->GetDlgItem(IDC_EDIT_1)->GetWIndowText(str);
/*	void CSettingDlg::OnOK() 
{
	

	this->GetDlgItemText(IDC_EDIT_1, No_1);
	this->GetDlgItemText(IDC_EDIT_2, No_2);
	this->GetDlgItemText(IDC_EDIT_3, No_3);
	this->GetDlgItemText(IDC_EDIT_4, No_4);
	this->GetDlgItemText(IDC_EDIT_5, No_5);
	this->GetDlgItemText(IDC_EDIT_6, No_6);
	this->GetDlgItemText(IDC_EDIT_7, No_7);
	 
	CDialog::OnOK();
}
	*/