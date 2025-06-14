#include "pch.h"
#include "BitmapAction.h"

///**
//*description   : 비트맵 영상 하나의 동작 객체 용 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapAction::CBitmapAction()
{
	m_pCuserRGBQuad = NULL;
	m_pCbmpElements = NULL;
	Initialize();
}

///**
//*description   : 비트맵 영상 하나의 동작 객체 용 소멸자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapAction::~CBitmapAction()
{
	Clear();
}

///**
//*description   : 비트맵 영상 하나의 동작 객체 용 깊은 복사 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapAction::CBitmapAction(const CBitmapAction& rhs)
{
	m_pCuserRGBQuad = NULL;
	m_pCbmpElements = NULL;

	Set(rhs);
}

///**
//*description   : 비트맵 영상 하나의 동작 객체 용 이동 복사 생성자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapAction::CBitmapAction(CBitmapAction&& rhs) noexcept
{
	m_pCuserRGBQuad = NULL;
	m_pCbmpElements = NULL;

	m_pCuserRGBQuad = rhs.m_pCuserRGBQuad;
	m_pCbmpElements = rhs.m_pCbmpElements;

	rhs.m_pCuserRGBQuad = NULL;
	rhs.m_pCbmpElements = NULL;
}

///**
//*description   : 비트맵 영상 하나의 동작 객체 용 깊은 복사 대입 연산자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
CBitmapAction& CBitmapAction::operator=(const CBitmapAction& rhs)
{
	if (this != &rhs)
	{
		Set(rhs);
	}
	return *this;
}

///**
//*description   : 비트맵 영상 하나의 동작 객체 용 이동 대입 연산자
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/	
CBitmapAction& CBitmapAction::operator=(CBitmapAction&& rhs) noexcept
{
	m_pCuserRGBQuad = rhs.m_pCuserRGBQuad;
	m_pCbmpElements = rhs.m_pCbmpElements;

	rhs.m_pCuserRGBQuad = NULL;
	rhs.m_pCbmpElements = NULL;
	return *this;
}

///**
//*description   : 비트맵 영상 하나의 동작 객체 동적할당 메모리 해제
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
void CBitmapAction::Clear(void)
{
	ClearCUserRGBQuad();
	ClearCUserBitmap();
}

///**
//*description   : 비트맵 영상 하나의 동작 객체 동적할당 내부 변수 초기화
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
bool CBitmapAction::Initialize(void)
{
	if (InitializeCuserRGBQuad() == false)
	{
		return false;
	}

	if (InitializeCUserBitmap() == false)
	{
		return false;
	}

	return true;
}

///**
//*description   :  
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
bool CBitmapAction::InitializeCuserRGBQuad(void)
{
	m_pCuserRGBQuad = new CUserRGBQuad;

	if (m_pCuserRGBQuad == NULL)
	{
		return false;
	}

	m_pCuserRGBQuad->Initialize();

	return true;
}

///**
//*description   : 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
bool CBitmapAction::InitializeCUserBitmap(void)
{
	m_pCbmpElements = new CUserBitmap;

	if (m_pCbmpElements == NULL)
	{
		return false;
	}
	return true;
}

