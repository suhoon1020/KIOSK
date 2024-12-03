#pragma once
#include "afxdialogex.h"


// CSIGNUP 대화 상자

class CSIGNUP : public CDialogEx
{
	DECLARE_DYNAMIC(CSIGNUP)

public:
	CSIGNUP(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSIGNUP();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SIGNUP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()

public:
	CString ID;
	CString PW;
	CString name;
	CString address;
	afx_msg void OnBnClickedButtOk();
	CString m_CustomID;
	CString m_CustomPW;
	CString m_CheckPw;
	CString m_Name;
//	CString m_Address;
};
