
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test9_track.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	MouseIn = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
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
	
	dc.SetTextColor(RGB(0, 0, 255));  //글자색, 청색

	CFont font, * newFont1;

	//font.CreatePointFont(250, _T("Tahoma"));
	//font.CreatePointFont(250, _T("Lemon"));
	//font.CreatePointFont(250, _T("Impact"));

	font.CreatePointFont(250, _T("궁서체"));
	newFont1 = (CFont*)dc.SelectObject(&font);
	dc.TextOut(10, 50, CString(_T("Visual C++ MFC 한글")));

	dc.SetTextColor(RGB(255, 0, 0));  //글자색, 빨강
	CFont font2, * newFont2;
	font2.CreatePointFont(250, _T("Impact"));
	newFont2 = (CFont*)dc.SelectObject(&font2);
	dc.TextOut(10, 100, CString(_T("마우스 커서 위치 추척하기")));
}



void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	if (MouseIn == FALSE) {  //마우스가 윈도우 클라이언트 영역 벗어날때 추적을 요청
 
		// 마우스 커서 추적을 요청
		TRACKMOUSEEVENT time;
		time.cbSize = sizeof(time); // cbSize에 구조체의 메모리 sizeof를 저장 
		time.dwFlags = TME_LEAVE;  // 마우스가 해당윈도우 영역을 벗어났다는 메시지를 받고싶다
		time.hwndTrack = this->m_hWnd;  // 마우스 커서 추적(트랙(추적)할 윈도우 핸들)
		
		//time.dwHoverTime = HOVER_DEFAULT;  //이벤트가 발생할 기본값, HOVER=> '맴돌다'라는 뜻
		time.dwHoverTime = 0;  //이벤트가 발생할 기본값, 0초동안에도 이벤트 발생
		::TrackMouseEvent(&time);  //TRUE 이면 이벤트 발생

		// 메인 윈도우 크기를 800*350으로 변경한다
		CWnd* pMainWnd = AfxGetMainWnd();  // 메인 윈도우의 객체주소값을 가져옴
		CRect rect;
		pMainWnd->GetWindowRect(&rect);  //사각형 윈도우 주서값을 메인윈도우에 대입
		rect.right = rect.left + 800;  // 윈도우 화면 윈쪽에서 800 픽셀 오른쪽으로 크게
		rect.bottom = rect.top + 300; // 윈도우 화면 위에서 300 픽셀 아래로 크게
		pMainWnd->MoveWindow(&rect);

		// 마우스 커서가 클라이언트 영역에 있음을 기억
		MouseIn = TRUE;
	}
	//CWnd::OnMouseMove(nFlags, point);
}


void CChildView::OnMouseLeave()
{
	MouseIn = FALSE;

	//메인 윈도우 크기를 300*250으로 변경한다.
	CWnd* pMainWnd = AfxGetMainWnd(); // 메인 윈도우의 객체주소값을 가져옴
	CRect rect;
	pMainWnd->GetWindowRect(&rect);
	rect.right = rect.left + 300;
	rect.bottom = rect.top + 250;
	pMainWnd->MoveWindow(&rect);

	CWnd::OnMouseLeave();
}