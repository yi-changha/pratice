
// mfc_test13_documentView.cpp: Cmfctest13documentView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test13_document.h"
#endif

#include "mfc_test13_documentDoc.h"
#include "mfc_test13_documentView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest13documentView

IMPLEMENT_DYNCREATE(Cmfctest13documentView, CView)

BEGIN_MESSAGE_MAP(Cmfctest13documentView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Cmfctest13documentView 생성/소멸

Cmfctest13documentView::Cmfctest13documentView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest13documentView::~Cmfctest13documentView()
{
}

BOOL Cmfctest13documentView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cmfctest13documentView 그리기

void Cmfctest13documentView::OnDraw(CDC* pDC)
{
	Cmfctest13documentDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	pDC->SetMapMode(MM_LOMETRIC); // 0.1mm 단위 매핑모드 변경(화면출력 및 종이에 그대로 출력)
	pDC->Rectangle(50, -50, 350, -350); // 30mm 정사각형 화면 출력 및 인쇄됨.
	pDC->Ellipse(500, -50, 800, -350); // 30mm 타원이 화면 출력 및 인쇄됨.
	// y좌표 A4용지에서 출력되는 것 생각해보기. -가 붙어야 출력됨. 

	pDC->MoveTo(450, 500); //y좌표 음수로 표현하지 않으면 MM_LOMETRIC에서는 화면에 표시 안됨.
	pDC->LineTo(450, -500);


	//--------------------------------
	pDC->SetMapMode(MM_TEXT); // 픽셀 단위 매핑모드로 변경, 주석처리 시 화면에 그려지지 않음.

	CPen pen, * pen1;
	CPen pen_Red;

	pen.CreatePen(PS_SOLID, 3, RGB(0, 0, 0)); // 검정펜
	pen_Red.CreatePen(PS_DOT, 1, RGB(255, 0, 0)); // 빨간 점선

	pen1 = pDC->SelectObject(&pen);
	pDC->MoveTo(50, 200);
	pDC->LineTo(50, 500);
	pDC->LineTo(700, 500);

	//빨간선
	pDC->SelectObject(pen_Red);

	pDC->MoveTo(50, 500);
	pDC->LineTo(150, 300);
	pDC->LineTo(250, 350);
	pDC->LineTo(350, 200);
	pDC->LineTo(450, 350);
	pDC->LineTo(550, 300);
	pDC->LineTo(650, 500);

	
	//---------------------------------------
	CFont font; // 폰트 클래스 변수명 font 선언

	font.CreatePointFont(300, _T("궁서")); // 윈도우 시스템 궁성체 300픽셀
	pDC->SelectObject(&font); // 폰트 선택

	pDC->SetTextColor(RGB(0, 255, 255));
	pDC->TextOut(330, 30, CString(_T("0.1mm 단위 매핑모드로 사각형, 원이 종이에 인쇄됨")));

	pDC->SetTextColor(RGB(255, 0, 255));
	pDC->TextOut(100, 160, CString(_T("MFC DocumentView 연습")));
}


// Cmfctest13documentView 인쇄

BOOL Cmfctest13documentView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest13documentView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest13documentView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cmfctest13documentView 진단

#ifdef _DEBUG
void Cmfctest13documentView::AssertValid() const
{
	CView::AssertValid();
}

void Cmfctest13documentView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfctest13documentDoc* Cmfctest13documentView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest13documentDoc)));
	return (Cmfctest13documentDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest13documentView 메시지 처리기
