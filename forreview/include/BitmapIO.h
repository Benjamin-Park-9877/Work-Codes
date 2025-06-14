/////** 
////*description   : 
////* 
////*/
#ifndef _BITMAPIO_H_
#define _BITMAPIO_H_
#pragma once

#include <winnt.h>

#ifndef _BASICBONE_H_
#include "basicbone.h"
#endif //_BASICBONE_H_

#ifndef _USERMACHRO_H_
#include "UserMachro.h"
#endif //_USERMACHRO_H_

#ifndef _USER_RGBQUAD_H_
#include "UserRGBQuad.h"
#endif //_USER_RGBQUAD_H_

#ifndef _BITMAPFILEHEADER_H_
#include "BitmapFileHeader.h"
#endif //_BITMAPFILEHEADER_H_

#ifndef _USERBITMAP_H_
#include "UserBitmap.h"
#endif //_USERBITMAP_H_

///** 
//*description   :  
//*@parent class : private CBasicBone : 대입 연산자, 복사 생성자 호출 방지용
//*/
class CBitmapIO : private CBasicBone
{
//// 멤버 변수 정의 부분
public:

protected:

private:

//// 멤버 함수 정의 부분
public:

	///**
	//*description   : 파일로부터 비트맵 읽어옴
	//*@param input  : LPCTSTR lpszPathName					파일 경로명
	//*@param input  :  
	//*@param output :  
	//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
	//*/
	bool Open(LPCTSTR lpszPathName, CUserBitmap& bmpNode, RGBQUAD* palRGB = NULL);

	///**
	//*description   : 비트맵을 파일로 저장
	//*@param input  : LPCTSTR lpszPathName	파일 경로명
	//*@param input  : SmallUserBitmap& smallUserBitmap
	//*@param input  : RGBQUAD*	palRGB
	//*@param output : -
	//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
	//*/
	bool Save(LPCTSTR lpszPathName, CUserBitmap& bmpNode, RGBQUAD* palRGB = NULL);

protected:

	///**
	//*description   : 확장자 붙여줌
	//*@param input  : CString lpszPathName	파일 경로명
	//*@param input  : 
	//*@param input  : 
	//*@param output : -
	//*@return		 : 경로명
	//*/
	CString AddExtendString(CString lpszPathName);

private:

};
#endif //_BITMAPIO_H_