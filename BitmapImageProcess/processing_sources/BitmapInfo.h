/////** 
////*description   : 비트맵 영상이 실제 저장되는 객체 정의 헤더파일
////*               
////* 
////*/
#ifndef _BITMAPINFO_H_
#define _BITMAPINFO_H_
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
class CBitmapInfo :  private CBasicBone
{
//// 멤버 변수 정의 부분
public:

protected:
	BITMAPINFO* m_pBmpInfo;			// 비트맵 이미지 화면 출력용 헤더 정보 

private:

//// 멤버 함수 정의 부분
public:

	///**
	//*description   : 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapInfo(void);

	///**
	//*description   : 소멸자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	~CBitmapInfo(void);

	///**
	//*description   : 실제 저장되는 객체 용 복사 생성자 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapInfo(const CBitmapInfo& rhs);

	///**
	//*description   : 실제 저장되는 객체 용 복사 생성자 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapInfo(const BITMAPINFO& rhs);

	///**
	//*description   : 실제 저장되는 객체 용 복사 생성자 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapInfo(const BITMAPINFOHEADER& rhs);

	///**
	//*description   : 이동 생성자 정의
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapInfo( CBitmapInfo&& rhs ) noexcept;

	///**
	//*description   : 이동 대입 연산자 정의
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapInfo& operator=( CBitmapInfo&& rhs) noexcept;

	///**
	//*description   :실제 저장되는 객체 용 대입 연산자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapInfo& operator=(const CBitmapInfo& rhs);

	///**
	//*description   : 실제 저장되는 객체 용 복사 생성자 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapInfo& operator=(const BITMAPINFO& rhs);

	///**
	//*description   : 실제 저장되는 객체 용 복사 생성자 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapInfo& operator=( BITMAPINFOHEADER& rhs);

	///**
	//*description   : 동일한지 여부 확인
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline const bool operator==(const CBitmapInfo& rhs) const { return isEqual(rhs);}

	///**
	//*description   : 다른지 여부 확인
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline const bool operator!=(const CBitmapInfo& rhs) const { return !(isEqual(rhs)); }

	///**
	//*description   : 동일한지 여부 확인
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const bool operator==(const BITMAPINFO& rhs) const { return isEqual(rhs); }

	///**
	//*description   : 다른지 여부 확인
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline const bool operator!=(const BITMAPINFO& rhs) const { return !(isEqual(rhs)); }

	///**
	//*description   : 동일한지 여부 확인
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const bool operator==( const BITMAPINFOHEADER& rhs) const { return isEqual(rhs); }

	///**
	//*description   : 다른지 여부 확인
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline const bool operator!=(const BITMAPINFOHEADER& rhs) const { return !(isEqual(rhs)); }

	///**
	//*description   : 동일한지 여부 확인
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const bool isEqual(const CBitmapInfo& rhs) const;

	///**
	//*description   : 동일한지 여부 확인
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const bool isEqual(const BITMAPINFO& rhs) const;

	///**
	//*description   : 동일한지 여부 확인
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const bool isEqual( const BITMAPINFOHEADER& rhs) const;

	///**
	//*description   : 객체 메모리 해제 및 내용 비우기
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline void Clear(void) { if (m_pBmpInfo != NULL) { free(m_pBmpInfo); m_pBmpInfo = NULL; } }

	///**
	//*description   : BITMAPINFO 항목 받아옴 (R-Value용)
	//*@param input  : -
	//*@param output : -
	//*@return		 : BITMAPINFO 포인터
	//*/
	inline BITMAPINFO* GetBitmapInfo(void) const { return ((m_pBmpInfo != NULL) ? m_pBmpInfo : NULL); }

	///**
	//*description   :  
	//*@param input  : -
	//*@param output : -
	//*@return		 : 
	//*/
	inline bool GetBitmapInfo(BITMAPINFO& rhs) const { return  GetBitmapInfo(&rhs); }

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : 
    //*/
	bool GetBitmapInfo(BITMAPINFO* rhs) const;

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 : const BITMAPINFOHEADER*
	//*/
	inline BITMAPINFOHEADER* GetBimapInfoHeader(void) const { return ((m_pBmpInfo != NULL) ? &(m_pBmpInfo->bmiHeader) : NULL); }

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 : 
	//*/
	inline bool GetBimapInfoHeader(BITMAPINFOHEADER& rhs) const { return GetBimapInfoHeader(&rhs); }

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 : 
	//*/
	bool GetBimapInfoHeader(BITMAPINFOHEADER* rhs) const;

