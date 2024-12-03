// Option1.cpp: 구현 파일
//

#include "pch.h"
#include "FoodProject.h"
#include "afxdialogex.h"
#include "Option1.h"


// Option1 대화 상자

IMPLEMENT_DYNAMIC(Option1, CDialogEx)

Option1::Option1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPTION1, pParent)
{

}

Option1::~Option1()
{
}

BOOL Option1::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Bone.LoadBitmaps(IDB_BONE, NULL, NULL, NULL);
	m_Bone.SizeToContent();

	m_Boneless.LoadBitmaps(IDB_BONELESS, NULL, NULL, NULL);
	m_Boneless.SizeToContent();


	return true;
}

void Option1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NOMAL, m_Bone);
	DDX_Control(pDX, IDC_BONELESS, m_Boneless);
}


BEGIN_MESSAGE_MAP(Option1, CDialogEx)
	ON_BN_CLICKED(IDC_NOMAL, &Option1::OnBnClickedNomal)
	ON_BN_CLICKED(IDC_BONELESS, &Option1::OnBnClickedBoneless)
END_MESSAGE_MAP()


// Option1 메시지 처리기

// 뼈 버튼
void Option1::OnBnClickedNomal()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bone = TRUE;
	OnOK();
}


void Option1::OnBnClickedBoneless()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bone = FALSE;
	OnOK();
}
