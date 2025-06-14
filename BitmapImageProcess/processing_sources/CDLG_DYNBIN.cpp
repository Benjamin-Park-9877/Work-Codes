// CDLG_DYNBIN.cpp: 구현 파일
//

#include "pch.h"
#include "BitmapImageProcess.h"
#include "CDLG_DYNBIN.h"
#include "afxdialogex.h"


// CDLG_DYNBIN 대화 상자

IMPLEMENT_DYNAMIC(CDLG_DYNBIN, CDialog)
CDLG_DYNBIN::CDLG_DYNBIN(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DLG_DYNBIN, pParent) , m_nThreshValueDisp(0)
{
	m_dynBinProcess.SetThreshValueDisp(m_nThreshValueDisp);
}

CDLG_DYNBIN::~CDLG_DYNBIN()
{
	Clear();
}

void CDLG_DYNBIN::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDT_THRESHHOLD, m_nThreshValueDisp);
	DDX_Control(pDX, IDC_SLD_THRESHHOLD, m_ctrlSlider);
	DDV_MinMaxInt(pDX, m_nThreshValueDisp, 0, 255);
}


BEGIN_MESSAGE_MAP(CDLG_DYNBIN, CDialog)
	ON_WM_PAINT()
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLD_THRESHHOLD, &CDLG_DYNBIN::OnNMCustomdrawSldThreshhold)
END_MESSAGE_MAP()


// CDLG_DYNBIN 메시지 처리기


BOOL CDLG_DYNBIN::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_ctrlSlider.SetRange(0, 255);
	m_ctrlSlider.SetPos(100);
	m_nThreshValueDisp = m_ctrlSlider.GetPos();
	m_dynBinProcess.OnInitDialog(m_nThreshValueDisp);
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDLG_DYNBIN::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.
	CPaintDC dcView(GetDlgItem(IDC_IMG_HISTO_VIEW));

	CRect rect;
	GetDlgItem(IDC_IMG_HISTO_VIEW)->GetClientRect(&rect);
	m_dynBinProcess.OnPaint(dcView, rect);
}


void CDLG_DYNBIN::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CDialog::OnCancel();
}


void CDLG_DYNBIN::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CDialog::OnOK();
}

///**
//*description   : 동적 이진화 대화상자에서 조정된 이미지를 받아옴
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CDLG_DYNBIN::Clear(void)
{
	m_dynBinProcess.Clear();
}

void CDLG_DYNBIN::OnNMCustomdrawSldThreshhold(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;

	m_nThreshValueDisp = m_ctrlSlider.GetPos();
	
	m_dynBinProcess.OnNMCustomdrawSldThreshhold(m_nThreshValueDisp);
	
	UpdateData(FALSE);
	
	CRect rect;
	GetDlgItem(IDC_IMG_HISTO_VIEW)->GetWindowRect(&rect);
	ScreenToClient(rect);
	InvalidateRect(&rect, FALSE);
}

///**
//*description   : 동적 이진화 대화상자에서 사용할 이미지를 지정함
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
BOOL CDLG_DYNBIN::Set(const CUserBitmap& userBitmap)
{
	if (m_dynBinProcess.SetImage(userBitmap) == false)
	{
		return FALSE;
	}
	return TRUE;
}

///**
//*description   : 동적 이진화 대화상자에서 조정된 이미지를 받아옴
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
BOOL CDLG_DYNBIN::Get(CUserBitmap& userBitmap)
{
	if (m_dynBinProcess.GetImage(userBitmap) == false)
	{
		return FALSE;
	}
	return TRUE;
}