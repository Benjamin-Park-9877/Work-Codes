/////** 
////*description   : 비트맵 영상이 실제 저장되는 객체 정의 헤더파일
////*               
////* 
////*/
#ifndef _BITMAPNODE_H_
#define _BITMAPNODE_H_
#pragma once

#include <winnt.h>
#include <wingdi.h>
#include <vcruntime_string.h>
#include <windef.h>
#include <tchar.h>
#include <afx.h>

#ifndef _BASICBONE_H_
#include "basicbone.h"
#endif //_BASICBONE_H_

#ifndef _USERMACHRO_H_
#include "UserMachro.h"
#endif //_USERMACHRO_H_

///** 
//*description   : 비트맵 영상이 실제 저장되는 객체 
//*@parent class : private CBasicBone : 대입 연산자, 복사 생성자 호출 방지용
//*/
class CBitmapNode : private CBasicBone
{
//// 멤버 변수 정의 부분
public:

protected:
	BITMAPINFO*			m_pBmpInfo;			// 비트맵 이미지 화면 출력용 헤더 정보 
	BITMAPINFOHEADER*	m_pDibHi;			// 파일에서 읽어온 헤더 정보 
	BITMAPFILEHEADER*	m_pDibHf;			// 비트맵 파일 헤더 정보
	unsigned char*		m_pUcBmpImage;		// 읽어온 비트맵 저장 변수

private:

//// 멤버 함수 정의 부분
public:

	///**
	//*description   : 비트맵 영상이 실제 저장되는 객체 용 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapNode(void);

	///**
	//*description   : 비트맵 영상이 실제 저장되는 객체 용 소멸자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	~CBitmapNode(void);

	///**
	//*description   : 비트맵 영상이 실제 저장되는 객체 용 복사 생성자 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapNode(const CBitmapNode& rhs);

	///**
	//*description   : 비트맵 영상이 실제 저장되는 객체 용 대입 연산자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapNode& operator = (const CBitmapNode& rhs);

	///**
	//*description   : 객체 메모리 해제 및 내용 비우기
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void Clear(void);

	///**
	//*description   : 객체 초기화 및 배열 부분 제외한 메모리 할당
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool Initialize(void);

	///**
	//*description   : 객체 초기화 및 지정한 크기의 배열을 가진 메모리 할당
	//*@param input  : const size_t& szTotalSize
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool Initialize(const size_t& szTotalSize);

	///**
	//*description   : BITMAPINFO 항목 받아옴
	//*@param input  : -
	//*@param output : BITMAPINFO& bmpInfo
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool GetBitmapInfo(BITMAPINFO& bmpInfo) const;

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
	//*@param output : BITMAPFILEHEADER& bmpFileHead
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool GetBitmapFileHeader(BITMAPFILEHEADER& bmpFileHead) const;

	///**
	//*description   :  
	//*@param input  : -
	//*@param output : BITMAPINFOHEADER& bmpInfoHead
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool GetBitmapInfoHeader(BITMAPINFOHEADER& bmpInfoHead) const;

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 : const BITMAPINFOHEADER*
	//*/
	inline BITMAPINFOHEADER* GetBimapInfoHeader(void) const { return ((m_pDibHi != NULL) ? m_pDibHi : NULL); }

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 : const BITMAPFILEHEADER*
	//*/
	inline BITMAPFILEHEADER* GetBimapFileHeader(void) const { return ((m_pDibHf != NULL) ? m_pDibHf : NULL); }

	//*description   : c 형태의 배열로 되돌리기
	//*@param input  :   
	//*@return		 : c 형태의 배열 주소
	//*/
	unsigned char* c_arr(void) const { return ((m_pUcBmpImage != NULL) ? m_pUcBmpImage : NULL); }

	///**
	//*description   : 첨자 연산자 재정의(미리 범위 정도는 확인 필요)
	//*@param input  : size_t nPos : 위치
	//*@return		 : 해당 위치의 값
	//*/
	inline unsigned char& operator[](const size_t& nPos) { return  m_pUcBmpImage[nPos]; }

	///**
	//*description   : 첨자 연산자 재정의 const type
	//*@param input  : size_t nPos : 위치
	//*@return		 : 해당 위치의 값
	//*/
	inline const unsigned char operator[](const size_t& nPos) const { return (((m_pUcBmpImage != NULL)) ? m_pUcBmpImage[nPos] : 0); }

	///**
	//*description   : 이미지 폭을 받아온다.
	//*@param input  : -
	//*@return		 : 이미지 폭
	//*/
	inline const int GetMaximumWidth(void) const { return (((m_pBmpInfo != NULL) ) ? (m_pBmpInfo->bmiHeader.biWidth) : INVALID_IMAGE_SIZE); }

