/////** 
////*description   : 비트맵 영상이 실제 저장되는 객체 정의 헤더파일
////*              : vector class 에서 data() 메소드 지원 안된다면 헤더에서 "  #define _NOT_APPLYED_VEDCTOR_DATA_ " 정의 하고 쓸 것
////*              : 다만 그런 경우, 추가 코드 분석 및 디버깅등을 통해서 동작 확인하면서 쓰기
////* 
////*/
#ifndef _USERBITMAP_H_
#define _USERBITMAP_H_
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

#ifndef _BITMAPINFO_H_
#include "BitmapInfo.h"
#endif //_BITMAPINFO_H_

#ifndef _BITMAPFILEHEADER_H_
#include "BitmapFileHeader.h"
#endif //_BITMAPFILEHEADER_H_

#include<vector>

using namespace std;

///** 
//*description   : 비트맵 영상이 실제 저장되는 객체 
//*@parent class : private CBasicBone : 대입 연산자, 복사 생성자 호출 방지용
//*/
class CUserBitmap : private CBasicBone
{
//// 멤버 변수 정의 부분
public:

protected:

	CBitmapInfo					m_BmpInfo;			// 비트맵 이미지 화면 출력용 헤더 정보 
	
	CBitmapFileHeader			m_DibHf;			// 비트맵 파일 헤더 정보

	unsigned char*				m_pUcBmpImage;		// 읽어온 비트맵 저장 변수

#ifndef _NOT_APPLYED_VECTOR_DATA_	
	vector<unsigned char>		m_vecBmpImage;		// 벡터 형식으로 저장된 비트맵 실제 영상 부분 
#endif //_NOT_APPLYED_VECTOR_DATA_	

private:

//// 멤버 함수 정의 부분
public:

	///**
	//*description   : 비트맵 영상이 실제 저장되는 객체 용 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CUserBitmap();

	///**
	//*description   : 비트맵 영상이 실제 저장되는 객체 용 소멸자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	~CUserBitmap();

	///**
	//*description   : BITMAPINFO 항목 받아옴 (R-Value용)
	//*@param input  : -
	//*@param output : -
	//*@return		 : BITMAPINFO 포인터
	//*/
	inline BITMAPINFO* GetBitmapInfo(void) const { return m_BmpInfo.GetBitmapInfo(); }

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 : const BITMAPINFOHEADER*
	//*/
	inline const BITMAPINFOHEADER* GetBimapInfoHeader(void) const { return m_BmpInfo.GetBimapInfoHeader(); }

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 :
	//*/
	bool GetBimapInfoHeader(BITMAPINFOHEADER& rhs) const { return m_BmpInfo.GetBimapInfoHeader(rhs); }

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 : 
	//*/
	bool GetBimapInfoHeader(BITMAPINFOHEADER* rhs) const { return m_BmpInfo.GetBimapInfoHeader(rhs); }

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 : const BITMAPFILEHEADER*
	//*/
	inline const BITMAPFILEHEADER* GetBimapFileHeader(void) const { return m_DibHf.GetBitmapFileHeader(); }

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 :  
	//*/
	bool GetBimapFileHeader(BITMAPFILEHEADER* rhs) const { return m_DibHf.GetBitmapFileHeader(rhs); }

	///**
	//*description   :  
	//*@param input  :   
	//*@return		 :  
	//*/
	bool GetBimapFileHeader(BITMAPFILEHEADER& rhs) const { return m_DibHf.GetBitmapFileHeader(rhs); }

	///**
	//*description   : 이미지 폭을 받아온다.
	//*@param input  : -
	//*@return		 : 이미지 폭
	//*/
	inline const int GetMaximumWidth(void) const { return m_BmpInfo.GetMaximumWidth(); }

	///**
	//*description   : 이미지 높이를 받아온다.
	//*@param input  : -
	//*@return		 : 이미지 높이
	//*/
	inline const int GetMaximumHeight(void) const { return m_BmpInfo.GetMaximumHeight(); }

	///**
	//*description   : 이미지 실제 픽셀 폭을 계산한다.
	//*@param input  : -
	//*@return		 : 이미지 실제 픽셀 폭
	//*/
	inline const int GetRwSize(void) const { return m_BmpInfo.GetRwSize(); }

	///**
	//*description   : 색상 비트 값을 받아온다.
	//*@param input  : -
	//*@return		 : 색상 비트
	//*/
	inline const int GetBitCount(void) const { return m_BmpInfo.GetBitCount(); }

	///**
	//*description   : 영상이 저장된 배열의 총 크기를 계산한다.
	//*@param input  : -
	//*@return		 : 색상 비트
	//*/
	inline const int GetTotalSize(void) const { return m_BmpInfo.GetTotalSize(); }

protected:

	///**
	//*description   : BITMAPINFO 항목 설정
	//*@param input  : const BITMAPINFO& bmpInfo
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	inline bool SetBitmapInfo(const BITMAPINFO& bmpInfo) { return m_BmpInfo.Set(bmpInfo); }

