// ProMISeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ProMISe.h"
#include "ProMISeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

MYSQL mysql; //数据库连接句柄

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CProMISeDlg dialog




CProMISeDlg::CProMISeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CProMISeDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CProMISeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDT_D1_NAME, m_edt_usrname);
	DDX_Control(pDX, IDC_EDT_D1_PASSW, m_edt_passwd);
}

BEGIN_MESSAGE_MAP(CProMISeDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTN_D1_LEAVE, &CProMISeDlg::OnBnClickedBtnD1Leave)
	ON_BN_CLICKED(IDC_BTN_D1_LOG, &CProMISeDlg::OnBnClickedBtnD1Log)
END_MESSAGE_MAP()


// CProMISeDlg message handlers

BOOL CProMISeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	freopen("errout.txt","w",stderr);
	mysql_init (&mysql);
	if(!mysql_real_connect(&mysql,"localhost","root","roottoor","mydb",3306,NULL,0))
	{ 
		AfxMessageBox(_T("数据库连接失败")); 
		fprintf(stderr,"Failedtoconnecttodatabase:Error:%s\\n",mysql_error(&mysql));
		return FALSE;
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CProMISeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CProMISeDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CProMISeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CProMISeDlg::OnBnClickedBtnD1Leave()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CProMISeDlg::OnBnClickedBtnD1Log()
{
	// TODO: Add your control notification handler code here
	CString strUsrName,strPassWd;
	m_edt_usrname.GetWindowText(strUsrName);
	m_edt_passwd.GetWindowText(strPassWd);
	if(strPassWd!=_T(""))
	{
		MessageBox(strPassWd);
	}
	else
	{
		MessageBox(_T("Password can not be blank!"));
	}

}
