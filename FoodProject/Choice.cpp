// Choice.cpp: 구현 파일
//

#include "pch.h"
#include "FoodProject.h"
#include "afxdialogex.h"
#include "Choice.h"
#include "FoodProjectDlg.h"
#include "Pay.h"
#include "Choice.h"
#include "Option1.h"
#include "Option2.h"
#include "Option3.h"
#include "CREVISE.h"
#include "CBILL.h"
#include <vector>
#include <iostream>



// Choice 대화 상자

IMPLEMENT_DYNAMIC(Choice, CDialog)

Choice::Choice(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CHOICE, pParent)
	, m_Price(0)
	, m_Name(_T(""))
{
	m_Price = 0;

	//  m_strOrder = _T("");
}

Choice::~Choice()
{
}


Choice* ch = new Choice;


BOOL Choice::OnInitDialog()
{
	CDialog::OnInitDialog();

	UpdateData(true);
	CString str;
	str.Format(_T("%s 회원님 반갑습니다."), cpd.name);

	
	m_Name = str;
	UpdateData(false);


	

	UpdateTotalPrice();

	m_Chik1.LoadBitmaps(IDB_FRIED, NULL, NULL, NULL);
	m_Chik1.SizeToContent();

	m_Chik2.LoadBitmaps(IDB_SEASONING, NULL, NULL, NULL);
	m_Chik2.SizeToContent();

	m_Chik3.LoadBitmaps(IDB_SOY, NULL, NULL, NULL);
	m_Chik3.SizeToContent();

	m_Chik4.LoadBitmaps(IDB_GANGJUNG, NULL, NULL, NULL);
	m_Chik4.SizeToContent();


	m_Piz1.LoadBitmaps(IDB_COMBI, NULL, NULL, NULL);
	m_Piz1.SizeToContent();

	m_Piz2.LoadBitmaps(IDB_BUL, NULL, NULL, NULL);
	m_Piz2.SizeToContent();

	m_Piz3.LoadBitmaps(IDB_SWEETPOTATO, NULL, NULL, NULL);
	m_Piz3.SizeToContent();

	m_Piz4.LoadBitmaps(IDB_PEP, NULL, NULL, NULL);
	m_Piz4.SizeToContent();

	m_Jk1.LoadBitmaps(IDB_ZOK, NULL, NULL, NULL);
	m_Jk1.SizeToContent();

	m_Jk2.LoadBitmaps(IDB_BOSSAM, NULL, NULL, NULL);
	m_Jk2.SizeToContent();

	m_Jk3.LoadBitmaps(IDB_SEASONZOK, NULL, NULL, NULL);
	m_Jk3.SizeToContent();

	m_Jk4.LoadBitmaps(IDB_BULZOK, NULL, NULL, NULL);
	m_Jk4.SizeToContent();




	m_Cf1.LoadBitmaps(IDB_JJA, NULL, NULL, NULL);
	m_Cf1.SizeToContent();

	m_Cf2.LoadBitmaps(IDB_JJAM, NULL, NULL, NULL);
	m_Cf2.SizeToContent();

	m_Cf3.LoadBitmaps(IDB_TANG, NULL, NULL, NULL);
	m_Cf3.SizeToContent();

	m_Cf4.LoadBitmaps(IDB_RICE, NULL, NULL, NULL);
	m_Cf4.SizeToContent();




	return true;
}

void Choice::UpdateTotalPrice() {
	CString strPrice;
	strPrice.Format(_T("%d"), m_Price);
	SetDlgItemText(IDC_PRICE, strPrice);
}



void Choice::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	GetDlgItem(IDC_CHIK1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHIK2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHIK3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CHIK4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PIZ1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PIZ2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PIZ3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_PIZ4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_JK1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_JK2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_JK3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_JK4)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CF1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CF2)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CF3)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_CF4)->ShowWindow(SW_HIDE);
	DDX_Control(pDX, IDC_CHIK1, m_Chik1);
	DDX_Control(pDX, IDC_CHIK2, m_Chik2);
	DDX_Control(pDX, IDC_CHIK3, m_Chik3);
	DDX_Control(pDX, IDC_PIZ1, m_Piz1);
	DDX_Control(pDX, IDC_PIZ2, m_Piz2);
	DDX_Control(pDX, IDC_PIZ3, m_Piz3);
	DDX_Control(pDX, IDC_PIZ4, m_Piz4);
	DDX_Control(pDX, IDC_JK1, m_Jk1);
	DDX_Control(pDX, IDC_JK2, m_Jk2);
	DDX_Control(pDX, IDC_JK3, m_Jk3);
	DDX_Control(pDX, IDC_JK4, m_Jk4);
	DDX_Control(pDX, IDC_CF1, m_Cf1);
	DDX_Control(pDX, IDC_CF2, m_Cf2);
	DDX_Control(pDX, IDC_CF3, m_Cf3);
	DDX_Control(pDX, IDC_CF4, m_Cf4);
	DDX_Control(pDX, IDC_CHIK4, m_Chik4);
	DDX_Control(pDX, IDC_LIST_MENU, m_listOrder);
	DDX_Text(pDX, IDC_PRICE, m_Price);;
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
}


