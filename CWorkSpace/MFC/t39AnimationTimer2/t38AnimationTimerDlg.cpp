
// t38AnimationTimerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "t38AnimationTimer.h"
#include "t38AnimationTimerDlg.h"
#include "afxdialogex.h"
#include <atlimage.h> // png 이미지 (배경 투명처리 기능) 관련 헤더파일 추가

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// Ct38AnimationTimerDlg 대화 상자



Ct38AnimationTimerDlg::Ct38AnimationTimerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_T38ANIMATIONTIMER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ct38AnimationTimerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ct38AnimationTimerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON1, &Ct38AnimationTimerDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Ct38AnimationTimerDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Ct38AnimationTimerDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Ct38AnimationTimerDlg::OnBnClickedButton4)
END_MESSAGE_MAP()


// Ct38AnimationTimerDlg 메시지 처리기

BOOL Ct38AnimationTimerDlg::OnInitDialog()
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

	SetTimer(1, 10, NULL); // 100/1000초 단위 사건 발생 image1(물고기들)
	image1.x = 0;

	SetTimer(2, 500, NULL); // 500/1000초 (0.5)초 단위
	SetTimer(3, 500, NULL);

	// 이미지 형식별 불러오기
	m_png1.Load(_T("shark.png"));
	m_jpg1.Load(_T("fish.jpg"));
	m_bmp1.Load(_T("dolphin.bmp"));
	m_gif1.Load(_T("seahorse.gif")); // gif 애니메이션은 별도로 작성해야함.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Ct38AnimationTimerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Ct38AnimationTimerDlg::OnPaint()
{
	CPaintDC dc(this);
	CPaintDC* pDC = &dc; // OnDraw() 함수에서의 형식을 그대로 사용하기 위함.

	CBitmap bk1, bk2, octo1, turtle1, octo2, turtle2, shark1, * pold;
	CDC memDC;

	memDC.CreateCompatibleDC(pDC); // 화면DC와 호환되는 메모리 DC 생성

	bk1.LoadBitmap(IDB_BITMAP1);
	bk2.LoadBitmap(IDB_BITMAP2);

	octo1.LoadBitmap(IDB_OCTO1);
	turtle1.LoadBitmap(IDB_TURTLE1);
	octo2.LoadBitmap(IDB_OCTO1);
	turtle2.LoadBitmap(IDB_TURTLE1);
	shark1.LoadBitmap(IDB_SHARK1);


	// StretchBlt: Blt => Block Transfer 비트맵 데이터를 블록 단위로 고속 전송한다.

	pold = memDC.SelectObject(&bk1); // 배경 1
	pDC->StretchBlt(0, 0, 1920, 1080, &memDC, 0, 0, 1920, 1080, SRCCOPY);
	DeleteObject(bk1);

	// 상어 이동
	pold = memDC.SelectObject(&shark1);
	pDC->TransparentBlt(image1.x, 150, 100, 75, &memDC, 0, 0, 100, 75, RGB(255, 255, 255)); // image1.x timer에 의해 발생된 값
	DeleteObject(shark1);

	// 문어 이동
	pold = memDC.SelectObject(&octo1);
	pDC->TransparentBlt(1920 - image1.x, 450, 100, 66, &memDC, 0, 0, 100, 66, RGB(255, 255, 255));
	DeleteObject(octo1);

	// 거북이 이동
	pold = memDC.SelectObject(&turtle1);
	pDC->TransparentBlt(1920 - image1.x, 850, 100, 72, &memDC, 0, 0, 100, 72, RGB(255, 255, 255));
	DeleteObject(turtle1);

	// 불투명 객체 이동
	// 문어 이동
	pold = memDC.SelectObject(&octo2);
	pDC->StretchBlt(1920 - image1.x, 550, 100, 66, &memDC, 0, 0, 100, 66, SRCCOPY);
	DeleteObject(octo2);
	// 거북이 이동
	pold = memDC.SelectObject(&turtle2);
	pDC->StretchBlt(1920 - image1.x, 950, 100, 72, &memDC, 0, 0, 100, 72, SRCCOPY);
	DeleteObject(turtle2);
	

	// 이미지 형태별 그리기
	m_png1.Draw(dc, 200, 800); // 그림 크기 default
	m_jpg1.Draw(dc, 600, 800, 100, 100); // 그림 크기 100 x 100
	m_bmp1.Draw(dc, 1000, 600);
	m_gif1.Draw(dc, 200, 200);


	// 배경그림 1 시작
	
	int i1 = 0;
	static int flag1 = 0;

	if (flag1 == 0) {	// 배경 그림 한번만 불러오기 위한 플러그 설정 시작
		for (i1 = 1920; i1 > -1920; i1 = i1 - 10) {
			pDC->StretchBlt(i1, 0, 1920, 1080, &memDC, 0, 0, 1920, 1080, SRCCOPY);
		}
		flag1 = 1; // 배경 그림 한번만 불러오기 위한 플러그 설정 끝
	}
	DeleteObject(bk1); // bk1 객체 지우기

	// 배경그림 2 시작

	int i2 = 0;
	static int flag2 = 0;

	if (flag2 == 0) {	
		for (i2 = 1920; i2 > -1920; i2 = i2 - 10) {
			pDC->StretchBlt(i2, 0, 1920, 1080, &memDC, 0, 0, 1920, 1080, SRCCOPY);
		}
		flag2 = 1; 
		pDC->StretchBlt(0, 0, 1920, 1080, &memDC, 0, 0, 1920, 1080, SRCCOPY);
	}
	DeleteObject(bk2);

	CDialogEx::OnPaint();
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Ct38AnimationTimerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Ct38AnimationTimerDlg::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent) {
	case(1): // 타이머 1 선택
	{
		image1.x++;
	}
	case(2): // 타이머 2 선택 (물고기 확대)
	{
		CClientDC dc(this);
		CDC memDC;
		static CBitmap img1[4];
		static int flag = 0;
		static int lx = width1 / 100, ly = height1 / 100;
		int x = 0, y = 0;
		
		if (flag == 0) {
			img1[1].LoadBitmap(IDB_OCTO1);
			img1[2].LoadBitmap(IDB_SHARK1);
			img1[3].LoadBitmap(IDB_TURTLE1);
			flag = 1;
		}

		if (lx > 1500) // 창 크기가 가로(x좌표) 1500픽셀에 도달하면
		{
			InvalidateRect(NULL, TRUE); // 창 내부를 지움 (그림 확대 후 다시 나타날 때 지움

			lx = width1 / 100;
			ly = height1 / 100;
			return;
		}

		memDC.CreateCompatibleDC(&dc);
		memDC.SelectObject(img1[idx]);

		x = width1 / 2 - lx / 2;
		y = height1 / 2 - ly / 2;

		dc.StretchBlt(x, y, lx, ly, &memDC, 0, 0, 100, 100, SRCCOPY);

		DeleteObject(&dc); // 메모리 해제

		lx += width1 / 100; // x축 크기 증가
		ly += height1 / 80; // y축 크기 증가
	}
	}
	CDialogEx::OnTimer(nIDEvent);
}


void Ct38AnimationTimerDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	RECT rect1;
	GetClientRect(&rect1);
	width1 = rect1.right;
	height1 = rect1.bottom;
}


void Ct38AnimationTimerDlg::OnBnClickedButton1() // 거북이
{
	InvalidateRect(NULL, TRUE); // 창 내부를 지움
	idx = 3;
}


void Ct38AnimationTimerDlg::OnBnClickedButton2() // 문어
{
	InvalidateRect(NULL, TRUE); // 창 내부를 지움
	idx = 1;
}


void Ct38AnimationTimerDlg::OnBnClickedButton3() // 상어
{
	InvalidateRect(NULL, TRUE); // 창 내부를 지움
	idx = 2;
}


void Ct38AnimationTimerDlg::OnBnClickedButton4()
{
	InvalidateRect(NULL, TRUE); // 창 내부를 지움
	idx = 0;
}
