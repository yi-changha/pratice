
// mfc_test43_htmlCtrlView.h: Cmfctest43htmlCtrlView 클래스의 인터페이스
//

#pragma once


class Cmfctest43htmlCtrlView : public CHtmlView
{
protected: // serialization에서만 만들어집니다.
	Cmfctest43htmlCtrlView() noexcept;
	DECLARE_DYNCREATE(Cmfctest43htmlCtrlView)

// 특성입니다.
public:
	Cmfctest43htmlCtrlDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.

// 구현입니다.
public:
	virtual ~Cmfctest43htmlCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnWebBack();
	afx_msg void OnWebForward();
	afx_msg void OnWebOpen();
};

#ifndef _DEBUG  // mfc_test43_htmlCtrlView.cpp의 디버그 버전
inline Cmfctest43htmlCtrlDoc* Cmfctest43htmlCtrlView::GetDocument() const
   { return reinterpret_cast<Cmfctest43htmlCtrlDoc*>(m_pDocument); }
#endif

