#ifndef BLOPS_INTERNAL_DRAW_CPP
#define BLOPS_INTERNAL_DRAW_CPP

#include "GraphicsUtils/Draw.h"

void DrawLine(int x1, int y1, int x2, int y2, int Thickness, D3DCOLOR Color)
{
	if (!GHack.LineL)
		D3DXCreateLine(pDevice, &GHack.LineL);


	D3DXVECTOR2 Line[2];
	Line[0] = D3DXVECTOR2(x1, y1);
	Line[1] = D3DXVECTOR2(x2, y2);
	GHack.LineL->SetWidth(Thickness);
	GHack.LineL->Draw(Line, 2, Color);
}

void DrawLine(Vec2 Src, Vec2 Dst, int Thickness, D3DCOLOR Color)
{
	DrawLine(Src.x, Src.y, Dst.x, Dst.y, Thickness, Color);
}

void DrawTextF(const char* Text, float x, float y, D3DCOLOR Color)
{
	RECT Rect;
	if (!GHack.FontF)
		D3DXCreateFont(pDevice, 14, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, ANTIALIASED_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "Arial", &GHack.FontF);

	SetRect(&Rect, x + 1, y + 1, x + 1, y + 1);
	GHack.FontF->DrawTextA(NULL, Text, -1, &Rect, DT_CENTER | DT_NOCLIP, D3DCOLOR_ARGB(255, 255, 255, 255));

	SetRect(&Rect, x, y, x, y);
	GHack.FontF->DrawTextA(NULL, Text, -1, &Rect, DT_CENTER | DT_NOCLIP, Color);
}



#endif //BLOPS_INTERNAL_DRAW_CPP