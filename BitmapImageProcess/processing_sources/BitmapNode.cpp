/////** 
////*description   : 비트맵 영상이 실제 저장되는 객체정의 소스 파일
////*               
////* 
////*/
#include "pch.h"
#include "BitmapNode.h"

///**
//*description   : 비트맵 영상이 실제 저장되는 객체 용 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapNode::CBitmapNode(void) : m_pBmpInfo(NULL) , m_pUcBmpImage(NULL), m_pDibHi(NULL), m_pDibHf(NULL)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::CBitmapNode(void) \n");
#endif //DEBUG

	Initialize();

#ifdef DEBUG
	TraceElements();
#endif //DEBUG

#ifdef DEBUG	
	TRACE("CBitmapNode::CBitmapNode(void) \n");
#endif //DEBUG
}

///**
//*description   : 비트맵 영상이 실제 저장되는 객체 용 소멸자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapNode::~CBitmapNode(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::~CBitmapNode(void) \n");
#endif //DEBUG
	
	Clear();

#ifdef DEBUG
	TRACE("CBitmapNode::~CBitmapNode(void) \n");
#endif //DEBUG
}

///**
//*description   : 비트맵 영상이 실제 저장되는 객체 용 복사 생성자 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapNode::CBitmapNode(const CBitmapNode& rhs) 
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::CBitmapNode(const CBitmapNode& rhs)  \n");
#endif //DEBUG

	m_pBmpInfo = NULL;
	m_pUcBmpImage = NULL;
	m_pDibHi = NULL;
	m_pDibHf = NULL;

	if (this == &rhs)
	{
#ifdef DEBUG
		TRACE("if (this == &rhs) \n");
		TRACE("CBitmapNode::CBitmapNode(const CBitmapNode& rhs)  \n");
#endif //DEBUG
		return ;
	}

	if (SetImage(rhs) == false)
	{
#ifdef DEBUG
		TRACE("if (SetImage(rhs) == false)  \n");
#endif //DEBUG
	}
#ifdef DEBUG
	TRACE("CBitmapNode::CBitmapNode(const CBitmapNode& rhs)  \n");
#endif //DEBUG
}

///**
//*description   : 비트맵 영상이 실제 저장되는 객체 용 대입 연산자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapNode& CBitmapNode::operator=(const CBitmapNode& rhs)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode& CBitmapNode::operator=(const CBitmapNode& rhs)  \n");
#endif //DEBUG

	if (this == &rhs)
	{
#ifdef DEBUG
		TRACE("if (this == &rhs) \n");
		TRACE("CBitmapNode& CBitmapNode::operator=(const CBitmapNode& rhs)  \n");
#endif //DEBUG
		return *this;
	}

	if (SetImage(rhs) == false)
	{
#ifdef DEBUG
		TRACE("if (SetImage(rhs) == false)  \n");
#endif //DEBUG
	}

#ifdef DEBUG
	TRACE("CBitmapNode& CBitmapNode::operator=(const CBitmapNode& rhs)  \n");
#endif //DEBUG
	return *this;
}

///**
//*description   : 객체 초기화 및 메모리 할당
//*@param input  : -
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::Initialize(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::Initialize(void) \n");
#endif //DEBUG

	if (InitializeBitmapInfo() == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapInfo() == false) \n");
		TRACE("CBitmapNode::Initialize(void) \n");
		TRACE(" \n");
#endif //DEBUG

		return false;
	}

	if (InitializeBitmapInfoHeader() == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapInfoHeader() == false) \n");
		TRACE("CBitmapNode::Initialize(void) \n");
		TRACE(" \n");
#endif //DEBUG
		return false;
	}

	if (InitializeBitmapFileHeader() == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapFileHeader() == false) \n");
		TRACE("CBitmapNode::Initialize(void) \n");
		TRACE(" \n");
#endif //DEBUG
		return false;
	}

#ifdef DEBUG
	TRACE("CBitmapNode::Initialize(void) \n");
	TRACE(" \n");
#endif //DEBUG
	return true;
}

