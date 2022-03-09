
// mfc_test42_prgressCtrlView.h: Cmfctest42prgressCtrlView 클래스의 인터페이스
//

#pragma once


class Cmfctest42prgressCtrlView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cmfctest42prgressCtrlView() noexcept;
	DECLARE_DYNCREATE(Cmfctest42prgressCtrlView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_TEST42_PRGRESSCTRL_FORM };
#endif

// 특성입니다.
public:
	Cmfctest42prgressCtrlDoc* GetDocument() const;

	// 프로그래스 동작여부를 나타내는 멤버 변수 선언
	BOOL start1;
	BOOL start2;

	int cnt = 0;

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
	virtual ~Cmfctest42prgressCtrlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	// 프로그래스 객체 멤버 변수
	CProgressCtrl m_progress;
	CProgressCtrl m_progress2;

	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonPause();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // mfc_test42_prgressCtrlView.cpp의 디버그 버전
inline Cmfctest42prgressCtrlDoc* Cmfctest42prgressCtrlView::GetDocument() const
   { return reinterpret_cast<Cmfctest42prgressCtrlDoc*>(m_pDocument); }
#endif