BEGIN_MESSAGE_MAP(Choice, CDialog)
	ON_BN_CLICKED(IDC_PAYMENT, &Choice::OnBnClickedPayment)
	ON_BN_CLICKED(IDC_CHIK1, &Choice::OnBnClickedChik1)
	ON_BN_CLICKED(IDC_CHICKEN, &Choice::OnBnClickedChicken)
	ON_BN_CLICKED(IDC_PIZZA, &Choice::OnBnClickedPizza)
	ON_BN_CLICKED(IDC_JOKBO, &Choice::OnBnClickedJokbo)
	ON_BN_CLICKED(IDC_CFOOD, &Choice::OnBnClickedCfood)
	ON_BN_CLICKED(IDC_CF1, &Choice::OnBnClickedCf1)
	ON_BN_CLICKED(IDC_CHIK2, &Choice::OnBnClickedChik2)
	ON_BN_CLICKED(IDC_CHIK3, &Choice::OnBnClickedChik3)
	ON_BN_CLICKED(IDC_CHIK4, &Choice::OnBnClickedChik4)
	ON_BN_CLICKED(IDC_PIZ1, &Choice::OnBnClickedPiz1)
	ON_BN_CLICKED(IDC_PIZ2, &Choice::OnBnClickedPiz2)
	ON_BN_CLICKED(IDC_PIZ3, &Choice::OnBnClickedPiz3)
	ON_BN_CLICKED(IDC_PIZ4, &Choice::OnBnClickedPiz4)
	ON_BN_CLICKED(IDC_JB1, &Choice::OnBnClickedJb1)
	ON_BN_CLICKED(IDC_JB2, &Choice::OnBnClickedJb2)
	ON_BN_CLICKED(IDC_JB3, &Choice::OnBnClickedJb3)
	ON_BN_CLICKED(IDC_JB4, &Choice::OnBnClickedJb4)
	ON_BN_CLICKED(IDC_CF2, &Choice::OnBnClickedCf2)
	ON_BN_CLICKED(IDC_CF3, &Choice::OnBnClickedCf3)
	ON_BN_CLICKED(IDC_CF4, &Choice::OnBnClickedCf4)
	ON_BN_CLICKED(IDC_BUTT_LOGOUT, &Choice::OnBnClickedButtLogout)
	ON_BN_CLICKED(IDC_BUTT_CANCEL, &Choice::OnBnClickedButtCancel)
	ON_BN_CLICKED(IDC_BUTT_EXIT, &Choice::OnBnClickedButtExit)
END_MESSAGE_MAP()


// Choice 메시지 처리기

// 뒤로가기 버튼
void Choice::OnBack()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	//CFoodProjectDlg& cpd = CFoodProjectDlg::Instance();

	cpd.ShowWindow(SW_SHOW);
}

// 종료 버튼
void Choice::OnExit()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	OnOK();
}

// 결제 버튼
void Choice::OnBnClickedPayment()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Pay CHICKENDialog;
	
	UpdateData(true);
	if (m_listOrder.GetCount()==0) {
		MessageBox(_T("메뉴를 선택해 주십시오"));
	}
	else {
		CHICKENDialog.m_Total = m_Price;


		cpd.ShowWindow(SW_HIDE);
		if (CHICKENDialog.DoModal() == IDOK)
		{
			UpdateData(true);
			int itemCount = m_listOrder.GetCount();

			for (int i = itemCount - 1; i >= 0; i--) {
				m_listOrder.DeleteString(i);
			}

			price = 0;
			m_Price = 0;


			UpdateData(FALSE);
		}

		
	}
	UpdateData(false);
}

// 치킨 버튼
void Choice::OnBnClickedChicken()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_Chik1.ShowWindow(SW_SHOW);
	m_Chik2.ShowWindow(SW_SHOW);
	m_Chik3.ShowWindow(SW_SHOW);
	m_Chik4.ShowWindow(SW_SHOW);

	m_Piz1.ShowWindow(SW_HIDE);
	m_Piz2.ShowWindow(SW_HIDE);
	m_Piz3.ShowWindow(SW_HIDE);
	m_Piz4.ShowWindow(SW_HIDE);

	m_Jk1.ShowWindow(SW_HIDE);
	m_Jk2.ShowWindow(SW_HIDE);
	m_Jk3.ShowWindow(SW_HIDE);
	m_Jk4.ShowWindow(SW_HIDE);

	m_Cf1.ShowWindow(SW_HIDE);
	m_Cf2.ShowWindow(SW_HIDE);
	m_Cf3.ShowWindow(SW_HIDE);
	m_Cf4.ShowWindow(SW_HIDE);
}