///**
//*description   : 객체 초기화 및 지정한 크기의 배열을 가진 메모리 할당
//*@param input  : const size_t& szTotalSize
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::Initialize(const size_t& szTotalSize)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::Initialize(const size_t& szTotalSize) \n");
#endif //DEBUG

	if (szTotalSize <= INVALID_IMAGE_SIZE)
	{
#ifdef DEBUG
		TRACE("if (szTotalSize <= INVALID_IMAGE_SIZE) \n");
		TRACE("CBitmapNode::Initialize(const size_t& szTotalSize) \n");
		TRACE(" \n");
#endif //DEBUG
		return false;
	}

	if (InitializeBitmapInfo() == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapInfo() == false) \n");
		TRACE("CBitmapNode::Initialize(const size_t& szTotalSize) \n");
		TRACE(" \n");
#endif //DEBUG
		return false;
	}

	if (InitializeBitmapInfoHeader() == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapInfoHeader() == false) \n");
		TRACE("CBitmapNode::Initialize(const size_t& szTotalSize) \n");
		TRACE(" \n");
#endif //DEBUG
		return false;
	}

	if (InitializeBitmapFileHeader() == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapFileHeader() == false) \n");
		TRACE("CBitmapNode::Initialize(const size_t& szTotalSize) \n");
		TRACE(" \n");
#endif //DEBUG
		return false;
	}

	if (InitializeBitmapArray(szTotalSize) == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapArray(szTotalSize) == false) \n");
		TRACE("CBitmapNode::Initialize(const size_t& szTotalSize) \n");
		TRACE(" \n");
#endif //DEBUG
	}

#ifdef DEBUG
	TRACE("CBitmapNode::Initialize(const size_t& szTotalSize) \n");
	TRACE(" \n");
#endif //DEBUG
	return true;
}

///**
//*description   : 객체 메모리 해제 및 내용 비우기
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CBitmapNode::Clear(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::Clear(void) \n");
#endif //DEBUG

	ClearBitmapInfo();
	ClearBitmapInfoHeader();
	ClearBitmapFileHeader();
	ClearBitmapArray();

#ifdef DEBUG
	TRACE("CBitmapNode::Clear(void) \n");
#endif //DEBUG
}

#ifdef DEBUG
///**
//*description   : 객체 안의 멤버변수 값 출력창에 보여주기(디버깅용)
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CBitmapNode::TraceElements(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::TraceElements(void) \n");
	TRACE("m_pBmpInfo : %x \n", m_pBmpInfo);
	TRACE("m_pDibHi : %x \n", m_pDibHi);
	TRACE("m_pDibHf : %x \n", m_pDibHf);
	TRACE("m_pUcBmpImage :% x \n",m_pUcBmpImage);
	TRACE("GetMaximumWidth(void) :% d \n",GetMaximumWidth());
	TRACE("GetMaximumHeight(void) :% d \n", GetMaximumHeight());
	TRACE("GetRwSize(void) :% d \n", GetRwSize());
	TRACE("GetBitCount(void) :% d \n", GetBitCount());
	TRACE("GetTotalSize(void) :% d \n", GetTotalSize());
	TRACE("CBitmapNode::TraceElements(void) \n");
#endif //DEBUG
}
#endif //DEBUG

///**
//*description   : BITMAPINFO 초기화 및 메모리 할당
//*@param input  : -
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::InitializeBitmapInfo(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::InitializeBitmapInfo(void) \n");
	TRACE("m_pBmpInfo : %x \n", m_pBmpInfo);
#endif //DEBUG

	ClearBitmapInfo();

	m_pBmpInfo = (BITMAPINFO*)malloc(DEFALUT_BITMAPINFO_HEADERSIZE);

	if (m_pBmpInfo == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pBmpInfo == NULL) ");
		TRACE("m_pBmpInfo : %x \n", m_pBmpInfo);
		TRACE("CBitmapNode::InitializeBitmapInfo(void) \n");
#endif //DEBUG
		return false;
	}

	memset(m_pBmpInfo, 0, DEFALUT_BITMAPINFO_HEADERSIZE);

	for (int i = 0; i < MAXIMUM_PIXEL_VALUE; i++)
	{
		m_pBmpInfo->bmiColors[i].rgbRed = i;
		m_pBmpInfo->bmiColors[i].rgbGreen = i;
		m_pBmpInfo->bmiColors[i].rgbBlue = i;
		m_pBmpInfo->bmiColors[i].rgbReserved = 0;
	}

