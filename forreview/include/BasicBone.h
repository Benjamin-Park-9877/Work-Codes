/////** 
////*description   : 추후 C++ 프로그램 작성시 기반되는 클래스 정의 헤더 파일  
////* 
////*/
#ifndef _BASICBONE_H_
#define _BASICBONE_H_
#pragma once

//*
// 다른 헤더 파일 추가시 이런 형식을 따를 것
//#ifndef _SMAPLE_H_
//#include "sample.h"
//#endif //_SAMPLE_H_
//*/

// 주로 쓸 수 있는 C++ 기본헤더 포함
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

/////** 
////*description   : 추후 C++ 프로그램 작성시 기반되는 클래스  
////*@parent class : -
////*/
class CBasicBone
{
//// 멤버 변수 정의 부분
public:

protected:

private:

//// 멤버 함수 정의 부분

public:

	///**
	//*description   : CBasicBone 클래스용 생성자
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	CBasicBone(void){}
		
	///**
	//*description   : CBasicBone 클래스용 소멸자
	//                 상속 받는 클래스에서 반드시 소멸자를 정의하도록 하기 위해 virtual 선언했음
	//*@param input  : -
	//*@param output : -
	//*@return		 : -
	//*/
	virtual ~CBasicBone(void){}

protected:

private: 
    //////////////////////////////////////////////////////////////////
	// 깊은 복사를 쓰는 경우 아니면, 실수로라도 호출되지 않게 조치함
	// 이동 생성자, 이동 복사도 정의하지 않는다면, 실수로라도 호출되지 않게 조치함
	// 실제 사용할 클래스가 해당 클래스를 상속받아서 만들면 실수로 호출시 컴파일때 잡아줄 수 있음.
	//////////////////////////////////////////////////////////////////
    
	/////**
	////*description	 : CBasicBone 클래스용 복사 생성자(깊은 복사로 만들지 않았다면 호출도 못하게 함)
	////*@param input	 : -
	////*@param output	 : -
	////*@return		 : -
	////*/
	CBasicBone(const CBasicBone& rhs);  
	
	/////**
	////*description	 : CBasicBone 클래스용 이동 생성자(필요할 경우 상속 받은 클래스에서 명시적으로 재정의할 것)
	////*@param input	 : -
	////*@param output	 : -
	////*@return		 : -
	////*/
	CBasicBone(CBasicBone&& rhs) noexcept;

	/////**
	////*description	 : CBasicBone 클래스용 대입 연산자 (깊은 복사로 만들지 않았다면 호출도 못하게 함)
	////*@param input	 : -
	////*@param output	 : -
	////*@return		 : -
	////*/
    CBasicBone& operator=(const CBasicBone& rhs);


	/////**
	////*description	 : CBasicBone 클래스용 이동 대입 연산자 (필요할 경우 상속 받은 클래스에서 명시적으로 재정의할 것)
	////*@param input	 : -
	////*@param output	 : -
	////*@return		 : -
	////*/
	CBasicBone& operator=(CBasicBone&& rhs) noexcept;

	//////////////////////////////////////////////////////////////////
	//// 깊은 복사를 쓰는 경우라면 이런 코드 양식으로 작성할 것
	////CBasicBone(const CBasicBone& p)
	////{  
	////	// 아래 예는 별도로 동적 할당을 받아서 대입
	////	//name= new char[strlen(p.name)+1];  
	////	//strcpy(name, p.name);  
	////}  
	//////////////////////////////////////////////////////////////////	
	//// 대입 연산자도 깊은 복사, 자기 대입 검사등을 반영할 것
	////CBasicBone& operator=(const CBasicBone& p)  
	////{  
	////	if (this == &rhs)   //  일치성 검사, 즉 객체가 같은지, 자기 대입인지 검사한다.  
	////		return *this; 
	////
	////	// 아래 두 종류 코드들 중 한 종류만 선택해서 클래스에 맞춰 수정하기
	////    /* 
	////    // 1. 기존 객체 삭제 
	////	delete []name;  
	////	name= new char[strlen(p.name)+1];   
	////	strcpy(name, p.name);
	////    */
	////    /* 
	////    // 2. 객체 끼리 교환
    ////    CBasicBone temp(rhs);   // rhs의 데이터에 대해 사본을 하나 만든다.  
    ////    swap(temp);         // *this의 데이터를 그 사본의 것과 맞바꾼다.  
    ////    delete temp.pb; 
	////    */
	////	reurn *this;  
	////} 
	//////////////////////////////////////////////////////////////////	
	//// 필요시 값(혹은 복사 객체)를 이용한 대입 연산자도 고려할 수도 있음
	////CBasicBone& operator=(CBasicBone rhs)   
    ////{  
    ////    cout << "CBasicBone& operator=(const CBasicBone& rhs)" << endl;  
    ////  
    ////    swap(rhs);  // *this의 데이터를 그 사본의 데이터와 맞바꾼다.  
    ////  
    ////    delete rhs.pb;  
    ////    return *this;  
    ////}  
	/////////////////////////////////////////////////////////////////
	////// *this의 데이터 및 rhs의 데이터를 맞바꾼다.  
	////void swap(CBasicBone& rhs)  
    ////{  
	////	// 객체끼리 맞바꾸는 작업이므로 실제 사용시 수정 필요
	////  CBasicBone * pOrig = pb;  
	////  pb = new CBasicBone(*rhs.pb);  
	////  rhs.pb = pOrig;       
	////}
	//////////////////////////////////////////////////////////////////
	//// 이동 생성자를 사용하는 경우라면 이런 코드 양식으로 작성할 것
	////CBasicBone(CBasicBone&& p)
	////{  
	////	// 아래 예는 클래스 설계에 따라 다르지만 얕은 복사한 다음 원래 rhs측의 포인터 값을 NULL로 끊음(C++ 표준에 따라 다를수도 있음)
	////	// len = rhs.len; 
	////	// strName = rhs.strName;
	////    // rhs.StrName = NULL; 
	////
	////}  
	//////////////////////////////////////////////////////////////////
	//// 이동 대입 연산자를 사용하는 경우라면 이런 코드 양식으로 작성할 것
	////CBasicBone& operator=(CBasicBone&& p)
	////{  
	////	// 아래 예는 클래스 설계에 따라 다르지만 얕은 복사한 다음 원래 rhs측의 포인터 값을 NULL로 끊음(C++ 표준에 따라 다를수도 있음)
	////	// len = rhs.len; 
	////	// strName = rhs.strName;
	////    // rhs.StrName = NULL; 
	////	// return *this;
	////}  
};

//////////////////////////////////////////////////////////////////
///// 소스 파일 부분
///// 이 파일 한정으로 헤더에 예시를 남겼지만, 다른 클래스들은 왠만하면 cpp로 따로 분리해두어 작성하기
//////////////////////////////////////////////////////////////////
/////** 
////*description   : 추후 C++ 프로그램 작성시 기반되는 클래스 정의 소스 파일 
////*               
////* 
////*/
//#include "pch.h"
//#include "BasicBone.h"
//
/////**
////*description   : CBasicBone 클래스용 생성자
////*@param input  : -
////*@param output : -
////*@return		 : -
////*/
//CBasicBone::CBasicBone(void)
//{
//}
//
/////**
////*description   : CBasicBone 클래스용 소멸자
////                 상속 받는 클래스에서 반드시 소멸자를 정의하도록 하기 위해 virtual 선언했음
////*@param input  : -
////*@param output : -
////*@return		 : -
////*/
//CBasicBone::~CBasicBone(void)
//{
//}
//////////////////////////////////////////////////////////////////

#endif //_BASICBONE_H_