	///**
	//*description   : 이미지 높이를 받아온다.
	//*@param input  : -
	//*@return		 : 이미지 높이
	//*/
	inline const int GetMaximumHeight(void) const { return (((m_pBmpInfo != NULL)) ? (m_pBmpInfo->bmiHeader.biHeight) : INVALID_IMAGE_SIZE); }

	///**
	//*description   : 이미지 실제 픽셀 폭을 계산한다.
	//*@param input  : -
	//*@return		 : 이미지 실제 픽셀 폭
	//*/
	inline const int GetRwSize(void) const { return (((m_pBmpInfo != NULL) ) ? (WIDTHBYTES((m_pBmpInfo->bmiHeader.biBitCount * m_pBmpInfo->bmiHeader.biWidth))) : INVALID_IMAGE_SIZE); }

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
	inline const int GetTotalSize(void) const { return  (((m_pBmpInfo != NULL)) ? (m_pBmpInfo->bmiHeader.biSizeImage) : INVALID_IMAGE_SIZE); }

	///**
	//*description   : 
	//*@param input  : unsigned char*	pUcBmpImage
	//*@param input  : BITMAPINFO*		pBmpInfo
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo);

	///**
	//*description   :  
	//*@param input  : unsigned char*		pUcBmpImage
	//*@param input  : BITMAPINFOHEADER*	pDibHi
	//*@param input  : BITMAPFILEHEADER*	pDibHf
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf);

	///**
	//*description   :  
	//*@param input  : unsigned char*		pUcBmpImage
	//*@param input  : BITMAPINFO*			pBmpInfo  
	//*@param input  : BITMAPINFOHEADER*	pDibHi
	//*@param input  : BITMAPFILEHEADER*	pDibHf
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf);

	///**
	//*description   :  
	//*@param input  : const CBitmapNode& rhs
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool SetImage(const CBitmapNode& rhs);

	///**
	//*description   : 
	//*@param output  : unsigned char*	pUcBmpImage
	//*@param output  : BITMAPINFO*		pBmpInfo
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	const bool GetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) const;

	///**
	//*description   :  
	//*@param output  : unsigned char*		pUcBmpImage
	//*@param output  : BITMAPINFOHEADER*	pDibHi
	//*@param output  : BITMAPFILEHEADER*	pDibHf
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	const bool GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const;

#ifdef DEBUG
	///**
	//*description   : 객체 안의 멤버변수 값 출력창에 보여주기(디버깅용)
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void TraceElements(void);
#endif DEBUG

protected:

	///**
	//*description   : BITMAPINFO 초기화 및 메모리 할당
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool InitializeBitmapInfo(void);

	///**
	//*description   : BITMAPINFO 메모리 해제 및 내용 비우기
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void ClearBitmapInfo(void);

	///**
	//*description   : BITMAPINFOHEADER 초기화
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool InitializeBitmapInfoHeader(void);

	///**
	//*description   : BITMAPINFOHEADER 메모리 해제 및 내용 비우기
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void ClearBitmapInfoHeader(void);

	///**
	//*description   : 비트맵 파일 헤더 정보 초기화
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool InitializeBitmapFileHeader(void);

	///**
	//*description   : 비트맵 파일 헤더 메모리 해제
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void ClearBitmapFileHeader(void);

	///**
	//*description   :
	//*@param input  : const size_t& size (할당 받을 배열의 크기)
	//*@param output : 
	//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
	//*/
	bool InitializeBitmapArray(const size_t& size);

	///**
	//*description   : 비트맵 영상 배열 메모리 해제 및 내용 비우기
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void ClearBitmapArray(void);

	///**
	//*description   : BITMAPINFO 항목 설정
	//*@param input  : const BITMAPINFO& bmpInfo
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool SetBitmapInfo(const BITMAPINFO& bmpInfo);

	///**
	//*description   : BITMAPINFO 항목 설정(포인터로 받아온 경우)
	//*@param input  : const BITMAPINFO* bmpInfo
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool SetBitmapInfo(const BITMAPINFO* pBmpInfo);

	///**
	//*description   :  
	//*@param input  : const BITMAPINFOHEADER& bmpInfoHead
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	bool SetBitmapInfoHeader(const BITMAPINFOHEADER& bmpInfoHead);

	///**
	//*description   :  
	//*@param input  : const BITMAPINFOHEADER* pBmpInfoHead
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	bool SetBitmapInfoHeader(const BITMAPINFOHEADER* pBmpInfoHead);

	///**
	//*description   :  
	//*@param input  : const BITMAPFILEHEADER& bmpFileHead
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	bool SetBitmapFileHeader(const BITMAPFILEHEADER& bmpFileHead);

	///**
	//*description   :  
	//*@param input  : const BITMAPFILEHEADER* pBmpFileHead
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	bool SetBitmapFileHeader(const BITMAPFILEHEADER* pBmpFileHead);

private:

};
#endif //_BITMAPNODE_H_

