
// t38AnimationTimerDlg.h: 헤더 파일
//

#pragma once


// Ct38AnimationTimerDlg 대화 상자
class Ct38AnimationTimerDlg : public CDialogEx
{
// 생성입니다.
public:
	Ct38AnimationTimerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_T38ANIMATIONTIMER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();

	int width1, height1;
	int idx;
	CPoint image1, image2, image3; // 이미지 시간단위로 나타내기 멤버 변수
	CImage m_png1, m_jpg1, m_bmp1, m_gif1; // png, jpg, bmp 이미지 처리(컴퓨터 폴더에 있는 것)
	// MFC Dialog에서 gif image 동작을 기본적으로 지원하지 않음.

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
