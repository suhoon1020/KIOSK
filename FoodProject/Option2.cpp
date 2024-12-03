// Option2.cpp: 구현 파일
//

#include "pch.h"
#include "FoodProject.h"
#include "afxdialogex.h"
#include "Option2.h"


// Option2 대화 상자

IMPLEMENT_DYNAMIC(Option2, CDialogEx)

Option2::Option2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPTION2, pParent)
{

}

Option2::~Option2()
{
}

BOOL Option2::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Bone.LoadBitmaps(IDB_BONE, NULL, NULL, NULL);
	m_Bone.SizeToContent();

	m_Boneless.LoadBitmaps(IDB_BONELESS, NULL, NULL, NULL);
	m_Boneless.SizeToContent();



	return true;
}

void Option2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_Bone);
	DDX_Control(pDX, IDC_BUTTON2, m_Boneless);
}


BEGIN_MESSAGE_MAP(Option2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Option2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Option2::OnBnClickedButton2)
END_MESSAGE_MAP()


// Option2 메시지 처리기

// 뼈 버튼
void Option2::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bone = TRUE;
	OnOK();
}

// 순살 버튼
void Option2::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bone = FALSE;
	OnOK();
}
