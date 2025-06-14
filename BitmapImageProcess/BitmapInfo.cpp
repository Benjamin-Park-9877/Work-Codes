#include "pch.h"
#include "BitmapInfo.h"

///**
//*description   : 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapInfo::CBitmapInfo(void)
{
	m_pBmpInfo = NULL;
}

///**
//*description   : 소멸자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapInfo::~CBitmapInfo(void)
{
	Clear();
}

///**
//*description   : 실제 저장되는 객체 용 복사 생성자 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapInfo::CBitmapInfo(const CBitmapInfo& rhs)
{
	m_pBmpInfo = NULL;
	Set(&rhs);
}

///**
//*description   : 실제 저장되는 객체 용 복사 생성자 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapInfo::CBitmapInfo(const BITMAPINFO& rhs)
{
	m_pBmpInfo = NULL;
	Set(&rhs);
}

///**
//*description   : 실제 저장되는 객체 용 복사 생성자 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapInfo::CBitmapInfo(const BITMAPINFOHEADER& rhs)
{
	m_pBmpInfo = NULL;
	Set(&rhs);
}

///**
//*description   : 이동 생성자 정의
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapInfo::CBitmapInfo(CBitmapInfo&& rhs) noexcept
{
	m_pBmpInfo = NULL;
	m_pBmpInfo = rhs.m_pBmpInfo;
	rhs.m_pBmpInfo = NULL;
}

///**
//*description   : 이동 대입 연산자 정의
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapInfo& CBitmapInfo::operator=(CBitmapInfo&& rhs) noexcept
{
	if (this != &rhs)
	{
		m_pBmpInfo = rhs.m_pBmpInfo;
		rhs.m_pBmpInfo = NULL;
	}
	return *this;
}

///**
//*description   :실제 저장되는 객체 용 대입 연산자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapInfo& CBitmapInfo::operator=(const CBitmapInfo& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	Set(&rhs);

	return *this;
}

///**
//*description   : 실제 저장되는 객체 용 복사 생성자 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapInfo& CBitmapInfo::operator=(const BITMAPINFO& rhs)
{
	if ( this->isEqual(rhs) == true )
	{
		return *this;
	}

	Set(&rhs);

	return *this;
}

///**
//*description   : 실제 저장되는 객체 용 복사 생성자 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapInfo& CBitmapInfo::operator=( BITMAPINFOHEADER& rhs)
{
	if ( this->isEqual(rhs) == true )
	{
		return *this;
	}

	Set(&rhs);

	return *this;
}

