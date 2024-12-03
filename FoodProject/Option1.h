#pragma once
#include "afxdialogex.h"


// Option1 대화 상자

class Option1 : public CDialogEx
{
	DECLARE_DYNAMIC(Option1)

public:
	Option1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Option1();

	BOOL OnInitDialog();
	bool bone;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPTION1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedNomal();
	afx_msg void OnBnClickedBoneless();
	CBitmapButton m_Bone;
	CBitmapButton m_Boneless;
};
