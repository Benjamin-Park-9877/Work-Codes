/////** 
////*description   :  작업 수행 클래스 소스 파일
////*               
////* 
////*/
#include "pch.h"
#include "ChannelsplitRgb.h"

#include "BlobColoring.h"
#include "ColorConv.h"

//*description   :  
//*@param input  : CUserBitmap* pCbmpElementsIn
//*@param input  :   
//*@param input  :  
//*@param input  :  
//*@param input  : 
//*@param output : -
//*@return		 :  
//*/
void CChannelsplitRgb::Process(const CUserBitmap* pCbmpElementsIn)
{
	if (pCbmpElementsIn->c_arr_const() == NULL)
	{
		return;
	}

	if (pCbmpElementsIn->GetBitmapInfo() == NULL)
	{
		return;
	}

	if (pCbmpElementsIn->GetBitCount() != 24)
	{
		return;
	}

	// 빈이미지로 초기화 하여야 하나 동작 확인 및 별도로 set 하는 일 막기 위해 이렇게 처리함
	if (Set(pCbmpElementsIn) == false)
	{
		return;
	}

	int index = 0;
	unsigned long i = 0;
	unsigned long j = 0;

	for (int k = 2; k >= 0; k--)
	{
		for (i = 0; i < pCbmpElementsIn->GetMaximumHeight() * pCbmpElementsIn->GetRwSize(); i++)
		{
			m_pCbmpElements->LocateAt(i) = 0;
		}

		for (i = 0; i < m_pCbmpElements->GetMaximumHeight(); i++)
		{
			index = (pCbmpElementsIn->GetMaximumHeight() - i - 1) * pCbmpElementsIn->GetRwSize();

			for (j = 0; j < m_pCbmpElements->GetMaximumWidth(); j++)
			{
				m_pCbmpElements->LocateAt(index + 3 * j + k) = pCbmpElementsIn->LocateAt(index + 3 * j + k);
			}
		}

		CopyClipboard(m_pCbmpElements->c_arr_const(), m_pCbmpElements->GetMaximumHeight(), m_pCbmpElements->GetMaximumWidth(), 24);

		AfxGetMainWnd()->SendMessage(WM_COMMAND, ID_FILE_NEW);
	}
}

