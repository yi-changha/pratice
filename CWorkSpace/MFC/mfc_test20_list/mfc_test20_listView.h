
// mfc_test20_listView.h: Cmfctest20listView 클래스의 인터페이스
//

#pragma once


class Cmfctest20listView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cmfctest20listView() noexcept;
	DECLARE_DYNCREATE(Cmfctest20listView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_TEST20_LIST_FORM };
#endif

// 특성입니다.
public:
	Cmfctest20listDoc* GetDocument() const;

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
	virtual ~Cmfctest20listView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_listMeal;
	CListBox m_listDessert;
	CListBox m_listSelect;
	CString m_strEtc;

	afx_msg void OnBnClickedButtonMeal();
	afx_msg void OnBnClickedButtonDessert();
	afx_msg void OnBnClickedButtonEtc();
	afx_msg void OnBnClickedButtonErase();
	afx_msg void OnBnClickedButtonDelete();
};

#ifndef _DEBUG  // mfc_test20_listView.cpp의 디버그 버전
inline Cmfctest20listDoc* Cmfctest20listView::GetDocument() const
   { return reinterpret_cast<Cmfctest20listDoc*>(m_pDocument); }
#endif

