#pragma once
#include "afxdialogex.h"
#include "Choice.h"

// CADMIN 대화 상자

class CADMIN : public CDialogEx
{
	DECLARE_DYNAMIC(CADMIN)

public:
	CADMIN(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CADMIN();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtChangeprice();
	afx_msg void OnBnClickedButtHome();

	afx_msg void OnBnClickedButtBill();
};
