/////** 
////*description   : 비트맵 영상을 처리하는 객체 정의 소스 파일
////*               
////* 
////*/
#include "pch.h"
#include "RGBToHSI.h"
#include "BlobColoring.h"
#include "ColorConv.h"

//*description   : RGB -> HSI 영상으로 변환 후 분할
//*@param input  : CUserBitmap* pCbmpElementsIn
//*@param input  :   
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CRGBToHSI::Process(const CUserBitmap* pCbmpElementsIn)
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

	RGB2HSI(pCbmpElementsIn->c_arr_const() , m_pCbmpElements->c_arr(), (int)m_pCbmpElements->GetMaximumHeight(), (int)m_pCbmpElements->GetMaximumWidth());

	SpiltOneColorImage(*m_pCbmpElements);
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
void  CRGBToHSI::RGB2HSI(const unsigned char* InImg, unsigned char* OutImg, int height, int width)
{
	if (InImg == NULL)
	{
		return;
	}

	if (OutImg == NULL)
	{
		return;
	}

	if (height <= 0)
	{
		return;
	}

	if (width <= 0)
	{
		return;
	}

	int rwsize = WIDTHBYTES(24 * width);

	int i, j, index, ih;
	double r, g, b, h, s, iv;
	CColorConv pColorConv;
	for (i = 0; i < height; i++)
	{
		index = (height - i - 1) * rwsize;
		for (j = 0; j < width; j++)
		{
			r = (double)InImg[index + 3 * j + 2] / 255.0f;
			g = (double)InImg[index + 3 * j + 1] / 255.0f;
			b = (double)InImg[index + 3 * j] / 255.0f;

			pColorConv.RGB_To_HSI(r, g, b, &h, &s, &iv);
			ih = (int)(h * 255.0 / 360.0);
			OutImg[index + 3 * j] = (unsigned char)ih;
			OutImg[index + 3 * j + 1] = (unsigned char)(s * 255.0);
			OutImg[index + 3 * j + 2] = (unsigned char)(iv * 255.0);
		}
	}
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
bool CRGBToHSI::SpiltOneColorImage(const CUserBitmap& bitmapNode, int nType /*= THREE_COLOR_TYPE*/)
{

	if (bitmapNode.c_arr_const() == NULL)
	{
		return false;
	}

	if (nType <= 0 || nType > FOUR_COLOR_TYPE)
	{
		return false;
	}

	int index = 0;
	int i = 0;
	int j = 0;
	int grRWSIZE = WIDTHBYTES(8 * bitmapNode.GetMaximumWidth());
	int width = (int)bitmapNode.GetMaximumWidth();
	int height = (int)bitmapNode.GetMaximumHeight();
	int rwsize = (int)bitmapNode.GetRwSize();

	std::vector<unsigned char> GrayImg;
	GrayImg.resize((height * grRWSIZE));
	std::fill(GrayImg.begin(), GrayImg.end(), 0);

	for (int k = 0; k < nType; k++)
	{
		for (i = 0; i < height; i++)
		{
			index = (height - i - 1) * rwsize;
			for (j = 0; j < width; j++) GrayImg[(height - i - 1) * grRWSIZE + j] = bitmapNode[index + 3 * j + k];
		}

		CopyClipboard(GrayImg.data(), height, width, 8);

		AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_FILE_NEW);
	}

	return true;
}
