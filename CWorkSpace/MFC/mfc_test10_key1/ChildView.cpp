
// ChildView.cpp: CChildView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "mfc_test10_key1.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView() // 생성자 메모리 할당.
{
	m_xPos = m_yPos = 100; // 임의의 값으로 초기화
	m_bFill = FALSE;  //도형 내부를 채우지 않음
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_KEYDOWN()
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
	if (m_bFill == TRUE) dc.SelectStockObject(BLACK_BRUSH);  // m_bFill 이 TRUE 이면 내부를 검은색으로 채운다.
	/*
	CBrush brush1(RGB(255, 0, 0));
	dc.SelectObject(&brush1);
	*/
	dc.Ellipse(m_xPos - 20, m_yPos - 20, m_xPos + 20, m_yPos + 20);  // 타원 x1, y1, x2, y2
}



void CChildView::OnSize(UINT nType, int cx, int cy)
{
	CWnd::OnSize(nType, cx, cy);
	m_xClient = cx; // 클라이언트 영역 x좌표 픽셀값
	m_yClient = cy; // 클라이언트 영역 y좌표 픽셀값
}


void CChildView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
// 키보드 메시지 핸들러
// UINT nChar => 키에 할당된 가상 키 코드값을 가진다.(운영체제가 각각 키에 할당한 고유값)
// UINT nRepCnt => 키를 게속 누르고 있으면 1보다 큰 값을 가질 수 있다.
// UINT nFlags => 키와 관련된 부가적 정보(스캔 코드, 확장 키 여부...)

{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
	case VK_LEFT:  // 왼쪽 이동 가상 키코드 
		m_xPos -= 20;  // 20픽셀 이동
		break;
	case VK_RIGHT:  // 오른쪽 이동 가상 키코드
		m_xPos += 20;
		break;
	case VK_UP:  // 위로 이동 가상 키코드
		m_yPos -= 20;
		break;
	case VK_DOWN:  // 아래로 이동 가상 키코드
		m_yPos += 20;
		break;
	case VK_HOME:  // HOME 이동 가상 키코드
		m_xPos += -10000;  // 가장 작은값으로 설정하여 좌상단으로 이동
		m_yPos += -10000;
		break;
	case VK_SPACE:  // 스페이스바를 눌렀을때 가상 키코드
		m_bFill = !m_bFill;  // 도형이 반전(검정색)
	}

	//20 <= m_xPos <= m_xClient - 20;
	m_xPos = min(max(20, m_xPos), m_xClient - 20);  // 도형의 위치가 클라이언트 영역을 벋어나지 않게 하는 min(), max() 매크로함수
	// m_xPos = max(20, m_xPos), m_xClient - 20;  // 도형의 위치가 클라이언트 영역을 벋어남
	//20 <= m_yPos <= m_yClient - 20;
	m_yPos = min(max(20, m_yPos), m_yClient - 20);

	Invalidate();  // 클라이언트 영역 전체를 무효화 함으로써 WM_PAINT 메시지를 강제로 발생시킨다. 즉 화면을 갱신한다
}