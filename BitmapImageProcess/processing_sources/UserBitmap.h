/////** 
////*description   : 비트맵 영상이 실제 저장되는 객체 정의 헤더파일
////* 
////*/
#ifndef _USERBITMAP_H_
#define _USERBITMAP_H_
#pragma once

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
	vector<unsigned char>		m_vecBmpImage;		// 벡터 형식으로 저장된 비트맵 실제 영상 부분 
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
	inline const unsigned long GetMaximumWidth(void) const { return m_BmpInfo.GetMaximumWidth(); }

	///**
	//*description   : 이미지 높이를 받아온다.
	//*@param input  : -
	//*@return		 : 이미지 높이
	//*/
	inline const unsigned long GetMaximumHeight(void) const { return m_BmpInfo.GetMaximumHeight(); }

	///**
	//*description   : 이미지 실제 픽셀 폭을 계산한다.
	//*@param input  : -
	//*@return		 : 이미지 실제 픽셀 폭
	//*/
	inline const unsigned long GetRwSize(void) const { return m_BmpInfo.GetRwSize(); }

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
	inline const unsigned long GetTotalSize(void) const { return m_BmpInfo.GetTotalSize(); }

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
	//*description   : 이동 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CUserBitmap(CUserBitmap&& rhs) noexcept;

	///**
	//*description   : 이동 대입 연산자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CUserBitmap& operator=(CUserBitmap&& rhs) noexcept;

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
	unsigned char* c_arr(void) { return m_vecBmpImage.data(); }

	//*description   : c 형태의 배열로 되돌리기 (상수형)
	//*@param input  :   
	//*@param output : 
	//*@return		 : c 형태의 배열 주소
	//*/
	inline const unsigned char* c_arr_const(void) const { return m_vecBmpImage.data(); }

	//*description   : 
	//*@param input  :   
	//*@param output : 
	//*@return		 :  
	//*/
	inline vector<unsigned char>& GetImage(void) { return this->m_vecBmpImage; }

	///**
	//*description   : 첨자 연산자 재정의(미리 범위 정도는 확인 필요)
	//*@param input  : size_t nPos : 위치
	//*@return		 : 해당 위치의 값
	//*/
	inline unsigned char& LocateAt(const size_t& nPos) { return  m_vecBmpImage[nPos]; }

	///**
	//*description   : 첨자 연산자 재정의(미리 범위 정도는 확인 필요)
	//*@param input  : size_t nPos : 위치
	//*@return		 : 해당 위치의 값
	//*/
	inline const unsigned char& LocateAt(const size_t& nPos) const { return  m_vecBmpImage[nPos]; }

	///**
	//*description   : 첨자 연산자 재정의(미리 범위 정도는 확인 필요)
	//*@param input  : size_t nPos : 위치
	//*@return		 : 해당 위치의 값
	//*/
	inline unsigned char& operator[](const size_t& nPos) { return  LocateAt(nPos); }

	///**
	//*description   : 첨자 연산자 재정의 const type
	//*@param input  : size_t nPos : 위치
	//*@return		 : 해당 위치의 값
	//*/
	inline const unsigned char operator[](const size_t& nPos) const { return  LocateAt(nPos); }

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

	///**
	//*description   :  
	//*@param input  : size_t szSize
	//*@return		 : 
	//*/
	inline void PushBitmapImageVector(const unsigned char* pUcBmpImage, const size_t& szSize) { m_vecBmpImage.clear(); for (size_t i = 0; i < (size_t)((GetRwSize() * GetMaximumHeight())); i++) { m_vecBmpImage.push_back(pUcBmpImage[i]); } }

private:

};
#endif //_USERBITMAP_H_
