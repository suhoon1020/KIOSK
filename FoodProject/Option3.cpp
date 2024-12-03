// Option3.cpp: 구현 파일
//

#include "pch.h"
#include "FoodProject.h"
#include "afxdialogex.h"
#include "Option3.h"


// Option3 대화 상자

IMPLEMENT_DYNAMIC(Option3, CDialogEx)

Option3::Option3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OPTION3, pParent)
{

}

Option3::~Option3()
{
}

BOOL Option3::OnInitDialog()
{
	CDialog::OnInitDialog();


	m_Bone.LoadBitmaps(IDB_BONE, NULL, NULL, NULL);
	m_Bone.SizeToContent();

	m_Boneless.LoadBitmaps(IDB_BONELESS, NULL, NULL, NULL);
	m_Boneless.SizeToContent();


	return true;
}

void Option3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_Bone);
	DDX_Control(pDX, IDC_BUTTON2, m_Boneless);
}


BEGIN_MESSAGE_MAP(Option3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Option3::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Option3::OnBnClickedButton2)
END_MESSAGE_MAP()


// Option3 메시지 처리기

// 뼈 버튼
void Option3::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bone = TRUE;
	OnOK();
}

// 순살 버튼
void Option3::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	bone = FALSE;
	OnOK();
}
