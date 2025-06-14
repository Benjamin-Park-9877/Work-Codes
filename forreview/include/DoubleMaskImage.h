/////** 
////*description   : 이중 마스크 작업 수행 클래스 정의 헤더 파일
////*               
////* 
////*/
#ifndef _DOUBLEMASKIMAGE_H_
#define _DOUBLEMASKIMAGE_H_
#pragma once
#ifndef _BITMAPACTION_H_
#include "BitmapAction.h"
#endif //_BITMAPACTION_H_

///** 
//*description   : 이중 마스크  작업 수행 클래스
//*@parent class : public CBitmapAction  
//*/
class CDoubleMaskImage :  public CBitmapAction
{
//// 멤버 변수 정의 부분
public:

protected:

private:

//// 멤버 함수 정의 부분
public:

	//*description   :  외부에서 호출하는 함수
	//*@param input  :  CUserBitmap& pCbmpElementsIn
	//*@param output : 
	//*@return		 :  
	//*/
	inline void Process(CUserBitmap& pCbmpElementsIn) { return Process(&pCbmpElementsIn); }

	//*description   : 외부에서 호출하는 함수
	//*@param input  : CUserBitmap* pCbmpElementsIn
	//*@param output : 
	//*@return		 :  
	//*/
	void Process(CUserBitmap* pCbmpElementsIn);

protected:

	//*description   : 
	//*@param input  :  
	//*@param output : 
	//*@return		 :  
	//*/
	void Work(std::vector<unsigned char>& InImg, std::vector<unsigned char>& OutImg, const int& height, const int& width);

	//*description   : 
	//*@param input  :  
	//*@param output : 
	//*@return		 :  
	//*/
	virtual bool InitializeMask_1St(std::vector<float>& mask, const size_t& winsize);

	//*description   : 
	//*@param input  :  
	//*@param output : 
	//*@return		 :  
	//*/
	virtual bool InitializeMask_2nd(std::vector<float>& mask, const size_t& winsize);

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
	bool ImgConvolution(std::vector<unsigned char>& InImg, std::vector<unsigned char>& OutImg, const size_t& height, const size_t& width, std::vector<float>& Mask1, std::vector<float>& Mask2, int winsize);

private:

};
#endif //_DOUBLEMASKIMAGE_H_