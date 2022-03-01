
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test11_menu1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_color = RGB(0, 0, 0);
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_COLOR_RED, &CChildView::OnColorRed)
	ON_COMMAND(ID_COLOR_GREEN, &CChildView::OnColorGreen)
	ON_COMMAND(ID_COLOR_BLUE, &CChildView::OnColorBlue)
	ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CChildView::OnUpdateColorRed)
	ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CChildView::OnUpdateColorGreen)
	ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CChildView::OnUpdateColorBlue)
	ON_WM_CONTEXTMENU()
END_MESSAGE_MAP()



// CChildView 메시지 처리기

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.
	
	CFont font; // 폰트 클래스 변수명 font 선언
	font.CreatePointFont(300, _T("궁서")); // 윈도우 시스템 궁서체, 300 픽셀
	dc.SelectObject(&font); // 폰트 선택
	dc.SetTextColor(m_color); // Color refreshaer(생각나게 하는 것), COLORREF : 색깔 선택 예약어

	CRect rect;
	GetClientRect(&rect);
	CString str = _T("메뉴 선택 예제 - Color Select");
	dc.DrawText(str, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE); // DT : DrawText, 윈도우화면 가운데 글자 출력

	dc.TextOut(400, 200, CString(_T("MFC 연습")));
}



void CChildView::OnColorRed()
{
	m_color = RGB(255, 0, 0);
	Invalidate();	// 클라이언트 영역 전체를 무효화 함으로써 WM_PAINT 메세지를 강제로 발생시킴.
					// 즉, 화면을 갱신함.
}


void CChildView::OnColorGreen()
{
	m_color = RGB(0, 255, 0);
	Invalidate();
}


void CChildView::OnColorBlue()
{
	m_color = RGB(0, 0, 255);
	Invalidate();
}


// 메뉴 항목 갱신 핸들러
void CChildView::OnUpdateColorRed(CCmdUI* pCmdUI) // 빨강 메뉴 항목 갱신 핸들러, UI : 사용자 인터페이스
{
	pCmdUI->SetCheck(m_color == RGB(255, 0, 0)); // pCmdUI : 커멘드 유저 인터페이스 포인터(주소값)
}


void CChildView::OnUpdateColorGreen(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(0, 255, 0));
}


void CChildView::OnUpdateColorBlue(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_color == RGB(0, 0, 255));
}


// 컨텍스트 메뉴(단축메뉴) 함수 생성, 마우스 오른쪽 버튼 클릭 시 열리는 메뉴들
void CChildView::OnContextMenu(CWnd* /*pWnd*/, CPoint point)
{
	CMenu menu1; //메뉴 클래스명 menu1 선언
	menu1.LoadMenu(IDR_MAINFRAME); // IDR_MAINFRAME 메뉴 리소스 로드
	CMenu* pMenu = menu1.GetSubMenu(4); // 메뉴 5번째 위치 [색상] 가져와서 pMenu 포인터 대입.


// 코드로 메뉴 추가하는 방법
	pMenu->AppendMenu(MF_SEPARATOR); // 분리자(Separator) 항목을 추가

	//ID가 20인 메뉴항목을 추가
	pMenu->AppendMenu(MF_STRING, 20, _T("원하는 색 선택!"));
//-----------------------------------------------------------------------

	pMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
	// 팝업메뉴(컨텍스트)로 표시, 마우스 오른쪽 버튼 눌렀을 때 메뉴 나타남.

	//AfxGetMainWnd()->PostMessage(WM_CLOSE); // 프로그램 종료1
	//PostQuitMessage(0); //프로그램 종료2
}
