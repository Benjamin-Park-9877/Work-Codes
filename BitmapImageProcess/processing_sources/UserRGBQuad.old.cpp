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
#ifdef DEBUG
	TRACE("CUserRGBQuad::CUserRGBQuad(void)  \n");
#endif //DEBUG

	Initialize();

#ifdef DEBUG
	TRACE("CUserRGBQuad::CUserRGBQuad(void)  \n");
#endif //DEBUG
}

///**
//*description   : RGBQUAD 값 저장 객체용 소멸자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CUserRGBQuad::~CUserRGBQuad(void)
{
#ifdef DEBUG
	TRACE("CUserRGBQuad::~CUserRGBQuad(void)  \n");
#endif //DEBUG


#ifdef DEBUG
	TRACE("CUserRGBQuad::~CUserRGBQuad(void)  \n");
#endif //DEBUG
}

///**
//*description   :  RGBQUAD 값 저장 객체 초기화
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CUserRGBQuad::Initialize(void)
{
#ifdef DEBUG
	TRACE("void CUserRGBQuad::Initialize(void)  \n");
#endif //DEBUG

	memset(m_PalRGB,0,MAXIMUM_PIXEL_VALUE*sizeof(RGBQUAD));

	for(int i=0; i<MAXIMUM_PIXEL_VALUE; i++) 
	{
		m_PalRGB[i].rgbBlue     = i;
		m_PalRGB[i].rgbGreen    = i;
		m_PalRGB[i].rgbRed	    = i;
		m_PalRGB[i].rgbReserved = 0;
	}

#ifdef DEBUG
	TRACE("void CUserRGBQuad::Initialize(void)  \n");
#endif //DEBUG
}

///**
//*description   : 첨자 연산자 재정의 ( L-value 방향 )
//*@param input  : const size_t& nPos	: 위치
//*@return		 : 해당 위치의 값
//*/
RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos) 
{ 
#ifdef DEBUG
	TRACE("RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos)  \n");
#endif //DEBUG

	if (nPos <= 0)
	{
#ifdef DEBUG
		TRACE("if (nPos <= 0) at RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos)  \n");
#endif //DEBUG
		return m_PalRGB[0];
	}

	if (nPos >= MAXIMUM_PIXEL_VALUE)
	{
#ifdef DEBUG
		TRACE("if (nPos >= MAXIMUM_PIXEL_VALUE) at RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos)  \n");
#endif //DEBUG
		return m_PalRGB[(MAXIMUM_PIXEL_VALUE-1)];
	}

#ifdef DEBUG
	TRACE("RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos)  \n");
#endif //DEBUG
	return m_PalRGB[nPos]; 
}

///**
//*description   : 첨자 연산자 재정의 const type ( R-value 방향 )
//*@param input  : const size_t& nPos : 위치
//*@return		 : 해당 위치의 값
//*/
const RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos) const
{
#ifdef DEBUG
	TRACE("const RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos) const  \n");
#endif //DEBUG

	if (nPos <= 0)
	{
#ifdef DEBUG
		TRACE("if (nPos <= 0) at const RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos) const  \n");
#endif //DEBUG
		return m_PalRGB[0];
	}

	if (nPos >= MAXIMUM_PIXEL_VALUE)
	{
#ifdef DEBUG
		TRACE("if (nPos >= MAXIMUM_PIXEL_VALUE) at const RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos) const  \n");
#endif //DEBUG
		return m_PalRGB[(MAXIMUM_PIXEL_VALUE - 1)];
	}

#ifdef DEBUG
	TRACE("const RGBQUAD& CUserRGBQuad::operator[](const size_t& nPos) const  \n");
#endif //DEBUG
	return m_PalRGB[nPos];
}