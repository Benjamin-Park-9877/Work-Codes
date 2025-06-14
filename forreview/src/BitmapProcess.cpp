/////** 
////*description   : 비트맵 영상을 처리하는 객체 정의 소스 파일
////*               
////* 
////*/
#include "pch.h"
#include "BitmapProcess.h"


///**
//*description   : 비트맵 영상을 처리하는 객체용 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapProcess::CBitmapProcess(void)
{
	Initialize();
}

///**
//*description   : 비트맵 영상을 처리하는 객체용 소멸자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapProcess::~CBitmapProcess(void)
{
	Clear();
}

///**
//*description   : 비트맵 이미지 처리 담당 객체 내부 동적할당 메모리 해제
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CBitmapProcess::Clear(void)
{
	m_cbmpNodeIn.Clear();
}

///**
//*description   : 비트맵 이미지 처리 담당 객체 내부 변수 초기화
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CBitmapProcess::Initialize(void)
{
	m_cuserRGBQuad.Initialize();
}

///**
//*description   : 비트맵을 파일로 저장
//*@param input  : LPCTSTR lpszPathName	파일 경로명
//*@param input  : SmallUserBitmap& smallUserBitmap
//*@param input  : RGBQUAD*	palRGB
//*@param output : -
//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
//*/
bool CBitmapProcess::SaveImageToFile(LPCTSTR lpszPathName)
{
	if (lpszPathName == NULL)
	{
		return false;
	}

	if (_tcslen(lpszPathName) <= 0)
	{
		return false;
	}

	CBitmapIO bitmapIO;

	if (bitmapIO.Save(lpszPathName, m_cbmpNodeIn, m_cuserRGBQuad.Get()) == false)
	{
		return false;
	}

	return true;
}

///**
//*description   : 파일로부터 비트맵 읽어옴
//*@param input  : LPCTSTR lpszPathName					파일 경로명
//*@param input  :  
//*@param output :  
//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
//*/
bool CBitmapProcess::OpenImageFromFile(LPCTSTR lpszPathName)
{
	if (lpszPathName == NULL)
	{
		return false;
	}

	if (_tcslen(lpszPathName) <= 0)
	{
		return false;
	}

	CBitmapIO bitmapIO;

	if (bitmapIO.Open(lpszPathName, m_cbmpNodeIn, m_cuserRGBQuad.Get()) == false)
	{
		return false;
	}

	return true;
}

//*description   : 
//*@param input  :  
//*@param input  :   
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CBitmapProcess::RGB2HSI(void)
{
	CRGBToHSI rgb2hsi;
	
	rgb2hsi.Process(m_cbmpNodeIn);

	rgb2hsi.Clear(); // 메모리 누수 방지 및 확인을 위해서라도 반드시 이 부분은 추가할 것
}

//*description   : 
//*@param input  :  
//*@param input  :   
//*@param input  :
//*@param input  : 
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CBitmapProcess::RGB2Gray(void)
{
	CRGBToGray rgb2gray;

	rgb2gray.Process(m_cbmpNodeIn);

	rgb2gray.Clear(); // 메모리 누수 방지 및 확인을 위해서라도 반드시 이 부분은 추가할 것		 
}

//*description   : 
//*@param input  :  
//*@param input  :  
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CBitmapProcess::ColorEmbossing(void)
{
	CColorEmbossing colorEmbossing;

	colorEmbossing.Process(m_cbmpNodeIn);

	colorEmbossing.Clear();// 메모리 누수 방지 및 확인을 위해서라도 반드시 이 부분은 추가할 것		 
}

//*description   : 
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param input  :
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CBitmapProcess::RGBShapening(void)
{
	CRGBSharpening rgbSharpening;
	
	rgbSharpening.Process(m_cbmpNodeIn);

	rgbSharpening.Clear();

}

//*description   :  
//*@param input  : -
//*@param output : -
//*@return		 :  
//*/
void CBitmapProcess::OnRgbSobel(void)
{
	CSobelImage sobelImage;

	sobelImage.Process(m_cbmpNodeIn);

	sobelImage.Clear();
}


