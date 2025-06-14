// ColorConv.cpp: implementation of the CColorConv class.
//
//////////////////////////////////////////////////////////////////////
#include "pch.h"
#include "ColorConv.h"
#include "math.h"

//////////////////////////////////////////////////////////////////////
// Construction
//////////////////////////////////////////////////////////////////////
CColorConv::CColorConv()
{
}

//////////////////////////////////////////////////////////////////////
// Destruction
//////////////////////////////////////////////////////////////////////
CColorConv::~CColorConv()
{
}

//////////////////////////////////////////////////////////////////////////////////
// RGB_To_Gray - RGB값을 Gray로 바꾼다.
//
// Gray 는 각각 [0,1]사이 값을 갖는다.
// R,G,B는 각각 [0,1]사이 값을 갖는다.
void CColorConv::RGB_To_Gray(double r, double g, double b, double *gray)
{
	*gray = r * 0.30F + g * 0.59F + b * 0.11F;
}

//////////////////////////////////////////////////////////////////////////////////
// Gray_To_RGB - Gray 값을 RGB로 바꾼다. 
//               이과정은 promotion에 해당하는 과정으로 사실상 별의미가 없다.
// Gray 는 각각 [0,1]사이 값을 갖는다.
// R,G,B는 각각 [0,1]사이 값을 갖는다.
void CColorConv::Gray_To_RGB(double gray, double *r, double *g, double *b)
{
	*r = *g = *b = gray;
}


//////////////////////////////////////////////////////////////////////////////////
// CMY_To_RGB - CMY값을 RGB로 바꾼다.
//
// R,G,B는 각각 [0,1]사이 값을 갖는다.
// C,M,Y는 각각 [0,1]사이 값을 갖는다.
void CColorConv::RGB_To_CMY(double r, double g, double b, double *c, double *m, double *y)
{
	*c = 1.0F - r;
	*m = 1.0F - g;
	*y = 1.0F - b;
}


//////////////////////////////////////////////////////////////////////////////////
// CMY_To_RGB - CMY값을 RGB로 바꾼다.
//
// R,G,B는 각각 [0,1]사이 값을 갖는다.
// C,M,Y는 각각 [0,1]사이 값을 갖는다.
void CColorConv::CMY_To_RGB(double c, double m, double y, double *r, double *g, double *b)
{
	*r = 1.0F - c;
	*g = 1.0F - m;
	*b = 1.0F - y;
}

//////////////////////////////////////////////////////////////////////////////////
// RGB_To_HSV - RGB값을 HSV로 바꾼다.
//
// R,G,B는 각각 [0,1]사이 값을 갖는다.
// H는 [0,360) 범위, S,V값은 각각 [0,1]범위를 갖는다.
void CColorConv::RGB_To_HSV(double r, double g, double b, double *h, double *s, double *v)
{
	double max, min;
    
	max = std::max<double>(r,g);
	max = std::max<double>(max,b);
	
	min = std::min<double>(r,g);
	min = std::min<double>(min,b);

	*v = max;                                   // 명도(V) = max(r,g,b)
	*s = (max != 0.0F) ? (max-min)/max : 0.0F;    // 채도(S)을 계산, S=0이면 R=G=B=0
	
	if(*s == 0.0F)	*h = UNDEFINED;
	else                                       // 채도(S)는 != 0
	{
		double delta = max - min;                 // 색상(H)를 구한다.
		if(r == max) *h = (g - b) / delta;     // 색상이 Yello와 Magenta사이 
		else if( g == max) *h = 2.0F + (b - r) / delta; // 색상이 Cyan와 Yello사이 
		else if( b == max) *h = 4.0F + (r - g) / delta; // 색상이 Magenta와 Cyan사이
		
		*h *= 60.0F;
		
		if(*h < 0.0F) *h += 360.0F;           // 색상값을 각도로 바꾼다.
	}
}


