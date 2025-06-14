/////** 
////*description   : 비트맵 영상이 실제 저장되는 객체 정의 헤더파일
////*               
////* 
////*/
#ifndef _BITMAPFILEHEADER_H_
#define _BITMAPFILEHEADER_H_
#pragma once

#ifndef _BASICBONE_H_
#include "basicbone.h"
#endif //_BASICBONE_H_

#ifndef _USERMACHRO_H_
#include "UserMachro.h"
#endif //_USERMACHRO_H_


/////** 
////*description   :  
////*@parent class : -
////*/
class CBitmapFileHeader :   private CBasicBone
{
//// 멤버 변수 정의 부분
public:

protected:
	
	BITMAPFILEHEADER* m_pDibHf;			// 비트맵 파일 헤더 정보

private:

//// 멤버 함수 정의 부분
public:

	///**
	//*description   : CBasicBone 클래스용 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapFileHeader(void);

	///**
	//*description   : CBasicBone 클래스용 소멸자           
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	~CBitmapFileHeader(void);

	///**
	//*description   : 실제 저장되는 객체 용 복사 생성자 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapFileHeader(const CBitmapFileHeader& rhs);

	///**
	//*description   : 실제 저장되는 객체 용 복사 생성자 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapFileHeader(const BITMAPFILEHEADER& rhs);

	///**
	//*description   : 이동 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapFileHeader(CBitmapFileHeader&& rhs) noexcept;

	///**
	//*description   : 이동 대입 연산자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapFileHeader& operator=(CBitmapFileHeader&& rhs) noexcept;

	///**
	//*description   :실제 저장되는 객체 용 대입 연산자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapFileHeader& operator=(const CBitmapFileHeader& rhs);

	///**
	//*description   : 실제 저장되는 객체 용 복사 생성자 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapFileHeader& operator=(const BITMAPFILEHEADER& rhs);

	///**
	//*description   : 동일한지 여부 연산자 재정의
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const bool isEqual(const CBitmapFileHeader& rhs) const;

	///**
	//*description   : 동일한지 여부 연산자 재정의
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const bool isEqual(const BITMAPFILEHEADER& rhs) const;

	///**
	//*description   : 동일한지 여부 연산자 재정의
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const bool operator==(const CBitmapFileHeader& rhs) const { return isEqual(rhs); }

	///**
	//*description   : 동일한지 여부 연산자 재정의
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const bool operator==(const BITMAPFILEHEADER& rhs) const { return isEqual(rhs); }

	///**
	//*description   : 다른지 여부 연산자 재정의
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline const bool operator!=(const CBitmapFileHeader& rhs) const { return !(isEqual(rhs)); }

	///**
	//*description   : 다른지 여부 연산자 재정의
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline const bool operator!=(const BITMAPFILEHEADER& rhs) const { return !(isEqual(rhs)); }

	///**
	//*description   : 객체 메모리 해제 및 내용 비우기
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline void Clear(void) { if (m_pDibHf != NULL) { delete m_pDibHf; m_pDibHf = NULL; } }

	///**
	//*description   : 메모리 할당
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool Initialize(void);

	///**
	//*description   :  
	//*@param input  : const BITMAPFILEHEADER& rhs
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	inline bool Set(const BITMAPFILEHEADER& rhs) { return Set(&rhs); }

	///**
	//*description   :  
	//*@param input  : const CBitmapFileHeader& rhs
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	inline bool Set(const CBitmapFileHeader& rhs) { return Set(&rhs); }

	///**
	//*description   :  
	//*@param input  : const BITMAPFILEHEADER* pDibHf
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	bool Set(const BITMAPFILEHEADER* pDibHf);

	///**
	//*description   :  
	//*@param input  : const CBitmapFileHeader* pBmpFileHead
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	bool Set(const CBitmapFileHeader* pBmpFileHead);

	///**
	//*description   : 
	//*@param input  : -
	//*@return		 : 
	//*/
	inline const BITMAPFILEHEADER* GetBitmapFileHeader(void) const { return  (m_pDibHf != NULL) ? m_pDibHf : NULL; }

	///**
	//*description   : 
	//*@param input  : -
	//*@return		 : 
	//*/
	bool GetBitmapFileHeader(BITMAPFILEHEADER* pDibHf) const;

	///**
	//*description   : 
	//*@param input  : -
	//*@return		 : 
	//*/
	inline bool GetBitmapFileHeader(BITMAPFILEHEADER& dibHf) const { return GetBitmapFileHeader(&dibHf); }

	///**
	//*description   : 
	//*@param input  : -
	//*@return		 : 
	//*/
	inline const CBitmapFileHeader* Get(void) const { return (m_pDibHf != NULL) ?  this : NULL; }

protected:

private:

};

#endif //_BITMAPFILEHEADER_H_
