
// OCCViewerDoc.cpp: COCCViewerDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "OCCViewer.h"
#endif

#include <sstream>

#include <AIS_InteractiveContext.hxx>
#include <AIS_InteractiveObject.hxx>
#include <AIS_Shape.hxx>

#include <BOPAlgo_Builder.hxx>

#include "StepReader.h"
#include "IgesReader.h"
#include "MainFrm.h"
#include "OCCViewerDoc.h"

#include <propkey.h>

// OCCT에서 사용하기 위해서는 아래 부분을 주석처리 해야 함
/*
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
*/

// COCCViewerDoc

IMPLEMENT_DYNCREATE(COCCViewerDoc, CDocument)

BEGIN_MESSAGE_MAP(COCCViewerDoc, CDocument)
	ON_COMMAND(ID_FILE_IMPORT, &COCCViewerDoc::OnFileImport)
	ON_COMMAND(ID_FILE_IMPORT_FOLDER, &COCCViewerDoc::OnFileImportFolder)
	ON_COMMAND(ID_EDIT_CLEAR, &COCCViewerDoc::OnEditClear)
	ON_COMMAND(ID_EDIT_CLEAR_ALL, &COCCViewerDoc::OnEditClearAll)
	ON_COMMAND(ID_BOOLEAN_UNION, &COCCViewerDoc::OnBooleanUnion)
END_MESSAGE_MAP()


// COCCViewerDoc 생성/소멸

COCCViewerDoc::COCCViewerDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

COCCViewerDoc::~COCCViewerDoc()
{
}

void COCCViewerDoc::InitializeDocument()
{
	Handle(Graphic3d_GraphicDriver) graphicDriver = static_cast<COCCViewerApp*>(AfxGetApp())->GetGraphicDriver();

	// Viewer를 생성하고, 광원을 기본으로 설정한다.
	m_viewer = new V3d_Viewer(graphicDriver);
	m_viewer->SetDefaultLights();
	m_viewer->SetLightOn();
	m_viewer->SetDefaultBgGradientColors(Quantity_Color(0.0, 0.5, 0.5, Quantity_TOC_RGB), Quantity_Color(1.0, 0.98, 0.98, Quantity_TOC_RGB), Aspect_GFM_VER);
	m_viewer->SetDefaultTypeOfView(V3d_ORTHOGRAPHIC);

	// AIS_InteractiveContext를 생성한다.
	m_context = new AIS_InteractiveContext(m_viewer);
	m_context->DefaultDrawer()->SetFaceBoundaryDraw(true);
}

BOOL COCCViewerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.
	InitializeDocument();

	return TRUE;
}

BOOL COCCViewerDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	InitializeDocument();

	return TRUE;
}

// COCCViewerDoc serialization

void COCCViewerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void COCCViewerDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT)GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void COCCViewerDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void COCCViewerDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl* pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// COCCViewerDoc 진단

#ifdef _DEBUG
void COCCViewerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COCCViewerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// COCCViewerDoc 명령

void COCCViewerDoc::OnFileImport()
{
	CString strFilter = _T("STEP 파일 (*.stp)|*.stp|IGES 파일 (*.igs, *.iges)|*.igs;*.iges||");

	CFileDialog dialog(TRUE, _T("*.stp"), 0, OFN_HIDEREADONLY, strFilter);

	if (IDOK == dialog.DoModal())
	{
		TopoDS_Shape shape;

		CString extension = dialog.GetFileExt();
		extension.MakeLower();

		if (extension == _T("stp"))
		{
			StepReader reader;
			reader.Read(dialog.GetPathName(), shape);
		}
		else if (extension == _T("igs") || extension == _T("iges"))
		{
			IgesReader reader;
			reader.Read(dialog.GetPathName(), shape);
		}

		if (!shape.IsNull())
		{
			Handle(AIS_Shape) aisShape = new AIS_Shape(shape);
			aisShape->SetDisplayMode(AIS_Shaded);
			GetContext()->Display(aisShape, true);
		}
	}
}