//////////////////////////////////////////////////////////////////////////////////
// HSV_To_RGB - HSV값을 RGB로 바꾼다.
//
// H는 [0,360) 범위, S,V값은 각각 [0,1]범위를 갖는다.
// R,G,B는 각각 [0,1]값을 갖는다.
void CColorConv::HSV_To_RGB(double h, double s, double v, double *r, double *g, double *b)
{  
	if(s == 0.0F)                                // 컬러값은 흑백명암값.
	{
		if(h == UNDEFINED) *r = *g = *b = v;     // 이경우 색상 값은 없다.
		else			*r = *g = *b = UNDEFINED;
	} 
	else 
	{                                           // S != 0 이므로 색상(H)이 있다.
		double f, p, q, t;
		int i;
		
		if(h == 360.0F) h = 0.0F;
		h /= 60.0F;                             // H 값은 [0,360)사이 값
		i = (int)h;                             // <=H 인 가장 큰 정수값
		f = h - i;                              // F 는 H 의 실수 부분
		p = v * (1.0F - s);
		q = v * (1.0F - (s * f));
		t = v * (1.0F - (s * (1.0F - f)));
    
		switch(i)
		{
			case 0: *r = v; *g = t; *b = p; break;
			case 1: *r = q; *g = v; *b = p; break;
			case 2: *r = p; *g = v; *b = t; break;
			case 3: *r = p; *g = q; *b = v; break;
			case 4: *r = t; *g = p; *b = v; break;
			case 5: *r = v; *g = p; *b = q; break;
		}
	}
}


//////////////////////////////////////////////////////////////////////////////////
// RGB_To_HLS - RGB값을 HLS로 바꾼다.
//
// R,G,B는 각각 [0,1]값을 갖는다.
// H는 [0,360) 범위, S,V값은 각각 [0,1]범위를 갖는다.
void CColorConv::RGB_To_HSL(double	r, double g, double b, double *h, double *s, double *l)
{
	double v, m, vm;
	double r2, g2, b2;
	
	v = std::max<double>(r,g); 	v = std::max<double>(v,b);
	m = std::min<double>(r,g);	m = std::min<double>(m,b);

	if ((*l = (m + v) / 2.0F) <= 0.0F) return;
	if ((*s = vm = v - m) > 0.0F) *s /= (*l <= 0.5F) ? (v + m ) : (2.0F - v - m) ;
	else return;

	r2 = (v - r) / vm;
	g2 = (v - g) / vm;
	b2 = (v - b) / vm;

	if (r == v)		 *h = (g == m ? 5.0F + b2 : 1.0F - g2);
	else if (g == v) *h = (b == m ? 1.0F + r2 : 3.0F - b2);
	else			 *h = (r == m ? 3.0F + g2 : 5.0F - r2);
	*h *= 60.0F;
}


//////////////////////////////////////////////////////////////////////////////////
// HLS_To_RGB - HLS값을 RGB로 바꾼다.
//
// H는 [0,360) 범위, S,V값은 각각 [0,1]범위를 갖는다.
// R,G,B는 각각 [0,1]값을 갖는다.
void CColorConv::HSL_To_RGB(double h, double sl, double l, double *r, double *g, double *b)
{
	double v;
	
	v = (l <= 0.5F) ? (l * (1.0F + sl)) : (l + sl - l * sl);
	if (v <= 0) *r = *g = *b = 0.0F;
	else 
	{
		int sextant;
		double m, sv, fract, vsf, mid1, mid2;
		
		m = l + l - v;
		sv = (v - m ) / v;
		h /= 60.0F;
		sextant = (int)h;	
		fract = h - sextant;
		vsf = v * sv * fract;
		mid1 = m + vsf;
		mid2 = v - vsf;
		
		switch (sextant) 
		{
			case 0: *r = v;    *g = mid1; *b = m; break;
			case 1: *r = mid2; *g = v;    *b = m; break;
			case 2: *r = m;    *g = v;    *b = mid1; break;
			case 3: *r = m;    *g = mid2; *b = v; break;
			case 4: *r = mid1; *g = m;    *b = v; break;
			case 5: *r = v;    *g = m;    *b = mid2; break;
		}
	}
}



