/////** 
////*description   : 색상 엠보싱 작업 수행 클래스 정의 헤더 파일
////*               
////* 
////*/
#ifndef _COLOREMBOSSING_H_
#define _COLOREMBOSSING_H_
#pragma once

#ifndef _BITMAPACTION_H_
#include "BitmapAction.h"
#endif //_BITMAPACTION_H_

///** 
//*description   : 색상 엠보싱 작업 수행 클래스
//*@parent class : public CBitmapAction  
//*/
class CColorEmbossing : public CBitmapAction
{
//// 멤버 변수 정의 부분
public:

protected:

private:

//// 멤버 함수 정의 부분
public:

	//*description   : 색상 엠보싱 작업
	//*@param input  : CUserBitmap* pCbmpElementsIn
	//*@param input  :   
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	inline void Process(const CUserBitmap& pCbmpElementsIn) { return Process(&pCbmpElementsIn); }

	//*description   : 색상 엠보싱 작업
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
	//*@param input  : int				height
	//*@param input  : int				width
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void ColorEmbossing(const unsigned char* InImg, unsigned char* OutImg, int height, int width);

private:

};
#endif //_COLOREMBOSSING_H_

