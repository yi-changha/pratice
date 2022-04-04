
// OCCViewer.h: OCCViewer 응용 프로그램의 기본 헤더 파일
//
#pragma once

#ifndef __AFXWIN_H__
#error "PCH에 대해 이 파일을 포함하기 전에 'stdafx.h'를 포함합니다."
#endif

#include "resource.h"       // 주 기호입니다.
#include <Graphic3d_GraphicDriver.hxx>

// COCCViewerApp:
// 이 클래스의 구현에 대해서는 OCCViewer.cpp을(를) 참조하세요.
//

class COCCViewerApp : public CWinAppEx
{
public:
	COCCViewerApp() noexcept;

private:
	Handle(Graphic3d_GraphicDriver) m_graphicDriver;

public:
	Handle(Graphic3d_GraphicDriver) GetGraphicDriver() const { return m_graphicDriver; }

private:
	// OCCT 초기화 함수
	bool InitOCCT();

	// 재정의입니다.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	// 구현입니다.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern COCCViewerApp theApp;
