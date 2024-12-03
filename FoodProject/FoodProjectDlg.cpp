﻿
// FoodProjectDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "FoodProject.h"
#include "FoodProjectDlg.h"
#include "afxdialogex.h"
#include "CSIGNUP.h"
#include "Choice.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "CADMIN.h"



// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

CFoodProjectDlg cpd;

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
public:
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)

END_MESSAGE_MAP()


// CFoodProjectDlg 대화 상자



CFoodProjectDlg::CFoodProjectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FOODPROJECT_DIALOG, pParent)
	, m_ID(_T(""))
	, m_PW(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFoodProjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_ID, m_ID);
	DDX_Text(pDX, IDC_EDIT_PW, m_PW);
}

BEGIN_MESSAGE_MAP(CFoodProjectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTT_LOGIN, &CFoodProjectDlg::OnBnClickedButtLogin)
	ON_BN_CLICKED(IDC_BUTT_SIGNUP, &CFoodProjectDlg::OnBnClickedButtSignup)
	ON_BN_CLICKED(IDC_BUTTON1, &CFoodProjectDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFoodProjectDlg 메시지 처리기

BOOL CFoodProjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	


	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CFoodProjectDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CFoodProjectDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CFoodProjectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// 로그인 버튼
void CFoodProjectDlg::OnBnClickedButtLogin()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//ch = new Choice;

	UpdateData(TRUE);
	
	if (m_ID==aID && m_PW == aPW) {
		MessageBox(_T("관리자 로그인에 성공하였습니다"));
		/*
		관리자 모달창 띄우기
		*/
		CADMIN admin;
		ShowWindow(SW_HIDE);
		admin.DoModal();
	}
	else if (m_ID == customID && m_PW == customPW && m_ID != "" && m_PW != "") {
		MessageBox(_T("사용자 로그인 성공"));
		/*
		* 사용자 로그인 모달창 띄우면됨
		*/
		ShowWindow(SW_HIDE);
		if (ch->GetSafeHwnd() == NULL) {
			ch->Create(IDD_CHOICE);
		}
		ch->ShowWindow(SW_SHOW);
		ch->name = name;
	}
	else {
		MessageBox(_T("로그인 실패"));
	}

	UpdateData(false);
}


void CFoodProjectDlg::OnBnClickedButtSignup()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (isSign == false) {
		CSIGNUP PopupDialog;
		if (PopupDialog.DoModal() == IDOK)
		{
			customID = PopupDialog.ID;
			customPW = PopupDialog.PW;
			name = PopupDialog.name;
			UpdateData(FALSE);
		}
	}
	else {
		MessageBox(_T("이미 회원가입을 완료 하였습니다."));
	}
}





void CFoodProjectDlg::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ch->DestroyWindow();
	OnOK();
}
