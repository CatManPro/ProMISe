// ProMISeDlg.h : header file
//

#pragma once
#include "afxwin.h"


// CProMISeDlg dialog
class CProMISeDlg : public CDialog
{
// Construction
public:
	CProMISeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_PROMISE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBtnD1Leave();
	afx_msg void OnBnClickedBtnD1Log();
	CEdit m_edt_usrname;
	CEdit m_edt_passwd;
};