// 피자 버튼
void Choice::OnBnClickedPizza()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_Chik1.ShowWindow(SW_HIDE);
	m_Chik2.ShowWindow(SW_HIDE);
	m_Chik3.ShowWindow(SW_HIDE);
	m_Chik4.ShowWindow(SW_HIDE);

	m_Piz1.ShowWindow(SW_SHOW);
	m_Piz2.ShowWindow(SW_SHOW);
	m_Piz3.ShowWindow(SW_SHOW);
	m_Piz4.ShowWindow(SW_SHOW);

	m_Jk1.ShowWindow(SW_HIDE);
	m_Jk2.ShowWindow(SW_HIDE);
	m_Jk3.ShowWindow(SW_HIDE);
	m_Jk4.ShowWindow(SW_HIDE);

	m_Cf1.ShowWindow(SW_HIDE);
	m_Cf2.ShowWindow(SW_HIDE);
	m_Cf3.ShowWindow(SW_HIDE);
	m_Cf4.ShowWindow(SW_HIDE);
}


// 족발/보쌈 버튼
void Choice::OnBnClickedJokbo()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_Chik1.ShowWindow(SW_HIDE);
	m_Chik2.ShowWindow(SW_HIDE);
	m_Chik3.ShowWindow(SW_HIDE);
	m_Chik4.ShowWindow(SW_HIDE);

	m_Piz1.ShowWindow(SW_HIDE);
	m_Piz2.ShowWindow(SW_HIDE);
	m_Piz3.ShowWindow(SW_HIDE);
	m_Piz4.ShowWindow(SW_HIDE);

	m_Jk1.ShowWindow(SW_SHOW);
	m_Jk2.ShowWindow(SW_SHOW);
	m_Jk3.ShowWindow(SW_SHOW);
	m_Jk4.ShowWindow(SW_SHOW);

	m_Cf1.ShowWindow(SW_HIDE);
	m_Cf2.ShowWindow(SW_HIDE);
	m_Cf3.ShowWindow(SW_HIDE);
	m_Cf4.ShowWindow(SW_HIDE);
}

// 중국집 버튼
void Choice::OnBnClickedCfood()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_Chik1.ShowWindow(SW_HIDE);
	m_Chik2.ShowWindow(SW_HIDE);
	m_Chik3.ShowWindow(SW_HIDE);
	m_Chik4.ShowWindow(SW_HIDE);

	m_Piz1.ShowWindow(SW_HIDE);
	m_Piz2.ShowWindow(SW_HIDE);
	m_Piz3.ShowWindow(SW_HIDE);
	m_Piz4.ShowWindow(SW_HIDE);

	m_Jk1.ShowWindow(SW_HIDE);
	m_Jk2.ShowWindow(SW_HIDE);
	m_Jk3.ShowWindow(SW_HIDE);
	m_Jk4.ShowWindow(SW_HIDE);

	m_Cf1.ShowWindow(SW_SHOW);
	m_Cf2.ShowWindow(SW_SHOW);
	m_Cf3.ShowWindow(SW_SHOW);
	m_Cf4.ShowWindow(SW_SHOW);
}

// 후라이드 치킨 버튼
void Choice::OnBnClickedChik1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Option1 dlg;
	CString str;
	m_listOrder.ShowWindow(SW_SHOW);
	if (dlg.DoModal() == IDOK) {
		if (dlg.bone == true) {
			str.Format(_T("후라이드 치킨 - %d"), Chik1);
			m_Price += Chik1;
			m_listOrder.AddString(str);
			UpdateTotalPrice();
		}
		else {
			str.Format(_T("후라이드 치킨 순살 - %d"), Chik1 + 2000);
			m_Price += Chik1 + 2000;
			m_listOrder.AddString(str);
			UpdateTotalPrice();
		}
	}
}

// 양념 버튼
void Choice::OnBnClickedChik2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Option2 dlg;
	CString str;
	m_listOrder.ShowWindow(SW_SHOW);
	if (dlg.DoModal() == IDOK) {
		if (dlg.bone == true) {
			str.Format(_T("양념 치킨 - %d"), Chik2);
			m_Price += Chik2;
			m_listOrder.AddString(str);
			UpdateTotalPrice();
		}
		else {
			str.Format(_T("양념 치킨 순살 - %d"), Chik2 + 2000);
			m_Price += Chik2 + 2000;
			m_listOrder.AddString(str);
			UpdateTotalPrice();
		}
	}
}

