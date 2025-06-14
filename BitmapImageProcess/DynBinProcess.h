/////** 
////*description   : 동적 이진화를 처리하는 객체 정의 헤더파일
////*               
////* 
////*/
#ifndef _DYNBINPROCESS_H_
#define _DYNBINPROCESS_H_

#pragma once
#include <winnt.h>
#include <wingdi.h>
#include <vcruntime_string.h>
#include <windef.h>
#include <tchar.h>
#include <afx.h>

#include "BlobColoring.h"
#include "ColorConv.h"

#ifndef _BASICBONE_H_
#include "basicbone.h"
#endif //_BASICBONE_H_

#ifndef _USERMACHRO_H_
#include "UserMachro.h"
#endif //_USERMACHRO_H_

#ifndef _USER_RGBQUAD_H_
#include "UserRGBQuad.h"
#endif //_USER_RGBQUAD_H_

#ifndef _USERBITMAP_H_
#include "UserBitmap.h"
#endif //_USERBITMAP_H_ 

///** 
//*description   : 동적 이진화 처리하는 객체
//*@parent class : private CBasicBone : 대입 연산자, 복사 생성자 호출 방지용
//*/
class CDynBinProcess : private CBasicBone
{
	//// 멤버 변수 정의 부분
public:

protected:
	int				m_nThresValueDisp;
	CUserBitmap		m_bmpDynBinIn;
	CUserBitmap		m_bmpDynBinOut;

private:

	///// 멤버 함수 정의 부분
public:
	///**
	//*description   : 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CDynBinProcess(void);

	///**
	//*description   : 소멸자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	~CDynBinProcess(void);

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline void SetThreshValueDisp(const int nThresValueDisp) { m_nThresValueDisp = nThresValueDisp; }

	///**
	//*description   : 
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	inline const int GetThreshValueDisp(void) const { return m_nThresValueDisp; }

	///**
	//*description   : 내용 비우기
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	void Clear(void);

	///**
	//*description   : 대화상자 초기화 때 처리할 사항
	//*@param input  : int nThresValueDisp
	//*@param output : -
	//*@return		 :  
	//*/
	bool OnInitDialog(int nThresValueDisp);

	///**
	//*description   :  
	//*@param input  : int nThresValueDisp
	//*@param output : -
	//*@return		 : 정상 수행 여부
	//*/
	bool OnNMCustomdrawSldThreshhold(int nThresValueDisp);

	///**
	//*description   :  
	//*@param input  : const CPaintDC& dcView
	//*@param input  : const CRect& rect
	//*@param output : -
	//*@return		 : 정상 수행 여부
	//*/
	bool OnPaint(const CPaintDC& dcView, const CRect& rect);

	///**
	//*description   : 미리 비트맵 이미지를 받으면서 초기화 
	//*@param input  : 
	//*@param output : CUserBitmap& bitmapNode
	//*@return		 : 정상 수행 여부
	//*/
	bool GetImage(CUserBitmap& bitmapNode ) const;

	///**
	//*description   : 미리 비트맵 이미지를 받으면서 초기화 
	//*@param input  : const CUserBitmap& bitmapNode
	//*@param output : -
	//*@return		 : 정상 수행 여부
	//*/
	bool SetImage(const CUserBitmap& bitmapNode);

protected:

	///**
	//*description   : 초기화
	//*@param input  : int nThresValueDisp
	//*@param output : -
	//*@return		 :  
	//*/
	void Initialize(int nThresValueDisp = 0);

private:

};
#endif //_DYNBINPROCESS_H_
