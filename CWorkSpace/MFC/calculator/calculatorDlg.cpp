
// calculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define plus 1 // 덧셈, 상수 1로 선언
#define minus 2 // 뺄셈
#define multiple 3 // 곱셈
#define divide 4 // 나눗셈

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

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


// CcalculatorDlg 대화 상자



CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent)
	//, m_result(_T("")
{
	m_result = _T(""); // 결과값 출력 초기화

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bEqualClk = false; // '='클릭 생성자함수 초기화
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_result);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ERASE, &CcalculatorDlg::OnBnClickedErase)
	ON_BN_CLICKED(IDC_B0, &CcalculatorDlg::OnBnClickedB0)
	ON_BN_CLICKED(IDC_B1, &CcalculatorDlg::OnBnClickedB1)
	ON_BN_CLICKED(IDC_B2, &CcalculatorDlg::OnBnClickedB2)
	ON_BN_CLICKED(IDC_B3, &CcalculatorDlg::OnBnClickedB3)
	ON_BN_CLICKED(IDC_B4, &CcalculatorDlg::OnBnClickedB4)
	ON_BN_CLICKED(IDC_B5, &CcalculatorDlg::OnBnClickedB5)
	ON_BN_CLICKED(IDC_B6, &CcalculatorDlg::OnBnClickedB6)
	ON_BN_CLICKED(IDC_B7, &CcalculatorDlg::OnBnClickedB7)
	ON_BN_CLICKED(IDC_B8, &CcalculatorDlg::OnBnClickedB8)
	ON_BN_CLICKED(IDC_B9, &CcalculatorDlg::OnBnClickedB9)
	ON_BN_CLICKED(IDC_DOT, &CcalculatorDlg::OnBnClickedDot)
	ON_BN_CLICKED(IDC_EQUAL, &CcalculatorDlg::OnBnClickedEqual)
	ON_BN_CLICKED(IDC_LOTTO, &CcalculatorDlg::OnBnClickedLotto)
	ON_BN_CLICKED(IDC_PLUS, &CcalculatorDlg::OnBnClickedPlus)
	ON_BN_CLICKED(IDC_MINUS, &CcalculatorDlg::OnBnClickedMinus)
	ON_BN_CLICKED(IDC_MUL, &CcalculatorDlg::OnBnClickedMul)
	ON_BN_CLICKED(IDC_DIV, &CcalculatorDlg::OnBnClickedDiv)
END_MESSAGE_MAP()


// CcalculatorDlg 메시지 처리기

BOOL CcalculatorDlg::OnInitDialog()
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

	// 제목 코드
	CString str;
	str.Format(_T("계산기"));
	SetWindowText(str);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CcalculatorDlg::OnPaint()
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
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalculatorDlg::OnBnClickedErase()
{
	m_result.Empty();	//m_result += _T("");
	UpdateData(false);	// 변수 => 컨트롤에 출력
}


void CcalculatorDlg::OnBnClickedB0()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("0"); // 문자 0
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB1()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("1");
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB2()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("2");
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB3()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("3");
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB4()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("4");
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB5()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("5");
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB6()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("6");
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB7()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("7");
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB8()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("8");
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedB9()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T("9");
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedDot()
{
	if (m_bEqualClk) {
		m_result.Empty();
		m_bEqualClk = false;
	}
	m_result += _T(".");
	UpdateData(false);
}


void CcalculatorDlg::OnBnClickedEqual()
{
	double op1, op2, result;

	op1 = _tstof(m_buf); // 문자를 숫자로 변환
	op2 = _tstof(m_result);

	switch (m_cType) {
	case plus: //1
		result = op1 + op2;
		break;
	case minus: //2
		result = op1 - op2;
		break;
	case multiple: //3
		result = op1 * op2;
		break;
	case divide: //4
		result = op1 / op2;
		break;
	}
	m_result.Format(_T("%.6f"), result);

	UpdateData(false); // 화면에 출력
	m_bEqualClk = true;
}


void CcalculatorDlg::OnBnClickedLotto()	// 로또 복권 추첨
{
	UpdateData(FALSE);
	CClientDC dc(this);
	srand((unsigned)time(NULL)); // 난수 발생 초기화

	CString str, lotto;
	for (int i = 0; i < 6; i++) {
		str.Format(_T(" %2d "), rand() % 45 + 1);
		// 45로 나눈 나머지 값으로 범위는 0~44,
		// 이 값에 1을 더하므로 1~45 사이의 난수 생성

		lotto = lotto + str;
	}
	SetDlgItemText(IDC_EDIT1, lotto);
	UpdateData(TRUE); // 컨트롤 => 변수
}


void CcalculatorDlg::OnBnClickedPlus()
{
	m_cType = plus;
	m_buf = m_result;
	m_result.Empty();
}


void CcalculatorDlg::OnBnClickedMinus()
{
	m_cType = minus;
	m_buf = m_result;
	m_result.Empty();
}


void CcalculatorDlg::OnBnClickedMul()
{
	m_cType = multiple;
	m_buf = m_result;
	m_result.Empty();
}


void CcalculatorDlg::OnBnClickedDiv()
{
	m_cType = divide;
	m_buf = m_result;
	m_result.Empty();
}
