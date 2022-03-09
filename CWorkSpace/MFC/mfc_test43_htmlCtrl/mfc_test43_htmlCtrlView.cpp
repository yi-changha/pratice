
// mfc_test43_htmlCtrlView.cpp: Cmfctest43htmlCtrlView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test43_htmlCtrl.h"
#endif

#include "mfc_test43_htmlCtrlDoc.h"
#include "mfc_test43_htmlCtrlView.h"

// 추가
#include "CWeb1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest43htmlCtrlView

IMPLEMENT_DYNCREATE(Cmfctest43htmlCtrlView, CHtmlView)

BEGIN_MESSAGE_MAP(Cmfctest43htmlCtrlView, CHtmlView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CHtmlView::OnFilePrint)
	ON_COMMAND(ID_WEB_BACK, &Cmfctest43htmlCtrlView::OnWebBack)
	ON_COMMAND(ID_WEB_FORWARD, &Cmfctest43htmlCtrlView::OnWebForward)
	ON_COMMAND(ID_WEB_OPEN, &Cmfctest43htmlCtrlView::OnWebOpen)
END_MESSAGE_MAP()

// Cmfctest43htmlCtrlView 생성/소멸

Cmfctest43htmlCtrlView::Cmfctest43htmlCtrlView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest43htmlCtrlView::~Cmfctest43htmlCtrlView()
{
}

BOOL Cmfctest43htmlCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CHtmlView::PreCreateWindow(cs);
}

void Cmfctest43htmlCtrlView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	//Navigate2(_T("http://www.msdn.microsoft.com/korea/visualc/"),nullptr, nullptr);

	Navigate(_T("https://www.naver.com/"));
}


// Cmfctest43htmlCtrlView 인쇄



// Cmfctest43htmlCtrlView 진단

#ifdef _DEBUG
void Cmfctest43htmlCtrlView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void Cmfctest43htmlCtrlView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}

Cmfctest43htmlCtrlDoc* Cmfctest43htmlCtrlView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest43htmlCtrlDoc)));
	return (Cmfctest43htmlCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest43htmlCtrlView 메시지 처리기


void Cmfctest43htmlCtrlView::OnWebBack()
{
	GoBack(); // 히스토리 목록에서 이전 항목으로 이동
}


void Cmfctest43htmlCtrlView::OnWebForward()
{
	GoForward(); // 히스토리 목록에서 다음 항목으로 이동
}


void Cmfctest43htmlCtrlView::OnWebOpen() // 웹 문서 열기
{
	CWeb1 dlg;
	if (dlg.DoModal() == IDOK)
		Navigate(dlg.m_url);
}
