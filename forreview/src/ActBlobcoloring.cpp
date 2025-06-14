/////** 
////*description   : 작업 수행 클래스 소스 파일
////*               
////* 
////*/
#include "pch.h"
#include "ActBlobcoloring.h"
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
void CActBlobcoloring::Process(const CUserBitmap* pCbmpElementsIn, CClientDC* pDc)
{
	if (pDc == NULL)
	{
		return;
	}

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

	int sx, sy, ex, ey;
	int count = 0;
	int height = m_pCbmpElements->GetMaximumHeight();
	int width = m_pCbmpElements->GetMaximumWidth();

	CBlobColoring pBlob(m_pCbmpElements->c_arr(), height, width);
	pBlob.fnBlobColoring(50);

	for (int i = 1; i < pBlob.nBlob; i++)
	{
		if (pBlob.blobData[i].n < 50) continue;
		sx = (int)pBlob.blobData[i].cx - 5;
		ex = (int)pBlob.blobData[i].cx + 5;
		sy = (int)pBlob.blobData[i].cy - 5;
		ey = (int)pBlob.blobData[i].cy + 5;
		sx = sx < 0 ? 0 : sx;
		sy = sy < 0 ? 0 : sy;
		ex = ex >= height ? height - 1 : ex;
		ey = ey >= width ? width - 1 : ey;

		float eccen = (pBlob.blobData[i].u02 - pBlob.blobData[i].u20) * (pBlob.blobData[i].u02 - pBlob.blobData[i].u20);
		eccen = (eccen + 4 * pBlob.blobData[i].u11) / pBlob.blobData[i].n;

		if (pBlob.blobData[i].v > 5) continue;

		pDc->MoveTo((int)pBlob.blobData[i].cy, sx);
		pDc->LineTo((int)pBlob.blobData[i].cy, ex);
		pDc->MoveTo(sy, (int)pBlob.blobData[i].cx);
		pDc->LineTo(ey, (int)pBlob.blobData[i].cx);
		count++;
	}
}
