#include "pch.h"
#include "UserBitmap.h"

///**
//*description   : 비트맵 영상이 실제 저장되는 객체 용 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CUserBitmap::CUserBitmap()
{
	m_pUcBmpImage = NULL;
}

///**
//*description   : 비트맵 영상이 실제 저장되는 객체 용 소멸자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CUserBitmap::~CUserBitmap()
{
	Clear();
}

#ifdef _NOT_APPLYED_VECTOR_DATA_
///**
//*description   : 객체 메모리 해제 및 내용 비우기
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CUserBitmap::Clear(void)
{
	m_BmpInfo.Clear();
	m_DibHf.Clear();
	ClearBitmapArray();
}

///**
//*description   :
//*@param input  : const size_t& size (할당 받을 배열의 크기)
//*@param output : 
//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
//*/
bool CUserBitmap::InitializeBitmapArray(const size_t& size)
{
	if (size <= 0)
	{
		return false;
	}

	ClearBitmapArray();

	m_pUcBmpImage = new unsigned char[(size_t)size];

	if (m_pUcBmpImage == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
}


//**
//*description   : 
//*@param output  : unsigned char*	pUcBmpImage
//*@param output  : BITMAPINFO*		pBmpInfo
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
const bool  CUserBitmap::GetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) const
{
	if (m_pUcBmpImage == NULL)
	{
		return false;
	}

	if (pBmpInfo == NULL)
	{
		return false;
	}

	if (m_pUcBmpImage == NULL)
	{
		return false;
	}

	if (m_BmpInfo.GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (m_BmpInfo.GetBitmapInfo(pBmpInfo) == false)
	{
		return false;
	}

	memcpy(pUcBmpImage, m_pUcBmpImage, (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

	return true;
}

///**
//*description   :  
//*@param output  : unsigned char*		pUcBmpImage
//*@param output  : BITMAPINFOHEADER*	pDibHi
//*@param output  : BITMAPFILEHEADER*	pDibHf
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
const bool  CUserBitmap::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const
{
	if (pUcBmpImage == NULL)
	{
		return false;
	}

	if (pDibHi == NULL)
	{
		return false;
	}

	if (pDibHf == NULL)
	{
		return false;
	}

	if (m_pUcBmpImage == NULL)
	{
		return false;
	}

	if (m_BmpInfo.GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (m_BmpInfo.GetBimapInfoHeader() == NULL)
	{
		return false;
	}

	if (m_DibHf.GetBitmapFileHeader() == NULL)
	{

		return false;
	}

	if (m_BmpInfo.GetBimapInfoHeader(*pDibHi) == false)
	{
		return false;
	}

	if (m_DibHf.GetBitmapFileHeader(*pDibHf) == false)
	{
		return false;
	}

	memcpy(pUcBmpImage, m_pUcBmpImage, (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

	return true;
}


///**
//*description   : 
//*@param input  : unsigned char*	pUcBmpImage
//*@param input  : BITMAPINFO*		pBmpInfo
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CUserBitmap::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo)
{
	if (pUcBmpImage == NULL)
	{
		return false;
	}

	if (pBmpInfo == NULL)
	{
		return false;
	}

	if (m_BmpInfo.Set(pBmpInfo) == false)
	{
		return false;
	}

	if (InitializeBitmapArray((GetRwSize() * GetMaximumHeight())) == false)
	{
		return false;
	}

	m_DibHf.Initialize();

	memcpy(m_pUcBmpImage, pUcBmpImage, (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

	return true;
}

///**
//*description   :  
//*@param input  : unsigned char*		pUcBmpImage
//*@param input  : BITMAPINFOHEADER*	pDibHi
//*@param input  : BITMAPFILEHEADER*	pDibHf
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CUserBitmap::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf)
{
	if (pUcBmpImage == NULL)
	{
		return false;
	}

	if (pDibHi == NULL)
	{
		return false;
	}

	if (pDibHf == NULL)
	{
		return false;
	}

	if (m_BmpInfo.Set(pDibHi) == false)
	{
		return false;
	}

	if (m_DibHf.Set(pDibHf) == false)
	{
		return false;
	}

	if (InitializeBitmapArray((GetRwSize() * GetMaximumHeight())) == false)
	{
		return false;
	}

	memcpy(m_pUcBmpImage, pUcBmpImage, (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

	return true;
}

///**
//*description   :  
//*@param input  : const CBitmapNode& rhs
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool  CUserBitmap::SetImage(const CUserBitmap& rhs)
{
	if (this == &rhs)
	{
		return false;
	}

	if (SetImage(rhs.c_arr(), rhs.GetBitmapInfo(), rhs.GetBimapFileHeader()) == false)
	{
		return false;
	}

	return true;
}

#else //_NOT_APPLYED_VECTOR_DATA_	

///**
//*description   : 비트맵 영상이 실제 저장되는 객체용 복사 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CUserBitmap::CUserBitmap(const CUserBitmap& rhs)
{
	m_pUcBmpImage = NULL;

	SetImage(rhs);

}

///**
//*description   : 비트맵 영상이 실제 저장되는 객체용 대입 연산자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CUserBitmap& CUserBitmap::operator=(const CUserBitmap& rhs)
{
	if (this != &rhs)
	{
		SetImage(rhs);
	}

	return *this;
}

///**
//*description   : 객체 메모리 해제 및 내용 비우기
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CUserBitmap::Clear(void)
{
	m_BmpInfo.Clear();
	m_DibHf.Clear();
	m_vecBmpImage.clear();
}

//*description   : c 형태의 배열로 되돌리기
//*@param input  :   
//*@return		 : c 형태의 배열 주소
//*/
unsigned char* CUserBitmap::c_arr() 
{
	m_pUcBmpImage = NULL;
	m_pUcBmpImage = m_vecBmpImage.data();
	return m_pUcBmpImage;
}

///**
//*description   : 
//*@param output  : unsigned char*	pUcBmpImage
//*@param output  : BITMAPINFO*		pBmpInfo
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
const bool  CUserBitmap::GetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) const
{
	if (m_vecBmpImage.empty() == true)
	{
		return false;
	}

	if (pBmpInfo == NULL)
	{
		return false;
	}

	if (m_pUcBmpImage == NULL)
	{
		return false;
	}

	if (m_BmpInfo.GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (m_BmpInfo.GetBitmapInfo(pBmpInfo) == false)
	{
		return false;
	}

	memcpy(pUcBmpImage, m_vecBmpImage.data(), (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

	return true;
}

///**
//*description   :  
//*@param output  : unsigned char*		pUcBmpImage
//*@param output  : BITMAPINFOHEADER*	pDibHi
//*@param output  : BITMAPFILEHEADER*	pDibHf
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
const bool  CUserBitmap::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const
{
	if (m_vecBmpImage.empty() == true)
	{
		return false;
	}

	if (pDibHi == NULL)
	{
		return false;
	}

	if (pDibHf == NULL)
	{
		return false;
	}

	if (m_pUcBmpImage == NULL)
	{
		return false;
	}

	if (m_BmpInfo.GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (m_BmpInfo.GetBimapInfoHeader() == NULL)
	{
		return false;
	}

	if (m_DibHf.GetBitmapFileHeader() == NULL)
	{

		return false;
	}

	if (m_BmpInfo.GetBimapInfoHeader(pDibHi) == false)
	{
		return false;
	}

	if (m_DibHf.GetBitmapFileHeader(pDibHf) == false)
	{
		return false;
	}

	memcpy(pUcBmpImage, m_vecBmpImage.data(), (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

	return true;
}

///**
//*description   : 
//*@param input  : unsigned char*	pUcBmpImage
//*@param input  : BITMAPINFO*		pBmpInfo
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CUserBitmap::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo)
{
	if (pUcBmpImage == NULL)
	{
		return false;
	}

	if (pBmpInfo == NULL)
	{
		return false;
	}

	if (m_BmpInfo.Set(pBmpInfo) == false)
	{
		return false;
	}

	PushBitmapImageVector(pUcBmpImage, (GetRwSize() * GetMaximumHeight()));

	m_DibHf.Initialize();

	return true;
}

///**
//*description   :  
//*@param input  : unsigned char*		pUcBmpImage
//*@param input  : BITMAPINFOHEADER*	pDibHi
//*@param input  : BITMAPFILEHEADER*	pDibHf
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CUserBitmap::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf)
{
	if (pUcBmpImage == NULL)
	{
		return false;
	}

	if (pDibHi == NULL)
	{
		return false;
	}

	if (pDibHf == NULL)
	{
		return false;
	}

	if (m_BmpInfo.Set(pDibHi) == false)
	{
		return false;
	}

	if (m_DibHf.Set(pDibHf) == false)
	{
		return false;
	}

	PushBitmapImageVector(pUcBmpImage, (GetRwSize() * GetMaximumHeight()));

	return true;
}

///**
//*description   :  
//*@param input  : const CBitmapNode& rhs
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool  CUserBitmap::SetImage(const CUserBitmap& rhs)
{
	if (this == &rhs)
	{
		return false;
	}

	if (rhs.GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (rhs.GetBimapFileHeader() == NULL)
	{
		return false;
	}

	if (m_BmpInfo.Set(rhs.GetBitmapInfo()) == false)
	{
		return false;
	}

	if (m_DibHf.Set(rhs.GetBimapFileHeader()) == false)
	{
		return false;
	}

	PushBitmapImageVector(rhs.c_arr_const(), (GetRwSize() * GetMaximumHeight()));

	return true;
}

#endif //_NOT_APPLYED_VEDCTOR_DATA_	
