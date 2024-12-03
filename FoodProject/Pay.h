#pragma once
#include "afxdialogex.h"
#include <string>
#include <vector>
#include <vector>


// Pay 대화 상자

class Pay : public CDialog
{
	DECLARE_DYNAMIC(Pay)

public:
	Pay(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Pay();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAY };
#endif

protected:
	BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBack();
	afx_msg void OnExit();
	CComboBox m_Coupon;
	CBitmapButton m_Card;
	CBitmapButton m_Cash;
	afx_msg void OnBnClickedButton1();
	CString random;
	afx_msg void OnCbnSelchangeCombo1();
	int m_Total;
	int total;
	afx_msg void OnBnClickedCard();
	afx_msg void OnBnClickedPay();
	
	int isCard = 0;
	int cashNum = 0;
};