// 간장 버튼
void Choice::OnBnClickedChik3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Option3 dlg;
	CString str;
	m_listOrder.ShowWindow(SW_SHOW);
	if (dlg.DoModal() == IDOK) {
		if (dlg.bone == true) {
			str.Format(_T("간장 치킨 - %d"), Chik3);
			m_Price += Chik3;
			m_listOrder.AddString(str);
			UpdateTotalPrice();
		}
		else {
			str.Format(_T("간장 치킨 순살 - %d"), Chik3 + 2000);
			m_Price += Chik3 + 2000;
			m_listOrder.AddString(str);
			UpdateTotalPrice();
		}
	}
}

// 닭강정 버튼
void Choice::OnBnClickedChik4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Chik4;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("닭강정 - %d"), Chik4);
	m_listOrder.AddString(str);
}

// 콤비네이션 버튼
void Choice::OnBnClickedPiz1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Piz1;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("콤비네이션 피자 - %d"), Piz1);
	m_listOrder.AddString(str);
}

// 불고기 버튼
void Choice::OnBnClickedPiz2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Piz2;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("불고기 피자 - %d"), Piz2);
	m_listOrder.AddString(str);
}

// 고구마 버튼
void Choice::OnBnClickedPiz3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Piz3;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("고구마 피자 - %d"), Piz3);
	m_listOrder.AddString(str);
}

// 페퍼로니
void Choice::OnBnClickedPiz4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Piz4;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("페퍼로니 피자 - %d"), Piz4);
	m_listOrder.AddString(str);
}

// 족발 버튼
void Choice::OnBnClickedJb1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Jk1;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("족발 - %d"), Jk1);
	m_listOrder.AddString(str);
}

// 보쌈 버튼
void Choice::OnBnClickedJb2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Jk2;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("보쌈 - %d"), Jk2);
	m_listOrder.AddString(str);
}

// 양념족발 버튼
void Choice::OnBnClickedJb3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Jk3;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("양념족발 - %d"), Jk3);
	m_listOrder.AddString(str);
}

// 불족발 버튼
void Choice::OnBnClickedJb4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Jk4;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("불족발 - %d"), Jk4);
	m_listOrder.AddString(str);
}

// 짜장면 버튼
void Choice::OnBnClickedCf1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Cf1;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("짜장면 - %d"), Cf1);
	m_listOrder.AddString(str);

}

// 짬뽕 버튼
void Choice::OnBnClickedCf2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Cf2;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("짬뽕 - %d"), Cf2);
	m_listOrder.AddString(str);
}

// 탕수육 버튼
void Choice::OnBnClickedCf3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Cf3;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("탕수육 - %d"), Cf3);
	m_listOrder.AddString(str);
}

// 볶음밥 버튼
void Choice::OnBnClickedCf4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CString str;
	m_Price += Cf4;
	UpdateTotalPrice();
	m_listOrder.ShowWindow(SW_SHOW);
	str.Format(_T("볶음밥 - %d"), Cf4);
	m_listOrder.AddString(str);
}




void Choice::OnBnClickedButtLogout()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CFoodProjectDlg& cpd = CFoodProjectDlg::Instance();
	ShowWindow(SW_HIDE);
	cpd.ShowWindow(SW_SHOW);
	UpdateData(true);
	int itemCount = m_listOrder.GetCount();

	for (int i = itemCount - 1; i >= 0; i--) {
		m_listOrder.DeleteString(i);
	}

	price = 0;
	m_Price = 0;
	UpdateData(false);

	MessageBox(_T("로그아웃이 완료 되었습니다."));

}


void Choice::OnBnClickedButtCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int selectedIndex = m_listOrder.GetCurSel();

	if (selectedIndex != LB_ERR) {
		CString strPrice;
		m_listOrder.GetText(selectedIndex, strPrice);

		// 숫자만 추출하여 가격에서 차감
		int priceToRemove = _tstoi(strPrice.Right(strPrice.GetLength() - strPrice.ReverseFind(_T('-')) - 2));
		m_Price -= priceToRemove;

		// 리스트에서 항목 제거
		m_listOrder.DeleteString(selectedIndex);

		// 총 결제 금액 업데이트
		UpdateTotalPrice();
		UpdateData(FALSE);
	}
}


void Choice::OnBnClickedButtExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CWnd* pActiveWnd = GetActiveWindow();

	if (pActiveWnd)
	{
		// 현재 활성화된 창이 모달 창인 경우
		CDialog* pDialog = dynamic_cast<CDialog*>(pActiveWnd);
		if (pDialog && pDialog->IsKindOf(RUNTIME_CLASS(CDialog)))
		{
			pDialog->EndDialog(IDCANCEL);
		}

		// 현재 활성화된 창이 모달리스 창인 경우
		CWnd* pParentWnd = pActiveWnd->GetParent();
		if (pParentWnd && pParentWnd->IsKindOf(RUNTIME_CLASS(CWnd)))
		{
			pParentWnd->DestroyWindow();
		}
	}
}
