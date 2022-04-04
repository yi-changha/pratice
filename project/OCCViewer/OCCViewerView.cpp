
// OCCViewerView.cpp: COCCViewerView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "OCCViewer.h"
#endif

#include <OpenGl_GraphicDriver.hxx>
#include <WNT_Window.hxx>

#include "OCCViewerDoc.h"
#include "OCCViewerView.h"



// COCCViewerView

IMPLEMENT_DYNCREATE(COCCViewerView, CView)

BEGIN_MESSAGE_MAP(COCCViewerView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COCCViewerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_SIZE()
END_MESSAGE_MAP()

// COCCViewerView 생성/소멸

COCCViewerView::COCCViewerView() noexcept
	//: m_pOperator(nullptr)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

COCCViewerView::~COCCViewerView()
{
	m_view->Remove();
}

BOOL COCCViewerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.
	cs.lpszClass = ::AfxRegisterWndClass(CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS | CS_OWNDC, ::LoadCursor(NULL, IDC_ARROW), NULL, NULL);
	return CView::PreCreateWindow(cs);
}

// COCCViewerView 그리기

void COCCViewerView::OnDraw(CDC* /*pDC*/)
{
	COCCViewerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	m_view->Redraw();
}


// COCCViewerView 인쇄


void COCCViewerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL COCCViewerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void COCCViewerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void COCCViewerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void COCCViewerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// COCCViewerView 진단

#ifdef _DEBUG
void COCCViewerView::AssertValid() const
{
	CView::AssertValid();
}

void COCCViewerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COCCViewerDoc* COCCViewerView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COCCViewerDoc)));
	return (COCCViewerDoc*)m_pDocument;
}
#endif //_DEBUG


// COCCViewerView 메시지 처리기


void COCCViewerView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// View를 생성한다.
	m_view = GetDocument()->GetViewer()->CreateView();

	// 윈도우를 생성한다.
	Handle(WNT_Window) window = new WNT_Window(GetSafeHwnd());
	// View와 Window를 연결한다.
	m_view->SetWindow(window);

	if (!window->IsMapped())
	{
		window->Map();
	}

	// 좌표계를 표시한다.
	m_view->ZBufferTriedronSetup();
	m_view->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_BLACK, 0.07, V3d_ZBUFFER);

}

void COCCViewerView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	if (!m_view.IsNull())
		m_view->MustBeResized();
}
