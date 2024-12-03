#pragma once
#include "afxdialogex.h"


// CBILL 대화 상자

class CBILL : public CDialogEx
{
	DECLARE_DYNAMIC(CBILL)

public:
	CBILL(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CBILL();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BILL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtOk();
	CListBox m_BillList;
	int m_Total;
	afx_msg void OnBnClickedButton1();
};
