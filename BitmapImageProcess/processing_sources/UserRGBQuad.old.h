/////** 
////*description   : RGBQUAD 값 저장 객체 정의 헤더 파일 
////*               
////* 
////*/
#ifndef _USER_RGBQUAD_H_
#define _USER_RGBQUAD_H_
#pragma once

#include <wingdi.h>
#include <vcruntime_string.h>

#ifndef _BASICBONE_H_
#include "basicbone.h"
#endif //_BASICBONE_H_

#ifndef _USERMACHRO_H_
#include "UserMachro.h"
#endif //_USERMACHRO_H_

///** 
//*description   : RGBQUAD 값 저장 객체 
//*@parent class : private CBasicBone : 대입 연산자, 복사 생성자 호출 방지용
//*/
class CUserRGBQuad :private CBasicBone
{
//// 멤버 변수 정의 부분
public:
	RGBQUAD		m_PalRGB[MAXIMUM_PIXEL_VALUE];

private:

//// 멤버 함수 정의 부분
public:

	///**
	//*description   :  RGBQUAD 값 저장 객체용 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CUserRGBQuad(void);

	///**
	//*description   : RGBQUAD 값 저장 객체용 소멸자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	~CUserRGBQuad(void);

	///**
	//*description   :  RGBQUAD 값 저장 객체 초기화
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void Initialize(void);

	///**
	//*description   : c 형태의 배열로 되돌리기
	//*@param input  :   
	//*@return		 : c 형태의 배열 주소
	//*/
	RGBQUAD* c_arr(void) { return m_PalRGB; }

	///**
	//*description   : 첨자 연산자 재정의 ( L-value 방향 )
	//*@param input  : const size_t& nPos	: 위치
	//*@return		 : 해당 위치의 값
	//*/
	RGBQUAD& operator[](const size_t& nPos);

	///**
	//*description   : 첨자 연산자 재정의 const type ( R-value 방향 )
	//*@param input  : const size_t& nPos : 위치
	//*@return		 : 해당 위치의 값
	//*/
	const RGBQUAD& operator[](const size_t& nPos) const;

private:

};
#endif //_USER_RGBQUAD_H_