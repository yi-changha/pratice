
// mfc_test22_comboBoxView.h: Cmfctest22comboBoxView 클래스의 인터페이스
//

#pragma once


class Cmfctest22comboBoxView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	Cmfctest22comboBoxView() noexcept;
	DECLARE_DYNCREATE(Cmfctest22comboBoxView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_MFC_TEST22_COMBOBOX_FORM };
#endif

// 특성입니다.
public:
	Cmfctest22comboBoxDoc* GetDocument() const;

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
	virtual ~Cmfctest22comboBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo1;
	CComboBox m_combo2;
	CComboBox m_combo3;
	CListBox m_list1;
	CStatic m_picture;
	CImage m_img;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};

#ifndef _DEBUG  // mfc_test22_comboBoxView.cpp의 디버그 버전
inline Cmfctest22comboBoxDoc* Cmfctest22comboBoxView::GetDocument() const
   { return reinterpret_cast<Cmfctest22comboBoxDoc*>(m_pDocument); }
#endif

