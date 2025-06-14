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
class CBitmapClipBoard : private CBasicBone
{
//// 멤버 변수 정의 부분
public:

protected:

private:

//// 멤버 함수 정의 부분
public:

	///**
	//*description   : 새로운 User Image 설정함
	//*@param input  : -
	//*@param output : -
	//*@return		 : 정상동작 수행여부(true:동작함,false:실패함)
	//*/
	bool NewDocument(CUserBitmap& cbmpNodeIn, CUserRGBQuad&	cUserRGBQuad);

	//*description   : 클립보드로 복사하기(nFlag는 기본적으로 FLAG_SELECT_INPUT 즉, 입력 받은 이미지를 복사함)
	//*@param input  : unsigned char	*m_CpyImg
	//*@param input  : int				height
	//*@param input  : int				width
	//*@param input  : int				biBitCount 
	//*@param input  : int				nFlag
	//*@param output : -
	//*@return		 :  
	//*/
	void CopyClipboard(const CUserBitmap& cbmpNodeIn, CUserRGBQuad& cUserRGBQuad);

protected:

	///**
	//*description   : 비트맵 파일 채우기
	//*@param input  : LPSTR pDIB 
	//*@param output : CBitmapNode& bmpNode
	//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
	//*/
	bool OpenImageFromClipBoard(LPSTR pDIB, CUserBitmap& bmpNode);

	//*description   : 클립보드로 복사하기(nFlag는 기본적으로 FLAG_SELECT_INPUT 즉, 입력 받은 이미지를 복사함)
	//*@param input  : unsigned char	*m_CpyImg
	//*@param input  : int				height
	//*@param input  : int				width
	//*@param input  : int				biBitCount 
	//*@param input  : int				nFlag
	//*@param output : -
	//*@return		 :  
	//*/
	void CopyClipboard(const unsigned char* m_CpyImg, int height, int width, int biBitCount, const BITMAPINFOHEADER& dibHi, CUserRGBQuad& cUserRGBQuad);

private:

};