#ifdef DEBUG
	TRACE("m_pBmpInfo : %x \n", m_pBmpInfo);
	TRACE("CBitmapNode::InitializeBitmapInfo(void) \n");
#endif //DEBUG

	return true;
}

///**
//*description   : BITMAPINFO 메모리 해제 및 내용 비우기
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CBitmapNode::ClearBitmapInfo(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::ClearBitmapInfo(void) \n");
	TRACE("m_pBmpInfo : %x \n", m_pBmpInfo);
#endif //DEBUG

	if (m_pBmpInfo != NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pBmpInfo != NULL) \n");
#endif //DEBUG
		free(m_pBmpInfo);
		m_pBmpInfo = NULL;
	}

#ifdef DEBUG
	TRACE("m_pBmpInfo : %x \n", m_pBmpInfo);
	TRACE("CBitmapNode::ClearBitmapInfo(void) \n");
#endif //DEBUG
}

///**
//*description   : BITMAPINFOHEADER 초기화
//*@param input  : -
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::InitializeBitmapInfoHeader(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::InitializeBitmapInfoHeader(void) \n");
#endif //DEBUG

	ClearBitmapInfoHeader();

	m_pDibHi = new BITMAPINFOHEADER;

	if (m_pDibHi == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pDibHi == NULL) \n");
		TRACE("CBitmapNode::InitializeBitmapInfoHeader(void) \n");
#endif //DEBUG
		return false;
	}

	memset(m_pDibHi, 0, sizeof(BITMAPINFOHEADER));

#ifdef DEBUG
	TRACE("m_pDibHi : %x \n", m_pDibHi);
	TRACE("CBitmapNode::InitializeBitmapInfoHeader(void) \n");
#endif //DEBUG

	return true;
}

///**
//*description   : BITMAPINFOHEADER 메모리 해제 및 내용 비우기
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CBitmapNode::ClearBitmapInfoHeader(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::ClearBitmapInfoHeader(void) \n");
	TRACE("m_pDibHi : %x \n", m_pDibHi);
#endif //DEBUG

	if (m_pDibHi != NULL)
	{
		delete m_pDibHi;
		m_pDibHi = NULL;
	}
#ifdef DEBUG
	TRACE("m_pDibHi : %x \n", m_pDibHi);
	TRACE("CBitmapNode::ClearBitmapInfoHeader(void) \n");
#endif //DEBUG
}

//*description   : 비트맵 파일 헤더 정보 초기화
//*@param input  : -
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::InitializeBitmapFileHeader(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::InitializeBitmapFileHeader(void) \n");
#endif //DEBUG

	ClearBitmapFileHeader();

	m_pDibHf = new BITMAPFILEHEADER;

	if (m_pDibHf == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pDibHf == NULL) \n");
		TRACE("CBitmapNode::InitializeBitmapFileHeader(void) \n");
#endif //DEBUG
		return false;
	}

	memset(m_pDibHf, 0, sizeof(BITMAPFILEHEADER));

#ifdef DEBUG
	TRACE("m_pDibHf : %x \n", m_pDibHf);
	TRACE("CBitmapNode::InitializeBitmapFileHeader(void) \n");
#endif //DEBUG	
	return true;
}

///**
//*description   : 비트맵 파일 헤더 메모리 해제
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CBitmapNode::ClearBitmapFileHeader(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::InitializeBitmapFileHeader(void) \n");
	TRACE("m_pDibHf : %x \n", m_pDibHf);
#endif //DEBUG

	if (m_pDibHf != NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pDibHf != NULL) \n", m_pDibHf);
#endif //DEBUG
		delete m_pDibHf;
		m_pDibHf = NULL;
	}

#ifdef DEBUG
	TRACE("m_pDibHf : %x \n", m_pDibHf);
	TRACE("CBitmapNode::InitializeBitmapFileHeader(void) \n");
#endif //DEBUG
}

