
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test5_pen.h"
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
	
	int nPenStyle[] = { PS_SOLID, PS_DASH, PS_DOT, PS_DASHDOT, PS_DASHDOTDOT, PS_NULL, PS_INSIDEFRAME };

	// char : 1바이트 문자
	// WCHAR : 멀티바이트 캐릭터셋, 2바이트 unsigned short
	// TCHAR : 프로젝트의 디버깅 설정에서 정한 캐릭터 셋에 따라 멀티바이트가 되기도 하고,
	// 유니코드가 되기도 하는 자료형. 컴파일 단계에서 결정됨. 문자열 깨짐을 방지하기 위해 사용.

	TCHAR* PenStyle[] = { _T("1. PS_SOLID(실선)"), _T("2. PS_DASH(파선)"), _T("3. PS_DOT(가는점선)"),
	  _T("4. PS_DASHDOT(1점쇄선)"), _T("5. PS_DASHDOTDOT(2점쇄선)"), _T("6. PS_NULL(투명선)"),
	  _T("7. PS_INSIDEFRAME(안쪽프레임선)") };

	dc.SetTextAlign(TA_BASELINE); // 텍스트 기본 정렬 방식

	for (int i = 0; i < sizeof(nPenStyle) / sizeof(nPenStyle[0]); i++) {
		// sizeof(nPenStlye) / sizeof(nPenStyle[0]) => 결과값 == 7, 배열 개수 == 7

		CPen pen(nPenStyle[i], 1, RGB(255, 0, 0));  // 폭(선 굵기): 1픽셀
		dc.SelectObject(&pen); // 주소값에 있는 pen 선택
		dc.TextOut(50, 25 + i * 25, PenStyle[i], lstrlen(PenStyle[i]));
		// x좌표 : 50픽셀, y좌표 : 25, 50, 75, 100, 125...
		// lstrlen: TextOut 함수는 마지막에 문자열 길이를 요구함.
		// 길이를 알려줘서 유니코드 변환 시 글자 깨짐 방지

		dc.MoveTo(300, 25 + i * 25);  // 첫 좌표 설정. x좌표 300 픽셀로 이동. 좌표 25, 50, 70, 100, 125....
		dc.LineTo(800, 25 + i * 25);  // x좌표(수평선) 300픽셀 위치부터 800픽셀로 선그리기
	}

	CPen blackpen1(PS_SOLID, 3, RGB(0, 0, 0)); // 폭3, 검정색 실선
	CPen blackpen2(PS_SOLID, 3, RGB(0, 255, 0)); // 폭3, 녹색 실선
	CPen pen1(PS_SOLID, 20, RGB(255, 0, 0)); // 폭 20, 빨간색 실선
	CPen pen2(PS_INSIDEFRAME, 20, RGB(0, 0, 255)); // 폭 20, 파란색 PS_INSIDEFRAME(안쪽으로만 선이 확장됨)펜

	// 직사각형(왼쪽)
	dc.SelectObject(&blackpen1); // 폭3, 검정 실선
	dc.Rectangle(50, 200, 150, 300); // 폭과 높이가 100인 직사각형
				//x1, y1, x2, y2.  1: 좌상단 2: 우하단

	// 원(왼쪽)
	dc.SelectObject(&pen1); // 폭20, 빨간색 실선
	dc.Ellipse(50, 200, 150, 300); // 지름이 100인 원
			// (x1, y1, x2, y2. 1: 좌상단 2: 우하단) 과 내접하는 원

	// 직사각형(오른쪽)
	dc.SelectObject(&blackpen2); // 폭 3, 녹색 실선
	dc.Rectangle(250, 200, 350, 300); // 폭과 높이가 100인 직사각형

	// 원(오른쪽)
	dc.SelectObject(&pen2); // 폭 20, 파란색 안쪽으로 확장된 선
	dc.Ellipse(250, 200, 350, 300); // 지름이 100인 원(직사각형 좌상단, 우하단에 내접하는 원)
}

