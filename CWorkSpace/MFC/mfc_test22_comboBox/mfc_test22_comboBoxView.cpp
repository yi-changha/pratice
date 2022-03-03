
// mfc_test22_comboBoxView.cpp: Cmfctest22comboBoxView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test22_comboBox.h"
#endif

#include "mfc_test22_comboBoxDoc.h"
#include "mfc_test22_comboBoxView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest22comboBoxView

IMPLEMENT_DYNCREATE(Cmfctest22comboBoxView, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest22comboBoxView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(IDC_BUTTON1, &Cmfctest22comboBoxView::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &Cmfctest22comboBoxView::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Cmfctest22comboBoxView::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &Cmfctest22comboBoxView::OnBnClickedButton4)
END_MESSAGE_MAP()

// Cmfctest22comboBoxView 생성/소멸

Cmfctest22comboBoxView::Cmfctest22comboBoxView() noexcept
	: CFormView(IDD_MFC_TEST22_COMBOBOX_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest22comboBoxView::~Cmfctest22comboBoxView()
{
}

void Cmfctest22comboBoxView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_COMBO2, m_combo2);
	DDX_Control(pDX, IDC_COMBO3, m_combo3);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_PICTURE, m_picture);
}

BOOL Cmfctest22comboBoxView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest22comboBoxView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	//---------콤보상자(단순)------------
	CString combo1;
	for (int i = 1; i <= 6; i++) {
		combo1.Format(_T("%d 학년"), i);
		m_combo1.AddString(combo1); // m_combo1 객체 변수명
	}
	m_combo1.SetCurSel(0); // 0번째 기본 설정


	//---------콤보상자(드롭다운)------------
	m_combo2.AddString(_T("사과"));
	m_combo2.AddString(_T("배"));
	m_combo2.AddString(_T("감"));
	m_combo2.AddString(_T("귤"));
	m_combo2.AddString(_T("수박"));
	m_combo2.AddString(_T("바나나"));
	m_combo2.SetCurSel(0);	// 0번째 기본 설정


	//---------콤보상자(드롭다운)------------
	m_combo3.AddString(_T("국어"));
	m_combo3.AddString(_T("영어"));
	m_combo3.AddString(_T("수학"));
	m_combo3.AddString(_T("사회"));
	m_combo3.AddString(_T("과학"));
	m_combo3.AddString(_T("국사"));
	m_combo3.SetCurSel(0);	// 0번째 기본 설정
}


// Cmfctest22comboBoxView 인쇄

BOOL Cmfctest22comboBoxView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest22comboBoxView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest22comboBoxView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cmfctest22comboBoxView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// Cmfctest22comboBoxView 진단

#ifdef _DEBUG
void Cmfctest22comboBoxView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest22comboBoxView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest22comboBoxDoc* Cmfctest22comboBoxView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest22comboBoxDoc)));
	return (Cmfctest22comboBoxDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest22comboBoxView 메시지 처리기


void Cmfctest22comboBoxView::OnBnClickedButton1()
{
	int Index = m_combo1.GetCurSel();	// 선택된 콤보 메뉴를 Index에 대입
	if (Index != CB_ERR) {
		CString str1;
		m_combo1.GetLBText(Index, str1);	// 주어진 항목의 문자열 조사
		m_combo1.SetCurSel(Index);	// 주어진 항목을 선택 상태로 만듦
		m_list1.AddString(str1);	// m_combo1에서 선택된 메뉴 출력
	}
}


void Cmfctest22comboBoxView::OnBnClickedButton2()
{
	int Index = m_combo2.GetCurSel();	// 선택된 콤보 메뉴를 Index에 대입
	if (Index != CB_ERR) {
		CString str2;
		m_combo2.GetLBText(Index, str2);	// 주어진 항목의 문자열 조사
		m_combo2.SetCurSel(Index);	// 주어진 항목을 선택 상태로 만듦
		m_list1.AddString(str2);	// m_combo2에서 선택된 메뉴 출력
	}
}


void Cmfctest22comboBoxView::OnBnClickedButton3()
{
	int Index = m_combo3.GetCurSel();	// 선택된 콤보 메뉴를 Index에 대입
	if (Index != CB_ERR) {
		CString str3;
		m_combo3.GetLBText(Index, str3);	// 주어진 항목의 문자열 조사
		m_combo3.SetCurSel(Index);	// 주어진 항목을 선택 상태로 만듦
		m_list1.AddString(str3);	// m_combo3에서 선택된 메뉴 출력
	}
}


void Cmfctest22comboBoxView::OnBnClickedButton4()
{
	m_img.Load(_T("test1.bmp"));
	CClientDC dc(this);
	m_img.Draw(dc, 600, 100);
}
