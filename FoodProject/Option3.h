﻿#pragma once
#include "afxdialogex.h"


// Option3 대화 상자

class Option3 : public CDialogEx
{
	DECLARE_DYNAMIC(Option3)

public:
	Option3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Option3();

	BOOL OnInitDialog();
	bool bone;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OPTION3 };
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