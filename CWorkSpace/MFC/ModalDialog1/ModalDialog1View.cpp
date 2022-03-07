
// ModalDialog1View.cpp: CModalDialog1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ModalDialog1.h"
#endif

#include "ModalDialog1Doc.h"
#include "ModalDialog1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalDialog1View

IMPLEMENT_DYNCREATE(CModalDialog1View, CFormView)

BEGIN_MESSAGE_MAP(CModalDialog1View, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CModalDialog1View 생성/소멸

CModalDialog1View::CModalDialog1View() noexcept
	: CFormView(IDD_MODALDIALOG1_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CModalDialog1View::~CModalDialog1View()
{
}

void CModalDialog1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CModalDialog1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CModalDialog1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CModalDialog1View 인쇄

BOOL CModalDialog1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CModalDialog1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CModalDialog1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CModalDialog1View::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CModalDialog1View 진단

#ifdef _DEBUG
void CModalDialog1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CModalDialog1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CModalDialog1Doc* CModalDialog1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CModalDialog1Doc)));
	return (CModalDialog1Doc*)m_pDocument;
}
#endif //_DEBUG


// CModalDialog1View 메시지 처리기


void CModalDialog1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CDialog dlg(IDD_DIALOG1); // 대화 상자 리소스 ID를 생성자에 넘겨준다.
	if (dlg.DoModal() == IDOK)
		MessageBox(_T("확인 버튼 누름"));
	else // 리턴 값이 IDCANCEL 인 경우
		MessageBox(_T("취소 버튼 누름"));
}
