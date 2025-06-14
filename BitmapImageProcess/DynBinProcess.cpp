/////** 
////*description   : 동적 이진화를 처리하는 객체 정의 소스파일
////*               
////* 
////*/
#include "pch.h"
#include "DynBinProcess.h"
#include "MainFrm.h"
#include "ChildFrm.h"
#include "BitmapImageProcessDoc.h"
#include "BitmapImageProcessView.h"

///**
//*description   : 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CDynBinProcess::CDynBinProcess::CDynBinProcess(void)
{
	m_nThresValueDisp = 0;
}

///**
//*description   : 소멸자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CDynBinProcess::~CDynBinProcess(void)
{
	Clear();
}

///**
//*description   : 내용 비우기
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CDynBinProcess::Clear(void)
{
	m_bmpDynBinIn.Clear();
	m_bmpDynBinOut.Clear();
}

///**
//*description   : 대화상자 초기화 때 처리할 사항
//*@param input  : int nThresValueDisp
//*@param output : -
//*@return		 :  
//*/
bool  CDynBinProcess::OnInitDialog(int nThresValueDisp)
{

	SetThreshValueDisp(nThresValueDisp);

	return true;
}

///**
//*description   : 동적할당 없는 초기화
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CDynBinProcess::Initialize(int nThresValueDisp /*=0*/ )
{
	SetThreshValueDisp(nThresValueDisp);
	Clear();
}

///**
//*description   : 미리 비트맵 이미지를 받으면서 초기화 
//*@param input  : const CBitmapNode& bitmapNode
//*@param output : -
//*@return		 : 정상 수행 여부
//*/
bool CDynBinProcess::SetImage(const CUserBitmap& bitmapNode)
{
	if (bitmapNode.GetBitCount() != 24)
	{
		return false;
	}

	Clear();

	if (m_bmpDynBinIn.SetImage(bitmapNode) == false)
	{
		return false;
	}

	if (m_bmpDynBinOut.SetImage(bitmapNode) == false)
	{
		return false;
	}

	return true;
}

///**
//*description   :  
//*@param input  : int nThresValueDisp
//*@param output : -
//*@return		 : 정상 수행 여부
//*/
bool CDynBinProcess::OnNMCustomdrawSldThreshhold(int nThresValueDisp)
{
	SetThreshValueDisp(nThresValueDisp);
	
	int height = m_bmpDynBinIn.GetMaximumHeight();
	int width = m_bmpDynBinIn.GetMaximumWidth();
	int bitcount = m_bmpDynBinIn.GetBitCount();
	int rwsize = m_bmpDynBinIn.GetRwSize();

	int index = 0;
	int index2 = 0;
	int i = 0;
	int j = 0;
	
	int LUT[256];
	for (i = 0; i < 256; i++) LUT[i] = i > m_nThresValueDisp ? (unsigned char)255 : 0;

	if (bitcount == 24)
	{
		for (i = 0; i < height; i++)
		{
			index = (height - i - 1) * rwsize;
			for (j = 0; j < width; j++)
			{
				index2 = index + 3 * j;
				m_bmpDynBinOut[index2] = LUT[(int)(m_bmpDynBinIn[index2])];
				m_bmpDynBinOut[index2 + 1] = LUT[(int)(m_bmpDynBinIn[index2 + 1])];
				m_bmpDynBinOut[index2 + 2] = LUT[(int)(m_bmpDynBinIn[index2 + 2])];
			}
		}
	}
	else if (m_bmpDynBinIn.GetBitCount() == 8)
	{
		for (i = 0; i < height; i++)
		{
			index = (height - i - 1) * rwsize;
			for (j = 0; j < width; j++)
			{
				index2 = index + j;
				m_bmpDynBinOut[index2] = LUT[(int)(m_bmpDynBinIn[index2])];
			}
		}
	}
	else
	{
		return false;
	}
	return true;
}

///**
//*description   :  
//*@param input  : const CPaintDC& dcView
//*@param input  : const CRect& rect
//*@param output : -
//*@return		 : 정상 수행 여부
//*/
bool CDynBinProcess::OnPaint(const CPaintDC& dcView, const CRect& rect)
{
	StretchDIBits(dcView.m_hDC, rect.left, rect.top, rect.right, rect.bottom, 0, 0,
		m_bmpDynBinOut.GetMaximumWidth(), m_bmpDynBinOut.GetMaximumHeight(),
		m_bmpDynBinOut.c_arr_const(), m_bmpDynBinOut.GetBitmapInfo(), BI_RGB, SRCCOPY);

	return true;
}

///**
//*description   : 미리 비트맵 이미지를 받으면서 초기화 
//*@param input  : 
//*@param output : CBitmapNode& bitmapNode
//*@return		 : 정상 수행 여부
//*/
bool CDynBinProcess::GetImage(CUserBitmap& bitmapNode) const
{
	if (m_bmpDynBinOut.c_arr_const() == NULL)
	{
		return false;
	}

	if (bitmapNode.SetImage(m_bmpDynBinOut) == false)
	{
		return false;
	}

	return true;
}