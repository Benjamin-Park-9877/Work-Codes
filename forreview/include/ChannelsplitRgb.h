/////** 
////*description   : 색상 영상을 R/G/B 성분으로 분리 작업 수행 클래스 정의 헤더 파일
////*               
////* 
////*/
#ifndef _CHANNELSPLITRGB_H_
#define _CHANNELSPLITRGB_H_
#pragma once

#ifndef _BITMAPACTION_H_
#include "BitmapAction.h"
#endif //_BITMAPACTION_H_

///** 
//*description   : 색상 영상을 R/G/B 성분으로 분리 작업 수행 클래스
//*@parent class : public CBitmapAction  
//*/
class CChannelsplitRgb : public CBitmapAction
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
	inline void Process(const CUserBitmap& pCbmpElementsIn) { return Process(&pCbmpElementsIn); }

	//*description   :  
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

private:

};
#endif //_CHANNELSPLITRGB_H_
