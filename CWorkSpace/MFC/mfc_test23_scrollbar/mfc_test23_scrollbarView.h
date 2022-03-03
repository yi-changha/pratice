
// mfc_test23_scrollbarView.h: Cmfctest23scrollbarView 클래스의 인터페이스
//

#pragma once


class Cmfctest23scrollbarView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cmfctest23scrollbarView() noexcept;
	DECLARE_DYNCREATE(Cmfctest23scrollbarView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_TEST23_SCROLLBAR_FORM };
#endif

// 특성입니다.
public:
	Cmfctest23scrollbarDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~Cmfctest23scrollbarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static;
	CScrollBar m_scrollh;
	CScrollBar m_scrollv;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual void OnDraw(CDC* /*pDC*/);
};

#ifndef _DEBUG  // mfc_test23_scrollbarView.cpp의 디버그 버전
inline Cmfctest23scrollbarDoc* Cmfctest23scrollbarView::GetDocument() const
   { return reinterpret_cast<Cmfctest23scrollbarDoc*>(m_pDocument); }
#endif

