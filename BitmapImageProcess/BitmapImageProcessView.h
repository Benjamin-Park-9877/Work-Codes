
// BitmapImageProcessView.h: CBitmapImageProcessView 클래스의 인터페이스
//

#pragma once
#include "CDLG_DYNBIN.h"

class CBitmapImageProcessView : public CView
{
protected: // serialization에서만 만들어집니다.
	CBitmapImageProcessView() noexcept;
	DECLARE_DYNCREATE(CBitmapImageProcessView)

// 특성입니다.
public:
	CBitmapImageProcessDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CBitmapImageProcessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEditCopy();
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnChannelsplitRgb();
	afx_msg void OnChannelsplitHsi();
	afx_msg void OnColor2gray();
	afx_msg void OnRgbEmbossing();
	afx_msg void OnUpdateRgbEmbossing(CCmdUI* pCmdUI);
	afx_msg void OnRgbShapenning();
	afx_msg void OnUpdateRgbShapenning(CCmdUI* pCmdUI);
	afx_msg void OnUpdateColor2gray(CCmdUI* pCmdUI);
	afx_msg void OnUpdateChannelsplitHsi(CCmdUI* pCmdUI);
	afx_msg void OnUpdateChannelsplitRgb(CCmdUI* pCmdUI);
	afx_msg void OnImgDynbin();
	afx_msg void OnUpdateImgDynbin(CCmdUI* pCmdUI);
	afx_msg void OnBlobcoloring();
	afx_msg void OnUpdateBlobcoloring(CCmdUI* pCmdUI);
	afx_msg void OnRgbSobel();
	afx_msg void OnUpdateRgbSobel(CCmdUI* pCmdUI);
};

#ifndef _DEBUG  // BitmapImageProcessView.cpp의 디버그 버전
inline CBitmapImageProcessDoc* CBitmapImageProcessView::GetDocument() const
   { return reinterpret_cast<CBitmapImageProcessDoc*>(m_pDocument); }
#endif

