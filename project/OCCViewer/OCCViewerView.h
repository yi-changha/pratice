
// OCCViewerView.h: COCCViewerView 클래스의 인터페이스
//

#pragma once

#include <V3d_View.hxx>

class COCCViewerDoc;

class COCCViewerView : public CView
{
protected: // serialization에서만 만들어집니다.
	COCCViewerView() noexcept;
	DECLARE_DYNCREATE(COCCViewerView)

// 특성입니다.
private:
	Handle(V3d_View) m_view;


public:
	COCCViewerDoc* GetDocument() const;
	Handle(V3d_View) GetView() const { return m_view; }

public:
	void FitAll();

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	virtual void OnInitialUpdate();

	// 구현입니다.
public:
	virtual ~COCCViewerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // OCCViewerView.cpp의 디버그 버전
inline COCCViewerDoc* COCCViewerView::GetDocument() const
{
	return reinterpret_cast<COCCViewerDoc*>(m_pDocument);
}
#endif

