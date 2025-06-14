/////** 
////*description   : 색상 영상을 선명하게 만드는 작업 수행 클래스 정의 소스 파일
////*               
////* 
////*/
#include "pch.h"
#include "RGBSharpening.h"
#include "BlobColoring.h"
#include "ColorConv.h"

//*description   :  
//*@param input  : CUserBitmap* pCbmpElementsIn
//*@param input  :   
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CRGBSharpening::Process(CUserBitmap* pCbmpElementsIn)
{
	if (pCbmpElementsIn->c_arr_const() == NULL)
	{
		return;
	}

	if (pCbmpElementsIn->GetBitmapInfo() == NULL)
	{
		return;
	}

	if (pCbmpElementsIn->GetBitCount() != 24)
	{
		return;
	}

	// 빈이미지로 초기화 하여야 하나 동작 확인 및 별도로 set 하는 일 막기 위해 이렇게 처리함
	if (Set(pCbmpElementsIn) == false)
	{
		return;
	}

	RGBShapening(pCbmpElementsIn->GetImage(), m_pCbmpElements->GetImage(), (int)m_pCbmpElements->GetMaximumHeight(), (int)m_pCbmpElements->GetMaximumWidth());

	CopyClipboard(m_pCbmpElements->c_arr_const(), (int)m_pCbmpElements->GetMaximumHeight(), (int)m_pCbmpElements->GetMaximumWidth(), 24);

	AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_FILE_NEW);
}

//*description   : 
//*@param input  :  
//*@param input  :  
//*@param input  :  
//*@param input  :  
//*@param input  :  
//*@param input  :  
//*@param output :  
//*@return		 :  
//*/
bool CRGBSharpening::InitializeMask(std::vector<float>& mask, const size_t& winsize)
{
	CBitmapAction::InitializeMask(mask, winsize);

	mask[1] = mask[3] = mask[5] = mask[7] = -1.0f; mask[4] = 5.0f;

	return true;
}


//*description   : 
//*@param input  :  
//*@param input  :  
//*@param input  : int				height
//*@param input  : int				width
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CRGBSharpening::RGBShapening(std::vector<unsigned char>& InImg, std::vector<unsigned char>& OutImg, const int& height, const int& width)
{
	if (InImg.empty() == true) { return; }

	if (OutImg.empty() == true)  { return; }

	if (height <= 0) { return; }

	if (width <= 0)  { return; }

	// convolution MASK의 정의 
	const int winsize = 3;
	std::vector<float> Mask;
	InitializeMask(Mask, winsize);

	// HSI영상을 위한 메모리 정의
	std::vector<short> H;
	InitializeBufferImage(H, (height * width));

	std::vector<unsigned char> S;
	InitializeBufferImage(S, (height * width));

	std::vector<unsigned char> IV;
	InitializeBufferImage(IV, (height * width));

	if ((H.empty() != true) && (S.empty() != true) && (IV.empty() != true))
	{
		RGBtoHSI(InImg, H, S, IV, height, width);

		std::vector<unsigned char> IVO;
		InitializeBufferImage(IVO, (height * width));

		if (IVO.empty() == false)
		{
			ImgConvolution(IV, IVO, height, width, Mask, winsize);

			HSItoRGB(OutImg, H, S, IVO, height, width);
		}
	}
}