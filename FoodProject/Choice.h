#pragma once
#include "afxdialogex.h"
#include <vector>

// Choice 대화 상자
class Choice;
extern Choice* ch;

class Choice : public CDialog
{
	
	DECLARE_DYNAMIC(Choice)

public:

	Choice(CWnd* pParent = nullptr);
	virtual ~Choice();
	BOOL OnInitDialog();

private:



// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CHOICE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBack();
	afx_msg void OnExit();
	afx_msg void OnBnClickedPayment();
	CBitmapButton m_Chik1;
	CBitmapButton m_Chik2;
	CBitmapButton m_Chik3;
	CBitmapButton m_Chik4;
	CBitmapButton m_Piz1;
	CBitmapButton m_Piz2;
	CBitmapButton m_Piz3;
	CBitmapButton m_Piz4;
	CBitmapButton m_Jk1;
	CBitmapButton m_Jk2;
	CBitmapButton m_Jk3;
	CBitmapButton m_Jk4;
	CBitmapButton m_Cf1;
	CBitmapButton m_Cf2;
	CBitmapButton m_Cf3;
	CBitmapButton m_Cf4;
	afx_msg void OnBnClickedChik1();
	afx_msg void OnBnClickedChicken();
	afx_msg void OnBnClickedPizza();
	afx_msg void OnBnClickedJokbo();
	afx_msg void OnBnClickedCfood();
	afx_msg void OnBnClickedCf1();
	CListBox m_listOrder;
	int Chik1 = 17000;
	int Chik2 = 18000;
	int	Chik3 = 18000;
	int	Chik4 = 18000;
	int Piz1 = 10900;
	int	Piz3 = 10900;
	int Piz2 = 11900;
	int Piz4 = 9900;
	int Jk1 = 24000;
	int Jk2 = 25000;
	int Jk3 = 26000;
	int	Jk4 = 26000;
	int Cf1 = 7000;
	int Cf2 = 8000;
	int Cf3 = 20000;
	int Cf4 = 7500;
	int price;
	int m_Price;
	void UpdateTotalPrice();
	afx_msg void OnBnClickedChik2();
	afx_msg void OnBnClickedChik3();
	afx_msg void OnBnClickedChik4();
	afx_msg void OnBnClickedPiz1();
	afx_msg void OnBnClickedPiz2();
	afx_msg void OnBnClickedPiz3();
	afx_msg void OnBnClickedPiz4();
	afx_msg void OnBnClickedJb1();
	afx_msg void OnBnClickedJb2();
	afx_msg void OnBnClickedJb3();
	afx_msg void OnBnClickedJb4();
	afx_msg void OnBnClickedCf2();
	afx_msg void OnBnClickedCf3();
	afx_msg void OnBnClickedCf4();
	CButton m_Revise;
	CString m_ID;
	CString customID;
	CString name;
	afx_msg void OnBnClickedButtRevise();
	afx_msg void OnBnClickedButtBill();
	CButton m_Bill;

	std::vector<int> sum;
	std::vector<CString> listbox;

	afx_msg void OnBnClickedButtLogout();
	CString m_Name;
	afx_msg void OnBnClickedButtCancel();
	afx_msg void OnBnClickedButtExit();
};

