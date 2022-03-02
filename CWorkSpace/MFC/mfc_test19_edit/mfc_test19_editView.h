
// mfc_test19_editView.h: Cmfctest19editView 클래스의 인터페이스
//

#pragma once


class Cmfctest19editView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cmfctest19editView() noexcept;
	DECLARE_DYNCREATE(Cmfctest19editView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_TEST19_EDIT_FORM };
#endif

// 특성입니다.
public:
	Cmfctest19editDoc* GetDocument() const;

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
	virtual ~Cmfctest19editView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_static1;
	CEdit m_edit1;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnMaxtextEdit1();
};

#ifndef _DEBUG  // mfc_test19_editView.cpp의 디버그 버전
inline Cmfctest19editDoc* Cmfctest19editView::GetDocument() const
   { return reinterpret_cast<Cmfctest19editDoc*>(m_pDocument); }
#endif

