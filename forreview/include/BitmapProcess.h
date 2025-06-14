/////** 
////*description   : 비트맵 영상을 처리하는 객체 정의 헤더파일
////*               
////* 
////*/
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

#include "ColorConv.h"
#include "BlobColoring.h"
#include "RGBToHSI.h"
#include "RGBToGray.h"
#include "ColorEmbossing.h"
#include "RGBSharpening.h"
#include "ChannelsplitRgb.h"
#include "ActBlobcoloring.h"
#include "BitmapIO.h"
#include "BitmapClipBoard.h"
#include "CDLG_DYNBIN.h"
#include "SobelImage.h"

///** 
//*description   : 비트맵 영상을 처리하는 객체
//*@parent class : private CBasicBone : 대입 연산자, 복사 생성자 호출 방지용
//*/
class CBitmapProcess :  private CBasicBone
{
//// 멤버 변수 정의 부분
public:

	CUserRGBQuad	m_cuserRGBQuad;

	CUserBitmap		m_cbmpNodeIn;

protected:

private:

//// 멤버 함수 정의 부분
public:

	///**
	//*description   : 비트맵 영상을 처리하는 객체용 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBitmapProcess(void);

	///**
	//*description   : 비트맵 영상을 처리하는 객체용 소멸자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	~CBitmapProcess(void);

	///**
	//*description   : 비트맵 이미지 처리 담당 객체 내부 동적할당 메모리 해제
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void Clear(void);

	///**
	//*description   : 비트맵 이미지 처리 담당 객체 내부 변수 초기화
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void Initialize(void);

	///**
	//*description   : 새로운 User Image 설정함
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상동작 수행여부(true:동작함,false:실패함)
	//*/
	bool NewDocument(void);

	///**
	//*description   : 파일로부터 비트맵 읽어옴
	//*@param input  : LPCTSTR lpszPathName					파일 경로명
	//*@param input  :  
	//*@param output :  
	//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
	//*/
	bool OpenImageFromFile(LPCTSTR lpszPathName);

	///**
	//*description   : 비트맵을 파일로 저장
	//*@param input  : LPCTSTR lpszPathName	파일 경로명
	//*@param input  : SmallUserBitmap& smallUserBitmap
	//*@param input  : RGBQUAD*	palRGB
	//*@param output : -
	//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
	//*/
	bool SaveImageToFile(LPCTSTR lpszPathName);

	//*description   : 
	//*@param input  : int nFlag
	//*@param output : -
	//*@return		 : 
	//*/
	const size_t GetImageWidth(void) const;

	//*description   : 
	//*@param input  : int nFlag
	//*@param output : -
	//*@return		 :  
	//*/
	const size_t GetImageHeight(void) const;

	//*description   : 
	//*@param input  : int nFlag
	//*@param output : -
	//*@return		 :  
	//*/
	const int GetImageBitCount(void) const;

	//*description   : 
	//*@param input  : int nFlag
	//*@param output : -
	//*@return		 :  
	//*/
	const int GetImageRwSize(void) const;

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
	void  CopyClipboard(void);

	//*description   : 
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void ChannelsplitRgb(void);

	//*description   : 
	//*@param input  :  
	//*@param input  :   
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void RGB2HSI(void);

	//*description   : 
	//*@param input  :  
	//*@param input  :   
	//*@param input  :
	//*@param input  : 
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void RGB2Gray(void);

	//*description   : 
	//*@param input  :  
	//*@param input  :  
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void ColorEmbossing(void);

	//*description   : 
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param input  :
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void RGBShapening(void);

	//*description   : 
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param input  :
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void Blobcoloring(CClientDC* pDc);

	//*description   : 
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param input  :
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	bool OnImgDynbinSet(CDLG_DYNBIN* pDlg);

	//*description   : 
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param input  :
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	bool OnImgDynbinGet(CDLG_DYNBIN* pDlg);

	//*description   :  
	//*@param input  : -
	//*@param output : -
	//*@return		 :  
	//*/
	void OnRgbSobel(void);

protected:
	
private:


};

