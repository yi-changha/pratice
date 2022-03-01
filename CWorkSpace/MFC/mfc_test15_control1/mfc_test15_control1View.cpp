
// mfc_test15_control1View.cpp: Cmfctest15control1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test15_control1.h"
#endif

#include "mfc_test15_control1Doc.h"
#include "mfc_test15_control1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest15control1View

IMPLEMENT_DYNCREATE(Cmfctest15control1View, CScrollView)

BEGIN_MESSAGE_MAP(Cmfctest15control1View, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_CREATE()

	// 버튼 클릭시 발생하는 통지메시지와 함수연결 메시지맵
	ON_BN_CLICKED(101, OnButtonClicked1) // 버튼아이디, 멤버함수
	ON_BN_CLICKED(102, OnButtonClicked2) // 버튼아이디, 멤버함수

END_MESSAGE_MAP()

// Cmfctest15control1View 생성/소멸

Cmfctest15control1View::Cmfctest15control1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest15control1View::~Cmfctest15control1View()
{
}

BOOL Cmfctest15control1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// Cmfctest15control1View 그리기

void Cmfctest15control1View::OnDraw(CDC* pDC)
{
	Cmfctest15control1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	pDC->SetTextColor(RGB(0, 0, 0)); // 글자색
	pDC->SetBkColor(RGB(255, 255, 0)); // 글씨 배경색
	pDC->TextOut(50, 50, CString(_T("※ 다음 물음에 알맞은 답을 고르세요.")));

	// 문제 은행
	pDC->SetTextColor(RGB(0, 0, 0)); // 글자색
	pDC->SetBkColor(RGB(255, 255, 255)); // 글씨 배경색
	CFont font, * pOldFont;
	font.CreatePointFont(150, _T("궁서체"));
	pOldFont = (CFont*)pDC->SelectObject(&font);

	pDC->TextOut(50, 100, CString(_T("1. 다음 중 동물이 아닌 것은? [20점]")));
	pDC->TextOut(50, 140, CString(_T("가. 물")));
	pDC->TextOut(50, 180, CString(_T("나. 고양이")));
	pDC->TextOut(50, 220, CString(_T("다. 참새")));
	pDC->TextOut(50, 260, CString(_T("라. 자라")));
	pDC->TextOut(50, 300, CString(_T("마. 사람")));

	pDC->TextOut(50, 400, CString(_T("2. 다음 중 한 글자가 아닌 것은? [15점]")));
	pDC->TextOut(50, 440, CString(_T("가. 뱀")));
	pDC->TextOut(50, 480, CString(_T("나. 금")));
	pDC->TextOut(50, 520, CString(_T("다. 돈")));
	pDC->TextOut(50, 560, CString(_T("라. 힘")));
	pDC->TextOut(50, 600, CString(_T("마. 프로그래밍")));

	pDC->TextOut(50, 800, CString(_T("연습으로 화면을 벗어난 스크롤")));
	pDC->TextOut(50, 850, CString(_T("고양이 강아지 닭 토끼 말 기린")));
}

void Cmfctest15control1View::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 2000;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// Cmfctest15control1View 인쇄

BOOL Cmfctest15control1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest15control1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest15control1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cmfctest15control1View 진단

#ifdef _DEBUG
void Cmfctest15control1View::AssertValid() const
{
	CScrollView::AssertValid();
}

void Cmfctest15control1View::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

Cmfctest15control1Doc* Cmfctest15control1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest15control1Doc)));
	return (Cmfctest15control1Doc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest15control1View 메시지 처리기


int Cmfctest15control1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CScrollView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	//-----------------------1번 문항----------------------
	// 버튼 컨트롤을 생성한다.
	m_pushbutton1.Create(_T("정답확인"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(590, 90, 690, 130), this, 101);

	m_checkbox1_1.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 
		CRect(30, 130, 80, 170), this, 1011);
	m_checkbox1_2.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 
		CRect(30, 170, 80, 210), this, 1012);
	m_checkbox1_3.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 
		CRect(30, 210, 80, 250), this, 1013);
	m_checkbox1_4.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 
		CRect(30, 250, 80, 290), this, 1014);
	m_checkbox1_5.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX, 
		CRect(30, 290, 80, 330), this, 1015);

	// 버튼 컨트롤을 초기화한다.
	m_checkbox1_1.SetCheck(0);	// 0(체크안됨), 1(체크됨), 2(회색)
	m_checkbox1_2.SetCheck(0);
	m_checkbox1_3.SetCheck(0);
	m_checkbox1_4.SetCheck(0);
	m_checkbox1_5.SetCheck(0);


	//-----------------------2번 문항----------------------
	// 버튼 컨트롤을 생성한다.
	m_pushbutton2.Create(_T("정답확인"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
		CRect(620, 390, 720, 430), this, 102);

	m_checkbox2_1.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(30, 430, 80, 470), this, 1021);
	m_checkbox2_2.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(30, 470, 80, 510), this, 1022);
	m_checkbox2_3.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(30, 510, 80, 550), this, 1023);
	m_checkbox2_4.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(30, 550, 80, 590), this, 1024);
	m_checkbox2_5.Create(_T(""), WS_CHILD | WS_VISIBLE | BS_AUTOCHECKBOX,
		CRect(30, 590, 80, 630), this, 1025);

	// 버튼 컨트롤을 초기화한다.
	m_checkbox2_1.SetCheck(0);	// 0(체크안됨), 1(체크됨), 2(회색)
	m_checkbox2_2.SetCheck(0);
	m_checkbox2_3.SetCheck(0);
	m_checkbox2_4.SetCheck(0);
	m_checkbox2_5.SetCheck(0);

	return 0;
}


void Cmfctest15control1View::OnButtonClicked1()
{
	// 1번 문제
	int state_checkbox1_1 = m_checkbox1_1.GetCheck();
	int state_checkbox1_2 = m_checkbox1_2.GetCheck();
	int state_checkbox1_3 = m_checkbox1_3.GetCheck();
	int state_checkbox1_4 = m_checkbox1_4.GetCheck();
	int state_checkbox1_5 = m_checkbox1_5.GetCheck();

	CString str1;
	str1.Format(_T("맞은 점수 : [ %d ] 점"), state_checkbox1_1 * 20);

	MessageBox(str1, _T("1번 문제 결과"), MB_ICONINFORMATION);
}



void Cmfctest15control1View::OnButtonClicked2()
{
	// 2번 문제
	int state_checkbox2_1 = m_checkbox2_1.GetCheck();
	int state_checkbox2_2 = m_checkbox2_2.GetCheck();
	int state_checkbox2_3 = m_checkbox2_3.GetCheck();
	int state_checkbox2_4 = m_checkbox2_4.GetCheck();
	int state_checkbox2_5 = m_checkbox2_5.GetCheck();

	CString str2;
	str2.Format(_T("맞은 점수 : [ %d ] 점"), state_checkbox2_5 * 15);

	MessageBox(str2, _T("2번 문제 결과"), MB_ICONINFORMATION);
}
