#ifndef BLOPS_INTERNAL_DIRECTX_H_H
#define BLOPS_INTERNAL_DIRECTX_H_H

#include "main.h"

typedef HRESULT(APIENTRY* tEndScene)(LPDIRECT3DDEVICE9 pDevice);

bool InitD3D9(void** pTable, unsigned int Size);

#endif //BLOPS_INTERNAL_DIRECTX_H_H