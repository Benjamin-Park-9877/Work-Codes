
// BitmapImageProcessView.cpp: CBitmapImageProcessView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "BitmapImageProcess.h"
#endif

#include "BitmapImageProcessDoc.h"
#include "BitmapImageProcessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CBitmapImageProcessView

IMPLEMENT_DYNCREATE(CBitmapImageProcessView, CView)

BEGIN_MESSAGE_MAP(CBitmapImageProcessView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_EDIT_COPY, &CBitmapImageProcessView::OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, &CBitmapImageProcessView::OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, &CBitmapImageProcessView::OnUpdateEditPaste)
	ON_COMMAND(IDM_CHANNELSPLIT_RGB, &CBitmapImageProcessView::OnChannelsplitRgb)
	ON_COMMAND(IDM_CHANNELSPLIT_HSI, &CBitmapImageProcessView::OnChannelsplitHsi)
	ON_COMMAND(IDM_COLOR2GRAY, &CBitmapImageProcessView::OnColor2gray)
	ON_COMMAND(IDM_RGB_EMBOSSING, &CBitmapImageProcessView::OnRgbEmbossing)
	ON_UPDATE_COMMAND_UI(IDM_RGB_EMBOSSING, &CBitmapImageProcessView::OnUpdateRgbEmbossing)
	ON_COMMAND(IDM_RGB_SHAPENNING, &CBitmapImageProcessView::OnRgbShapenning)
	ON_UPDATE_COMMAND_UI(IDM_RGB_SHAPENNING, &CBitmapImageProcessView::OnUpdateRgbShapenning)
	ON_UPDATE_COMMAND_UI(IDM_COLOR2GRAY, &CBitmapImageProcessView::OnUpdateColor2gray)
	ON_UPDATE_COMMAND_UI(IDM_CHANNELSPLIT_HSI, &CBitmapImageProcessView::OnUpdateChannelsplitHsi)
	ON_UPDATE_COMMAND_UI(IDM_CHANNELSPLIT_RGB, &CBitmapImageProcessView::OnUpdateChannelsplitRgb)
	ON_COMMAND(IDM_IMG_DYNBIN, &CBitmapImageProcessView::OnImgDynbin)
	ON_UPDATE_COMMAND_UI(IDM_IMG_DYNBIN, &CBitmapImageProcessView::OnUpdateImgDynbin)
	ON_COMMAND(IDM_BLOBCOLORING, &CBitmapImageProcessView::OnBlobcoloring)
	ON_UPDATE_COMMAND_UI(IDM_BLOBCOLORING, &CBitmapImageProcessView::OnUpdateBlobcoloring)
	ON_COMMAND(IDM_RGB_SOBEL, &CBitmapImageProcessView::OnRgbSobel)
	ON_UPDATE_COMMAND_UI(IDM_RGB_SOBEL, &CBitmapImageProcessView::OnUpdateRgbSobel)
END_MESSAGE_MAP()

// CBitmapImageProcessView 생성/소멸

CBitmapImageProcessView::CBitmapImageProcessView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CBitmapImageProcessView::~CBitmapImageProcessView()
{
}

BOOL CBitmapImageProcessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CBitmapImageProcessView 그리기

void CBitmapImageProcessView::OnDraw(CDC* pDC)
{
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDoc->bmpProcess.DrawImage(pDC);
}


// CBitmapImageProcessView 인쇄

BOOL CBitmapImageProcessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CBitmapImageProcessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CBitmapImageProcessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CBitmapImageProcessView 진단
#ifdef _DEBUG
void CBitmapImageProcessView::AssertValid() const
{
	CView::AssertValid();
}

void CBitmapImageProcessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CBitmapImageProcessDoc* CBitmapImageProcessView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CBitmapImageProcessDoc)));
	return (CBitmapImageProcessDoc*)m_pDocument;
}
#endif //_DEBUG


// CBitmapImageProcessView 메시지 처리기

void CBitmapImageProcessView::OnEditCopy()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	pDoc->bmpProcess.CopyClipboard();
}


void CBitmapImageProcessView::OnEditPaste()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	if (!IsClipboardFormatAvailable(CF_DIB)) return;
	AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_FILE_NEW);
}


void CBitmapImageProcessView::OnUpdateEditPaste(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	pCmdUI->Enable(IsClipboardFormatAvailable(CF_DIB));
}


void CBitmapImageProcessView::OnChannelsplitRgb()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	pDoc->bmpProcess.ChannelsplitRgb();

}


void CBitmapImageProcessView::OnChannelsplitHsi()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	pDoc->bmpProcess.RGB2HSI();

}

void CBitmapImageProcessView::OnColor2gray()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	pDoc->bmpProcess.RGB2Gray();

}

void CBitmapImageProcessView::OnRgbEmbossing()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{

		return;
	}

	pDoc->bmpProcess.ColorEmbossing();
}


void CBitmapImageProcessView::OnUpdateRgbEmbossing(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	pCmdUI->Enable(pDoc->bmpProcess.GetImageBitCount() == 24);

}


void CBitmapImageProcessView::OnRgbShapenning()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{

		return;
	}

	pDoc->bmpProcess.RGBShapening();


}

void CBitmapImageProcessView::OnUpdateRgbShapenning(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.

	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{

		return;
	}

	pCmdUI->Enable(pDoc->bmpProcess.GetImageBitCount() == 24);

}


void CBitmapImageProcessView::OnUpdateColor2gray(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.

	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{

		return;
	}

	pCmdUI->Enable(pDoc->bmpProcess.GetImageBitCount() == 24);

}

void CBitmapImageProcessView::OnUpdateChannelsplitHsi(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.

	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{

		return;
	}

	pCmdUI->Enable(pDoc->bmpProcess.GetImageBitCount() == 24);

}


void CBitmapImageProcessView::OnUpdateChannelsplitRgb(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.

	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{

		return;
	}

	pCmdUI->Enable(pDoc->bmpProcess.GetImageBitCount() == 24);

}


void CBitmapImageProcessView::OnImgDynbin()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	CDLG_DYNBIN dlgDynBin;

	if (pDoc->bmpProcess.OnImgDynbinSet(&dlgDynBin) == false)
	{
		return;
	}

	if (dlgDynBin.DoModal() == IDOK) 
	{
		if (pDoc->bmpProcess.OnImgDynbinGet(&dlgDynBin) == false)
		{
			return;
		}
		Invalidate(FALSE);
	}
}

void CBitmapImageProcessView::OnUpdateImgDynbin(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	pCmdUI->Enable(pDoc->bmpProcess.GetImageBitCount() == 24);

}


void CBitmapImageProcessView::OnBlobcoloring()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	CPen pen;
	pen.CreatePen(PS_SOLID, 2, RGB(50, 50, 50));
	CClientDC dc(this);
	dc.SelectObject(&pen);

	pDoc->bmpProcess.Blobcoloring(&dc);

}


void CBitmapImageProcessView::OnUpdateBlobcoloring(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	pCmdUI->Enable(pDoc->bmpProcess.GetImageBitCount() == 24);
}


void CBitmapImageProcessView::OnRgbSobel()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	pDoc->bmpProcess.OnRgbSobel();

}


void CBitmapImageProcessView::OnUpdateRgbSobel(CCmdUI* pCmdUI)
{
	// TODO: 여기에 명령 업데이트 UI 처리기 코드를 추가합니다.
	CBitmapImageProcessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (!pDoc)
	{
		return;
	}

	pCmdUI->Enable(pDoc->bmpProcess.GetImageBitCount() == 24);
}
