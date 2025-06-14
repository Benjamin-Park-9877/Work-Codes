/////** 
////*description   : 비트맵 영상을 하나 받아서 특정한 한 가지만 처리를 하는 클래스 정의 헤더 파일
////*               
////* 
////*/
#ifndef _BITMAPACTION_H_
#define _BITMAPACTION_H_
#pragma once
#ifndef _BASICBONE_H_
#include "basicbone.h"
#endif //_BASICBONE_H_

#ifndef _USERMACHRO_H_
#include "UserMachro.h"
#endif //_USERMACHRO_H_

#ifndef _USER_RGBQUAD_H_
#include "UserRGBQuad.h"
#endif //_USER_RGBQUAD_H_

#ifndef _USERBITMAP_H_
#include "UserBitmap.h"
#endif //_USERBITMAP_H_ 

#ifndef _COLORCONV_H_
#include "ColorConv.h"
#endif //_COLORCONV_H_

///** 
//*description   : 비트맵 영상을 처리하는 객체
//*@parent class : private CBasicBone : 대입 연산자, 복사 생성자 호출 방지용
//*/
class CBitmapAction : private CBasicBone
{
//// 멤버 변수 정의 부분
public:

protected:

	CUserRGBQuad* m_pCuserRGBQuad;

	CUserBitmap* m_pCbmpElements;

private:

//// 멤버 함수 정의 부분
public:

	///**
	//*description   : 비트맵 영상 하나의 동작 객체 용 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapAction();

	///**
	//*description   : 비트맵 영상 하나의 동작 객체 용 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	virtual ~CBitmapAction();

	///**
	//*description   : 비트맵 영상 하나의 동작 객체 용 깊은 복사 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapAction(const CBitmapAction& rhs);

	///**
	//*description   : 비트맵 영상 하나의 동작 객체 용 이동 복사 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapAction(CBitmapAction&& rhs) noexcept;
	
	///**
	//*description   : 비트맵 영상 하나의 동작 객체 용 깊은 복사 대입 연산자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapAction& operator=(const CBitmapAction& rhs);

	///**
	//*description   : 비트맵 영상 하나의 동작 객체 용 이동 대입 연산자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/	
	CBitmapAction& operator=(CBitmapAction&& rhs) noexcept;

	///**
	//*description   : 비트맵 영상 하나의 동작 객체 동적할당 메모리 해제
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void Clear(void);

	//*description   : User Image를 지정된 정보로 화면 출력
	//*@param input  : CDC* pDC					출력할 DC 포인터
	//*@param output : -
	//*@return		 : 정상동작 수행여부(true:동작함,false:실패함)
	//*/
	bool DrawImage(CDC* pDC);

	//*description   : 
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void GetImageSize(CSize& csSizeImage) const;

	//*description   : 클립보드로 복사하기
	//*@param input  : -
	//*@param output : -
	//*@return		 :  
	//*/
	bool CopyClipboard(void);

protected:

	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline void ClearCUserRGBQuad(void) { if (m_pCuserRGBQuad != NULL) { m_pCuserRGBQuad->Clear();	delete m_pCuserRGBQuad;	m_pCuserRGBQuad = NULL; } }

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline void ClearCUserBitmap(void) { if (m_pCbmpElements != NULL) { m_pCbmpElements->Clear(); delete m_pCbmpElements; m_pCbmpElements = NULL; } }

	///**
	//*description   : 비트맵 영상 하나의 동작 객체 동적할당 내부 변수 초기화
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	bool Initialize(void);

	///**
	//*description   :  
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	bool InitializeCuserRGBQuad(void);

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	bool InitializeCUserBitmap(void);

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CUserRGBQuad* GetRGBQuad(int) { return ((m_pCuserRGBQuad != NULL) ? m_pCuserRGBQuad : NULL); }

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CUserBitmap* GetUserBitmap(int) { return ((m_pCbmpElements != NULL) ? m_pCbmpElements : NULL); }

