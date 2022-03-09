
// mfc_test41_TabCtrlView.cpp: Cmfctest41TabCtrlView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test41_TabCtrl.h"
#endif

#include "mfc_test41_TabCtrlDoc.h"
#include "mfc_test41_TabCtrlView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest41TabCtrlView

IMPLEMENT_DYNCREATE(Cmfctest41TabCtrlView, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest41TabCtrlView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &Cmfctest41TabCtrlView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &Cmfctest41TabCtrlView::OnTcnSelchangeTab1)
END_MESSAGE_MAP()

// Cmfctest41TabCtrlView 생성/소멸

Cmfctest41TabCtrlView::Cmfctest41TabCtrlView() noexcept
	: CFormView(IDD_MFC_TEST41_TABCTRL_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest41TabCtrlView::~Cmfctest41TabCtrlView()
{
}

void Cmfctest41TabCtrlView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BOOL Cmfctest41TabCtrlView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest41TabCtrlView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	// 탭 컨트롤에 사용할 이미지 리스트를 설정한다.
	CImageList m_iList;
	m_iList.Create(IDB_BITMAP3, 16, 10, RGB(255, 255, 255));
	// 16 : 이미지 픽셀 사이즈

	m_tab.SetImageList(&m_iList);
	m_iList.Detach(); // 리소스에 등록된 이미지를 분리하여 나타냄

	// 탭 3개 추가
	// InsertItem : nItem, 글씨, 이미지
	m_tab.InsertItem(0, _T("호수"), 0);
	m_tab.InsertItem(1, _T("나무"), 0);
	m_tab.InsertItem(2, _T("테스트 메세지"), 0);

	// n 번째 탭이 선택된 상태로 시작한다.
	m_tab.SetCurSel(0);
	m_edit.SetWindowText(_T("Tab #0 선택됨"));

}


// Cmfctest41TabCtrlView 인쇄


void Cmfctest41TabCtrlView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL Cmfctest41TabCtrlView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest41TabCtrlView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest41TabCtrlView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cmfctest41TabCtrlView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}

void Cmfctest41TabCtrlView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void Cmfctest41TabCtrlView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// Cmfctest41TabCtrlView 진단

#ifdef _DEBUG
void Cmfctest41TabCtrlView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest41TabCtrlView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest41TabCtrlDoc* Cmfctest41TabCtrlView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest41TabCtrlDoc)));
	return (Cmfctest41TabCtrlDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest41TabCtrlView 메시지 처리기

void Cmfctest41TabCtrlView::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	int nIndex = m_tab.GetCurSel();
	CString str;

	switch (nIndex) {
	case 0:
		str.Format(_T("호수호수호수"));
		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(FALSE);
		break;
	case 1:
		str.Format(_T("나무나무나무"));
		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(FALSE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
		break;
	case 2:
		str.Format(_T("텝 메뉴를 테스트 하고 있습니다."));
		GetDlgItem(IDC_EDIT1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC1)->ShowWindow(TRUE);
		GetDlgItem(IDC_STATIC2)->ShowWindow(TRUE);
		break;
	}
	m_edit.SetWindowText(str); // m_edit 멤버변수 에디트 컨트롤에 출력;

	*pResult = 0;
}
