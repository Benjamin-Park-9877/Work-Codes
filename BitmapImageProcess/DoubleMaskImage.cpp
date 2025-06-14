/////** 
////*description   : 이중 마스크 작업 수행 클래스 정의 소스 파일
////*               
////* 
////*/
#include "pch.h"
#include "DoubleMaskImage.h"

//*description   : 외부에서 호출하는 함수
//*@param input  : CUserBitmap* pCbmpElementsIn
//*@param output : 
//*@return		 :  
//*/
void CDoubleMaskImage::Process(CUserBitmap* pCbmpElementsIn)
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

	Work(pCbmpElementsIn->GetImage(), m_pCbmpElements->GetImage(), (int)m_pCbmpElements->GetMaximumHeight(), (int)m_pCbmpElements->GetMaximumWidth());

	CopyClipboard(m_pCbmpElements->c_arr_const(), (int)m_pCbmpElements->GetMaximumHeight(), (int)m_pCbmpElements->GetMaximumWidth(), 24);

	AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_FILE_NEW);
}

//*description   : 
//*@param input  :  
//*@param output : 
//*@return		 :  
//*/
void CDoubleMaskImage::Work(std::vector<unsigned char>& InImg, std::vector<unsigned char>& OutImg, const int& height, const int& width)
{
	if (InImg.empty() == true) { return; }

	if (OutImg.empty() == true) { return; }

	if (height <= 0) { return; }

	if (width <= 0) { return; }

	// convolution MASK의 정의 
	const int winsize = 3;
	std::vector<float> Mask1st;
	InitializeMask_1St(Mask1st, winsize);

	std::vector<float> Mask2nd;
	InitializeMask_2nd(Mask2nd, winsize);

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
			ImgConvolution(IV, IVO, height, width, Mask1st, Mask2nd, winsize);

			HSItoRGB(OutImg, H, S, IVO, height, width);
		}
	}
}


//*description   : 
//*@param input  :  
//*@param output : 
//*@return		 :  
//*/
bool CDoubleMaskImage::InitializeMask_1St(std::vector<float>& mask, const size_t& winsize)
{
	std::vector<float> pattern;

	pattern.resize(winsize * winsize);

	pattern = { 1,1,1,1,1,1,1,1,1 };

	FillMaskPattern(mask, pattern, winsize);

	return true;
}

//*description   : 
//*@param input  :  
//*@param output : 
//*@return		 :  
//*/
bool CDoubleMaskImage::InitializeMask_2nd(std::vector<float>& mask, const size_t& winsize)
{
	std::vector<float> pattern;

	pattern.resize(winsize * winsize);

	pattern = { 1,1,1,1,1,1,1,1,1 };

	FillMaskPattern(mask, pattern, winsize);

	return true;
}

//*description   : 
//*@param input  :  
//*@param input  :  
//*@param input  : int				height
//*@param input  : int				width
//*@param input  : float			*Mask
//*@param input  : int				winsize
//*@param output : -
//*@return		 :  
//*/
bool CDoubleMaskImage::ImgConvolution(std::vector<unsigned char>& InImg, std::vector<unsigned char>& OutImg, const size_t& height, const size_t& width, std::vector<float>& Mask1, std::vector<float>& Mask2, int winsize)
{
	if (InImg.empty() == true) { return false; }

	if (OutImg.empty() == true) { return false; }

	if (Mask1.empty() == true) { return false; }

	if (Mask2.empty() == true) { return false; }

	if (height <= INVALID_IMAGE_SIZE) { return false; }

	if (width <= INVALID_IMAGE_SIZE) { return false; }

	if (winsize <= INVALID_IMAGE_SIZE) { return false; }

	// 출력 메모리 초기화 
	std::fill(OutImg.begin(), OutImg.end(), 0);

	// winsize 절반의 offset크기를 계산 
	int n = (winsize - 1) >> 1;

	size_t i = 0;
	size_t j = 0;
	int k = 0;
	int l = 0;
	size_t index1 = 0;
	size_t index2 = 0;
	size_t index3 = 0;
	double centerValue1 = 0.0;
	double centerValue2 = 0.0;
	double sum = 0.0;

	for (i = n; i < height - n; i++)
	{
		index1 = i * width;

		for (j = n; j < width - n; j++)
		{
			centerValue1 = 0.0;
			centerValue2 = 0.0;
			sum = 0.0;

			for (k = -n; k <= n; k++)
			{
				index2 = (i + k) * width;
				index3 = (k + n) * winsize;
				for (l = -n; l <= n; l++)
				{
					centerValue1 += (double)(InImg[index2 + (j + l)]) * (double)(Mask1[index3 + l + n]);
					centerValue2 += (double)(InImg[index2 + (j + l)]) * (double)(Mask2[index3 + l + n]);
				}
			}
			sum = abs(centerValue1) + abs(centerValue2);
			CLIP<double>(sum, 0.0, 255.0);

			OutImg[index1 + j] = (unsigned char)sum;
		}
	}
	return true;
}