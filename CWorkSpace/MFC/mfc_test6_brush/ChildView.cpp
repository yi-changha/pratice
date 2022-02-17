
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test6_brush.h"
#include "ChildView.h"
#include "resource.h" // 리소스 파일 참조해야 bitmap 열 수 있음.

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

	CBitmap bitmap1, bitmap2;
	bitmap1.LoadBitmap(IDB_BITMAP1);
	bitmap2.LoadBitmap(IDB_BITMAP2);
	
	// solid brush(속이 꽉찬 브러시) (1,1)
	CBrush brush1(RGB(0, 0, 255));
	dc.SelectObject(&brush1);
	dc.Rectangle(50, 50, 200, 200);

	// hach brush(교차하는 평행성 브러시) (1,2)
	CBrush brush2(HS_DIAGCROSS, RGB(0, 0, 255));
	dc.SelectObject(&brush2);
	dc.Rectangle(250, 50, 400, 200);

	// pattern brush(비트맵의 반복 무늬 브러시) (1,3)
	CBrush brush3(&bitmap1);
	dc.SelectObject(&brush3);
	dc.Rectangle(450, 50, 600, 200);

	// solid brush(속이 꽉찬 브러시) (2,1)
	CBrush brush4(RGB(255, 0, 0));
	dc.SelectObject(&brush4);
	dc.Rectangle(50, 350, 200, 500);

	// hach brush(교차하는 평행성 브러시) (2,2)
	CBrush brush5(HS_DIAGCROSS, RGB(255, 0, 0));
	dc.SelectObject(&brush5);
	dc.Ellipse(250, 350, 400, 500);

	// pattern brush(비트맵의 반복 무늬 브러시) (2,3)
	CBrush brush6(&bitmap2);
	dc.SelectObject(&brush6);
	dc.RoundRect(450, 350, 600, 500, 50, 50);
				// x1, y1, x2, y2, rounding 50픽셀씩
}

/*  HatchBrush 종류

  HS_BDIAGONAL 좌하향 줄무늬
  HS_CROSS 바둑판 모양
  HS_DIAGCROSS좌 하향 및 우하향 줄무늬
  HS_FDIAGONAL 우하향 줄무늬
  HS_HORIZONTAL 수평선
  HS_VERTICAL 수직선
  */