void CColorConv::RGB_To_YIQ(double r, double g, double b, double *y, double *i, double *q)
{
	*y = 0.299f * r + 0.587f * g + 0.114f * b;
	*i = 0.596f * r - 0.275f * g - 0.321f * b;
	*q = 0.212f * r - 0.528f * g + 0.311f * b;
}


//////////////////////////////////////////////////////////////////////////////////
// RGB_To_HSI - RGB값을 HSI로 바꾼다.
//
// R,G,B는 각각 [0,1]값을 갖는다.
// H는 [0,360) 범위, S,V값은 각각 [0,1]범위를 갖는다.
void CColorConv::RGB_To_HSI(double r, double g, double b, double *h, double *s, double *i)
{
    double minc;              /// minimum and maximum RGB values 
    double angle;             /// temp variable used to compute Hue 
	
	minc = std::min<double>(r,g);
	minc = std::min<double>(minc,b);
	
    /// compute intensity 
    *i=(r + g + b) / 3.0f;
	
    /// compute hue and saturation 
    if((r==g) && (g==b))  /// gray-scale 
	{
		*s = 0.0f;
		*h = 0.0f;
		return;
	}
    else
	{
		*s= 1.0f - (3.0f / (r + g + b)) * minc;
		angle = (r - 0.5f * g - 0.5f * b) / (double)sqrt(((r - g) * (r - g)+(r - b) * (g - b)));
		*h = (double)acos(angle);
		*h *= 57.29577951f;          /// convert to degrees 
	}
	
    if(b>g)	*h = 360.0f - *h;
}


//////////////////////////////////////////////////////////////////////////////////
// HSI_To_RGB - HSI값을 RGB로 바꾼다.
//
// H는 [0,360) 범위, S,V값은 각각 [0,1]범위를 갖는다.
// R,G,B는 각각 [0,1]값을 갖는다.
void CColorConv::HSI_To_RGB(double h, double s, double i, double *r, double *g, double *b)
{
    double angle1, angle2, scale;   /// temp variables 
	
    if(i==0.0)    /// BLACK 
	{
		*r = 0.0f;
		*g = 0.0f;
		*b = 0.0f;
		return;
	}
    if(s==0.0)     /// gray-scale  H is undefined
	{
		*r = i;
		*g = i;
		*b = i;
		return;
	}
    if(h<0.0)	h += 360.0f;

    scale = 3.0f * i;
    if(h<=120.0)
	{
		angle1=h*0.017453293f;    /// convert to radians - mul by pi/180 
		angle2=(60.0f-h)*0.017453293f;
		
		*b = (1.0f-s)/3.0f;
		*r = (double)(1.0f + (s*cos(angle1)/cos(angle2)))/3.0f;
		*g = 1.0f-*r-*b;
		*b *= scale;
		*r *= scale;
		*g *= scale;
	}
	else if((h>120.0) && (h<=240.0))
	{
		h -= 120.0f;
		angle1=h*0.017453293f;    /// convert to radians - mul by pi/180 
		angle2=(60.0f-h)*0.017453293f;
		
		*r = (1.0f-s)/3.0f;
		*g = (double)(1.0f + (s*cos(angle1)/cos(angle2)))/3.0f;
		*b = 1.0f - *r - *g;
		*r *= scale;
		*g *= scale;
		*b *= scale;
	}
    else
	{
		h -= 240.0f;
		angle1=h*0.017453293f;    /// convert to radians - mul by pi/180 
		angle2=(60.0f-h)*0.017453293f;
		
		*g = (1.0f-s)/3.0f;
		*b = (double)(1.0 + (s*cos(angle1)/cos(angle2)))/3.0f;
		*r = 1.0f - *g - *b;
		*r *= scale;
		*g *= scale;
		*b *= scale;
	}
}
