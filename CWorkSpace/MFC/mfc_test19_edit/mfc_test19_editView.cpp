
// mfc_test19_editView.cpp: Cmfctest19editView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test19_edit.h"
#endif

#include "mfc_test19_editDoc.h"
#include "mfc_test19_editView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest19editView

IMPLEMENT_DYNCREATE(Cmfctest19editView, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest19editView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_EN_CHANGE(IDC_EDIT1, &Cmfctest19editView::OnEnChangeEdit1)
	ON_EN_MAXTEXT(IDC_EDIT1, &Cmfctest19editView::OnEnMaxtextEdit1)
END_MESSAGE_MAP()

// Cmfctest19editView 생성/소멸

Cmfctest19editView::Cmfctest19editView() noexcept
	: CFormView(IDD_MFC_TEST19_EDIT_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest19editView::~Cmfctest19editView()
{
}

void Cmfctest19editView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, m_static1);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
}

BOOL Cmfctest19editView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest19editView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_edit1.SetLimitText(30); // 초기화 코드 추가, 최대 한글, 영문, 숫자 30자까지 입력
}


// Cmfctest19editView 인쇄

BOOL Cmfctest19editView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest19editView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest19editView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cmfctest19editView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// Cmfctest19editView 진단

#ifdef _DEBUG
void Cmfctest19editView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest19editView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest19editDoc* Cmfctest19editView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest19editDoc)));
	return (Cmfctest19editDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest19editView 메시지 처리기


void Cmfctest19editView::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CFormView::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CString str; // CString 구조체 변수명 str 선언
	m_edit1.GetWindowText(str); // 에디트 컨트롤에 입력된 텍스트를 얻는다.
	m_static1.SetWindowText(str); // 스태틱 컨크롤에 에디트 컨트롤에서 입력한 문자를 출력한다.
}


void Cmfctest19editView::OnEnMaxtextEdit1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	MessageBox(_T("30자까지만 입력 가능 합니다."), _T("ERROR : 최대 길이 도달"), MB_ICONERROR);
}
