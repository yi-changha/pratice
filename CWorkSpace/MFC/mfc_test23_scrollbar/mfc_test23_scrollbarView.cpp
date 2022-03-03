
// mfc_test23_scrollbarView.cpp: Cmfctest23scrollbarView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test23_scrollbar.h"
#endif

#include "mfc_test23_scrollbarDoc.h"
#include "mfc_test23_scrollbarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest23scrollbarView

IMPLEMENT_DYNCREATE(Cmfctest23scrollbarView, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest23scrollbarView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_HSCROLL()
	ON_WM_VSCROLL()
END_MESSAGE_MAP()

// Cmfctest23scrollbarView 생성/소멸

Cmfctest23scrollbarView::Cmfctest23scrollbarView() noexcept
	: CFormView(IDD_MFC_TEST23_SCROLLBAR_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest23scrollbarView::~Cmfctest23scrollbarView()
{
}

void Cmfctest23scrollbarView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_static);
	DDX_Control(pDX, IDC_SCROLLBARH, m_scrollh);
	DDX_Control(pDX, IDC_SCROLLBARV, m_scrollv);
}

BOOL Cmfctest23scrollbarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest23scrollbarView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_scrollh.SetScrollRange(0, 360, FALSE); // 0~360 범위 설정
	m_scrollh.SetScrollPos(0);
	m_scrollv.SetScrollRange(0, 255, FALSE); // 0~255 범위 설정
	m_scrollv.SetScrollPos(128);
}


// Cmfctest23scrollbarView 인쇄

BOOL Cmfctest23scrollbarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest23scrollbarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest23scrollbarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cmfctest23scrollbarView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// Cmfctest23scrollbarView 진단

#ifdef _DEBUG
void Cmfctest23scrollbarView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest23scrollbarView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest23scrollbarDoc* Cmfctest23scrollbarView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest23scrollbarDoc)));
	return (Cmfctest23scrollbarDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest23scrollbarView 메시지 처리기



void Cmfctest23scrollbarView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{									// nSBCode : 스크롤바 코드, nPos : 스크롤 박스의 현재 위치, pScrollBar: pScrollBar 객체
	if (pScrollBar != NULL) {	// 스크롤바 컨트롤에서 발생한 메시지이면 (NULL 값이 아니면)
		if (pScrollBar->GetSafeHwnd() == m_scrollh.GetSafeHwnd()) {	// m_scrollh 객체의 수평 스크롤바 일때
			// GetSafeHwnd() : 자신의 핸들을 가져오는 함수, 스크롤바의 현재 위치를 얻는다.

			switch (nSBCode) {
			case SB_THUMBTRACK: // 스크롤바 위치(Thumb 라고 부름)
				pScrollBar->SetScrollPos(nPos);	// 스크롤바의 현재 위치값 설정
				break;
			}
			Invalidate();	// 클라이언트 영역 무효화(강제 화면 갱신)
		}
	}
	else   // 윈도우 스크롤바에서 발생한 메시지이면 (클라이언트 테두리에 있는 스크롤)
		CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void Cmfctest23scrollbarView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int pos;
	int delta = 0;
	if (pScrollBar != NULL) {
		if (pScrollBar->GetSafeHwnd() == m_scrollv.GetSafeHwnd()) {
			switch (nSBCode) {
			case SB_THUMBTRACK: 
				pScrollBar->SetScrollPos(nPos);
				break;
			case SB_LINEUP: // 사용자가 위쪽 화살표 버튼 누름, 위쪽으로 한 단위 스크롤
				delta -= 4;
				break;
			case SB_LINEDOWN:	// 사용자가 아래쪽 화살표 버튼을 누름, 아래쪽으로 한 단위 스크롤
				delta += 4;
				break;
			case SB_PAGEUP:	// 사용자가 위쪽 몸통 부분을 누름, 위쪽으로 한 페이지 스크롤
				delta -= 20;
				break;
			case SB_PAGEDOWN:	// 사용자가 아래쪽 몸통 부분을 누름, 아래쪽으로 한 페이지 스크롤
				delta += 20;
				break;
			}
			if (delta != 0) {
				pos = pScrollBar->GetScrollPos();
				pScrollBar->SetScrollPos(pos + delta);
			}
			Invalidate();	
		}
	}
	else 
		CFormView::OnVScroll(nSBCode, nPos, pScrollBar);
}




void Cmfctest23scrollbarView::OnDraw(CDC* pDC)
{
	// 스크롤바의 현재 위치를 얻는다.
	int posh = m_scrollh.GetScrollPos();
	int posv = m_scrollv.GetScrollPos();

	CFont font;

	LOGFONT lf = { 0 };	// LOGFONT 구조체 변수 IF를 0으로 초기화. 논리크기
	lf.lfHeight = posv / 3 + 1;	// 폰트 크기 설정. vpos==0이면 크기는 1.

	lf.lfEscapement = 10 * posh;	// 폰트 회전각을 설정. (*10을 하면 360도 회전됨)
	
	// lf.lfEscapement = hpos; // 폰트 회전각을 설정한다.
	// nEscapement:폰트의 각도를 0.1도 단위로 설정한다.(곱하기 10을 해주면 360도 회전됨)
	// 각도는 문자가 출력될 X출력과 문자열과의 각도이며 일상적인 360분법의 각도 체계를 사용한다.
	// 3시 방향이 0도로 사용되며 반시계 방향으로 각도가 증가한다

	font.CreateFontIndirect(&lf);	// 로그폰트 생성

	pDC->SelectObject(&font);
	pDC->SetTextColor(RGB(posv, 0, 0));	// 폰트 색상 설정.

	pDC->TextOut(300, 500, CString(_T("스크롤바 컨트롤 연습")));
	CString str;
	str.Format(_T("글자 크기 : %d, 회전각 : %d, 빨강색 농도 : %d"), lf.lfHeight, posh, posv);
	m_static.SetWindowText(str);	// 스태틱 텍스트 컨트롤에 출력

}
