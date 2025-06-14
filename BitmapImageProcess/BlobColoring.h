// BlobColoring.h: interface for the CBlobColoring class.
//
//////////////////////////////////////////////////////////////////////
#ifndef _BLOBCOLORING_H_ 
#define _BLOBCOLORING_H_
#pragma once

#ifndef _USERMACHRO_H_
#include "UserMachro.h"
#endif //_USERMACHRO_H_

#ifndef _BASICBONE_H_
#include "basicbone.h"
#endif //_BASICBONE_H_

#include <stack>
using namespace std;

class CBlobColoring : private CBasicBone
{
public:
	void fnBlobColoring(int distanceBound);
	CBlobColoring(unsigned char* InImg, int nheight, int nwidth);
	virtual ~CBlobColoring();

private:
	bool push(int vx, int vy);
	bool pop(int& vx, int& vy);
	void m_FindBoundary();
	void m_FindMoment();
	BOOL BoundDist(int rColor, int gColor, int bColor, int rVal, int gVal, int bVal);

public:
	int nBlob;

	typedef struct tagBLOBDATA
	{
		short ltx, lty, rbx, rby;
		int n, pc;
		float cx, cy, r, g, b, u02, u20, u11, m, v;
	} BLOBDATA;
	
	vector<BLOBDATA> blobData;

private:
	int width;
	int height;
	int distanceBound;
	size_t m_MaxStack;
	int rwsize;

	vector<int> m_Coloring;
	stack<int> m_stacky;
	stack<int> m_stackx;

	vector<char> passImg;
	vector<char> m_InImg;
};

#if 0
////////////////////////////////////////////////////////////////////////
////// 이전 버전 통합 개발환경용으로 남겨둔 코드 
////////////////////////////////////////////////////////////////////////
//////class CBlobColoring : private CBasicBone
//////{
//////public:
//////	void fnBlobColoring(int distanceBound);
//////	CBlobColoring(unsigned char* m_InImg, int height, int width);
//////	virtual ~CBlobColoring();
//////
//////private:
//////	CBlobColoring();
//////
//////	int push(int vx, int vy);
//////	int pop(int* vx, int* vy);
//////	void m_FindBoundary();
//////	void m_FindMoment();
//////	BOOL BoundDist(int rColor, int gColor, int bColor, int rVal, int gVal, int bVal);
//////
//////public:
//////	int nBlob;
//////
//////	typedef struct tagBLOBDATA
//////	{
//////		short ltx, lty, rbx, rby;
//////		int n, pc;
//////		float cx, cy, r, g, b, u02, u20, u11, m, v;
//////	} BLOBDATA;
//////	BLOBDATA* blobData;
//////
//////private:
//////	int width;
//////	int height;
//////	int distanceBound;
//////	int top;
//////	int m_MaxStack;
//////	int rwsize;
//////
//////	int* m_Coloring;
//////	int* m_stacky;
//////	int* m_stackx;
//////	unsigned char* passImg;
//////	unsigned char* m_InImg;
//////};
#endif //0

#endif //_BLOBCOLORING_H_
