
// mfc_test20_listView.cpp: Cmfctest20listView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "mfc_test20_list.h"
#endif

#include "mfc_test20_listDoc.h"
#include "mfc_test20_listView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfctest20listView

IMPLEMENT_DYNCREATE(Cmfctest20listView, CFormView)

BEGIN_MESSAGE_MAP(Cmfctest20listView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_BN_CLICKED(ID_BUTTON_MEAL, &Cmfctest20listView::OnBnClickedButtonMeal)
	ON_BN_CLICKED(ID_BUTTON_DESSERT, &Cmfctest20listView::OnBnClickedButtonDessert)
	ON_BN_CLICKED(IDC_BUTTON_ETC, &Cmfctest20listView::OnBnClickedButtonEtc)
	ON_BN_CLICKED(ID_BUTTON_ERASE, &Cmfctest20listView::OnBnClickedButtonErase)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &Cmfctest20listView::OnBnClickedButtonDelete)
END_MESSAGE_MAP()

// Cmfctest20listView 생성/소멸

Cmfctest20listView::Cmfctest20listView() noexcept
	: CFormView(IDD_MFC_TEST20_LIST_FORM)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cmfctest20listView::~Cmfctest20listView()
{
}

void Cmfctest20listView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MEAL, m_listMeal);
	DDX_Control(pDX, IDC_LIST_DESSERT, m_listDessert);
	DDX_Control(pDX, IDC_LIST_RESULT, m_listSelect);
	DDX_Text(pDX, IDC_EDIT_ETC, m_strEtc);
}

BOOL Cmfctest20listView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void Cmfctest20listView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_listMeal.AddString(_T("제육덮밥"));
	m_listMeal.AddString(_T("김밥"));
	m_listMeal.AddString(_T("장어덮밥"));
	m_listMeal.AddString(_T("회덮밥"));
	m_listMeal.AddString(_T("떡볶이"));
	m_listMeal.AddString(_T("라면"));
	m_listMeal.AddString(_T("뼈해장국"));
	m_listMeal.AddString(_T("김치찌개"));

	m_listDessert.AddString(_T("아메리카노"));
	m_listDessert.AddString(_T("에스프레소"));
	m_listDessert.AddString(_T("콜드브루"));
	m_listDessert.AddString(_T("카페라떼"));
	m_listDessert.AddString(_T("카라멜 마끼야또"));
	m_listDessert.AddString(_T("카페모카"));
	m_listDessert.AddString(_T("딸기에이드"));
	m_listDessert.AddString(_T("자몽에이드"));
}


// Cmfctest20listView 인쇄

BOOL Cmfctest20listView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cmfctest20listView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cmfctest20listView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void Cmfctest20listView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// Cmfctest20listView 진단

#ifdef _DEBUG
void Cmfctest20listView::AssertValid() const
{
	CFormView::AssertValid();
}

void Cmfctest20listView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Cmfctest20listDoc* Cmfctest20listView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfctest20listDoc)));
	return (Cmfctest20listDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfctest20listView 메시지 처리기


void Cmfctest20listView::OnBnClickedButtonMeal()	// 선택 : single
{
	int Index = m_listMeal.GetCurSel(); // 선택된 리스트의 메뉴를 Index에 대입
	if (Index != LB_ERR)
	{
		CString str;
		m_listMeal.SetCurSel(Index);	// 주어진 항목을 선택 상태로 만듬
		m_listMeal.GetText(Index, str); // 주어진 항목의 문자열 조사
		m_listSelect.AddString(str);	// m_listResult에 선택된 메뉴 문자 추가
	}
}


void Cmfctest20listView::OnBnClickedButtonDessert()	// 선택 : multiple
{
	CString str;
	int cnt = m_listDessert.GetCount();		// 총 항목 갯수 조사

	for(int i = cnt-1; i>=0; i--){ 
		if (m_listDessert.GetSel(i)) {	// 다중 선택 가능
			m_listDessert.GetText(i, str);	// 주어진 항목의 문자열 조사
			m_listSelect.AddString(str);	// 문자열 항목을 추가하여 그 인덱스를 select에 추가
		}
	}
}


void Cmfctest20listView::OnBnClickedButtonEtc()
{
	CString str;
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ETC);
	UpdateData(TRUE);

	if (m_strEtc.IsEmpty())
	{
		MessageBox(_T("기타 메뉴를 입력하세요."), _T("Error"), MB_ICONSTOP | MB_OK);
		pEdit->SetFocus();
		return;
	}

	str = m_strEtc;
	m_listSelect.AddString(str);
	UpdateData(FALSE);
}


void Cmfctest20listView::OnBnClickedButtonErase()
{
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT_ETC);
	UpdateData(TRUE);

	m_strEtc = _T("");
	pEdit->SetFocus();
	UpdateData(FALSE);
}




void Cmfctest20listView::OnBnClickedButtonDelete()
{
	int Index;
	Index = m_listSelect.GetCurSel();
	if (Index != LB_ERR)
		m_listSelect.DeleteString(Index);
	else
		MessageBox(_T("삭제할 메뉴를 선택해주세요."), _T("Error"), MB_ICONSTOP | MB_OK);
}