///**
//*description   : 동일한지 여부 확인
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
const bool CBitmapInfo::isEqual(const CBitmapInfo& rhs) const
{
	if (rhs.GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (rhs.GetBimapInfoHeader() == NULL)
	{
		return false;
	}

	if (m_pBmpInfo == NULL)
	{
		return false;
	}

	if (&(m_pBmpInfo->bmiHeader) == NULL)
	{
		return false;
	}

	if (isEqual(*rhs.GetBitmapInfo()) == false)
	{
		return false;
	}

	if (*this == rhs)
	{
		return false;
	}

	return true;
}

///**
//*description   : 
//*@param input  : -
//*@param output : -
//*@return		 : 
//*/
bool CBitmapInfo::GetBitmapInfo(BITMAPINFO* rhs) const
{
	if (m_pBmpInfo == NULL)
	{
		return false;
	}

	if (rhs == NULL)
	{
		return false;
	}

	memcpy(rhs, m_pBmpInfo, DEFALUT_BITMAPINFO_HEADERSIZE);

	return true;
}

///**
//*description   :  
//*@param input  :   
//*@return		 : 
//*/
bool CBitmapInfo::GetBimapInfoHeader(BITMAPINFOHEADER* rhs) const
{
	if (m_pBmpInfo == NULL)
	{
		return false;
	}

	if (&(m_pBmpInfo->bmiHeader) == NULL)
	{
		return false;
	}

	if (rhs == NULL)
	{
		return false;
	}

	memcpy(rhs, &(m_pBmpInfo->bmiHeader), sizeof(BITMAPINFOHEADER));

	return true;
}

///**
//*description   : 동일한지 여부 확인
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
const bool CBitmapInfo::isEqual(const BITMAPINFO& rhs) const
{
	if (m_pBmpInfo == NULL) 
	{
		return false; 
	}

	if ( &(m_pBmpInfo->bmiHeader) == NULL) 
	{ 
		return false; 
	}

	if (isEqual(rhs) == false)
	{
		return false;
	}

	if (m_pBmpInfo != &rhs) 
	{ 
		return false; 
	}

	return true;
}

///**
//*description   : 동일한지 여부 확인
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
const bool CBitmapInfo::isEqual(const BITMAPINFOHEADER& rhs) const
{
	if (m_pBmpInfo == NULL) 
	{ 
		return false; 
	}
	
	if ( &(m_pBmpInfo->bmiHeader) == NULL) 
	{ 
		return false; 
	}

	if (m_pBmpInfo->bmiHeader.biSize  != rhs.biSize) { return false; }
	if (m_pBmpInfo->bmiHeader.biWidth != rhs.biWidth) { return false; }
	if (m_pBmpInfo->bmiHeader.biHeight != rhs.biHeight) { return false; }
	if (m_pBmpInfo->bmiHeader.biPlanes != rhs.biPlanes) { return false; }
	if (m_pBmpInfo->bmiHeader.biBitCount != rhs.biBitCount) { return false; }
	if (m_pBmpInfo->bmiHeader.biCompression != rhs.biCompression) { return false; }
	if (m_pBmpInfo->bmiHeader.biSizeImage != rhs.biSizeImage) { return false; }
	if (m_pBmpInfo->bmiHeader.biXPelsPerMeter != rhs.biXPelsPerMeter) { return false; }
	if (m_pBmpInfo->bmiHeader.biYPelsPerMeter != rhs.biYPelsPerMeter) { return false; }
	if (m_pBmpInfo->bmiHeader.biClrUsed != rhs.biClrUsed) { return false; }
	if (m_pBmpInfo->bmiHeader.biClrImportant != rhs.biClrImportant) { return false; }

	return true;
}

///**
//*description   : 메모리 할당
//*@param input  : -
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapInfo::Initialize(void)
{
	Clear();

	m_pBmpInfo = (BITMAPINFO*)malloc(DEFALUT_BITMAPINFO_HEADERSIZE);

	if (m_pBmpInfo == NULL)
	{
		return false;
	}

	memset(m_pBmpInfo, 0, DEFALUT_BITMAPINFO_HEADERSIZE);

	for (int i = 0; i < MAXIMUM_PIXEL_VALUE; i++)
	{
		m_pBmpInfo->bmiColors[i].rgbRed = i;
		m_pBmpInfo->bmiColors[i].rgbGreen = i;
		m_pBmpInfo->bmiColors[i].rgbBlue = i;
		m_pBmpInfo->bmiColors[i].rgbReserved = 0;
	}

	return true;
}

///**
//*description   : BITMAPINFO 항목 설정(포인터로 받아온 경우)
//*@param input  : const CBitmapInfo* bmpInfo
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapInfo::Set(const CBitmapInfo* pBmpInfo)
{
	if (pBmpInfo == NULL)
	{
		return false;
	}

	if (this == pBmpInfo)
	{
		return false;
	}

	if (Initialize() == false)
	{
		return false;
	}

	if (m_pBmpInfo == NULL)
	{
		return false;
	}

	memcpy(m_pBmpInfo, pBmpInfo->m_pBmpInfo, DEFALUT_BITMAPINFO_HEADERSIZE);

	return true;
}

///**
//*description   : BITMAPINFO 항목 설정(포인터로 받아온 경우)
//*@param input  : const BITMAPINFO* bmpInfo
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapInfo::Set(const BITMAPINFO* pBmpInfo)
{
	if (pBmpInfo == NULL)
	{
		return false;
	}

	if (Initialize() == false)
	{
		return false;
	}

	if (m_pBmpInfo == NULL)
	{
		return false;
	}

	memcpy(m_pBmpInfo, pBmpInfo, sizeof(BITMAPINFO));

	return true;
}

///**
//*description   :  
//*@param input  : const BITMAPINFOHEADER* pBmpInfoHead
//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
//*/
bool CBitmapInfo::Set(const BITMAPINFOHEADER* pBmpInfoHead)
{
	if (pBmpInfoHead == NULL)
	{
		return false;
	}

	if (Initialize() == false)
	{
		return false;
	}

	if (m_pBmpInfo == NULL)
	{
		return false;
	}

	memcpy(&(m_pBmpInfo->bmiHeader), pBmpInfoHead, sizeof(BITMAPINFOHEADER));

	return true;
}