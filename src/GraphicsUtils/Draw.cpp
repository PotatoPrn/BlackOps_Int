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
	if (!GHack.FontF) // 14, 0
		D3DXCreateFont(pDevice, 18, 0, FW_NORMAL, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLEARTYPE_QUALITY,
				DEFAULT_PITCH | FF_DONTCARE, "Arial", &GHack.FontF);

	//SetRect(&Rect, x + 2, y + 2, x + 1, y + 1);
	//GHack.FontF->DrawTextA(NULL, Text, -1, &Rect, DT_CENTER | DT_NOCLIP, D3DCOLOR_ARGB(255, 255, 255, 255));

	SetRect(&Rect, x, y, x, y);
	GHack.FontF->DrawTextA(NULL, Text, -1, &Rect, DT_CENTER | DT_NOCLIP, Color);
}

void DrawMenu()
{
	int MenuOffx = GHack.WindowWidth / 2;
	int MenuOffy = 20;
	D3DCOLOR Enabled = D3DCOLOR_ARGB(255, 0, 255, 0);
	D3DCOLOR Disabled = D3DCOLOR_ARGB(255, 255, 0, 0);


	if (!THacks.T_ShowMenu)
	{
		DrawTextF("F1 To show Menu", MenuOffx, MenuOffy, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	else
	{
		DrawTextF("F10 Invincibility", MenuOffx, MenuOffy + 1 * 18, THacks.T_Health ? Enabled : Disabled);
		DrawTextF("F9 Infinite Points", MenuOffx, MenuOffy + 2 * 18, THacks.T_Point ? Enabled : Disabled);
		DrawTextF("F8 Infinite Ammo", MenuOffx, MenuOffy + 3 * 18, THacks.T_Ammo ? Enabled : Disabled);
		//DrawTextF("F7 Save Waypoint", MenuOffx, MenuOffy + 4 * 18, THacks.T_Health ? Enabled : Disabled);
		//DrawTextF("F6 / Shift F6 > Teleport To Waypoint / Teleport to Previous Destination", MenuOffx, MenuOffy + 5 * 18, THacks.T_Health ? Enabled : Disabled);
		DrawTextF("F5 InstaKill Hack", MenuOffx, MenuOffy + 6 * 18, THacks.T_IKill ? Enabled : Disabled);
		DrawTextF("F4 ESP", MenuOffx, MenuOffy + 7 * 18, THacks.T_ESP ? Enabled : Disabled);
		DrawTextF("F3 Rapid Fire", MenuOffx, MenuOffy + 8 * 18, THacks.T_RapidFire ? Enabled : Disabled);
	}
}

#endif //BLOPS_INTERNAL_DRAW_CPP