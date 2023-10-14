#ifndef BLOPS_INTERNAL_DRAW_H
#define BLOPS_INTERNAL_DRAW_H

#include "main.h"

#include "Offsets.h"



void DrawTextF(const char* Text, float x, float y, D3DCOLOR Color);

void DrawLine(int x1, int y1, int x2, int y2, int Thickness, D3DCOLOR Color);
void DrawLine(Vec2 Src, Vec2 Dst, int Thickness, D3DCOLOR Color);


#endif //BLOPS_INTERNAL_DRAW_H