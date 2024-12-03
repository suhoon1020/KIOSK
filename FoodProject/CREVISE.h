#pragma once
#include "afxdialogex.h"
#include "Choice.h"

// CREVISE 대화 상자

class CREVISE : public CDialogEx
{
	DECLARE_DYNAMIC(CREVISE)

public:
	CREVISE(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CREVISE();

	BOOL OnInitDialog();



// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_REVISE };
#endif

private:



protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	
	int m_Fried;
	int m_Season;
	int m_Soy;
	int m_Gangjung;
	int m_Combi;
	int m_Bul;
	int m_SweetPotato;
	int m_Pep;
	int m_Zok;
	int m_Bossam;
	int m_SeasonZok;
	int m_BulZok;
	int m_Zza;
	int m_Zzam;
	int m_Tang;
	int m_Rice;


	int ch1;
	int ch2;
	int ch3;
	int ch4;

	int pz1;
	int pz2;
	int pz3;
	int pz4;

	int zok1;
	int zok2;
	int zok3;
	int zok4;

	int jk1;
	int jk2;
	int jk3;
	int jk4;



	afx_msg void OnBnClickedButton1();
};
