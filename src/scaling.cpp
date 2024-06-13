#include <scaling.hpp>

UINT DUST_CLIENT_WIDTH = 512;
UINT DUST_CLIENT_HEIGHT = 384;
UINT DUST_CLIENT_HALFWIDTH = 256;
UINT DUST_CLIENT_HALFHEIGHT = 192;

UINT DUST_SCREEN_WIDTH = 2048;
UINT DUST_SCREEN_HEIGHT = 1280;
UINT DUST_SCREEN_HALFWIDTH = 1024;
UINT DUST_SCREEN_HALFHEIGHT = 768;

float DUST_CLIENT_SCALING = 1.0f;
POINT DUST_CLIENT_OFFSET = { 0,0 };
POINT DUST_SCREEN_OFFSET = { 0,0 };

void CalculateScaledBounds() {
	// Set client bounds (original image size and offset)
	DUST_CLIENT_OFFSET.x = DUST_SCREEN_HALFWIDTH - DUST_CLIENT_HALFWIDTH;
	DUST_CLIENT_OFFSET.y = DUST_SCREEN_HALFHEIGHT - DUST_CLIENT_HALFHEIGHT;

	// Determine the appropriate scaling
	float hscale = (float)DUST_SCREEN_WIDTH / DUST_CLIENT_WIDTH;
	float vscale = (float)DUST_SCREEN_HEIGHT / DUST_CLIENT_HEIGHT;
	DUST_CLIENT_SCALING = min(hscale, vscale);

	// Set screen bounds (scaled image size and offset)
	DUST_SCREEN_OFFSET.x = (DUST_SCREEN_HALFWIDTH - (DUST_CLIENT_HALFWIDTH * DUST_CLIENT_SCALING));
	DUST_SCREEN_OFFSET.y = (DUST_SCREEN_HALFHEIGHT - (DUST_CLIENT_HALFHEIGHT * DUST_CLIENT_SCALING));
}

void DFSCALE::Initialize() {
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);

	DUST_SCREEN_WIDTH = desktop.right;
	DUST_SCREEN_HEIGHT = desktop.bottom;
	DUST_SCREEN_HALFWIDTH = DUST_SCREEN_WIDTH / 2;
	DUST_SCREEN_HALFHEIGHT = DUST_SCREEN_HEIGHT / 2;

	CalculateScaledBounds();
}


int DFSCALE::XToScaledSpace(int x) {
	// Adjust positioning from centered to top-left corner
	x -= DUST_SCREEN_HALFWIDTH - DUST_CLIENT_HALFWIDTH;

	// Create new StretchBlt POSitioning values
	return (int)(x * DUST_CLIENT_SCALING) + DUST_SCREEN_OFFSET.x;
}

int DFSCALE::YToScaledSpace(int y) {
	// Adjust positioning from centered to top-left corner
	y -= DUST_SCREEN_HALFHEIGHT - DUST_CLIENT_HALFHEIGHT;

	// Create new StretchBlt POSitioning values
	return (int)(y * DUST_CLIENT_SCALING) + DUST_SCREEN_OFFSET.y;
}

void DFSCALE::PointToScaledSpace(POINT* p) {
	p->x = XToScaledSpace(p->x);
	p->y = XToScaledSpace(p->y);
}

void DFSCALE::RectToScaledSpace(RECT* r) {
	r->left = XToScaledSpace(r->left);
	r->right = XToScaledSpace(r->right);
	r->top = YToScaledSpace(r->top);
	r->bottom = YToScaledSpace(r->bottom);
}

int DFSCALE::XToOriginalSpace(int x) {
	return ((x - DUST_SCREEN_OFFSET.x) / DUST_CLIENT_SCALING) + DUST_CLIENT_OFFSET.x;
};

int DFSCALE::YToOriginalSpace(int y) {
	return (y - DUST_SCREEN_OFFSET.y) / DUST_CLIENT_SCALING + DUST_CLIENT_OFFSET.y;
};

void DFSCALE::PointToOriginalSpace(POINT* p) {
	p->x = XToOriginalSpace(p->x);
	p->y = YToOriginalSpace(p->y);
}