int COCCViewerDoc::GetFileCount(const CString& path) const
{
	CFileFind finder;
	BOOL find = finder.FindFile(path);

	int count = 0;

	while (find)
	{
		find = finder.FindNextFile();
		if (finder.IsDirectory() || finder.IsDots())
			continue;

		++count;
	}

	finder.Close();

	return count;
}

void COCCViewerDoc::OnFileImportFolder()
{
	CFolderPickerDialog dialog;

	if (IDOK == dialog.DoModal())
	{
		CWaitCursor wait;

		CString path = dialog.GetPathName();

		int total = GetFileCount(path + _T("\\*.*"));

		CFileFind finder;
		BOOL find = finder.FindFile(path + _T("\\*.*"));

		int count = 0;

		while (find)
		{
			find = finder.FindNextFile();
			CString filePath = finder.GetFilePath();
			if (finder.IsDirectory() || finder.IsDots())
				continue;

			int index = filePath.ReverseFind(_T('.'));
			if (index >= 0)
			{
				TopoDS_Shape shape;

				CString extension = filePath.Right(filePath.GetLength() - index - 1);
				extension.MakeLower();

				if (extension == _T("stp"))
				{
					StepReader reader;
					reader.Read(filePath, shape);
				}
				else if (extension == _T("igs") || extension == _T("iges"))
				{
					IgesReader reader;
					reader.Read(filePath, shape);
				}

				if (!shape.IsNull())
				{
					Handle(AIS_Shape) aisShape = new AIS_Shape(shape);
					aisShape->SetDisplayMode(AIS_Shaded);
					GetContext()->Display(aisShape, false);

					++count;

					CString progresMessage;
					progresMessage.Format(_T("%d/%d Done"), count, total);

					CMainFrame* pMainFrame = (CMainFrame*)AfxGetMainWnd();
					pMainFrame->SetStatusText(progresMessage);
				}
			}
		}

		finder.Close();

		GetContext()->UpdateCurrentViewer();
	}
}

std::vector<Handle(AIS_InteractiveObject)> COCCViewerDoc::GetSelectedObjects() const
{
	std::vector<Handle(AIS_InteractiveObject)> selectedObjects;

	GetContext()->InitSelected();
	while (GetContext()->MoreSelected())
	{
		Handle(AIS_InteractiveObject) selectedObject = GetContext()->SelectedInteractive();
		selectedObjects.push_back(selectedObject);

		GetContext()->NextSelected();
	}

	return selectedObjects;
}

void COCCViewerDoc::OnEditClear()
{
	std::vector<Handle(AIS_InteractiveObject)> selectedObjects = GetSelectedObjects();

	for (auto object : selectedObjects)
	{
		GetContext()->Remove(object, false);
	}

	GetContext()->UpdateCurrentViewer();
}

void COCCViewerDoc::OnEditClearAll()
{
	GetContext()->RemoveAll(true);
}

void COCCViewerDoc::OnBooleanUnion()
{
	CWaitCursor wait;

	std::vector<Handle(AIS_InteractiveObject)> selectedObjects = GetSelectedObjects();

	BOPAlgo_Builder builder;

	TopTools_ListOfShape arguments;
	for (auto aisObject : selectedObjects)
	{
		if (auto aisShape = Handle(AIS_Shape)::DownCast(aisObject))
		{
			arguments.Append(aisShape->Shape());
		}
	}

	builder.SetArguments(arguments);
	builder.SetRunParallel(Standard_True);
	builder.SetGlue(BOPAlgo_GlueShift);
	builder.SetUseOBB(Standard_True);
	builder.Perform();

	std::stringstream ss;

	// 에러 확인
	if (builder.HasErrors())
	{
		builder.DumpErrors(ss);
		TRACE(ss.str().c_str());
		return;
	}

	// 경고 확인
	if (builder.HasWarnings())
	{
		// 경고 처리기
		builder.DumpWarnings(ss);
		TRACE(ss.str().c_str());
	}

	// 시행 결과
	const TopoDS_Shape& resultShape = builder.Shape();

	OnEditClear();

	Handle(AIS_Shape) aisShape = new AIS_Shape(resultShape);
	aisShape->SetDisplayMode(AIS_Shaded);
	GetContext()->Display(aisShape, true);
}