///**
//*description   :
//*@param input  : const size_t& size (할당 받을 배열의 크기)
//*@param output : 
//*@return		 : 정상 수행 여부( true : 정상 수행, false : 예외 발생 )
//*/
bool CBitmapNode::InitializeBitmapArray(const size_t& size)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::InitializeBitmapArray(const size_t& size) \n");
	TRACE("size : %d \n", size);
#endif //DEBUG

	if (size <= 0)
	{
#ifdef DEBUG
		TRACE("if (size <= 0) \n");
		TRACE("CBitmapNode::InitializeBitmapArray(const size_t& size) \n");
#endif //DEBUG
		return false;
	}

	ClearBitmapArray();

	m_pUcBmpImage = new unsigned char[(size_t)size];

	if (m_pUcBmpImage == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pUcBmpImage == NULL) \n");
		TRACE("CBitmapNode::InitializeBitmapArray(const size_t& size) \n");
#endif //DEBUG
		return false;
	}
	else
	{
#ifdef DEBUG
		TraceElements();
		TRACE("CBitmapNode::InitializeBitmapArray(const size_t& size) \n");
#endif //DEBUG
		return true;
	}
}

///**
//*description   : 비트맵 영상 배열 메모리 해제 및 내용 비우기
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CBitmapNode::ClearBitmapArray(void)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::ClearBitmapArray(void) \n");
#endif //DEBUG

	if (m_pUcBmpImage != NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pUcBmpImage != NULL) \n");
#endif //DEBUG
	
		delete[] m_pUcBmpImage;
		m_pUcBmpImage = NULL;
	}
#ifdef DEBUG
	TRACE("CBitmapNode::ClearBitmapArray(void) \n");
#endif //DEBUG
}

///**
//*description   : BITMAPINFO 항목 설정
//*@param input  : const BITMAPINFO& bmpInfo
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::SetBitmapInfo(const BITMAPINFO& bmpInfo)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::SetBitmapInfo(const BITMAPINFO& bmpInfo) \n");
#endif //DEBUG

	if (InitializeBitmapInfo() == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapInfo() == false) \n");
		TRACE("CBitmapNode::SetBitmapInfo(const BITMAPINFO& bmpInfo) \n");
#endif //DEBUG
		return false;
	}

	if (m_pBmpInfo == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pBmpInfo == NULL) \n");
		TRACE("CBitmapNode::SetBitmapInfo(void) \n");
#endif //DEBUG
		return false;
	}

	memcpy(m_pBmpInfo, &bmpInfo, sizeof(BITMAPINFO));

#ifdef DEBUG
	TRACE("CBitmapNode::SetBitmapInfo(const BITMAPINFO& bmpInfo) \n");
#endif //DEBUG
	return true;
}

///**
//*description   : BITMAPINFO 항목 설정(포인터로 받아온 경우)
//*@param input  : const BITMAPINFO* bmpInfo
//*@param output : -
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::SetBitmapInfo(const BITMAPINFO* pBmpInfo)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::SetBitmapInfo(const BITMAPINFO* pBmpInfo) \n");
	TRACE("pBmpInfo : %x \n", pBmpInfo);
#endif //DEBUG

	if (pBmpInfo == NULL)
	{
#ifdef DEBUG
		TRACE("if (pBmpInfo == NULL) \n");
		TRACE("CBitmapNode::SetBitmapInfo(const BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG
		return false;
	}

	if (SetBitmapInfo(*pBmpInfo) == false)
	{
#ifdef DEBUG
		TRACE("if (SetBitmapInfo(*pBmpInfo) == false) \n");
		TRACE("CBitmapNode::SetBitmapInfo(const BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG
		return false;
	}

#ifdef DEBUG
	TRACE("CBitmapNode::SetBitmapInfo(const BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG
	return true;
}

///**
//*description   : BITMAPINFO 항목 받아옴
//*@param input  : -
//*@param output : BITMAPINFO& bmpInfo
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::GetBitmapInfo(BITMAPINFO& bmpInfo) const
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::GetBitmapInfo(BITMAPINFO& bmpInfo) const \n");
#endif //DEBUG

	if (m_pBmpInfo == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pBmpInfo == NULL) \n");
		TRACE("CBitmapNode::GetBitmapInfo(BITMAPINFO& bmpInfo) const \n");
#endif //DEBUG
		return false;
	}

	memcpy(&bmpInfo, m_pBmpInfo, sizeof(BITMAPINFO));

#ifdef DEBUG
	TRACE("CBitmapNode::GetBitmapInfo(BITMAPINFO& bmpInfo) const \n");
#endif //DEBUG
	return true;
}

