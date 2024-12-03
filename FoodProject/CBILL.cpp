// CBILL.cpp: 구현 파일
//

#include "pch.h"
#include "FoodProject.h"
#include "afxdialogex.h"
#include "CBILL.h"
#include "Pay.h"
#include "Choice.h"


// CBILL 대화 상자

IMPLEMENT_DYNAMIC(CBILL, CDialogEx)

CBILL::CBILL(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_BILL, pParent)
	, m_Total(0)
{

}

CBILL::~CBILL()
{
}

void CBILL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_BillList);
	DDX_Text(pDX, IDC_EDIT_TOTAL, m_Total);
}


BEGIN_MESSAGE_MAP(CBILL, CDialogEx)
	ON_BN_CLICKED(IDC_BUTT_OK, &CBILL::OnBnClickedButtOk)
	//ON_BN_CLICKED(IDC_BUTTON1, &CBILL::OnBnClickedButton1)
END_MESSAGE_MAP()


// CBILL 메시지 처리기


void CBILL::OnBnClickedButtOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (ch->listbox.empty()) {
		MessageBox(_T("결제 내역이 존재하지 않습니다"));
	}
	else {
		UpdateData(true);
		int size = ch->listbox.size();
		int total = 0;
		//MessageBox(pay.listbox[0]);

		m_BillList.ResetContent();

		for (int i = 0; i < size; i++) {
			CString str;
			str.Format((_T("결제방식 : %s | 금액 : %d")), ch->listbox[i], ch->sum[i]);

			m_BillList.AddString(str);

			total += ch->sum[i];
		}


		m_Total = total;

		UpdateData(false);
	}
}



