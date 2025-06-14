/////** 
////*description   : 색상 영상을 선명하게 만드는 작업 수행 클래스 정의 헤더 파일
////*               
////* 
////*/
#ifndef _RGBSHARPENING_H_
#define _RGBSHARPENING_H_
#pragma once
#include "BitmapAction.h"

///** 
//*description   : 색상 영상을 선명하게 만드는 작업 수행 클래스
//*@parent class : public CBitmapAction  
//*/
class CRGBSharpening : public CBitmapAction
{
//// 멤버 변수 정의 부분
public:

protected:

private:

//// 멤버 함수 정의 부분
public:

	//*description   :  
	//*@param input  :  
	//*@param input  :   
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	inline void Process(CUserBitmap& pCbmpElementsIn) { return Process(&pCbmpElementsIn); }

	//*description   :  
	//*@param input  : CUserBitmap* pCbmpElementsIn
	//*@param input  :   
	//*@param input  :  
	//*@param input  :  
	//*@param input  : 
	//*@param output : -
	//*@return		 :  
	//*/
	void Process(CUserBitmap* pCbmpElementsIn);

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
	void RGBShapening(std::vector<unsigned char>& InImg, std::vector<unsigned char>& OutImg, const int& height, const int& width);

	//*description   : 
	//*@param input  :  
	//*@param input  :  
	//*@param input  :  
	//*@param input  :  
	//*@param input  :  
	//*@param input  :  
	//*@param output :  
	//*@return		 :  
	//*/
	bool InitializeMask(std::vector<float>& mask, const size_t& winsize);

private:


};

#endif //_RGBSHARPENING_H_
