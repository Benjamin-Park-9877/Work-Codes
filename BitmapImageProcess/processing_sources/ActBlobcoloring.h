/////** 
////*description   : 영역 중심 구하기 작업 수행 클래스 정의 헤더 파일
////*               
////* 
////*/
#ifndef _ACTBLOBCOLORING_H_
#define _ACTBLOBCOLORING_H_
#pragma once

#ifndef _BITMAPACTION_H_
#include "BitmapAction.h"
#endif //_BITMAPACTION_H_

///** 
//*description   : 영역 중심 구하기 작업 수행 클래스
//*@parent class : public CBitmapAction  
//*/
class CActBlobcoloring : public CBitmapAction
{
	//// 멤버 변수 정의 부분
public:

protected:

private:

	//// 멤버 함수 정의 부분
public:

	//*description   :  
	//*@param input  : CUserBitmap* pCbmpElementsIn
	//*@param input  :   
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	inline void Process(const CUserBitmap& pCbmpElementsIn, CClientDC* pDc) { return Process(&pCbmpElementsIn, pDc); }

	//*description   :  
	//*@param input  : CUserBitmap* pCbmpElementsIn
	//*@param input  :   
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void Process(const CUserBitmap* pCbmpElementsIn, CClientDC* pDc);

protected:

private:

};
#endif // _ACTBLOBCOLORING_H_
