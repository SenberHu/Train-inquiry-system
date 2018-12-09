#pragma once


// CSettingDlg 对话框

class CSettingDlg : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSettingDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_Add };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	//virtual void OnOK();
	DECLARE_MESSAGE_MAP()
public:
	// 1

	CString No_1;
	CString No_2;
	CString No_3;
	CString No_4;
	CString No_5;
	CString No_6;
	CString No_7;
	
	
	
};