//*description   : 
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CBitmapProcess::ChannelsplitRgb(void)
{
	CChannelsplitRgb channelsplitRgb;

	channelsplitRgb.Process(m_cbmpNodeIn);

	channelsplitRgb.Clear();
}

//*description   : 
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param input  :
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CBitmapProcess::Blobcoloring(CClientDC* pDc)
{
	if (pDc == NULL)
	{
		return;
	}
	
	CActBlobcoloring actBlobcoloring;

	actBlobcoloring.Process(m_cbmpNodeIn, pDc);

	actBlobcoloring.Clear();
}

//*description   : 
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param input  :
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
bool CBitmapProcess::OnImgDynbinSet(CDLG_DYNBIN* pDlg)
{
	if (pDlg == NULL)
	{
		return false;
	}

	if (m_cbmpNodeIn.GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (m_cbmpNodeIn.c_arr_const() == NULL)
	{
		return false;
	}

	pDlg->Set(m_cbmpNodeIn);

	return true;
}

//*description   : 
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param input  :
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
bool CBitmapProcess::OnImgDynbinGet(CDLG_DYNBIN* pDlg)
{
	if (pDlg == NULL)
	{
		return false;
	}

	if (m_cbmpNodeIn.GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (m_cbmpNodeIn.c_arr_const() == NULL)
	{
		return false;
	}
	pDlg->Get(m_cbmpNodeIn);

	return true;
}


///**
//*description   : 새로운 User Image 설정함
//*@param input  : -
//*@param output : -
//*@return		 : 정상동작 수행여부(true:동작함,false:실패함)
//*/
bool CBitmapProcess::NewDocument(void)
{
	CBitmapClipBoard bitmapClipBoard;

	if (bitmapClipBoard.NewDocument(m_cbmpNodeIn, m_cuserRGBQuad) == false)
	{
		return false;
	}

	return true;
}

//*description   : 
//*@param input  : int nFlag
//*@param output : -
//*@return		 : 
//*/
const size_t CBitmapProcess::GetImageWidth(void) const
{
	return m_cbmpNodeIn.GetMaximumWidth();
}

//*description   : 
//*@param input  : int nFlag
//*@param output : -
//*@return		 :  
//*/
const size_t CBitmapProcess::GetImageHeight(void) const
{
	return m_cbmpNodeIn.GetMaximumHeight();
}

//*description   : 
//*@param input  : int nFlag
//*@param output : -
//*@return		 :  
//*/
const int CBitmapProcess::GetImageBitCount(void) const
{
	return m_cbmpNodeIn.GetBitCount();
}

//*description   : 
//*@param input  : int nFlag
//*@param output : -
//*@return		 :  
//*/
const int CBitmapProcess::GetImageRwSize(void) const
{
	return m_cbmpNodeIn.GetRwSize();
}


//*description   : User Image를 지정된 정보로 화면 출력
//*@param input  : CDC* pDC					출력할 DC 포인터
//*@param output : -
//*@return		 : 정상동작 수행여부(true:동작함,false:실패함)
//*/
bool CBitmapProcess::DrawImage(CDC* pDC)
{
	if (pDC == NULL)
	{
		return false;
	}

	if (m_cbmpNodeIn.c_arr_const() == NULL)
	{
		return false;
	}

	SetDIBitsToDevice(pDC->GetSafeHdc(), 0, 0,
		m_cbmpNodeIn.GetMaximumWidth(), m_cbmpNodeIn.GetMaximumHeight(),
		0, 0, 0, m_cbmpNodeIn.GetMaximumHeight(),
		m_cbmpNodeIn.c_arr_const(), m_cbmpNodeIn.GetBitmapInfo(), DIB_RGB_COLORS);

	return true;

}

//*description   : 
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CBitmapProcess::GetImageSize(CSize& csSizeImage) const
{
		csSizeImage.cx = GetImageWidth();
		csSizeImage.cy = GetImageHeight();
}

//*description   : 클립보드로 복사하기
//*@param input  : -
//*@param output : -
//*@return		 :  
//*/
void  CBitmapProcess::CopyClipboard(void)
{
	CBitmapClipBoard bitmapClipBoard;

	bitmapClipBoard.CopyClipboard(m_cbmpNodeIn, m_cuserRGBQuad);

}