	///**
	//*description   : BITMAPINFO 항목 설정(포인터로 받아온 경우)
	//*@param input  : const BITMAPINFO* bmpInfo
	//*@param output : -
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	inline bool SetBitmapInfo(const BITMAPINFO* pBmpInfo) { return m_BmpInfo.Set(pBmpInfo); }

	///**
	//*description   :  
	//*@param input  : const BITMAPINFOHEADER& bmpInfoHead
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	inline bool SetBitmapInfoHeader(const BITMAPINFOHEADER& bmpInfoHead) { return m_BmpInfo.Set(bmpInfoHead); }

	///**
	//*description   :  
	//*@param input  : const BITMAPINFOHEADER* pBmpInfoHead
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	inline bool SetBitmapInfoHeader(const BITMAPINFOHEADER* pBmpInfoHead) { return m_BmpInfo.Set(pBmpInfoHead); }

	///**
	//*description   :  
	//*@param input  : const BITMAPFILEHEADER& bmpFileHead
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	inline bool SetBitmapFileHeader(const BITMAPFILEHEADER& bmpFileHead) { return m_DibHf.Set(bmpFileHead); }

	///**
	//*description   :  
	//*@param input  : const BITMAPFILEHEADER* pBmpFileHead
	//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
	//*/
	inline bool SetBitmapFileHeader(const BITMAPFILEHEADER* pBmpFileHead) { return m_DibHf.Set(pBmpFileHead); }

private:

// 예전 vector class 에서 data() 메소드 지원 여부에 따라서 구현 방법 선택함
// vector class 에서 data() 메소드 지원 안된다면 헤더에서 "  #define _NOT_APPLYED_VEDCTOR_DATA_ " 정의 하고 쓸 것
// 그렇지 않다면 "  #define _NOT_APPLYED_VEDCTOR_DATA_ " 정의하지 않기
#ifdef _NOT_APPLYED_VECTOR_DATA_	

public:
	///**
	//*description   : 객체 메모리 해제 및 내용 비우기
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void Clear(void);

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
	//*@param input  : const CBitmapNode& rhs
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool SetImage(const CUserBitmap& rhs);

protected:

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
	inline void ClearBitmapArray(void) { if (m_pUcBmpImage != NULL) { delete[] m_pUcBmpImage; m_pUcBmpImage = NULL; } }

private:

#else //_NOT_APPLYED_VEDCTOR_DATA_

public:
	///**
	//*description   : 비트맵 영상이 실제 저장되는 객체용 복사 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CUserBitmap(const CUserBitmap& rhs);

	///**
	//*description   : 비트맵 영상이 실제 저장되는 객체용 대입 연산자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CUserBitmap& operator=(const CUserBitmap& rhs);

	///**
	//*description   : 객체 메모리 해제 및 내용 비우기
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void Clear(void);

	//*description   : c 형태의 배열로 되돌리기
	// 	               배열 내용을 바꾸어야 하는 경우 외에는 c_arr_const()로 사용하기
	//				   사용시 Dangling Reference 발생 하는지 확인 및 디버깅 하기
	//*@param input  :   
	//*@param output : 
	//*@return		 : c 형태의 배열 주소
	//*/
	unsigned char* c_arr(void);

	//*description   : c 형태의 배열로 되돌리기 (상수형)
	//*@param input  :   
	//*@param output : 
	//*@return		 : c 형태의 배열 주소
	//*/
	inline const unsigned char* c_arr_const(void) const { return m_vecBmpImage.data(); }

	///**
	//*description   : 첨자 연산자 재정의(미리 범위 정도는 확인 필요)
	//*@param input  : size_t nPos : 위치
	//*@return		 : 해당 위치의 값
	//*/
	inline unsigned char& operator[](const size_t& nPos) { return  m_vecBmpImage[nPos]; }

	///**
	//*description   : 첨자 연산자 재정의 const type
	//*@param input  : size_t nPos : 위치
	//*@return		 : 해당 위치의 값
	//*/
	inline const unsigned char operator[](const size_t& nPos) const { return (((m_vecBmpImage.empty() == false)) ? m_vecBmpImage[nPos] : 0); }

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
	//*@param input  : const CBitmapNode& rhs
	//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
	//*/
	bool SetImage(const CUserBitmap& rhs);

protected:

	///**
	//*description   :  
	//*@param input  : size_t szSize
	//*@return		 : 
	//*/
	inline void PushBitmapImageVector(const unsigned char* pUcBmpImage, const size_t& szSize) { m_vecBmpImage.clear(); for (int i = 0; i < ((GetRwSize() * GetMaximumHeight())); i++) { m_vecBmpImage.push_back(pUcBmpImage[i]); } }

private:

#endif //_NOT_APPLYED_VEDCTOR_DATA_	

};
#endif //_USERBITMAP_H_
