
// mfc_test42_prgressCtrlView.cpp: Cmfctest42prgressCtrlView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test42_prgressCtrl.h"
#endif

#include "mfc_test42_prgressCtrlDoc.h"
#include "mfc_test42_prgressCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest42prgressCtrlView

IMPLEMENT_DYNCREATE(Cmfctest42prgressCtrlView, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest42prgressCtrlView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON_START, &Cmfctest42prgressCtrlView::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_PAUSE, &Cmfctest42prgressCtrlView::OnBnClickedButtonPause)
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Cmfctest42prgressCtrlView 생성/소멸

Cmfctest42prgressCtrlView::Cmfctest42prgressCtrlView() noexcept
	: CFormView(IDD_MFC_TEST42_PRGRESSCTRL_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.
	start1 = FALSE;
	start2 = FALSE;

}

Cmfctest42prgressCtrlView::~Cmfctest42prgressCtrlView()
{
}

void Cmfctest42prgressCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_PROGRESS2, m_progress2);
}

BOOL Cmfctest42prgressCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest42prgressCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Cmfctest42prgressCtrlView 인쇄

BOOL Cmfctest42prgressCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest42prgressCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest42prgressCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cmfctest42prgressCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// Cmfctest42prgressCtrlView 진단

#ifdef _DEBUG
void Cmfctest42prgressCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest42prgressCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest42prgressCtrlDoc* Cmfctest42prgressCtrlView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest42prgressCtrlDoc)));
	return (Cmfctest42prgressCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest42prgressCtrlView 메시지 처리기


void Cmfctest42prgressCtrlView::OnBnClickedButtonStart()
{
	if (start1 == FALSE) {
		start1 = TRUE;
		m_progress.SetRange(0, 100); // 값의 범위를 설정한다.
		m_progress.SetPos(0); // 현재 위치를 설정한다.
		SetTimer(1, 50, NULL); // ID가 1, 50/1000 초인 타이머를 생성한다.
	}

	if (start2 == FALSE) {
		start2 = TRUE;
		m_progress2.SetRange(0, 100); 
		m_progress2.SetPos(0); 
		SetTimer(2, 50, NULL); // ID가 2, 50/1000 초인 타이머
	}
}


void Cmfctest42prgressCtrlView::OnBnClickedButtonPause() // 세로 프로그래스 일시 중지
{
	cnt++;
	if (cnt % 2 == 1) {
		KillTimer(2);
		m_progress2.OffsetPos(0);
	}
	else {
		SetTimer(2, 50, NULL);
		OnTimer(2);
	}
	//m_progress2.SetPos(PBST_PAUSED); // 세로 프로그래스 일시 중지
}


void Cmfctest42prgressCtrlView::OnTimer(UINT_PTR nIDEvent)
{
	m_progress.SetBarColor(RGB(255, 0, 0)); // 색상은 멀티바이트에서만 적용됨. 기본 색상은 녹색
	// 멀티바이트 설정이 아닐 때는 청색으로 표현됨.
	
	if (nIDEvent == 1) {
		if (m_progress.GetPos() < 100)
			m_progress.OffsetPos(1); // 현재 위치를 1씩 증가한다.
		else {
			KillTimer(1); //KillTimer(nIDEVENT); // 타이머 파괴
			start1 = FALSE;
		}
	}
	
	if (nIDEvent == 2) {
		if (m_progress2.GetPos() < 100)
			m_progress2.OffsetPos(1); // 현재 위치를 1씩 증가한다.
		else {
			KillTimer(2); //KillTimer(nIDEVENT); // 타이머 파괴
			start2 = FALSE;
		}
	}
	CFormView::OnTimer(nIDEvent);
}