///**
//*description   :  
//*@param input  : const BITMAPINFOHEADER& bmpInfoHead
//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
//*/
bool CBitmapNode::SetBitmapInfoHeader(const BITMAPINFOHEADER& bmpInfoHead)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::SetBitmapInfoHeader(const BITMAPINFOHEADER& bmpInfoHead) \n");
#endif //DEBUG

	InitializeBitmapInfoHeader();

	if (m_pDibHi == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pDibHi == NULL) \n");
		TRACE("CBitmapNode::SetBitmapInfoHeader(const BITMAPINFOHEADER& bmpInfoHead) \n");
#endif //DEBUG
		return false;
	}
	
	memcpy(m_pDibHi, &bmpInfoHead, sizeof(BITMAPINFOHEADER));

#ifdef DEBUG
	TRACE("CBitmapNode::SetBitmapInfoHeader(const BITMAPINFOHEADER& bmpInfoHead) \n");
#endif //DEBUG
	return true;
}

///**
//*description   :  
//*@param input  : const BITMAPINFOHEADER* pBmpInfoHead
//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
//*/
bool CBitmapNode::SetBitmapInfoHeader(const BITMAPINFOHEADER* pBmpInfoHead)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::SetBitmapInfoHeader(const BITMAPINFOHEADER* pBmpInfoHead) \n");
	TRACE("pBmpInfoHead : %x", pBmpInfoHead);
#endif //DEBUG

	if (pBmpInfoHead == NULL)
	{
#ifdef DEBUG
		TRACE("if(pBmpInfoHead == NULL) \n");
		TRACE("CBitmapNode::SetBitmapInfoHeader(const BITMAPINFOHEADER* pBmpInfoHead) \n");
#endif //DEBUG
		return false;
	}

	if (SetBitmapInfoHeader(*pBmpInfoHead) == false)
	{
#ifdef DEBUG
		TRACE("if (SetBitmapInfoHeader(*pBmpInfoHead) == false) \n");
		TRACE("CBitmapNode::SetBitmapInfoHeader(const BITMAPINFOHEADER* pBmpInfoHead) \n");
#endif //DEBUG
		return false;
	}

#ifdef DEBUG
	TRACE("m_pDibHi : %x", m_pDibHi);
	TRACE("CBitmapNode::SetBitmapInfoHeader(const BITMAPINFOHEADER* pBmpInfoHead) \n");
#endif //DEBUG

	return true;
}

///**
//*description   :  
//*@param input  : -
//*@param output : BITMAPINFOHEADER& bmpInfoHead
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::GetBitmapInfoHeader(BITMAPINFOHEADER& bmpInfoHead) const
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::GetBitmapInfoHeader(BITMAPINFOHEADER& bmpInfoHead) const \n");
#endif //DEBUG

	if (m_pDibHi == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pDibHi == NULL) \n");
		TRACE("CBitmapNode::GetBitmapInfoHeader(BITMAPINFOHEADER& bmpInfoHead) const \n");
#endif //DEBUG
		return false;
	}

	memcpy(&bmpInfoHead, m_pDibHi, sizeof(BITMAPINFOHEADER));

#ifdef DEBUG
	TRACE("CBitmapNode::GetBitmapInfoHeader(BITMAPINFOHEADER& bmpInfoHead) const \n");
#endif //DEBUG

	return true;
}

///**
//*description   :  
//*@param input  : const BITMAPFILEHEADER& bmpFileHead
//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
//*/
bool CBitmapNode::SetBitmapFileHeader(const BITMAPFILEHEADER& bmpFileHead)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::SetBitmapFileHeader(const BITMAPFILEHEADER& bmpFileHead) \n");
#endif //DEBUG

	InitializeBitmapFileHeader();

	if (m_pDibHf == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pDibHf == NULL) \n");
		TRACE("CBitmapNode::SetBitmapFileHeader(const BITMAPFILEHEADER& bmpFileHead) \n");
