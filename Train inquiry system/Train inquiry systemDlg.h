
// Train inquiry systemDlg.h : ͷ�ļ�
//

#pragma once
#include "afxcmn.h"
#include"TrueColorToolBar.h"


// CTraininquirysystemDlg �Ի���
class CTraininquirysystemDlg : public CDialogEx
{
// ����
public:
	CTraininquirysystemDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TRAININQUIRYSYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnIconNotify(WPARAM wParam,LPARAM lParam);
	DECLARE_MESSAGE_MAP()
public:
	void CTraininquirysystemDlg::CreateToolBar();
	void CTraininquirysystemDlg::CreateNotifyBar();
	
	// ...
	CListCtrl m_CList_Online;
	NOTIFYICONDATA  m_Nid;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	CTrueColorToolBar m_ToolBar;
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	afx_msg void OnAbout();
	afx_msg void OnAdd();
	afx_msg void OnNotifyShow();
	afx_msg void OnNotifyExit();
};
