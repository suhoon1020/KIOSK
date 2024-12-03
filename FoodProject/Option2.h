#pragma once
#include "afxdialogex.h"


// Option2 대화 상자

class Option2 : public CDialogEx
{
	DECLARE_DYNAMIC(Option2)

public:
	Option2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Option2();

	BOOL OnInitDialog();
	bool bone;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPTION2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CBitmapButton m_Bone;
	CBitmapButton m_Boneless;
};