#endif //DEBUG
		return false;
	}

	memcpy(m_pDibHf, &bmpFileHead, sizeof(BITMAPFILEHEADER));

#ifdef DEBUG
	TRACE("m_pDibHf : %x \n", m_pDibHf);
	TRACE("CBitmapNode::SetBitmapFileHeader(const BITMAPFILEHEADER& bmpFileHead) \n");
#endif //DEBUG

	return true;
}

///**
//*description   :  
//*@param input  : const BITMAPFILEHEADER* pBmpFileHead
//*@return		 : 정상 수행 여부( TRUE : 정상 수행, FALSE : 예외 발생 ) 
//*/
bool CBitmapNode::SetBitmapFileHeader(const BITMAPFILEHEADER* pBmpFileHead)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::SetBitmapFileHeader(const BITMAPFILEHEADER* pBmpFileHead) \n");
	TRACE("pBmpFileHead : %x", pBmpFileHead);
#endif //DEBUG

	if (pBmpFileHead == NULL)
	{
#ifdef DEBUG
		TRACE("if(pBmpFileHead == NULL) \n");
		TRACE("CBitmapNode::SetBitmapFileHeader(const BITMAPFILEHEADER* pBmpFileHead) \n");
#endif //DEBUG
		return false;
	}

	if (SetBitmapFileHeader(*pBmpFileHead) == false)
	{
#ifdef DEBUG
		TRACE("if (SetBitmapFileHeader(*pBmpInfoHead) == false) \n");
		TRACE("CBitmapNode::SetBitmapFileHeader(const BITMAPFILEHEADER* pBmpFileHead) \n");
#endif //DEBUG
		return false;
	}

#ifdef DEBUG
	TRACE("m_pDibHf : %x", m_pDibHf);
	TRACE("CBitmapNode::SetBitmapFileHeader(const BITMAPFILEHEADER* pBmpFileHead) \n");
#endif //DEBUG

	return true;
}

///**
//*description   :  
//*@param input  : -
//*@param output : BITMAPFILEHEADER& bmpFileHead
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::GetBitmapFileHeader(BITMAPFILEHEADER& bmpFileHead) const
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::GetBitmapFileHeader(BITMAPFILEHEADER& bmpFileHead) const \n");
#endif //DEBUG

	if (m_pDibHf == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pDibHi == NULL) \n");
		TRACE("CBitmapNode::GetBitmapFileHeader(BITMAPFILEHEADER& bmpFileHead) const \n");
#endif //DEBUG
		return false;
	}

	memcpy(&bmpFileHead, m_pDibHf, sizeof(BITMAPINFO));

#ifdef DEBUG
	TRACE("CBitmapNode::GetBitmapFileHeader(BITMAPFILEHEADER& bmpFileHead) const \n");
#endif //DEBUG

	return true;
}

