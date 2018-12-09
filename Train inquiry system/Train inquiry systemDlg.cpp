
// Train inquiry systemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Train inquiry system.h"
#include "Train inquiry systemDlg.h"
#include "afxdialogex.h"
#include"SettingDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define UM_ICONNOTIFY WM_USER+100

typedef struct
{
	char*   szTitle;           //�б������
	int		nWidth;            //�б�Ŀ��
}COLUMNSTRUCT;


COLUMNSTRUCT g_Column_Data_Online[] = 
{
	{"���",			110	},
	{"����ʱ��",			150	},
	{"���",	160	},
	{"�յ�",		128	},
	{"�г�ʱ��",			148	},
	{"�ؿ���",		94	},
	{"��Ʊ����",			151	}
};

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
int  g_Column_Count_Online  = 7;

int g_Column_Online_Width  = 0;
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


// CTraininquirysystemDlg �Ի���




CTraininquirysystemDlg::CTraininquirysystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CTraininquirysystemDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTraininquirysystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ONLINE, m_CList_Online);
}

BEGIN_MESSAGE_MAP(CTraininquirysystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	ON_COMMAND(IDM_ONLINE_About,&CTraininquirysystemDlg::OnAbout)
	ON_COMMAND(IDM_ONLINE_Add,&CTraininquirysystemDlg::OnAdd)
	ON_COMMAND(IDM_NOTIFY_SHOW, &CTraininquirysystemDlg::OnNotifyShow)
	ON_COMMAND(ID_NOTIFY_EXIT, &CTraininquirysystemDlg::OnNotifyExit)
	ON_MESSAGE(UM_ICONNOTIFY, (LRESULT (__thiscall CWnd::* )(WPARAM,LPARAM))OnIconNotify) 
END_MESSAGE_MAP()


// CTraininquirysystemDlg ��Ϣ�������

void CTraininquirysystemDlg::OnIconNotify(WPARAM wParam, LPARAM lParam)   
{
	switch ((UINT)lParam)
	{
	case WM_LBUTTONDOWN: 
	case WM_LBUTTONDBLCLK: 
		{
			if (!IsWindowVisible())
			{
				ShowWindow(SW_SHOW);
			}
			else
			{
				ShowWindow(SW_HIDE);
			}
			break;
		}
	
	case WM_RBUTTONDOWN:
		{
			CMenu Menu;
			Menu.LoadMenu(IDR_MENU_NOTIFY);
			CPoint Point;
			GetCursorPos(&Point);
			SetForegroundWindow();   //���õ�ǰ����
			Menu.GetSubMenu(0)->TrackPopupMenu(
				TPM_LEFTBUTTON|TPM_RIGHTBUTTON, 
				Point.x, Point.y, this, NULL); 
		
			break;
		}
		
	}
}


void CTraininquirysystemDlg::CreateNotifyBar()
{
	m_Nid.cbSize = sizeof(NOTIFYICONDATA);     //��С��ֵ
	m_Nid.hWnd = m_hWnd;           //������    �Ǳ������ڸ���CWnd����
	m_Nid.uID = IDR_MAINFRAME;     //icon  ID
	m_Nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;     //������ӵ�е�״̬
	m_Nid.uCallbackMessage = UM_ICONNOTIFY;              //�ص���Ϣ
	m_Nid.hIcon = m_hIcon;                               //icon ����
	CString strTips ="���β����г���ѯϵͳ.........";       //������ʾ
	lstrcpyn(m_Nid.szTip, (LPCSTR)strTips, sizeof(m_Nid.szTip) / sizeof(m_Nid.szTip[0]));
	Shell_NotifyIcon(NIM_ADD, &m_Nid);   //��ʾ����
} 

BOOL CTraininquirysystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CreateToolBar();
	CreateNotifyBar();

	CRect rect;
	GetWindowRect(&rect);
	rect.bottom+=20;
	MoveWindow(rect);


	for (int i = 0;i<g_Column_Count_Online;i++)
	{
		m_CList_Online.InsertColumn(i, g_Column_Data_Online[i].szTitle,LVCFMT_CENTER,g_Column_Data_Online[i].nWidth);


		g_Column_Online_Width+=g_Column_Data_Online[i].nWidth; 
	

	}

	SetTimer(0,1000,NULL);

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

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTraininquirysystemDlg::CreateToolBar()
{
	if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_ToolBar.LoadToolBar(IDR_TOOLBAR_MAIN))  //����һ��������  ������Դ
	{

		return;     
	}
	m_ToolBar.LoadTrueColorToolBar
		(
		48,    //������ʹ�����
		IDB_BITMAP_MAIN,
		IDB_BITMAP_MAIN,
		IDB_BITMAP_MAIN
		);  //�����ǵ�λͼ��Դ�����
	RECT Rect,RectMain;
	GetWindowRect(&RectMain);   //�õ��������ڵĴ�С
	Rect.left=0;
	Rect.top=0;
	Rect.bottom=80;
	Rect.right=RectMain.right-RectMain.left+10;
	m_ToolBar.MoveWindow(&Rect,TRUE);



	


	m_ToolBar.SetButtonText(0,"�����г�");     //��λͼ����������ļ�
	m_ToolBar.SetButtonText(1,"����г�");  
	m_ToolBar.SetButtonText(2,"����"); 
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);  //��ʾ
}



void CTraininquirysystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTraininquirysystemDlg::OnPaint()
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
		//CDialogEx::OnPaint();
		 CPaintDC   dc(this);    
           CRect   rect;     
           GetClientRect(&rect);    
           CDC   dcMem;     
           dcMem.CreateCompatibleDC(&dc);    
           CBitmap   bmpBackground;     
           bmpBackground.LoadBitmap(IDB_BITMAP1);   //IDB_BITMAP�����Լ���ͼ��Ӧ��ID   �����Ҹոռ����λͼ��Դ
  
                                                                             //������������IDB_Bg�������������bmpBackground.LoadBitmap(IDB_Bg);   
                    
           BITMAP   bitmap;     
           bmpBackground.GetBitmap(&bitmap);     
           CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);    
           dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,    
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);    
     }  

	
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTraininquirysystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTraininquirysystemDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_CList_Online.m_hWnd!=NULL)   //���ؼ�Ҳ�Ǵ������Ҳ�о����
	{
		CRect rc;
		rc.left = 1;          //�б��������     
		rc.top  = 80;         //�б��������
		rc.right  =  cx-1;    //�б��������
		rc.bottom = cy-160;   //�б��������
		m_CList_Online.MoveWindow(rc);

	 for(int i=0;i<g_Column_Count_Online;i++)
	   {           //����ÿһ����
			double Temp=g_Column_Data_Online[i].nWidth;     //�õ���ǰ�еĿ��   138
			Temp/=g_Column_Online_Width;                    //��һ����ǰ���ռ�ܳ��ȵļ���֮��
			Temp*=cx;                                       //��ԭ���ĳ��ȳ�����ռ�ļ���֮���õ���ǰ�Ŀ��
			int lenth = Temp;                               //ת��Ϊint ����
			m_CList_Online.SetColumnWidth(i,(lenth));       //���õ�ǰ�Ŀ��
		}

	}

		if(m_ToolBar.m_hWnd!=NULL)                  //������
	{
		CRect rc;
		rc.top=rc.left=0;
		rc.right=cx;
		rc.bottom=80;
		m_ToolBar.MoveWindow(rc);             //���ù�������Сλ��
	}

	// TODO: �ڴ˴������Ϣ����������
}






void CTraininquirysystemDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString strIsOK,strTime;
	CTime Timer =CTime::GetCurrentTime();          //����һ��CTime ���һ������ t ʹ�����еĳ�Ա����GetCurrentTime() ������ SDK����
	strTime= Timer.Format("%H:%M:%S");
	SetWindowText(strTime.GetBuffer(0));
	UpdateData(FALSE);
	

	CDialogEx::OnTimer(nIDEvent);
}


void CTraininquirysystemDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
		KillTimer(0);
	if (::MessageBox(NULL,"                      ��лʹ��","Train inquiry system",MB_OKCANCEL)==1)
	{
		Shell_NotifyIcon(NIM_DELETE, &m_Nid);
		CDialogEx::OnClose();
	}
	else
	{

	}
	
}


void CTraininquirysystemDlg::OnAbout()
{	
  	MessageBox("�����ˣ� ���β�");

}

void CTraininquirysystemDlg::OnNotifyShow()
{
	ShowWindow(SW_SHOW);
	// TODO: �ڴ���������������
}

//���̲˵�
void CTraininquirysystemDlg::OnNotifyExit()
{  
	SendMessage(WM_CLOSE);
	// TODO: �ڴ���������������
}
void CTraininquirysystemDlg::OnAdd()
{	
	CSettingDlg Dlg;
	Dlg.DoModal();
	UpdateData(true);



}