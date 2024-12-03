// CREVISE.cpp: 구현 파일
//

#include "pch.h"
#include "FoodProject.h"
#include "afxdialogex.h"
#include "CREVISE.h"
#include "Choice.h"
#include "FoodProjectDlg.h"
#include "CADMIN.h"


// CREVISE 대화 상자

IMPLEMENT_DYNAMIC(CREVISE, CDialogEx)

CREVISE::CREVISE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_REVISE, pParent)

	, m_Fried(0)
	, m_Season(0)
	, m_Soy(0)
	, m_Gangjung(0)
	, m_Combi(0)
	, m_Bul(0)
	, m_SweetPotato(0)
	, m_Pep(0)
	, m_Zok(0)
	, m_Bossam(0)
	, m_SeasonZok(0)
	, m_BulZok(0)
	, m_Zza(0)
	, m_Zzam(0)
	, m_Tang(0)
	, m_Rice(0)
{

}

CREVISE::~CREVISE()
{
}

BOOL CREVISE::OnInitDialog()
{
	CDialog::OnInitDialog();
	UpdateData(true);
	

	m_Fried = ch->Chik1;
	m_Season = ch->Chik2;
	m_Soy = ch->Chik3;
	m_Gangjung = ch->Chik4;

	m_Combi = ch->Piz1;
	m_Bul = ch->Piz2;
	m_SweetPotato = ch->Piz3;
	m_Pep = ch->Piz4;

	m_Zok = ch->Jk1;
	m_Bossam = ch->Jk2;
	m_SeasonZok = ch->Jk3;
	m_BulZok = ch->Jk4;

	m_Zza = ch->Cf1;
	m_Zzam = ch->Cf2;
	m_Tang = ch->Cf3;
	m_Rice = ch->Cf4;


	UpdateData(false);
	return true;
}

void CREVISE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Text(pDX, IDC_EDIT1, m_Fried);
	DDX_Text(pDX, IDC_EDIT2, m_Season);
	DDX_Text(pDX, IDC_EDIT5, m_Soy);
	DDX_Text(pDX, IDC_EDIT6, m_Gangjung);
	DDX_Text(pDX, IDC_EDIT3, m_Combi);
	DDX_Text(pDX, IDC_EDIT4, m_Bul);
	DDX_Text(pDX, IDC_EDIT7, m_SweetPotato);
	DDX_Text(pDX, IDC_EDIT8, m_Pep);
	DDX_Text(pDX, IDC_EDIT11, m_Zok);
	DDX_Text(pDX, IDC_EDIT12, m_Bossam);
	DDX_Text(pDX, IDC_EDIT9, m_SeasonZok);
	DDX_Text(pDX, IDC_EDIT10, m_BulZok);
	DDX_Text(pDX, IDC_EDIT15, m_Zza);
	DDX_Text(pDX, IDC_EDIT16, m_Zzam);
	DDX_Text(pDX, IDC_EDIT13, m_Tang);
	DDX_Text(pDX, IDC_EDIT14, m_Rice);
}




BEGIN_MESSAGE_MAP(CREVISE, CDialogEx)

	ON_BN_CLICKED(IDC_BUTTON1, &CREVISE::OnBnClickedButton1)
END_MESSAGE_MAP()


// CREVISE 메시지 처리기




void CREVISE::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE);

	ch->Chik1 = m_Fried;
	ch->Chik2 = m_Season;
	ch->Chik3 = m_Soy;
	ch->Chik4 = m_Gangjung;

	ch->Piz1 = m_Combi;
	ch->Piz2 = m_Bul;
	ch->Piz3 = m_SweetPotato;
	ch->Piz4 = m_Pep;

	ch->Jk1 = m_Zok;
	ch->Jk2 = m_Bossam;
	ch->Jk3 = m_SeasonZok;
	ch->Jk4 = m_BulZok;

	ch->Cf1 = m_Zza;
	ch->Cf2 = m_Zzam;
	ch->Cf3 = m_Tang;
	ch->Cf4 = m_Rice;

	UpdateData(false);

	MessageBox(_T("가격 수정이 완료되었습니다."));

	OnOK();
	CADMIN admin;
	admin.DoModal();
}
