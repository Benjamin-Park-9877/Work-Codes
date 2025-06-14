/////** 
////*description   : 비트맵 영상 받아서 RGB To Gray 작업 수행 클래스 정의 헤더 파일
////*               
////* 
////*/
#ifndef _RGBTOGRAY_H_
#define _RGBTOGRAY_H_
#pragma once

#ifndef _BITMAPACTION_H_
#include "BitmapAction.h"
#endif //_BITMAPACTION_H_

///** 
//*description   : 비트맵 영상 받아서 RGB To Gray 작업 수행 클래스
//*@parent class : private CBitmapAction  
//*/
class CRGBToGray :  public CBitmapAction
{

//// 멤버 변수 정의 부분
public:

protected:

private:

//// 멤버 함수 정의 부분
public:

	//*description   : RGB -> HSI 영상으로 변환 후 분할
	//*@param input  : CUserBitmap* pCbmpElementsIn
	//*@param input  :   
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	inline void Process(const CUserBitmap& pCbmpElementsIn) { return Process(&pCbmpElementsIn); }

	//*description   : RGB -> HSI 영상으로 변환 후 분할
	//*@param input  : CUserBitmap* pCbmpElementsIn
	//*@param input  :   
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void Process(const CUserBitmap* pCbmpElementsIn);

protected:

	//*description   : 
	//*@param input  :  
	//*@param input  :   
	//*@param input  :
	//*@param input  : 
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void RGB2Gray(const unsigned char* InImg, unsigned char* OutImg, int height, int width);

	//*description   : 
	//*@param input  :  
	//*@param input  :   
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	bool SpiltOneColorImage(const CUserBitmap& bitmapNode, int nType = THREE_COLOR_TYPE);

private:

};
#endif //_RGBTOGRAY_H_