///**
//*description   : 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
bool CBitmapAction::Set(const CBitmapAction& rhs) 
{
	if ( this == &rhs )
	{
		return false;
	}

	if (rhs.m_pCbmpElements == NULL)
	{
		return false;
	}

	if (rhs.m_pCbmpElements->c_arr_const() == NULL)
	{
		return false;
	}

	if(rhs.m_pCbmpElements->GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (rhs.m_pCbmpElements->GetBimapFileHeader() == NULL)
	{
		return false;
	}

	if (rhs.m_pCbmpElements->GetBimapInfoHeader() == NULL)
	{
		return false;
	}

	if (rhs.m_pCuserRGBQuad == NULL)
	{
		return false;
	}

	if (Set(rhs.m_pCbmpElements, rhs.m_pCuserRGBQuad) == false)
	{
		return false;
	}

	return true;

}

///**
//*description   : 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
bool CBitmapAction::Set(const CUserBitmap* pUserBitmap)
{
	if (pUserBitmap == NULL)
	{
		return false;
	}

	if (pUserBitmap->c_arr_const() == NULL)
	{
		return false;
	}

	if (pUserBitmap->GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (pUserBitmap->GetBimapFileHeader() == NULL)
	{
		return false;
	}

	if (pUserBitmap->GetBimapInfoHeader() == NULL)
	{
		return false;
	}

	Clear();

	if (Initialize() == false)
	{
		return false;
	}

	if (m_pCbmpElements->SetImage(*pUserBitmap) == false)
	{
		return false;
	}

	return true;
}

///**
//*description   : 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
bool CBitmapAction::Set( const CUserBitmap* pUserBitmap, const CUserRGBQuad* pRGBQuad ) 
{
	if (pUserBitmap == NULL)
	{
		return false;
	}

	if (pUserBitmap->c_arr_const() == NULL)
	{
		return false;
	}

	if (pUserBitmap->GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (pUserBitmap->GetBimapFileHeader() == NULL)
	{
		return false;
	}

	if (pUserBitmap->GetBimapInfoHeader() == NULL)
	{
		return false;
	}

	if (pRGBQuad == NULL)
	{
		return false;
	}

	Clear();

	if (Initialize() == false)
	{
		return false;
	}

	if (m_pCuserRGBQuad->Set(*pRGBQuad) == false)
	{
		return false;
	}

	if (m_pCbmpElements->SetImage(*pUserBitmap) == false)
	{
		return false;
	}

	return true;
}

///**
//*description   : 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
bool CBitmapAction::Get(CBitmapAction& rhs)
{
	if (this == &rhs)
	{
		return false;
	}

	if (m_pCbmpElements == NULL)
	{
		return false;
	}

	if (m_pCuserRGBQuad == NULL)
	{
		return false;
	}

	rhs.Clear();

	if (rhs.Initialize() == false)
	{
		return false;
	}

	if (rhs.m_pCuserRGBQuad->Set(*m_pCuserRGBQuad) == false)
	{
		return false;
	}

	if (rhs.m_pCbmpElements->SetImage(*m_pCbmpElements) == false)
	{
		return false;
	}

	return true;
}

//*description   : 
//*@param input  : -
//*@param output : -
//*@return		 : -
//*/
bool CBitmapAction::Get(CUserBitmap* pUserBitmap)
{
	if (m_pCbmpElements == NULL)
	{
		return false;
	}

	if (pUserBitmap == NULL)
	{
		return false;
	}

	if (pUserBitmap->SetImage(*m_pCbmpElements) == false)
	{
		return false;
	}

	return true;
}

//*description   : 
//*@param input  :  
//*@param output : -
//*@return		 : 
//*/
const size_t  CBitmapAction::GetImageWidth(void) const
{
	if (m_pCbmpElements == NULL)
	{
		return 0;
	}

	if (m_pCbmpElements->GetBimapInfoHeader() == NULL)
	{
		return 0;
    }

	return m_pCbmpElements->GetMaximumWidth();
}

//*description   : 
//*@param input  :  
//*@param output : -
//*@return		 :  
//*/
const size_t  CBitmapAction::GetImageHeight(void) const
{
	if (m_pCbmpElements == NULL)
	{
		return 0;
	}

	if (m_pCbmpElements->GetBimapInfoHeader() == NULL)
	{
		return 0;
	}

	return m_pCbmpElements->GetMaximumHeight();
}

//*description   : 
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
const int CBitmapAction::GetImageBitCount(void) const
{
	if (m_pCbmpElements == NULL)
	{
		return 0;
	}

	if (m_pCbmpElements->GetBimapInfoHeader() == NULL)
	{
		return 0;
	}

	return m_pCbmpElements->GetBitCount();
}

//*description   : 
//*@param input  :
//*@param output : -
//*@return		 :  
//*/
const unsigned long  CBitmapAction::GetImageRwSize(void) const
{
	if (m_pCbmpElements == NULL)
	{
		return 0;
	}

	if (m_pCbmpElements->GetBimapInfoHeader() == NULL)
	{
		return 0;
	}
	
	return m_pCbmpElements->GetRwSize();
}

//*description   : 
//*@param input  :
//*@param output : -
//*@return		 :  
//*/
const unsigned long CBitmapAction::GetTotalSize(void) const
{
	if (m_pCbmpElements == NULL)
	{
		return 0;
	}

	if (m_pCbmpElements->GetBimapInfoHeader() == NULL)
	{
		return 0;
	}

	return m_pCbmpElements->GetTotalSize();

}

//*description   : 
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CBitmapAction::GetImageSize(CSize& csSizeImage) const
{
	csSizeImage.cx = GetImageWidth();
	csSizeImage.cy = GetImageHeight();
}

//*description   : User Image를 지정된 정보로 화면 출력
//*@param input  : CDC* pDC					출력할 DC 포인터
//*@param output : -
//*@return		 : 정상동작 수행여부(true:동작함,false:실패함)
//*/
bool CBitmapAction::DrawImage(CDC* pDC)
{
	if (pDC == NULL)
	{
		return false;
	}

	if (m_pCbmpElements == NULL)
	{
		return false;
	}

	if (m_pCbmpElements->GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (m_pCbmpElements->c_arr_const() == NULL)
	{
		return false;
	}


	SetDIBitsToDevice(pDC->GetSafeHdc(), 0, 0,
					  GetImageWidth(), GetImageHeight(),
					  0, 0, 0, GetImageHeight(),
					  m_pCbmpElements->c_arr_const(), m_pCbmpElements->GetBitmapInfo(), DIB_RGB_COLORS);

	return true;
}


//*description   : 클립보드로 복사하기
//*@param input  : -
//*@param output : -
//*@return		 :  
//*/
bool  CBitmapAction::CopyClipboard(void)
{
	if (m_pCbmpElements == NULL)
	{
		return false;
	}

	if (m_pCbmpElements->c_arr_const() == NULL)
	{
		return false;
	}

	if (m_pCbmpElements->GetBitmapInfo() == NULL)
	{
		return false;
	}

	if (m_pCbmpElements->GetBimapInfoHeader() == NULL)
	{
		return false;
	}

	CopyClipboard(m_pCbmpElements->c_arr_const(), (int)GetImageHeight(), (int)GetImageWidth(), (int)GetImageBitCount());

	return true;
}

//*description   : 클립보드로 복사하기
//*@param input  : unsigned char	*m_CpyImg
//*@param input  : int				height
//*@param input  : int				width
//*@param input  : int				biBitCount 
//*@param output : -
//*@return		 :  
//*/
void CBitmapAction::CopyClipboard(const unsigned char* m_CpyImg, int height, int width, int biBitCount)
{
	if (m_CpyImg == NULL)
	{
		return;
	}

	if (height <= 0)
	{
		return;
	}

	if (width <= 0)
	{
		return;
	}

	if (biBitCount != 8 && biBitCount != 24)
	{
		return;
	}

	// 클립보드에 복사하기 위한 파일의 길이를 구함
	int rwsize = WIDTHBYTES(biBitCount * width);
	DWORD dwBitsSize = sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD) * MAXIMUM_PIXEL_VALUE + rwsize * height * sizeof(unsigned char); //

	// 메모리 할당(파일헤드만 제외시킨 길이)
	HGLOBAL m_hImage = NULL;
	LPSTR pDIB = NULL;

	m_hImage = (HGLOBAL)::GlobalAlloc(GMEM_MOVEABLE | GMEM_ZEROINIT, dwBitsSize);

	if (m_hImage == NULL)
	{
		return;
	}

	pDIB = (LPSTR) ::GlobalLock((HGLOBAL)m_hImage);

	if (pDIB == NULL)
	{
		return;
	}

	// 데이타복사 
	BITMAPINFOHEADER dibCpyHi;

	m_pCbmpElements->GetBimapInfoHeader(dibCpyHi);

	dibCpyHi.biBitCount = biBitCount;
	dibCpyHi.biHeight = height;
	dibCpyHi.biWidth = width;
	dibCpyHi.biSizeImage = height * rwsize;

	if (biBitCount == 8) dibCpyHi.biClrUsed = dibCpyHi.biClrImportant = MAXIMUM_PIXEL_VALUE;

	// 코드 수정으로 인해서 버퍼 오버런 발생 위험 있음. 
	// 추후 확인 필요
	memcpy(pDIB, &dibCpyHi, sizeof(BITMAPINFOHEADER));

	if (biBitCount == 8)
	{		
		memcpy(pDIB + sizeof(BITMAPINFOHEADER), m_pCuserRGBQuad->Get(), sizeof(RGBQUAD) * MAXIMUM_PIXEL_VALUE);
		memcpy(pDIB + dwBitsSize - dibCpyHi.biSizeImage, m_CpyImg, dibCpyHi.biSizeImage);
	}
	else memcpy(pDIB + sizeof(BITMAPINFOHEADER), m_CpyImg, dibCpyHi.biSizeImage);

	// 클립보드 복사 
	::OpenClipboard(NULL);
	::SetClipboardData(CF_DIB, m_hImage);
	::CloseClipboard();

	::GlobalUnlock((HGLOBAL)m_hImage);
	GlobalFree(m_hImage);
}

//*description   : 
//*@param input  :  
//*@param input  :  
//*@param input  : int				height
//*@param input  : int				width
//*@param input  : float			*Mask
//*@param input  : int				winsize
//*@param output : -
//*@return		 :  
//*/
bool CBitmapAction::ImgConvolution(std::vector<unsigned char>& InImg, std::vector<unsigned char>& OutImg, const size_t& height, const size_t& width, std::vector<float>& Mask, int winsize)
{
	if (InImg.empty() == true) { return false; }

	if (OutImg.empty() == true) { return false; }

	if (Mask.empty() == true) { return false; }

	if (height <= INVALID_IMAGE_SIZE) { return false; }

	if (width <= INVALID_IMAGE_SIZE) { return false; }

	if (winsize <= INVALID_IMAGE_SIZE) { return false; }

	// 출력 메모리 초기화 
	//memset(OutImg, 0, height * width * sizeof(unsigned char));
	std::fill(OutImg.begin(), OutImg.end(), 0);

	// winsize 절반의 offset크기를 계산 
	int n = (winsize - 1) >> 1;

	size_t i = 0;
	size_t j = 0;
	int k = 0;
	int l = 0;
	size_t index1 = 0;
	size_t index2 = 0;
	size_t index3 = 0;
	double sum = 0.0;

	for (i = n; i < height - n; i++)
	{
		index1 = i * width;
		
		for (j = n; j < width - n; j++)
		{
			sum = 0.0f;

			for (k = -n; k <= n; k++)
			{
				index2 = (i + k) * width;
				index3 = (k + n) * winsize;
				for (l = -n; l <= n; l++) sum += (double)(InImg[index2 + (j + l)]) * (double)(Mask[index3 + l + n]);
			}
			CLIP<double>(sum, 0.0, 255.0);

			OutImg[index1 + j] = (unsigned char)sum;
		}
	}
	return true;
}

//*description   : RGB --> HSI로의 변환 
//*@param input  :  
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param input  : 
//*@param input  :  
//*@param output :  
//*@return		 :  
//*/
bool CBitmapAction::RGBtoHSI(std::vector<unsigned char>& InImg, std::vector<short>& H, std::vector<unsigned char>& S, std::vector<unsigned char>& IV, const size_t& height, const size_t& width)
{
	if (InImg.empty() == true) { return false; }

	if (height <= 0) { return false; }

	if (width <= 0) { return false; }

	if (H.empty() == true) { return false; }

	if (S.empty() == true) { return false; }

	if (IV.empty() == true) { return false; }

	size_t i = 0;
	size_t j = 0;
	size_t index1 = 0;
	size_t index2 = 0;
	size_t rwsize = WIDTHBYTES(24 * width);

	double hue = 0.0;
	double satu = 0.0;
	double intens = 0.0;
	double r = 0.0;
	double g = 0.0;
	double b = 0.0;

	CColorConv pColorConv;


	for (i = 0; i < height; i++)
	{
		index1 = (height - i - 1) * rwsize;
		index2 = (height - i - 1) * width;

		for (j = 0; j < width; j++)
		{
			r = (double)InImg[index1 + 3 * j + 2] / 255.0f;
			g = (double)InImg[index1 + 3 * j + 1] / 255.0f;
			b = (double)InImg[index1 + 3 * j] / 255.0f;

			pColorConv.RGB_To_HSI(r, g, b, &hue, &satu, &intens);

			H[index2 + j] = (short)(hue);
			S[index2 + j] = (unsigned char)(satu * 255.0);
			IV[index2 + j] = (unsigned char)(intens * 255.0);
		}
	}

	return true;
}

//*description   : HSI --> RGB로의 변환 	
//*@param input  :  
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param input  : 
//*@param input  :  
//*@param output :  
//*@return		 :  
//*/
bool CBitmapAction::HSItoRGB(std::vector<unsigned char>& OutImg, std::vector<short>& H, std::vector<unsigned char>& S, std::vector<unsigned char>& IV, const size_t& height, const size_t& width)
{
	if (OutImg.empty() == true) { return false; }

	if (height <= 0) { return false; }

	if (width <= 0) { return false; }

	if (H.empty() == true) { return false; }

	if (S.empty() == true) { return false; }

	if (IV.empty() == true) { return false; }

	size_t i = 0;
	size_t j = 0;
	size_t index1 = 0;
	size_t index2 = 0;
	size_t rwsize = WIDTHBYTES(24 * width);

	double hue = 0.0;
	double satu = 0.0;
	double intens = 0.0;
	double r = 0.0;
	double g = 0.0;
	double b = 0.0;
	double rr = 0.0;
	double gg = 0.0;
	double bb = 0.0;
	CColorConv pColorConv;


	for (i = 0; i < height; i++)
	{
		index1 = (height - i - 1) * rwsize;
		index2 = (height - i - 1) * width;
		for (j = 0; j < width; j++)
		{
			hue = (double)H[index2 + j];
			satu = (double)S[index2 + j] / 255.0f;
			intens = (double)IV[index2 + j] / 255.0f;

			pColorConv.HSI_To_RGB(hue, satu, intens, &r, &g, &b);
			rr = r * 255.0f; gg = g * 255.0f; bb = b * 255.0f;

			CLIP<double>(rr, 0, 255);
			CLIP<double>(gg, 0, 255);
			CLIP<double>(bb, 0, 255);

			OutImg[index1 + 3 * j] = (unsigned char)bb;
			OutImg[index1 + 3 * j + 1] = (unsigned char)gg;
			OutImg[index1 + 3 * j + 2] = (unsigned char)rr;
		}
	}
	return true;
}

//*description   : 
//*@param input  : const size& winsize
//*@param output : std::vector<float>& mask
//*@return		 :  
//*/
bool CBitmapAction::InitializeMask(std::vector<float>& mask,const size_t& winsize)
{
	mask.resize((winsize * winsize));
	std::fill(mask.begin(), mask.end(), 0.0f);

	return true;
}

//*description   : 
//*@param input  : const size& winsize
//*@param input  : const std::vector<float>& pattern
//*@param output : std::vector<float>& mask
//*@return		 :  
//*/
bool CBitmapAction::FillMaskPattern(std::vector<float>& mask,const std::vector<float>& pattern, const size_t& winsize)
{
	InitializeMask(mask, winsize);
	
	if (pattern.size() <= 0) { return false;  }

	if( pattern.size() != (winsize * winsize)) { return false; }

	std::copy(pattern.begin(), pattern.end(), mask.begin());

	return true;
}


//*description   : 
//*@param input  : size& imageSize
//*@param output : std::vector<float>& ucImage
//*@return		 :  
//*/
bool CBitmapAction::InitializeBufferImage(std::vector<unsigned char>& ucImage, const size_t& imageSize)
{
	ucImage.resize(imageSize);
	std::fill(ucImage.begin(), ucImage.end(), 0);
	return true;
}

//*description   : 
//*@param input  : size& imageSize
//*@param output : std::vector<float>& ucImage
//*@return		 :  
//*/
bool CBitmapAction::InitializeBufferImage(std::vector<short>& sImage, const size_t& imageSize)
{
	sImage.resize(imageSize);
	std::fill(sImage.begin(), sImage.end(), 0);
	return true;
}