///**
//*description   : 
//*@param input  : unsigned char*	pUcBmpImage
//*@param input  : BITMAPINFO*		pBmpInfo
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG

	if (pUcBmpImage == NULL)
	{
#ifdef DEBUG
		TRACE("if (pUcBmpImage == NULL) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG
		return false;
	}

	if ( pBmpInfo == NULL )
	{
#ifdef DEBUG
		TRACE("if ( pBmpInfo == NULL ) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG
		return false;
	}

	if (Initialize() == false)
	{
#ifdef DEBUG
		TRACE("if (Initialize() == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG
		return false;
	}

	if (SetBitmapInfo(pBmpInfo) == false)
	{
#ifdef DEBUG
		TRACE("if (SetBitmapInfo(pBmpInfo) == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG
		return false;
	}

	memcpy(m_pDibHi, &pBmpInfo->bmiHeader, sizeof(BITMAPINFOHEADER));

	if (InitializeBitmapArray((GetRwSize() * GetMaximumHeight())) == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapArray((GetRwSize() * GetMaximumHeight())) == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG
		return false;
	}
	
	memcpy(m_pUcBmpImage, pUcBmpImage, (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));
		
#ifdef DEBUG
	TraceElements();
	TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG

	return true;
}

///**
//*description   :  
//*@param input  : unsigned char*		pUcBmpImage
//*@param input  : BITMAPINFOHEADER*	pDibHi
//*@param input  : BITMAPFILEHEADER*	pDibHf
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG

	if (pUcBmpImage == NULL)
	{
#ifdef DEBUG
		TRACE("if (pUcBmpImage == NULL) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (pDibHi == NULL)
	{
#ifdef DEBUG
		TRACE("if (pDibHi == NULL) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (pDibHf == NULL)
	{
#ifdef DEBUG
		TRACE("if (pDibHf == NULL) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (Initialize() == false)
	{
#ifdef DEBUG
		TRACE("if (Initialize() == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (SetBitmapInfoHeader(pDibHi) == false)
	{
#ifdef DEBUG
		TRACE("if (SetBitmapInfoHeader(pDibHi) == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (SetBitmapFileHeader(pDibHf) == false)
	{
#ifdef DEBUG
		TRACE("if (SetBitmapFileHeader(pDibHf) == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	memcpy(&m_pBmpInfo->bmiHeader, pDibHi, sizeof(BITMAPINFOHEADER));

	if (InitializeBitmapArray((GetRwSize() * GetMaximumHeight())) == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapArray((GetRwSize() * GetMaximumHeight())) == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG
		return false;
	}

	memcpy(m_pUcBmpImage, pUcBmpImage, (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

#ifdef DEBUG
	TraceElements();
	TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
	return true;
}

///**
//*description   :  
//*@param input  : unsigned char*		pUcBmpImage
//*@param input  : BITMAPINFO*			pBmpInfo  
//*@param input  : BITMAPINFOHEADER*	pDibHi
//*@param input  : BITMAPFILEHEADER*	pDibHf
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::SetImage(unsigned char* pUcBmpImage,  BITMAPINFO* pBmpInfo,  BITMAPINFOHEADER* pDibHi,  BITMAPFILEHEADER* pDibHf)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG

	if (pUcBmpImage == NULL)
	{
#ifdef DEBUG
		TRACE("if (pUcBmpImage == NULL) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (pDibHi == NULL)
	{
#ifdef DEBUG
		TRACE("if (pDibHi == NULL) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (pDibHf == NULL)
	{
#ifdef DEBUG
		TRACE("if (pDibHf == NULL) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (pBmpInfo == NULL)
	{
#ifdef DEBUG
		TRACE("if (pBmpInfo == NULL) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (Initialize() == false)
	{
#ifdef DEBUG
		TRACE("if (Initialize() == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (SetBitmapInfoHeader(pDibHi) == false)
	{
#ifdef DEBUG
		TRACE("if (SetBitmapInfoHeader(pDibHi) == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (SetBitmapFileHeader(pDibHf) == false)
	{
#ifdef DEBUG
		TRACE("if (SetBitmapFileHeader(pDibHf) == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (SetBitmapInfo(pBmpInfo) == false)
	{
#ifdef DEBUG
		TRACE("if (SetBitmapInfo(pBmpInfo) == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	if (InitializeBitmapArray((GetRwSize() * GetMaximumHeight())) == false)
	{
#ifdef DEBUG
		TRACE("if (InitializeBitmapArray((GetRwSize() * GetMaximumHeight())) == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
		return false;
	}

	memcpy(m_pUcBmpImage, pUcBmpImage, (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

#ifdef DEBUG
	TraceElements();
	TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) \n");
#endif //DEBUG
	return true;

}

///**
//*description   :  
//*@param input  : const CBitmapNode& rhs
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
bool CBitmapNode::SetImage(const CBitmapNode& rhs)
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::SetImage(const CBitmapNode& rhs) \n");
#endif //DEBUG

	if (this == &rhs)
	{
#ifdef DEBUG
		TRACE("if (this == &rhs) \n");
		TRACE("CBitmapNode::SetImage(const CBitmapNode& rhs) \n");
#endif //DEBUG
		return false;
	}

	if (SetImage(rhs.c_arr(),rhs.GetBitmapInfo(),rhs.GetBimapInfoHeader(),rhs.GetBimapFileHeader()) == false)
	{
#ifdef DEBUG		
		TRACE("CBitmapNode::SetImage(const CBitmapNode& rhs) \n");
#endif //DEBUG
		return false;
	}

#ifdef DEBUG
	TraceElements();
	TRACE("CBitmapNode::SetImage(const CBitmapNode& rhs) \n");
#endif //DEBUG
	return true;
}


///**
//*description   : 
//*@param output  : unsigned char*	pUcBmpImage
//*@param output  : BITMAPINFO*		pBmpInfo
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
const bool CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) const
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) const \n");
#endif //DEBUG

	if (pUcBmpImage == NULL)
	{
#ifdef DEBUG
		TRACE("if (pUcBmpImage == NULL) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) const \n");
#endif //DEBUG
		return false;
	}

	if (pBmpInfo == NULL)
	{
#ifdef DEBUG
		TRACE("if (pBmpInfo == NULL) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) const \n");
#endif //DEBUG
		return false;
	}

	if (m_pUcBmpImage == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pUcBmpImage == NULL) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) const \n");
#endif //DEBUG
		return false;
	}

	if (m_pBmpInfo == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pBmpInfo == NULL) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) const \n");
#endif //DEBUG
		return false;
	}

	if (GetBitmapInfo(*pBmpInfo) == false)
	{
#ifdef DEBUG
		TRACE("if (GetBitmapInfo(*pBmpInfo) == false) \n");
		TRACE("CBitmapNode::SetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) \n");
#endif //DEBUG
		return false;
	}

	memcpy( pUcBmpImage, m_pUcBmpImage, (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

#ifdef DEBUG
	TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFO* pBmpInfo) const \n");
#endif //DEBUG
	return true;
}

///**
//*description   :  
//*@param output  : unsigned char*		pUcBmpImage
//*@param output  : BITMAPINFOHEADER*	pDibHi
//*@param output  : BITMAPFILEHEADER*	pDibHf
//*@return		 : 정상 수행 여부 (true : 정상수행, false : 문제 생김)
//*/
const bool CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const
{
#ifdef DEBUG
	TRACE(" \n");
	TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const \n");
#endif //DEBUG

	if (pUcBmpImage == NULL)
	{
#ifdef DEBUG
		TRACE("if (pUcBmpImage == NULL) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const \n");
#endif //DEBUG
		return false;
	}

	if (pDibHi == NULL)
	{
#ifdef DEBUG
		TRACE("if (pDibHi == NULL) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const \n");
#endif //DEBUG
		return false;
	}

	if (pDibHf == NULL)
	{
#ifdef DEBUG
		TRACE("if (pDibHf == NULL) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const \n");
#endif //DEBUG
		return false;
	}

	if (m_pUcBmpImage == NULL)
	{
#ifdef DEBUG
		TRACE("if (m_pUcBmpImage == NULL) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const \n");
#endif //DEBUG
		return false;
	}

	if ( m_pDibHi == NULL )
	{
#ifdef DEBUG
		TRACE("if (m_pDibHi == NULL) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const \n");
#endif //DEBUG
		return false;
	}

	if ( m_pDibHf == NULL )
	{
#ifdef DEBUG
		TRACE("if (m_pDibHf == NULL) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const \n");
#endif //DEBUG
		return false;
	}

	if (GetBitmapInfoHeader(*pDibHi) == false)
	{
#ifdef DEBUG
		TRACE("if (GetBitmapInfoHeader(*pDibHi) == false) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const \n");
#endif //DEBUG
		return false;
	}

	if (GetBitmapFileHeader(*pDibHf) == false)
	{
#ifdef DEBUG
		TRACE("if (GetBitmapFileHeader(*pDibHf) == false) \n");
		TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const \n");
#endif //DEBUG
		return false;
	}

	memcpy(pUcBmpImage, m_pUcBmpImage, (size_t)(GetRwSize() * GetMaximumHeight() * sizeof(unsigned char)));

#ifdef DEBUG
	TRACE("CBitmapNode::GetImage(unsigned char* pUcBmpImage, BITMAPINFOHEADER* pDibHi, BITMAPFILEHEADER* pDibHf) const \n");
#endif //DEBUG
	return true;
}