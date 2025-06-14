#ifndef _USERMACHRO_H_
#define _USERMACHRO_H_
#pragma once

////////////////////////////////////////////////////////////////////////////
// 이후 프로그램에서는 별도 분리하지만, 우선은 이 프로그램에서 공통으로 쓰는 헤더를 따로 포함함
////////////////////////////////////////////////////////////////////////////
#include <wingdi.h>
#include <vcruntime_string.h>
#include <winnt.h>
#include <windef.h>
#include <tchar.h>
#include <afx.h>
////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////
// 사용할 범용 매크로 함수를 정의함(현재는 인라인 함수로 대체했음)
////////////////////////////////////////////////////////////////////////////
//////* 
////#define WIDTHBYTES(bits)    (((bits)+31)/32*4)  //4바이트의 배수여야  
////#define CLIP(val, low, high) {if(val<low) val=low; if(val>high) val=high;}
////*/

///**
//*description   : 4바이트의 배수 처리 함수
//*@param input  : const size_t& bits
//*@param output : -
//*@return		 : size_t 값
//*/
inline size_t WIDTHBYTES(const size_t& bits) { return  (((bits)+31) / 32 * 4); } 

///**
//*description   : 일정 값 기준으로 잘라냄
//*@param input  : const myType& low
//*@param input  : const myType& high
//*@param output : myType& val
//*@return		 : -
//*/
template <typename myType>
inline void CLIP(myType& val,const myType& low, const myType& high) { if(val < low) val=low; if(val > high) val=high; }
////////////////////////////////////////////////////////////////////////////
 

////////////////////////////////////////////////////////////////////////////
// 사용할 범용 상수 값 정의함
////////////////////////////////////////////////////////////////////////////
// 한 픽셀에 들어갈 수 있는 최대 밝기 경계값 
#define MAXIMUM_PIXEL_VALUE 256

// 기본 비트맵 헤더 정보 크기
#define DEFALUT_BITMAPINFO_HEADERSIZE ( sizeof(BITMAPINFO)+MAXIMUM_PIXEL_VALUE*sizeof(RGBQUAD) )

// 크기가 정해지지 않음을 상징하는 상수 값
#define INVALID_IMAGE_SIZE 0

// 무효한 색상 비트임을 나타내는 상수
#define INVALID_BIT_COUNT  0

// 단색 체계를 사용함을 나타내는 상수 값
#define	 MONO_COLOR_TYPE 1

// 3색 체계를 사용함을 나타내는 상수 값
#define	 THREE_COLOR_TYPE 3

// 4색 체계를 사용함을 나타내는 상수 값
#define	 FOUR_COLOR_TYPE 4

// 기본 이미지 확장자 명
#define STR_DEFAULT_EXTEND_NAME _T(".bmp")
////////////////////////////////////////////////////////////////////////////

#endif //_USERMACHRO_H_