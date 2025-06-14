/////** 
////*description   : RGBQUAD 값 저장 객체 정의 소스 파일 
////*               
////* 
////*/
#include "pch.h"
#include "UserRGBQuad.h"

///**
//*description   :  RGBQUAD 값 저장 객체용 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CUserRGBQuad::CUserRGBQuad(void)
{
	Initialize();
}

///**
//*description   : RGBQUAD 값 저장 객체용 소멸자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CUserRGBQuad::~CUserRGBQuad(void)
{
	Clear();
}

///**
//*description   :  RGBQUAD 값 저장 객체 초기화
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CUserRGBQuad::Initialize(void)
{
	Clear();

	RGBQUAD rgbElement;
	memset(&rgbElement, 0, sizeof(RGBQUAD));

	for(int i=0; i<MAXIMUM_PIXEL_VALUE; i++) 
	{
		rgbElement.rgbBlue		= i;
		rgbElement.rgbGreen		= i;
		rgbElement.rgbRed	    = i;
		rgbElement.rgbReserved	= 0;

		m_vecPalRGB.push_back(rgbElement);
	}
}

///**
//*description   : RGBQUAD 값 할당하기
//*@param input  : LPSTR pDIB
//*@param output : -
//*@return		 : 정상 실행 여부(true : 정상 실행, false : 문제 발생)
//*/
bool CUserRGBQuad::Set(LPSTR pDIB)
{
	if (pDIB == NULL)
	{
		return false;
	}
	
	Clear();

	memcpy(m_vecPalRGB.data(), pDIB, sizeof(RGBQUAD) * MAXIMUM_PIXEL_VALUE);

	return true;
}

///**
//*description   : RGBQUAD 값 할당하기
//*@param input  : const CUserRGBQuad& rhs
//*@param output : -
//*@return		 : 정상 실행 여부(true : 정상 실행, false : 문제 발생)
//*/
bool CUserRGBQuad::Set(const CUserRGBQuad& rhs)
{
	if (this == &rhs)
	{
		return false;
	}

	if (rhs.m_vecPalRGB.empty() == true)
	{
		return false;
	}

	Clear();

	for (int i = 0; i < MAXIMUM_PIXEL_VALUE; i++)
	{
		m_vecPalRGB.push_back(rhs.m_vecPalRGB[i]);
	}

	return true;
}

///**
//*description   : RGBQUAD 값 받아오기(함수 인자등으로 쓰는 경우)
//*@param input  : - 
//*@param output : CUserRGBQuad& rhs
//*@return		 : 정상 실행 여부(true : 정상 실행, false : 문제 발생)
//*/
bool CUserRGBQuad::Get(CUserRGBQuad& rhs)
{
	if (this == &rhs)
	{
		return false;
	}

	if (m_vecPalRGB.empty() == true)
	{
		return false;
	}

	rhs.Clear();

	for (int i = 0; i < MAXIMUM_PIXEL_VALUE; i++)
	{
		rhs.m_vecPalRGB.push_back(m_vecPalRGB[i]);
	}

	return true;
}

///**
//*description   : RGBQUAD 값 받아오기
//*@param input  : LPSTR pDIB
//*@param output : -
//*@return		 : 정상 실행 여부(true : 정상 실행, false : 문제 발생)
//*/
bool  CUserRGBQuad::Get(LPSTR pDIB)
{
	if (pDIB == NULL)
	{
		return false;
	}

	memcpy(pDIB, m_vecPalRGB.data(), sizeof(RGBQUAD) * MAXIMUM_PIXEL_VALUE);

	return true;
}


///**
//*description   : 첨자 연산자 재정의 ( L-value 방향 )
//*@param input  : const size_t& nPos	: 위치
//*@return		 : 해당 위치의 값
//*/
RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos) 
{ 
	if (nPos <= 0)
	{
		return m_vecPalRGB[0];
	}

	if (nPos >= m_vecPalRGB.size() )
	{
		return m_vecPalRGB[(m_vecPalRGB.size() - 1)];
	}

	return m_vecPalRGB[nPos];
}

///**
//*description   : 첨자 연산자 재정의 const type ( R-value 방향 )
//*@param input  : const size_t& nPos : 위치
//*@return		 : 해당 위치의 값
//*/
const RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos) const
{
	if (nPos <= 0)
	{
		return m_vecPalRGB[0];
	}

	if (nPos >= m_vecPalRGB.size())
	{
		return m_vecPalRGB[(m_vecPalRGB.size() - 1)];
	}

	return m_vecPalRGB[nPos];
}