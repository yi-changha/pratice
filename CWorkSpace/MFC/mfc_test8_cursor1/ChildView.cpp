
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test8_cursor1.h"
#include "ChildView.h"
#include "Resource.h"

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
	ON_WM_SETCURSOR()
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
	
	dc.SelectStockObject(LTGRAY_BRUSH);  // 밝은 회색 (내장되어있는 객체 기본 색깔)
	dc.Ellipse(10, 10, 400, 200);

	// 비트맵 리소스 로드 후 크기 정보 획득.
	CBitmap bitmap;
	bitmap.LoadBitmap(IDB_BITMAP1);
	BITMAP bmpinfo;
	bitmap.GetBitmap(&bmpinfo);

	//메모리 DC를 만든 후 비트맵을 선택해 넣는다.
	CDC dcmem;
	dcmem.CreateCompatibleDC(&dc);
	dcmem.SelectObject(&bitmap);

	//비트맵을 화면에 출력한다. BitBlt=> 비트맵 그림 원본 복사함수(화면에 가져와서 복사하는 명령어)
	dc.BitBlt(500, 10, bmpinfo.bmWidth, bmpinfo.bmHeight, &dcmem, 0, 0, SRCCOPY);
			// x,  y,   폭 정보,           폭 높이,  메모리의 주소값, 가져곳의 위치 x, y, 복사 명령어)
	//=======================================================
	dc.SetTextColor(RGB(0, 0, 255));  //글자색

	CFont font, * newFont1;
	//font.CreatePointFont(250, _T("Tahoma"));
	//font.CreatePointFont(250, _T("Lemon"));
	//font.CreatePointFont(250, _T("Impact"));
	font.CreatePointFont(250, _T("궁서체"));

	newFont1 = (CFont*)dc.SelectObject(&font);

	dc.TextOut(100, 360, CString(_T("그림 4 * 4 확대")));
	dc.StretchBlt(10, 400, bmpinfo.bmWidth * 4, bmpinfo.bmHeight * 4, &dcmem, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
}



BOOL CChildView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if (nHitTest == HTCLIENT) { // 커서가 어떤 영역 안에 들어갔을 때.
		CPoint point;
		::GetCursorPos(&point); // 스크린 좌표(마우스 포인터의 좌표) 얻기.
		ScreenToClient(&point); // 스크린 좌표를 클라이언트 좌표로 변환.

		CRgn rgn;  // Region(구역, 영역) : 다양한 형태의 면 선택에 사용.
		rgn.CreateEllipticRgn(10, 10, 400, 200); //타원형 region(영역)을 생성.

		if (rgn.PtInRegion(point)) // 커서가 region 안쪽에 있는지 확인
			::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));	// 사용자가 만든 커서로 변경

		else
			::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));	// 표준 커서 중 하나로 변경
		return TRUE;
	}
	// 클라이언트 영역 아니면 운영체제가 자동으로 처리 
	return CWnd::OnSetCursor(pWnd, nHitTest, message);
}
