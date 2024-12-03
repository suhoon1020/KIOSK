// CADMIN.cpp: 구현 파일
//

#include "pch.h"
#include "FoodProject.h"
#include "afxdialogex.h"
#include "CADMIN.h"
#include "CREVISE.h"
#include "FoodProjectDlg.h"
#include "Choice.h"
#include "CBILL.h"



// CADMIN 대화 상자

IMPLEMENT_DYNAMIC(CADMIN, CDialogEx)

CADMIN::CADMIN(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CADMIN::~CADMIN()
{
}

void CADMIN::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CADMIN, CDialogEx)
	ON_BN_CLICKED(IDC_BUTT_CHANGEPRICE, &CADMIN::OnBnClickedButtChangeprice)
	ON_BN_CLICKED(IDC_BUTT_HOME, &CADMIN::OnBnClickedButtHome)
	ON_BN_CLICKED(IDC_BUTT_BILL, &CADMIN::OnBnClickedButtBill)
END_MESSAGE_MAP()


// CADMIN 메시지 처리기


void CADMIN::OnBnClickedButtChangeprice()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CREVISE revise;
	OnOK();
	revise.DoModal();
}


void CADMIN::OnBnClickedButtHome()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CFoodProjectDlg& cpd = CFoodProjectDlg::Instance();
	OnOK();
	cpd.ShowWindow(SW_SHOW);
}


void CADMIN::OnBnClickedButtBill()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CBILL bill;
	bill.DoModal();

}
