/////** 
////*description   : sobel 작업 수행 클래스 정의 헤더 파일
////*               
////* 
////*/
#ifndef _SOBELIMAGE_H_
#define _SOBELIMAGE_H_
#pragma once

#ifndef _DOUBLEMASKIMAGE_H_
#include "DoubleMaskImage.h"
#endif //_DOUBLEMASKIMAGE_H_

///** 
//*description   : sobel 작업 수행 클래스
//*@parent class : public CDoubleMaskImage  
//*/
class CSobelImage :  public CDoubleMaskImage
{
//// 멤버 변수 정의 부분
public:

protected:

private:

//// 멤버 함수 정의 부분
public:

protected:

	//*description   : 
	//*@param input  :  
	//*@param output : 
	//*@return		 :  
	//*/
	bool InitializeMask_1St(std::vector<float>& mask, const size_t& winsize);

	//*description   : 
	//*@param input  :  
	//*@param output : 
	//*@return		 :  
	//*/
	bool InitializeMask_2nd(std::vector<float>& mask, const size_t& winsize);

private:

};
#endif //_SOBELIMAGE_H_
