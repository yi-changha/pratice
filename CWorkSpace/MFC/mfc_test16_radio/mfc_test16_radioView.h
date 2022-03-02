
// mfc_test16_radioView.h: Cmfctest16radioView 클래스의 인터페이스
//

#pragma once


class Cmfctest16radioView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	Cmfctest16radioView() noexcept;
	DECLARE_DYNCREATE(Cmfctest16radioView)

// 특성입니다.
public:
	Cmfctest16radioDoc* GetDocument() const;

	CButton m_pushbutton1; // 1번 문제 정답확인 멤버 변수
	CButton m_pushbutton2; // 2번 문제 정답확인 멤버 변수

	CButton m_sumbutton; // 전체 점수

	CButton m_radio1_1;
	CButton m_radio1_2;
	CButton m_radio1_3;
	CButton m_radio1_4;
	CButton m_radio1_5;
	CButton m_groupbox1;

	CButton m_radio2_1;
	CButton m_radio2_2;
	CButton m_radio2_3;
	CButton m_radio2_4;
	CButton m_radio2_5;
	CButton m_groupbox2;

	CButton m_3state;
	CButton m_radio1;
	CButton m_radio2;
	CButton m_groupbox;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~Cmfctest16radioView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	void OnButtonClicked1();
	void OnButtonClicked2();
	void sum1();
};

#ifndef _DEBUG  // mfc_test16_radioView.cpp의 디버그 버전
inline Cmfctest16radioDoc* Cmfctest16radioView::GetDocument() const
   { return reinterpret_cast<Cmfctest16radioDoc*>(m_pDocument); }
#endif

