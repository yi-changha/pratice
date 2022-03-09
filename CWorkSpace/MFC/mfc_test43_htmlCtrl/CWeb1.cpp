// CWeb1.cpp: 구현 파일
//

#include "pch.h"
#include "mfc_test43_htmlCtrl.h"
#include "CWeb1.h"
#include "afxdialogex.h"


// CWeb1 대화 상자

IMPLEMENT_DYNAMIC(CWeb1, CDialogEx)

CWeb1::CWeb1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_url(_T(""))
{

}

CWeb1::~CWeb1()
{
}

void CWeb1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_url);
}


BEGIN_MESSAGE_MAP(CWeb1, CDialogEx)
END_MESSAGE_MAP()


// CWeb1 메시지 처리기
