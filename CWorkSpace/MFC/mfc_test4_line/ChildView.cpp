
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test4_line.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
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
	
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	// 클라이언트 영역 좌표 획득.
	CRect rect;
	GetClientRect(&rect);

	// 화면 1/2 수평선 그리기
	//MoveTo() 현재 위치를 (X,Y) 위치로 옮김
	//LineTo() 현재 위치에서 (X,Y) 위치까지 선을 그리고 현재 위치를 (X,Y)로 변경
	dc.MoveTo(0, rect.bottom / 2);
	dc.LineTo(rect.right, rect.bottom / 2);

	// 화면 1/2 수직선 그리기
	dc.MoveTo(rect.right / 2, 0);
	dc.LineTo(rect.right / 2, rect.bottom);

	// 화면 1/4 수직선 그리기
	dc.MoveTo(rect.right / 4, 0);
	dc.LineTo(rect.right / 4, rect.bottom);

	// 화면 1/10 수평선 그리기
	dc.MoveTo(0, rect.bottom / 10);
	dc.LineTo(rect.right, rect.bottom / 10);

	// 마름모꼴 그리기
	POINT points[] = { {rect.right / 2, 0}, {rect.right, rect.bottom / 2},
		{ rect.right/2, rect.bottom},{0, rect.bottom/2},{rect.right/2, 0} };
	dc.Polyline(points, 5); // POINT 구조체 배열로 전달된 점들을 차례로 이어서 선을 그림.

	//별 모양
#define PI 3.141592 
	int    x = rect.CenterPoint().x;
	int    y = rect.CenterPoint().y;
	int    size = min(rect.Width() / 12, rect.Height() / 12);
	int    ang;

	CPoint ptPos[10] = { 0 };
	CBrush brBG, * old_Brush = NULL;

	for (int i = 0, ang = 90; i < 6; i++, ang += 36 * 4) {
		ptPos[i].x = x + (int)(size * cos(PI * ang / 180.0));
		ptPos[i].y = y - (int)(size * sin(PI * ang / 180.0));
	}
	dc.Polygon(ptPos, 6);
}