#pragma once
#include <windows.h>

extern UINT DUST_CLIENT_WIDTH;
extern UINT DUST_CLIENT_HEIGHT;
extern UINT DUST_CLIENT_HALFWIDTH;
extern UINT DUST_CLIENT_HALFHEIGHT;

extern UINT DUST_SCREEN_WIDTH;
extern UINT DUST_SCREEN_HEIGHT;
extern UINT DUST_SCREEN_HALFWIDTH;
extern UINT DUST_SCREEN_HALFHEIGHT;

extern float DUST_CLIENT_SCALING;
extern POINT DUST_CLIENT_OFFSET;
extern POINT DUST_SCREEN_OFFSET;

static class DFSCALE {

public:
	static void Initialize();
	static int XToScaledSpace(int x);
	static int YToScaledSpace(int y);
	static void PointToScaledSpace(POINT* p);
	static void RectToScaledSpace(RECT* r);

	static int XToOriginalSpace(int x);
	static int YToOriginalSpace(int y);
	static void PointToOriginalSpace(POINT* p);
};