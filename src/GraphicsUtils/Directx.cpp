#ifndef BLOPS_INTERNAL_DIRECTX_H_CPP
#define BLOPS_INTERNAL_DIRECTX_H_CPP

#include "GraphicsUtils/Directx.h"

#include "Utils/ProcessUtils.h"


bool InitD3D9(void** pTable, unsigned int Size)
{
	if (!pTable)
		return FALSE;

	IDirect3D9* PD3D = Direct3DCreate9(D3D_SDK_VERSION);

	IDirect3DDevice9* pDummyDevice = NULL;


	D3DPRESENT_PARAMETERS d3dpp = {};
	d3dpp.Windowed = false;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = GetDeviceWindow();

	HRESULT DummyDevCreated = PD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,d3dpp.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pDummyDevice);

	if (DummyDevCreated != S_OK)
	{
		d3dpp.Windowed = !d3dpp.Windowed;
		HRESULT DummyDevCreated = PD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL,d3dpp.hDeviceWindow, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &pDummyDevice);

		if (DummyDevCreated != S_OK)
		{
			PD3D->Release();
			return false;
		}
	}

	memcpy(pTable, *(void***)(pDummyDevice), Size);

	pDummyDevice->Release();
	PD3D->Release();
	return TRUE;
}


#endif //BLOPS_INTERNAL_DIRECTX_H_CPP