#include "pch.h"
#include "BitmapIO.h"

///**
//*description   : 파일로부터 비트맵 읽어옴
//*@param input  : LPCTSTR lpszPathName					파일 경로명
//*@param input  :  
//*@param output :  
//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
//*/
bool CBitmapIO::Open(LPCTSTR lpszPathName, CUserBitmap& bmpNode, RGBQUAD* palRGB /*= NULL*/)
{
	BITMAPINFOHEADER DibHi;
	BITMAPFILEHEADER DibHf;
	memset(&DibHi, 0, sizeof(BITMAPINFOHEADER));
	memset(&DibHf, 0, sizeof(BITMAPFILEHEADER));

	if (lpszPathName == NULL)
	{
		return false;
	}

	if (_tcslen(lpszPathName) <= 0)
	{
		return false;
	}

	CFile hFile;

	if (!hFile.Open(lpszPathName, CFile::modeRead | CFile::typeBinary))
	{
		return false;
	}

	hFile.Read(&DibHf, sizeof(BITMAPFILEHEADER)); // 파일 헤드를 읽음 

	//이 파일이 BMP파일인지 검사. 0x4d42=='BM'
	if (DibHf.bfType != 0x4D42)
	{
		return false;
	}

	hFile.Read(&DibHi, sizeof(BITMAPINFOHEADER)); //"영상정보의 Header"를 읽는다.  

	if (DibHi.biBitCount != 8 && DibHi.biBitCount != 24)
	{
		return false;
	}

	if (DibHi.biBitCount == 8 && palRGB != NULL)
	{
		hFile.Read(palRGB, sizeof(RGBQUAD) * MAXIMUM_PIXEL_VALUE);
	}

	// 메모리 할당 (바뀐 부분)
	int ImgSize = 0;

	if (DibHi.biBitCount == 8 && palRGB != NULL)
	{
		ImgSize = (int)hFile.GetLength() - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER) - MAXIMUM_PIXEL_VALUE * sizeof(RGBQUAD);
	}
	else if (DibHi.biBitCount == 24)
	{
		ImgSize = (int)hFile.GetLength() - sizeof(BITMAPFILEHEADER) - sizeof(BITMAPINFOHEADER);
	}

	std::vector<unsigned char> pUcBmpImage;
	pUcBmpImage.resize(ImgSize);
	std::fill(pUcBmpImage.begin(), pUcBmpImage.end(), 0);

	hFile.Read(pUcBmpImage.data(), ImgSize);

	hFile.Close();

	if (DibHi.biBitCount == 24)
	{
		// return true;
	}
	else
	{
		if (palRGB != NULL)
		{
			// 영상데이터 대입 
			unsigned int i, j, index;
			int rwsize = WIDTHBYTES(DibHi.biBitCount * DibHi.biWidth);

			for (i = 0; i < (size_t)DibHi.biHeight; i++)
			{
				index = i * rwsize;

				for (j = 0; j < (size_t)DibHi.biWidth; j++)
				{
					// 추후 보완 필요한 부분(오버플로우 발생 가능성 있다고 나옴)
					pUcBmpImage[index + j] = (unsigned char)(palRGB[(int)pUcBmpImage[index + j]].rgbBlue);
				}
			}
		}
	}

	bmpNode.SetImage(pUcBmpImage.data(), &DibHi, &DibHf);

	return true;

}

///**
//*description   : 확장자 붙여줌
//*@param input  : CString lpszPathName	파일 경로명
//*@param input  : 
//*@param input  : 
//*@param output : -
//*@return		 : 경로명
//*/
CString CBitmapIO::AddExtendString(CString lpszPathName)
{
	CString cStrPathName = CString(lpszPathName).Trim();

	CString cStrExt = cStrPathName.Right(4);

	if (cStrExt.CompareNoCase(STR_DEFAULT_EXTEND_NAME))
	{
		cStrPathName = cStrPathName + STR_DEFAULT_EXTEND_NAME;
	}
	
	return cStrPathName;
}

///**
//*description   : 비트맵을 파일로 저장
//*@param input  : LPCTSTR lpszPathName	파일 경로명
//*@param input  : SmallUserBitmap& smallUserBitmap
//*@param input  : RGBQUAD*	palRGB
//*@param output : -
//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
//*/
bool CBitmapIO::Save(LPCTSTR lpszPathName, CUserBitmap& bmpNode, RGBQUAD* palRGB /*= NULL*/)
{
	try
	{
		if (lpszPathName == NULL)
		{
			return false;
		}

		if (_tcslen(lpszPathName) <= 0)
		{
			return false;
		}

		CString cStrPathName = AddExtendString(lpszPathName);

		CFile hFile;

		if (!hFile.Open(cStrPathName, CFile::modeCreate | CFile::modeWrite | CFile::typeBinary))
		{
			return false;
		}

		hFile.Write(bmpNode.GetBimapFileHeader(), sizeof(BITMAPFILEHEADER));

		hFile.Write(bmpNode.GetBimapInfoHeader(), sizeof(BITMAPINFOHEADER));

		if (bmpNode.GetBimapInfoHeader()->biBitCount == 8 && palRGB != NULL)
		{
			hFile.Write(palRGB, sizeof(RGBQUAD) * 256);
		}

		hFile.Write(bmpNode.c_arr_const(), bmpNode.GetBimapInfoHeader()->biSizeImage);

		hFile.Close();

		return true;
	}
	catch (...)
	{
		return false;
	}
}
