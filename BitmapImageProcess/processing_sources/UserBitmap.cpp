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

///**
//*description   : 비트맵 영상이 실제 저장되는 객체용 복사 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CUserBitmap::CUserBitmap(const CUserBitmap& rhs)
{
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
//*description   : 이동 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CUserBitmap::CUserBitmap(CUserBitmap&& rhs) noexcept
{
	m_BmpInfo = rhs.m_BmpInfo;			 
	m_DibHf = rhs.m_DibHf;
	m_vecBmpImage = rhs.m_vecBmpImage;
}

///**
//*description   : 이동 대입 연산자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CUserBitmap& CUserBitmap::operator=(CUserBitmap&& rhs) noexcept
{
	if (this != &rhs)
	{
		m_BmpInfo = rhs.m_BmpInfo;
		m_DibHf = rhs.m_DibHf;
		m_vecBmpImage = rhs.m_vecBmpImage;
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

	if (m_BmpInfo.GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (m_BmpInfo.GetBitmapInfo(pBmpInfo) == false)
	{
		return false;
	}

	memcpy(pUcBmpImage, c_arr_const(), (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

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

	memcpy(pUcBmpImage, c_arr_const(), (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

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
