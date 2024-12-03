
// FoodProjectDlg.h: 헤더 파일
//
#pragma once
#include "afxdialogex.h"




// CFoodProjectDlg 대화 




class CFoodProjectDlg : public CDialogEx
{
// 생성입니다.

public:
	CFoodProjectDlg(CWnd* pParent = nullptr);

private:



// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FOODPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_ID;
	CString m_PW;
	afx_msg void OnBnClickedButtLogin();

	CString aID = _T("admin"); //어드민 계정
	CString aPW = _T("1234");

	CString customID; //사용자 계정
	CString customPW;

	CString address;
	CString name;
	
	bool isSign;

	afx_msg void OnBnClickedButtSignup();
	afx_msg void OnBnClickedButton1();
};

extern CFoodProjectDlg cpd;