	///**
	//*description   : 이미지 폭을 받아온다.
	//*@param input  : -
	//*@return		 : 이미지 폭
	//*/
	inline const unsigned long GetMaximumWidth(void) const { return (((m_pBmpInfo != NULL)) ? (m_pBmpInfo->bmiHeader.biWidth) : INVALID_IMAGE_SIZE); }

	///**
	//*description   : 이미지 높이를 받아온다.
	//*@param input  : -
	//*@return		 : 이미지 높이
	//*/
	inline const unsigned long GetMaximumHeight(void) const { return (((m_pBmpInfo != NULL)) ? (m_pBmpInfo->bmiHeader.biHeight) : INVALID_IMAGE_SIZE); }

	///**
	//*description   : 이미지 실제 픽셀 폭을 계산한다.
	//*@param input  : -
	//*@return		 : 이미지 실제 픽셀 폭
	//*/
	inline const unsigned long GetRwSize(void) const { return (((m_pBmpInfo != NULL)) ? (WIDTHBYTES((m_pBmpInfo->bmiHeader.biBitCount * m_pBmpInfo->bmiHeader.biWidth))) : INVALID_IMAGE_SIZE); }

	///**
	//*description   : 색상 비트 값을 받아온다.
	//*@param input  : -
	//*@return		 : 색상 비트
	//*/
	inline const int GetBitCount(void) const { return  (((m_pBmpInfo != NULL)) ? (m_pBmpInfo->bmiHeader.biBitCount) : INVALID_BIT_COUNT); }

	///**
	//*description   : 영상이 저장된 배열의 총 크기를 계산한다.
	//*@param input  : -
	//*@return		 : 색상 비트
	//*/
	inline const unsigned long GetTotalSize(void) const { return  (((m_pBmpInfo != NULL)) ? (m_pBmpInfo->bmiHeader.biSizeImage) : INVALID_IMAGE_SIZE); }

	///**
	//*description   : 
	//*@param input  : -
	//*@return		 : 
	//*/
	inline const CBitmapInfo* Get(void) const { return (m_pBmpInfo != NULL) ? this : NULL; }

	///**
	//*description   : BITMAPINFO 초기화 및 메모리 할당
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	inline bool Initialize(const CBitmapInfo* pBmpInfo) { return Set(pBmpInfo); }
	
	///**
	//*description   : BITMAPINFO 초기화 및 메모리 할당
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	inline bool Initialize(const BITMAPINFO* pBmpInfo) { return Set(pBmpInfo); }

	///**
	//*description   : BITMAPINFO 초기화 및 메모리 할당
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	inline bool Initialize(const BITMAPINFOHEADER* pBmpInfoHead) { return Set(pBmpInfoHead); }

	///**
	//*description   : BITMAPINFO 항목 설정(포인터로 받아온 경우)
	//*@param input  : const CBitmapInfo& rhs
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	inline  bool Set(const CBitmapInfo& rhs) { return Set(&rhs); }

	///**
	//*description   : BITMAPINFO 항목 설정(포인터로 받아온 경우)
	//*@param input  : const BITMAPINFO& rhs
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	inline bool Set(const BITMAPINFO& rhs) { return Set(&rhs); }

	///**
	//*description   :  
	//*@param input  : const BITMAPINFOHEADER& rhs
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	inline bool Set(const BITMAPINFOHEADER& rhs) { return Set(&rhs); }

	///**
	//*description   : BITMAPINFO 항목 설정(포인터로 받아온 경우)
	//*@param input  : const CBitmapInfo* bmpInfo
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool Set(const CBitmapInfo* pBmpInfo);

	///**
	//*description   : BITMAPINFO 항목 설정(포인터로 받아온 경우)
	//*@param input  : const BITMAPINFO* bmpInfo
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool Set(const BITMAPINFO* pBmpInfo);

	///**
	//*description   :  
	//*@param input  : const BITMAPINFOHEADER* pBmpInfoHead
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	bool Set(const BITMAPINFOHEADER* pBmpInfoHead);

protected:

	///**
	//*description   : 메모리 할당
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool Initialize(void);

private:
};

#endif //_BITMAPINFO_H_