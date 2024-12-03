// CSIGNUP.cpp: 구현 파일
//

#include "pch.h"
#include "FoodProject.h"
#include "afxdialogex.h"
#include "CSIGNUP.h"
#include "FoodProjectDlg.h"


// CSIGNUP 대화 상자

IMPLEMENT_DYNAMIC(CSIGNUP, CDialogEx)

CSIGNUP::CSIGNUP(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_SIGNUP, pParent)
	, m_CustomID(_T(""))
	, m_CustomPW(_T(""))
	, m_CheckPw(_T(""))
	, m_Name(_T(""))
{

}

CSIGNUP::~CSIGNUP()
{
}

void CSIGNUP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_CUSTOMID, m_CustomID);
	DDX_Text(pDX, IDC_EDIT_CUSTOMPW, m_CustomPW);
	DDX_Text(pDX, IDC_EDIT_CHECKPW, m_CheckPw);
	DDX_Text(pDX, IDC_EDIT_NAME, m_Name);
	//  DDX_Text(pDX, IDC_EDIT_ADDRESS, m_Address);
}


BEGIN_MESSAGE_MAP(CSIGNUP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTT_OK, &CSIGNUP::OnBnClickedButtOk)
END_MESSAGE_MAP()


// CSIGNUP 메시지 처리기


void CSIGNUP::OnBnClickedButtOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	UpdateData(true);
	if (m_CustomID.IsEmpty() || m_CheckPw.IsEmpty() || m_CustomID.IsEmpty() || m_Name.IsEmpty()) {
		MessageBox(_T("모든 입력이 제대로 되지 않았습니다."));
	}
	else {
		if (m_CustomID == cpd.aID) 
			MessageBox(_T("이미 사용중인 아이디 입니다"));
		else if (m_CustomPW == m_CheckPw && m_CustomID!=cpd.aID) {
			ID = m_CustomID;
			PW = m_CustomPW;
			name = m_Name;
			MessageBox(_T("회원 가입이 완료되었습니다!"));
			cpd.isSign = true;
			OnOK();
			
		}
		else {
			MessageBox(_T("비밀번호를 다시 확인하여 주십시오."));
		}
	}
	UpdateData(false);
}
