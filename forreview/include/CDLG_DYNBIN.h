#pragma once

#include "DynBinProcess.h"

// CDLG_DYNBIN 대화 상자

class CDLG_DYNBIN : public CDialog
{
public:
	CDynBinProcess	m_dynBinProcess;

	int m_nThreshValueDisp;
	
	CSliderCtrl m_ctrlSlider;

	DECLARE_DYNAMIC(CDLG_DYNBIN)	

public:
	CDLG_DYNBIN(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDLG_DYNBIN();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_DYNBIN };
#endif

public:
	
	///**
	//*description   : 동적 이진화 대화상자에서 사용할 이미지를 지정함
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	BOOL Set(const CUserBitmap& userBitmap);
	
	///**
	//*description   : 동적 이진화 대화상자에서 조정된 이미지를 받아옴
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	BOOL Get(CUserBitmap& userBitmap);

	///**
	//*description   : 동적 이진화 대화상자에서 조정된 이미지를 받아옴
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void Clear(void);

	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	virtual void OnOK();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnPaint();
	afx_msg void OnNMCustomdrawSldThreshhold(NMHDR* pNMHDR, LRESULT* pResult);
};
