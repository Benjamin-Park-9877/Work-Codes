/////** 
////*description   : (ColorConv.h) interface for the CColorConv class.
////* 
////*/
#ifndef _COLORCONV_H_
#define _COLORCONV_H_
#pragma once

#ifndef _USERMACHRO_H_
#include "UserMachro.h"
#endif //_USERMACHRO_H_

#ifndef _BASICBONE_H_
#include "basicbone.h"
#endif //_BASICBONE_H_

/////** 
////*description   :    
////*@parent class : private CBasicBone
////*/
class CColorConv : private CBasicBone
{
private:
	const double  UNDEFINED = (0.0F);

public:
	void HSI_To_RGB(double h,double s,double i,double *r,double *g,double *b);
	void RGB_To_HSI(double r,double g,double b,double *h,double *s,double *i);
	void RGB_To_YIQ(double r,double g,double b, double *y,double *i,double *q);
	void RGB_To_Gray(double r, double g, double b, double *gray);
	void Gray_To_RGB(double gray, double *r, double *g, double *b);
	void RGB_To_CMY(double r, double g, double b, double *c, double *m, double *y);
	void CMY_To_RGB(double c, double m, double y, double *r, double *g, double *b);
	void RGB_To_HSV(double r, double g, double b, double *h, double *s, double *v);
	void HSV_To_RGB(double h, double s, double v, double *r, double *g, double *b);
	void RGB_To_HSL(double r, double g, double b, double *h, double *l, double *s);
	void HSL_To_RGB(double h, double l, double s, double *r, double *g, double *b);
	CColorConv();
	virtual ~CColorConv();

};

#if 0 
///////////////////////////////////////
//// 예전 코드를 남겨 둔 것.
//// 통합 개발 환경등이 MAX, MIN을 지원 못할 경우 대비용
//// 추후 예전 버전 통합 개발 환경에서 빌드등이 안정될 경우 삭제할 것
///////////////////////////////////////
////class CColorConv : private CBasicBone
////{
////private:
////	inline double MAX(const double& a, const double& b) { return   (((a) > (b)) ? (a) : (b)); }
////	inline double MIN(const double& a, const double& b) { return   (((a) < (b)) ? (a) : (b)); }
////	const double  UNDEFINED = (0.0F);
////public:
////	void HSI_To_RGB(double h, double s, double i, double* r, double* g, double* b);
////	void RGB_To_HSI(double r, double g, double b, double* h, double* s, double* i);
////	void RGB_To_YIQ(double r, double g, double b, double* y, double* i, double* q);
////	void RGB_To_Gray(double r, double g, double b, double* gray);
////	void Gray_To_RGB(double gray, double* r, double* g, double* b);
////	void RGB_To_CMY(double r, double g, double b, double* c, double* m, double* y);
////	void CMY_To_RGB(double c, double m, double y, double* r, double* g, double* b);
////	void RGB_To_HSV(double r, double g, double b, double* h, double* s, double* v);
////	void HSV_To_RGB(double h, double s, double v, double* r, double* g, double* b);
////	void RGB_To_HSL(double r, double g, double b, double* h, double* l, double* s);
////	void HSL_To_RGB(double h, double l, double s, double* r, double* g, double* b);
////	CColorConv();
////	virtual ~CColorConv();
////};
///////////////////////////////////////
#endif //0

#endif // _COLORCONV_H_
