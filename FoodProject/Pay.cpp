// Pay.cpp: 구현 파일
//

#include "pch.h"
#include "FoodProject.h"
#include "afxdialogex.h"
#include "Pay.h"
#include "Choice.h"
#include <iostream>
#include <string>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "FoodProjectDlg.h"



#define MAX_LENGTH 8
// Pay 대화 상자



IMPLEMENT_DYNAMIC(Pay, CDialog)

Pay::Pay(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_PAY, pParent)
	, m_Total(0)
{

}

Pay::~Pay()
{
}


BOOL Pay::OnInitDialog()
{
	CDialog::OnInitDialog();

	

	m_Card.LoadBitmaps(IDB_CARD, NULL, NULL, NULL);
	m_Card.SizeToContent();

	m_Cash.LoadBitmaps(IDB_CASH, NULL, NULL, NULL);
	m_Cash.SizeToContent();

	m_Coupon.AddString(_T(""));

	UpdateData(true);
	total = m_Total;
	UpdateData(false);


	/*
	UpdateData(true);
	m_Total = ch.price;
	UpdateData(false);
	*/
	return true;
}

void Pay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Coupon);
	DDX_Control(pDX, IDC_CARD, m_Card);
	DDX_Control(pDX, IDC_PAY, m_Cash);
	DDX_Text(pDX, IDC_EDIT_TOTAL, m_Total);
}


BEGIN_MESSAGE_MAP(Pay, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &Pay::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Pay::OnCbnSelchangeCombo1)

	ON_BN_CLICKED(IDC_CARD, &Pay::OnBnClickedCard)
	ON_BN_CLICKED(IDC_PAY, &Pay::OnBnClickedPay)
END_MESSAGE_MAP()


// Pay 메시지 처리기

// 뒤로가기 버튼
void Pay::OnBack()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	ch->ShowWindow(SW_SHOW);
}

// 종료 버튼
void Pay::OnExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnOK();
}






void Pay::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	int textLength = m_Coupon.GetLBTextLen(1);

	if (textLength>0) {
		MessageBox(_T("이미 쿠폰을 발급 하셨습니다."));
		return;
	}
	else {
		m_Coupon.AddString(_T("15% 할인권!"));
		m_Coupon.AddString(_T("10% 할인권!"));
		m_Coupon.AddString(_T("5% 할인권!"));
		MessageBox(_T("쿠폰이 발급되었습니다!"));
	}

}





void Pay::OnCbnSelchangeCombo1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	UpdateData(true);
	m_Total = total;

	if (m_Coupon.GetCurSel() == 1) {
		m_Total-=m_Total / 100 * 15;
	}
	else if (m_Coupon.GetCurSel() == 2) {
		m_Total -= m_Total / 100 * 10;
	}
	else if (m_Coupon.GetCurSel() == 3) {
		m_Total -= m_Total / 100 * 5;
	}
	UpdateData(false);
}

// 카드 버튼
void Pay::OnBnClickedCard()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(true);
	MessageBox(_T("결제를 완료했습니다."), _T("알림"), MB_OK | MB_ICONINFORMATION);
	ch->listbox.push_back(_T("카드"));
	ch->sum.push_back(m_Total);
	UpdateData(false);
	OnOK();

}

// 현금 버튼
void Pay::OnBnClickedPay()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(true);
	MessageBox(_T("결제를 완료했습니다."), _T("알림"), MB_OK | MB_ICONINFORMATION);
	ch->listbox.push_back(_T("현금"));
	ch->sum.push_back(m_Total);
	UpdateData(false);
	OnOK();

}
