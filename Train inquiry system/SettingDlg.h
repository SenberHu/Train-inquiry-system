#pragma once


// CSettingDlg �Ի���

class CSettingDlg : public CDialog
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSettingDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_Add };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
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
