
// Train inquiry systemDlg.cpp : 实现文件
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
	char*   szTitle;           //列表的名称
	int		nWidth;            //列表的宽度
}COLUMNSTRUCT;


COLUMNSTRUCT g_Column_Data_Online[] = 
{
	{"班次",			110	},
	{"发车时间",			150	},
	{"起点",	160	},
	{"终点",		128	},
	{"行车时间",			148	},
	{"载客量",		94	},
	{"订票人数",			151	}
};

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
int  g_Column_Count_Online  = 7;

int g_Column_Online_Width  = 0;
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


// CTraininquirysystemDlg 对话框




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


// CTraininquirysystemDlg 消息处理程序

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
			SetForegroundWindow();   //设置当前窗口
			Menu.GetSubMenu(0)->TrackPopupMenu(
				TPM_LEFTBUTTON|TPM_RIGHTBUTTON, 
				Point.x, Point.y, this, NULL); 
		
			break;
		}
		
	}
}


void CTraininquirysystemDlg::CreateNotifyBar()
{
	m_Nid.cbSize = sizeof(NOTIFYICONDATA);     //大小赋值
	m_Nid.hWnd = m_hWnd;           //父窗口    是被定义在父类CWnd类中
	m_Nid.uID = IDR_MAINFRAME;     //icon  ID
	m_Nid.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;     //托盘所拥有的状态
	m_Nid.uCallbackMessage = UM_ICONNOTIFY;              //回调消息
	m_Nid.hIcon = m_hIcon;                               //icon 变量
	CString strTips ="胡鑫博的列车查询系统.........";       //气泡提示
	lstrcpyn(m_Nid.szTip, (LPCSTR)strTips, sizeof(m_Nid.szTip) / sizeof(m_Nid.szTip[0]));
	Shell_NotifyIcon(NIM_ADD, &m_Nid);   //显示托盘
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTraininquirysystemDlg::CreateToolBar()
{
	if (!m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_ToolBar.LoadToolBar(IDR_TOOLBAR_MAIN))  //创建一个工具条  加载资源
	{

		return;     
	}
	m_ToolBar.LoadTrueColorToolBar
		(
		48,    //加载真彩工具条
		IDB_BITMAP_MAIN,
		IDB_BITMAP_MAIN,
		IDB_BITMAP_MAIN
		);  //和我们的位图资源相关联
	RECT Rect,RectMain;
	GetWindowRect(&RectMain);   //得到整个窗口的大小
	Rect.left=0;
	Rect.top=0;
	Rect.bottom=80;
	Rect.right=RectMain.right-RectMain.left+10;
	m_ToolBar.MoveWindow(&Rect,TRUE);



	


	m_ToolBar.SetButtonText(0,"查找列车");     //在位图的下面添加文件
	m_ToolBar.SetButtonText(1,"添加列车");  
	m_ToolBar.SetButtonText(2,"关于"); 
	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);  //显示
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTraininquirysystemDlg::OnPaint()
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
		//CDialogEx::OnPaint();
		 CPaintDC   dc(this);    
           CRect   rect;     
           GetClientRect(&rect);    
           CDC   dcMem;     
           dcMem.CreateCompatibleDC(&dc);    
           CBitmap   bmpBackground;     
           bmpBackground.LoadBitmap(IDB_BITMAP1);   //IDB_BITMAP是你自己的图对应的ID   由于我刚刚加入的位图资源
  
                                                                             //被我命名成了IDB_Bg，因而我这句就是bmpBackground.LoadBitmap(IDB_Bg);   
                    
           BITMAP   bitmap;     
           bmpBackground.GetBitmap(&bitmap);     
           CBitmap   *pbmpOld=dcMem.SelectObject(&bmpBackground);    
           dc.StretchBlt(0,0,rect.Width(),rect.Height(),&dcMem,0,0,    
         bitmap.bmWidth,bitmap.bmHeight,SRCCOPY);    
     }  

	
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTraininquirysystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTraininquirysystemDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_CList_Online.m_hWnd!=NULL)   //（控件也是窗口因此也有句柄）
	{
		CRect rc;
		rc.left = 1;          //列表的左坐标     
		rc.top  = 80;         //列表的上坐标
		rc.right  =  cx-1;    //列表的右坐标
		rc.bottom = cy-160;   //列表的下坐标
		m_CList_Online.MoveWindow(rc);

	 for(int i=0;i<g_Column_Count_Online;i++)
	   {           //遍历每一个列
			double Temp=g_Column_Data_Online[i].nWidth;     //得到当前列的宽度   138
			Temp/=g_Column_Online_Width;                    //看一看当前宽度占总长度的几分之几
			Temp*=cx;                                       //用原来的长度乘以所占的几分之几得到当前的宽度
			int lenth = Temp;                               //转换为int 类型
			m_CList_Online.SetColumnWidth(i,(lenth));       //设置当前的宽度
		}

	}

		if(m_ToolBar.m_hWnd!=NULL)                  //工具条
	{
		CRect rc;
		rc.top=rc.left=0;
		rc.right=cx;
		rc.bottom=80;
		m_ToolBar.MoveWindow(rc);             //设置工具条大小位置
	}

	// TODO: 在此处添加消息处理程序代码
}






void CTraininquirysystemDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString strIsOK,strTime;
	CTime Timer =CTime::GetCurrentTime();          //定义一个CTime 类的一个对象 t 使用类中的成员函数GetCurrentTime() 而不是 SDK函数
	strTime= Timer.Format("%H:%M:%S");
	SetWindowText(strTime.GetBuffer(0));
	UpdateData(FALSE);
	

	CDialogEx::OnTimer(nIDEvent);
}


void CTraininquirysystemDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
		KillTimer(0);
	if (::MessageBox(NULL,"                      感谢使用","Train inquiry system",MB_OKCANCEL)==1)
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
  	MessageBox("制作人： 胡鑫博");

}

void CTraininquirysystemDlg::OnNotifyShow()
{
	ShowWindow(SW_SHOW);
	// TODO: 在此添加命令处理程序代码
}

//托盘菜单
void CTraininquirysystemDlg::OnNotifyExit()
{  
	SendMessage(WM_CLOSE);
	// TODO: 在此添加命令处理程序代码
}
void CTraininquirysystemDlg::OnAdd()
{	
	CSettingDlg Dlg;
	Dlg.DoModal();
	UpdateData(true);



}