/////** 
////*description   : RGBQUAD 값 저장 객체 정의 헤더 파일 
////*               
////* 
////*/
#ifndef _USER_RGBQUAD_H_
#define _USER_RGBQUAD_H_
#pragma once

#ifndef _BASICBONE_H_
#include "basicbone.h"
#endif //_BASICBONE_H_

#ifndef _USERMACHRO_H_
#include "UserMachro.h"
#endif //_USERMACHRO_H_

using namespace std;

///** 
//*description   : RGBQUAD 값 저장 객체 
//*@parent class : private CBasicBone : 대입 연산자, 복사 생성자 호출 방지용
//*/
class CUserRGBQuad :private CBasicBone
{
//// 멤버 변수 정의 부분
public:

protected:
	//RGBQUAD		m_PalRGB[MAXIMUM_PIXEL_VALUE];
	vector<RGBQUAD>		m_vecPalRGB;

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
	//*description   : RGBQUAD 값이 비었는지 확인하는 함수
	//*@param input  : -
	//*@param output : -
	//*@return		 : 비어있는지 여부 확인 값 ( true : 비어있음, false : 뭔가 있음 )
	//*/
	inline bool IsEmpty(void) { return m_vecPalRGB.empty(); }

	///**
	//*description   :  RGBQUAD 값 저장 객체 초기화
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void Initialize(void);

	///**
	//*description   : 객체 메모리 해제 및 내용 비우기
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline void Clear(void) { m_vecPalRGB.clear(); }

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

	///**
	//*description   : RGBQUAD 값 할당하기
	//*@param input  : LPSTR* pDIB
	//*@param output : -
	//*@return		 : 정상 실행 여부(true : 정상 실행, false : 문제 발생)
	//*/
	bool Set(LPSTR pDIB);

	///**
	//*description   : RGBQUAD 값 할당하기
	//*@param input  : const CUserRGBQuad& rhs
	//*@param output : -
	//*@return		 : 정상 실행 여부(true : 정상 실행, false : 문제 발생)
	//*/
	bool Set(const CUserRGBQuad& rhs);

	///**
	//*description   : RGBQUAD 값 받아오기(함수 인자등으로 쓰는 경우)
	//*@param input  :   
	//*@return		 : c 형태의 배열 주소
	//*/
	inline RGBQUAD* Get(void) { return m_vecPalRGB.data(); }

	///**
	//*description   : RGBQUAD 값 받아오기(함수 인자등으로 쓰는 경우)
	//*@param input  : - 
	//*@param output : CUserRGBQuad& rhs
	//*@return		 : 정상 실행 여부(true : 정상 실행, false : 문제 발생)
	//*/
	bool Get(CUserRGBQuad& rhs);

	///**
	//*description   : RGBQUAD 값 받아오기
	//*@param input  : LPSTR* pDIB
	//*@param output : -
	//*@return		 : 정상 실행 여부(true : 정상 실행, false : 문제 발생)
	//*/
	bool Get(LPSTR pDIB);

private:

};
#endif //_USER_RGBQUAD_H_