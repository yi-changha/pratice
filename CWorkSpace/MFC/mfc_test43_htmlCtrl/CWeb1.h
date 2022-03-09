#pragma once


// CWeb1 대화 상자

class CWeb1 : public CDialogEx
{
	DECLARE_DYNAMIC(CWeb1)

public:
	CWeb1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CWeb1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_url;
};
