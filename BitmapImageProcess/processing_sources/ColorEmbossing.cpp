/////** 
////*description   : 색상 엠보싱 작업 수행 클래스 정의 소스 파일
////*               
////* 
////*/
#include "pch.h"
#include "ColorEmbossing.h"
#include "BlobColoring.h"
#include "ColorConv.h"

//*description   : 색상 엠보싱 작업
//*@param input  : CUserBitmap* pCbmpElementsIn
//*@param input  :   
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CColorEmbossing::Process(const CUserBitmap* pCbmpElementsIn)
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

	ColorEmbossing(pCbmpElementsIn->c_arr_const(), m_pCbmpElements->c_arr(), (int)m_pCbmpElements->GetMaximumHeight(), (int)m_pCbmpElements->GetMaximumWidth());

	CopyClipboard(m_pCbmpElements->c_arr_const(), (int)m_pCbmpElements->GetMaximumHeight(), (int)m_pCbmpElements->GetMaximumWidth(), 24);

	AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_FILE_NEW);
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
void CColorEmbossing::ColorEmbossing(const unsigned char* InImg, unsigned char* OutImg, int height, int width)
{
	if (InImg == NULL)
	{
		return;
	}

	if (OutImg == NULL)
	{
		return;
	}

	if (height <= INVALID_IMAGE_SIZE)
	{
		return;
	}

	if (width <= INVALID_IMAGE_SIZE)
	{
		return;
	}

	int rwsize = WIDTHBYTES(24 * width);
	int i = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	int index1 = 0;
	int index2 = 0;
	int index3 = 0;

	// convolution MASK의 정의 
	int winsize = 3;
	std::vector<float> Mask;
	InitializeMask(Mask, winsize);

	Mask[0] = -1.0f; Mask[8] = 1.0f;

	//
	int n = (winsize - 1) >> 1;	// winsize 절반의 offset크기를 계산 

	for (i = n; i < height - n; i++)
	{
		index1 = i * rwsize;
		for (j = n; j < width - n; j++)
		{
			double sum1 = 0.0f;
			double sum2 = 0.0f;
			double sum3 = 0.0f;

			for (k = -n; k <= n; k++)
			{
				index2 = (i + k) * rwsize;
				index3 = (k + n) * winsize;
				for (l = -n; l <= n; l++)
				{
					sum1 += (double)(InImg[index2 + 3 * (j + l)]) * (double)(Mask[index3 + l + n]);
					sum2 += (double)(InImg[index2 + 3 * (j + l) + 1]) * (double)(Mask[index3 + l + n]);
					sum3 += (double)(InImg[index2 + 3 * (j + l) + 2]) * (double)(Mask[index3 + l + n]);
				}
			}
			sum1 += 128; sum2 += 128; sum3 += 128;
	
			CLIP<double>(sum1, 0.0, 255.0); 
			CLIP<double>(sum2, 0.0, 255.0);
			CLIP<double>(sum3, 0.0, 255.0);

			OutImg[index1 + 3 * j] = (unsigned char)sum1;
			OutImg[index1 + 3 * j + 1] = (unsigned char)sum2;
			OutImg[index1 + 3 * j + 2] = (unsigned char)sum3;
		}
	}
}