	//*description   : 클립보드로 복사하기
	//*@param input  : unsigned char	*m_CpyImg
	//*@param input  : int				height
	//*@param input  : int				width
	//*@param input  : int				biBitCount 
	//*@param output : -
	//*@return		 :  
	//*/
	void CopyClipboard(const unsigned char* m_CpyImg, int height, int width, int biBitCount);

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	bool Set(const CBitmapAction& rhs);

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	bool Set(const CUserBitmap* pUserBitmap);

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline bool Set(const CUserBitmap& userBitmap) { return Set(&userBitmap); }

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	bool Set(const CUserBitmap* pUserBitmap, const CUserRGBQuad* pRGBQuad);

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline bool Set(const CUserBitmap& userBitmap, const CUserRGBQuad& rgbQuad) { return Set(&userBitmap, &rgbQuad); }

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	bool Get(CBitmapAction& rhs);

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline bool Get(CUserBitmap& userBitmap) { return Get(&userBitmap); }

	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	bool Get(CUserBitmap* pUserBitmap);

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const CUserRGBQuad* GetRGBQuad(void) const { return ((m_pCuserRGBQuad != NULL) ? m_pCuserRGBQuad : NULL); }

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	const CUserBitmap* GetUserBitmap(void) const { return ((m_pCbmpElements != NULL) ? m_pCbmpElements : NULL); }

	//*description   : 
	//*@param input  :  
	//*@param output : -
	//*@return		 : 
	//*/
	const size_t GetImageWidth(void) const;

	//*description   : 
	//*@param input  :  
	//*@param output : -
	//*@return		 :  
	//*/
	const size_t GetImageHeight(void) const;

	//*description   : 
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	const int GetImageBitCount(void) const;

	//*description   : 
	//*@param input  :
	//*@param output : -
	//*@return		 :  
	//*/
	const unsigned long GetImageRwSize(void) const;

	//*description   : 
	//*@param input  :
	//*@param output : -
	//*@return		 :  
	//*/
	const unsigned long GetTotalSize(void) const;

	//*description   : 
	//*@param input  :  
	//*@param input  :  
	//*@param input  : int				height
	//*@param input  : int				width
	//*@param input  : float			*Mask
	//*@param input  : int				winsize
	//*@param output : -
	//*@return		 :  
	//*/
	virtual bool ImgConvolution(std::vector<unsigned char>& InImg, std::vector<unsigned char>& OutImg,
						const size_t& height, const size_t& width, 
						std::vector<float>& Mask, int winsize);

	//*description   : RGB --> HSI로의 변환 
	//*@param input  :  
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param input  : 
	//*@param input  :  
	//*@param output :  
	//*@return		 :  
	//*/
	bool RGBtoHSI(std::vector<unsigned char>& InImg, std::vector<short>& H,
				  std::vector<unsigned char>& S, std::vector<unsigned char>& IV,
				  const size_t& height, const size_t& width);

	//*description   : HSI --> RGB로의 변환 	
	//*@param input  :  
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param input  : 
	//*@param input  :  
	//*@param output :  
	//*@return		 :  
	//*/
	bool HSItoRGB(std::vector<unsigned char>& OutImg, std::vector<short>& H,
		          std::vector<unsigned char>& S, std::vector<unsigned char>& IV,
		          const size_t& height, const size_t& width);

	//*description   : 
	//*@param input  : const size& winsize
	//*@param output : std::vector<float>& mask
	//*@return		 :  
	//*/
	bool InitializeMask(std::vector<float>& mask, const size_t& winsize);


	//*description   : 
	//*@param input  : const size& winsize
	//*@param input  : const std::vector<float>& pattern
	//*@param output : std::vector<float>& mask
	//*@return		 :  
	//*/
	bool FillMaskPattern(std::vector<float>& mask, const std::vector<float>& pattern, const size_t& winsize);

	//*description   : 
	//*@param input  : size& imageSize
	//*@param output : std::vector<float>& ucImage
	//*@return		 :  
	//*/
	bool InitializeBufferImage(std::vector<unsigned char>& ucImage, const size_t& imageSize);

	//*description   : 
	//*@param input  : size& imageSize
	//*@param output : std::vector<float>& ucImage
	//*@return		 :  
	//*/
	bool InitializeBufferImage(std::vector<short>& sImage, const size_t& imageSize);

private:

};

#endif //_BITMAPACTION_H_

