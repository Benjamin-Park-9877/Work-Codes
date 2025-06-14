#include "pch.h"
#include "BitmapFileHeader.h"

///**
//*description   : CBasicBone 클래스용 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapFileHeader::CBitmapFileHeader(void) 
{
	m_pDibHf = NULL;
}

///**
//*description   : CBasicBone 클래스용 소멸자           
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapFileHeader::~CBitmapFileHeader(void)
{
	Clear();
}

///**
//*description   : 실제 저장되는 객체 용 복사 생성자 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapFileHeader::CBitmapFileHeader(const CBitmapFileHeader& rhs)
{
	m_pDibHf = NULL;
	Set(rhs);
}

///**
//*description   : 실제 저장되는 객체 용 복사 생성자 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapFileHeader::CBitmapFileHeader(const BITMAPFILEHEADER& rhs)
{
	m_pDibHf = NULL;
	Set(rhs);
}

///**
//*description   : 이동 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapFileHeader::CBitmapFileHeader(CBitmapFileHeader&& rhs) noexcept
{
	m_pDibHf = NULL;
	m_pDibHf = rhs.m_pDibHf;
	rhs.m_pDibHf = NULL;
}

///**
//*description   : 이동 대입 연산자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapFileHeader& CBitmapFileHeader::operator=(CBitmapFileHeader&& rhs) noexcept
{
	if (this != &rhs)
	{
		m_pDibHf = rhs.m_pDibHf;
		rhs.m_pDibHf = NULL;
	}
	return *this;
}

///**
//*description   :실제 저장되는 객체 용 대입 연산자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapFileHeader& CBitmapFileHeader::operator=(const CBitmapFileHeader& rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	Set(rhs);

	return *this;
}

///**
//*description   : 실제 저장되는 객체 용 복사 생성자 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapFileHeader& CBitmapFileHeader::operator=(const BITMAPFILEHEADER& rhs)
{
	if (this->m_pDibHf == &rhs)
	{
		return *this;
	}

	Set(rhs);

	return *this;
}

///**
//*description   : 동일한지 여부 연산자 재정의
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
const bool CBitmapFileHeader::isEqual(const CBitmapFileHeader& rhs) const
{
	if (rhs.GetBitmapFileHeader() == NULL)
	{
		return false;
	}

	if (m_pDibHf == NULL)
	{
		return false;
	}

	if (isEqual( *rhs.GetBitmapFileHeader() ) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

///**
//*description   : 동일한지 여부 연산자 재정의
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
const bool CBitmapFileHeader::isEqual(const BITMAPFILEHEADER& rhs) const
{
	if (m_pDibHf == NULL)
	{
		return false;
	}

	if (m_pDibHf != &rhs)
	{
		return false;
	}

	return true;
}

///**
//*description   : 메모리 할당
//*@param input  : -
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapFileHeader::Initialize(void)
{
	Clear();

	m_pDibHf = new BITMAPFILEHEADER;

	if (m_pDibHf == NULL)
	{
		return false;
	}

	memset(m_pDibHf, 0, sizeof(BITMAPFILEHEADER));

	return true;
}

///**
//*description   :  
//*@param input  : const BITMAPFILEHEADER* pDibHf
//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
//*/
bool CBitmapFileHeader::Set(const BITMAPFILEHEADER* pDibHf)
{
	if (pDibHf == NULL)
	{
		return false;
	}

	if (Initialize() == false)
	{
		return false;
	}

	if (m_pDibHf == NULL)
	{
		return false;
	}

	memcpy(m_pDibHf, pDibHf, sizeof(BITMAPFILEHEADER));

	return true;
}

///**
//*description   :  
//*@param input  : const CBitmapFileHeader* pDibHf
//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
//*/
bool CBitmapFileHeader::Set(const CBitmapFileHeader* pBmpFileHead)
{
	if (pBmpFileHead == NULL)
	{
		return false;
	}

	if (this == pBmpFileHead)
	{
		return false;
	}

	if (Initialize() == false)
	{
		return false;
	}

	if (m_pDibHf == NULL)
	{
		return false;
	}

	memcpy(m_pDibHf, pBmpFileHead->m_pDibHf, sizeof(BITMAPFILEHEADER));

	return true;
}
///**
//*description   : 
//*@param input  : -
//*@return		 : 
//*/
bool CBitmapFileHeader::GetBitmapFileHeader(BITMAPFILEHEADER* pDibHf) const
{
	if (m_pDibHf == NULL)
	{
		return false;
	}

	if (pDibHf == NULL)
	{
		return false;
	}

	memcpy(pDibHf, m_pDibHf, sizeof(BITMAPFILEHEADER));

	return true;
}
