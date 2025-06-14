/////** 
////*description   : 비트맵 영상을 처리하는 객체 정의 소스 파일
////*               
////* 
////*/

#include "pch.h"
#include "BitmapClipBoard.h"

///**
//*description   : 새로운 User Image 설정함
//*@param input  : -
//*@param output : -
//*@return		 : 정상동작 수행여부(true:동작함,false:실패함)
//*/
bool CBitmapClipBoard::NewDocument(CUserBitmap& cbmpNodeIn, CUserRGBQuad& cUserRGBQuad)
{
	::OpenClipboard(NULL);

	if (!IsClipboardFormatAvailable(CF_DIB))
	{
		return false;
	}

	HGLOBAL m_hImage = NULL;

	m_hImage = ::GetClipboardData(CF_DIB);

	::CloseClipboard();

	if (m_hImage == NULL)
	{
		return false;
	}

	LPSTR pDIB = NULL;
	pDIB = (LPSTR) ::GlobalLock((HGLOBAL)m_hImage);

	if (pDIB == NULL)
	{
		return false;
	}

	if (OpenImageFromClipBoard(pDIB, cbmpNodeIn) == false)
	{
		return false;
	}

	if (cbmpNodeIn.GetBitCount() == 8)
	{
		cUserRGBQuad.Set((LPSTR)(pDIB + sizeof(BITMAPINFOHEADER)));
	}

	return true;
}

//*description   : 클립보드로 복사하기(nFlag는 기본적으로 FLAG_SELECT_INPUT 즉, 입력 받은 이미지를 복사함)
//*@param input  : unsigned char	*m_CpyImg
//*@param output : -
//*@return		 :  
//*/
void CBitmapClipBoard::CopyClipboard(const CUserBitmap& cbmpNodeIn, CUserRGBQuad& cUserRGBQuad)
{
	CopyClipboard(cbmpNodeIn.c_arr_const(), cbmpNodeIn.GetMaximumHeight(), cbmpNodeIn.GetMaximumWidth(), cbmpNodeIn.GetBitCount(), *cbmpNodeIn.GetBimapInfoHeader(), cUserRGBQuad);
}

//*description   : 클립보드로 복사하기(nFlag는 기본적으로 FLAG_SELECT_INPUT 즉, 입력 받은 이미지를 복사함)
//*@param input  : unsigned char	*m_CpyImg
//*@param input  : int				height
//*@param input  : int				width
//*@param input  : int				biBitCount 
//*@param input  : int				nFlag
//*@param output : -
//*@return		 :  
//*/
void CBitmapClipBoard::CopyClipboard(const unsigned char* m_CpyImg, int height, int width, int biBitCount, const BITMAPINFOHEADER& dibHi, CUserRGBQuad& cUserRGBQuad)
{
	if (m_CpyImg == NULL)
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

	if (biBitCount != 8 && biBitCount != 24)
	{
		return;
	}

	// 클립보드에 복사하기 위한 파일의 길이를 구함
	int rwsize = WIDTHBYTES(biBitCount * width);
	DWORD dwBitsSize = sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * MAXIMUM_PIXEL_VALUE + rwsize * height * sizeof(unsigned char); //

	// 메모리 할당(파일헤드만 제외시킨 길이)
	HGLOBAL m_hImage = NULL;
	LPSTR pDIB = NULL;

	m_hImage = (HGLOBAL)::GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, dwBitsSize);

	if (m_hImage == NULL)
	{
		return;
	}

	pDIB = (LPSTR) ::GlobalLock((HGLOBAL)m_hImage);

	if (pDIB == NULL)
	{
		return;
	}

	// 데이타복사 
	BITMAPINFOHEADER dibCpyHi;

	memcpy(&dibCpyHi, &dibHi, sizeof(BITMAPINFOHEADER));

	dibCpyHi.biBitCount = biBitCount;
	dibCpyHi.biHeight = height;
	dibCpyHi.biWidth = width;
	dibCpyHi.biSizeImage = height * rwsize;

	if (biBitCount == 8) dibCpyHi.biClrUsed = dibCpyHi.biClrImportant = MAXIMUM_PIXEL_VALUE;

	// 코드 수정으로 인해서 버퍼 오버런 발생 위험 있음. 
	// 추후 확인 필요
	memcpy(pDIB, &dibCpyHi, sizeof(BITMAPINFOHEADER));

	if (biBitCount == 8)
	{
		memcpy(pDIB + sizeof(BITMAPINFOHEADER), cUserRGBQuad.Get(), sizeof(RGBQUAD) * MAXIMUM_PIXEL_VALUE);
		memcpy(pDIB + dwBitsSize - dibCpyHi.biSizeImage, m_CpyImg, dibCpyHi.biSizeImage);
	}
	else memcpy(pDIB + sizeof(BITMAPINFOHEADER), m_CpyImg, dibCpyHi.biSizeImage);

	// 클립보드 복사 
	::OpenClipboard(NULL);
	::SetClipboardData(CF_DIB, m_hImage);
	::CloseClipboard();

	::GlobalUnlock((HGLOBAL)m_hImage);
	GlobalFree(m_hImage);
}

///**
//*description   : 비트맵 파일 채우기
//*@param input  : LPSTR pDIB 
//*@param output : CBitmapNode& bmpNode
//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
//*/
bool CBitmapClipBoard::OpenImageFromClipBoard(LPSTR pDIB, CUserBitmap& bmpNode)
{
	BITMAPINFOHEADER DibHi;
	BITMAPFILEHEADER DibHf;
	memset(&DibHi, 0, sizeof(BITMAPINFOHEADER));
	memset(&DibHf, 0, sizeof(BITMAPFILEHEADER));

	if (pDIB == NULL)
	{
		return false;
	}

	memcpy(&DibHi, pDIB, sizeof(BITMAPINFOHEADER));

	int rwsize = WIDTHBYTES(DibHi.biBitCount * DibHi.biWidth);

	DWORD dwBitsSize = (sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * MAXIMUM_PIXEL_VALUE + rwsize * DibHi.biHeight * sizeof(char));

	std::vector<unsigned char> pUcBmpImage;
	pUcBmpImage.resize(DibHi.biSizeImage);
	std::fill(pUcBmpImage.begin(), pUcBmpImage.end(), 0);

	if (DibHi.biBitCount == 8)
	{
		memcpy(pUcBmpImage.data(), pDIB + dwBitsSize - DibHi.biSizeImage, DibHi.biSizeImage);
	}
	else
	{
		memcpy(pUcBmpImage.data(), pDIB + sizeof(BITMAPINFOHEADER), DibHi.biSizeImage);
	}

	// BITMAP Filer Header파라메타의 설정 
	DibHf.bfType = 0x4d42;  // 'BM'
	DibHf.bfSize = dwBitsSize + sizeof(BITMAPFILEHEADER); // 전체파일 크기 

	if (DibHi.biBitCount == 24) DibHf.bfSize -= sizeof(RGBQUAD) * MAXIMUM_PIXEL_VALUE; // no pallette 

	DibHf.bfOffBits = DibHf.bfSize - rwsize * DibHi.biHeight * sizeof(char);
	DibHf.bfReserved1 = DibHf.bfReserved2 = 0;

	if (bmpNode.SetImage(pUcBmpImage.data(), &DibHi, &DibHf) == false)
	{
		return false;
	}

	return true;
}
