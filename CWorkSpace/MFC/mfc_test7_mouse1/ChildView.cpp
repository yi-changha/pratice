
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test7_mouse1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
	m_bDrawMode = FALSE;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
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
	
	// 그리기 메시지에 대해서는 CWnd::OnPaint()를 호출하지 마십시오.
}



void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	SetCapture();  // 마우스 캡쳐 시작

	// 그리기 모드 시작
	m_bDrawMode = TRUE;

	m_x1 = m_x2 = point.x;	// 마우스 포인트의 x의 좌표를 멤버의 x1, x2에 저장
	m_y1 = m_y2 = point.y;	// 마우스 포인트의 y의 좌표를 멤버의 y1, y2에 저장
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// 그리기 모드이면 타원을 지우고 그리기를 반복.
	if (m_bDrawMode) {
		CClientDC dc(this); // dc: device context 그래픽에 필요한 모든옵션을 한곳에 모아둔 구조체
		dc.SelectStockObject(NULL_BRUSH); // SelectStockObject => 내장된 오브젝트, 이전에 그린 타원을 지움.

		dc.SetROP2(R2_NOT);   //SetROP2(R2_NOT)=> wingdi.h 파일에 정의 되어있음, 레스터 오퍼레이션
		// Raster Operation(레스터 오퍼레이션) => 윈도우에 이미 그려진 그림과 새로 그려질 그림을 합성하는 것
		// 
		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		dc.Rectangle(m_x1, m_y1, m_x2, m_y2);

		// 새로운 타원(직사각형)을 그림.
		dc.SetROP2(R2_NOT);
		m_x2 = point.x;	// 마우스 포인터의 x 좌표를 x2에 대입
		m_y2 = point.y;	// 마우스 포인터의 y 좌표를 y2에 대입

		//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
		dc.Rectangle(m_x1, m_y1, m_x2, m_y2);
	}
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	CPen pen(PS_SOLID, 10, RGB(255, 0, 0));  // 빨간색 10픽셀 펜
	dc.SelectObject(&pen);

	dc.SelectStockObject(NULL_BRUSH); // 주석 처리하면 지우개로 활용 가능.
	// 최종적인 도형을 그림
	dc.SetROP2(R2_COPYPEN);  // 새로이 그려지는 그림으로 화면에 덮어그림

	//dc.SetROP2(R2_XORPEN);	
	// 배경을 깨뜨리지 않고, 배경 위에서 움직이는 그림을 그릴 때
    // 똑같은 그림을 두 번 그려주면 원래 있던 바탕색이 복원

	m_x2 = point.x;	// 마우스 포인터의 x 좌표를 x2에 대입
	m_y2 = point.y;	// 마우스 포인터의 y 좌표를 y2에 대입

	//dc.Ellipse(m_x1, m_y1, m_x2, m_y2);
	dc.Rectangle(m_x1, m_y1, m_x2, m_y2);
	// 그리기 모드를 끝낸다.
	m_bDrawMode = FALSE;

	//마우스 캡쳐 해제
	::ReleaseCapture();	// ::(scope) 글로벌 범위
}