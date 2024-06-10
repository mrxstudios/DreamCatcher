#include <dreamcatcher.hpp>
#include <internals.hpp>

extern "C" __declspec(dllexport)
void __cdecl STUB(void)
{
}

struct POS {
	int x;
	int y;
	int width;
	int height;
};

int DUST_CLIENT_WIDTH = 512;
int DUST_CLIENT_HEIGHT = 384;
float DUST_CLIENT_SCALING = 1.0f;
POINT DUST_CLIENT_OFFSET = { 0,0 };
POINT DUST_SCREEN_OFFSET = { 0,0 };

void** DF_INTERNAL_ChangeDisplayMode_Addr =
#if TITANIC
(void**)NULL;
#elif LUNICUS
(void**)NULL;
#else
(void**)0x004468A8;
#endif

void** DF_INTERNAL_EnumDisplaySettings_Addr =
#if TITANIC
(void**)NULL;
#elif LUNICUS
#else
(void**)0x00444F54;
#endif

void** DF_INTERNAL_ExitWindowsEx_Addr =
#if TITANIC
(void**)NULL;
#elif LUNICUS
(void**)NULL;
#else
(void**)0x00445370;
#endif

GlobalState Global = {
	NULL,
	NULL,
	NULL,
	NULL
};

MethodInfo* AppendMethodInfo(GlobalState& global, const MethodInfo& info)
{
	MethodInfo* result = new MethodInfo();
	memcpy(result, &info, sizeof(MethodInfo));

	result->next = global.pMethodInfoList;
	global.pMethodInfoList = result;

	return result;
}

// Override the entry method in case we need to do
// anything fancier that is not appropriate for DllMain.

int WINAPI DivertedDFWinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	Global.appInstance = hInstance;
	printf("hInstance: %p\nhPrevInstance: %p\nlpCmdLine: %s\nnCmdShow: %i\n", hInstance, hPrevInstance, lpCmdLine, nCmdShow);

	return DF_WinMain(
		hInstance,
		hPrevInstance,
		lpCmdLine,
		nCmdShow);
}

BEGIN_CALL_PATCHES(DivertedDFWinMain)
PATCH_CALL_IN_DUST(0x0043C279)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x00428130, DivertedDFWinMain);

// Override this function to prevent the game from changing 
// the screen resolution.

void __cdecl DF_Set_Display(int, int, int)
{
	*DF_INTERNAL_ChangeDisplayMode_Addr = (void*)NULL;
	*DF_INTERNAL_EnumDisplaySettings_Addr = (void*)NULL;
	*DF_INTERNAL_ExitWindowsEx_Addr = (void*)NULL;
	return;
}

BEGIN_CALL_PATCHES(DF_Set_Display)
PATCH_CALL_IN_DUST(0x0042BCF2)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x00429CB0, DF_Set_Display);

/* Change BitBlt */
typedef BOOL(WINAPI* BitBlt_t)(HDC, int, int, int, int, HDC, int, int, DWORD);
BitBlt_t originalBitBlt = NULL;

typedef BOOL(WINAPI* StretchBlt_t)(HDC, int, int, int, int, HDC, int, int, int, int, DWORD);
StretchBlt_t customStretchBlt = NULL;

void InitializeOriginalBitBlt() {
	originalBitBlt = (BitBlt_t)GetProcAddress(GetModuleHandle("GDI32.dll"), "BitBlt");
	if (originalBitBlt == NULL) {
		printf("Failed to get original BitBlt address\n");
	}
	else {
		printf("Original BitBlt address: %p\n", originalBitBlt);
	}
}
void InitializecustomStretchBlt() {
	customStretchBlt = (StretchBlt_t)GetProcAddress(GetModuleHandle("GDI32.dll"), "StretchBlt");
	if (customStretchBlt == NULL) {
		printf("Failed to get original BitBlt address\n");
	}
	else {
		printf("Original BitBlt address: %p\n", customStretchBlt);
	}
}

RECT GetScreenDimensions() {
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	return desktop;
}

void CalculateScreenBounds() {
	RECT window = GetScreenDimensions();

	// Set client bounds (original image size and offset)
	DUST_CLIENT_OFFSET.x = (window.right / 2) - (DUST_CLIENT_WIDTH / 2);
	DUST_CLIENT_OFFSET.y = (window.bottom / 2) - (DUST_CLIENT_HEIGHT / 2);

	// Determine the appropriate scaling
	float hscale = (float)window.right / DUST_CLIENT_WIDTH;
	float vscale = (float)window.bottom / DUST_CLIENT_HEIGHT;
	DUST_CLIENT_SCALING = min(hscale, vscale);

	// Set screen bounds (scaled image size and offset)
	DUST_SCREEN_OFFSET.x = ((window.right / 2) - (DUST_CLIENT_WIDTH * DUST_CLIENT_SCALING / 2));
	DUST_SCREEN_OFFSET.y = ((window.bottom / 2) - (DUST_CLIENT_HEIGHT * DUST_CLIENT_SCALING / 2));
}

// Function to calculate the scaling factor and offset
POS CalculateScalingAndOffset(RECT window, int x, int y, int cx, int cy) {
	POS tempPos = { 0,0,0,0 };

	// Adjust positioning from centered to top-left corner
	x = x - ((window.right / 2) - (DUST_CLIENT_WIDTH / 2));
	y = y - ((window.bottom / 2) - (DUST_CLIENT_HEIGHT / 2));

	// Calculate new offset based on scaling factor
	int offsetX = ((window.right - (DUST_CLIENT_WIDTH * DUST_CLIENT_SCALING)) / 2);
	int offsetY = ((window.bottom - (DUST_CLIENT_HEIGHT * DUST_CLIENT_SCALING)) / 2);

	// Create new StretchBlt POSitioning values
	tempPos.x = (int)(x * DUST_CLIENT_SCALING) + DUST_SCREEN_OFFSET.x;
	tempPos.y = (int)(y * DUST_CLIENT_SCALING) + DUST_SCREEN_OFFSET.y;
	tempPos.width = cx * DUST_CLIENT_SCALING;
	tempPos.height = cy * DUST_CLIENT_SCALING;

	return tempPos;
}

BOOL WINAPI DF_BitBltPlaceholder(HDC hdc, int x, int y, int cx, int cy, HDC hdcSrc, int x1, int y1, DWORD rop) {
	RECT desktop = GetScreenDimensions();
	POS tempPos = CalculateScalingAndOffset(desktop, x, y, cx, cy);

	/*printf("Screen Bounds: x=%d, y=%d, w=%d, h=%d\n",
		DUST_SCREEN_OFFSET.x,
		DUST_SCREEN_OFFSET.y,
		DUST_SCREEN_OFFSET.width,
		DUST_SCREEN_OFFSET.height);

	printf("CustomBitBlt called: hdc=%p, x=%d, y=%d, cx=%d, cy=%d, hdcSrc=%p, x1=%d, y1=%d, rop=%lu\n",
		hdc, tempPos.x, tempPos.y, tempPos.width, tempPos.height, hdcSrc, x1, y1, rop);*/

	BOOL result = customStretchBlt(
		hdc,
		tempPos.x,
		tempPos.y,
		tempPos.width,
		tempPos.height,
		hdcSrc, x1, y1, cx, cy, rop);

	return result;
}

void PatchBitBlt() {
	DWORD oldProtect;
	// Change memory protection to allow writing
	if (VirtualProtect((LPVOID)0x0046233c, sizeof(LPVOID), PAGE_EXECUTE_READWRITE, &oldProtect)) {
		// Patch the IAT entry
		*(BitBlt_t*)0x0046233c = DF_BitBltPlaceholder;

		// Restore the old protection
		if (!VirtualProtect((LPVOID)0x0046233c, sizeof(LPVOID), oldProtect, &oldProtect)) {
			printf("Failed to restore memory protection at 0x0046233c\n");
		}
		else {
			printf("Patched IAT entry at 0x0046233c to point to CustomBitBlt\n");
		}
	}
	else {
		printf("Failed to change memory protection at 0x0046233c\n");
	}
}

BEGIN_CALL_PATCHES(DF_BitBltPlaceholder)
PATCH_CALL_IN_DUST(0x0042872d)
PATCH_CALL_IN_DUST(0x0042877f)
PATCH_CALL_IN_DUST(0x0042881b)
PATCH_CALL_IN_DUST(0x0042899a)
PATCH_CALL_IN_DUST(0x004289d2)
PATCH_CALL_IN_DUST(0x00428a6b)
PATCH_CALL_IN_DUST(0x00428aa3)
PATCH_CALL_IN_DUST(0x00428baa)
PATCH_CALL_IN_DUST(0x004290ce)
PATCH_CALL_IN_DUST(0x00429172)
PATCH_CALL_IN_DUST(0x0042e132)
END_CALL_PATCHES

/* Change ScreenToClient */

typedef BOOL(WINAPI* ScreenToClient_t)(HWND, LPPOINT);
ScreenToClient_t originalScreenToClient = NULL;

void InitializeScreenToClient() {
	originalScreenToClient = (ScreenToClient_t)GetProcAddress(GetModuleHandle("USER32.dll"), "ScreenToClient");
	if (originalScreenToClient == NULL) {
		printf("Failed to get original ScreenToClient address\n");
	}
	else {
		printf("Original ScreenToClient address: %p\n", originalScreenToClient);
	}
}

BOOL WINAPI DF_ScreenToClientPlaceholder(HWND hWind, LPPOINT lpPoint) {
	BOOL result = originalScreenToClient(hWind, lpPoint);

	POS tempPos = { 0,0,0,0 };

	tempPos.x = ((lpPoint->x - DUST_SCREEN_OFFSET.x) / DUST_CLIENT_SCALING) + DUST_CLIENT_OFFSET.x;
	tempPos.y = (lpPoint->y - DUST_SCREEN_OFFSET.y) / DUST_CLIENT_SCALING + DUST_CLIENT_OFFSET.y;

	//printf("(%d,%d) -> (%d,%d)\n", lpPoint->x, lpPoint->y,tempPos.x,tempPos.y);

	lpPoint->x = tempPos.x;
	lpPoint->y = tempPos.y;

	return result;
}

void PatchScreenToClient() {
	DWORD oldProtect;
	// Change memory protection to allow writing
	if (VirtualProtect((LPVOID)0x00462490, sizeof(LPVOID), PAGE_EXECUTE_READWRITE, &oldProtect)) {
		// Patch the IAT entry
		*(ScreenToClient_t*)0x00462490 = DF_ScreenToClientPlaceholder;

		// Restore the old protection
		if (!VirtualProtect((LPVOID)0x00462490, sizeof(LPVOID), oldProtect, &oldProtect)) {
			printf("Failed to restore memory protection at 0x00462490\n");
		}
		else {
			printf("Patched IAT entry at 0x00462490 to point to ScreenToClient\n");
		}
	}
	else {
		printf("Failed to change memory protection at 0x00462490\n");
	}
}

BEGIN_CALL_PATCHES(DF_ScreenToClientPlaceholder)
PATCH_CALL_IN_DUST(0x0042d5d3)
PATCH_CALL_IN_DUST(0x0042e2b7)
END_CALL_PATCHES

// Override this function to prevent the game
// from asking about changing the display resolution.

int __cdecl DF_Prompt_Display_Change(int unused)
{
	return 0;
}

BEGIN_CALL_PATCHES(DF_Prompt_Display_Change)
PATCH_CALL_IN_DUST(0x0042B019)
PATCH_CALL_IN_DUST(0x0042B11C)
PATCH_CALL_IN_DUST(0x0042B1CF)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x0042AD60, DF_Prompt_Display_Change);

// Override this function to prevent the game from
// putting itself into a pause state when the game
// window loses focus. (This makes the game easier to debug)

void __cdecl DF_Set_Pause(int pause)
{
	return;
}

BEGIN_CALL_PATCHES(DF_Set_Pause)
PATCH_CALL_IN_DUST(0x0042A6AE)
PATCH_CALL_IN_DUST(0x0042A7A7)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x0042A130, DF_Set_Pause);

void NOPPatch(void* pDest, size_t numNops)
{
	DWORD OldProt;
	char* ptr = (char*)pDest;

	VirtualProtect(pDest, 5, PAGE_EXECUTE_READWRITE, &OldProt);

	for (size_t i = 0; i < numNops; i++)
	{
		*ptr++ = (char)0x90;
	}

	VirtualProtect(pDest, 5, OldProt, &OldProt);
}

// http://www.rohitab.com/discuss/topic/35537-cc-reverse-engineering-tutorial-for-newbies/
void CallPatch(const void* pDest, void* pSrc) {

	DWORD OldProt;

	VirtualProtect(pSrc, 5, PAGE_EXECUTE_READWRITE, &OldProt);

	*(char*)pSrc = (char)0xE8;

	*(DWORD*)((DWORD)pSrc + 1) = (DWORD)pDest - (DWORD)pSrc - 5;

	VirtualProtect(pSrc, 5, OldProt, &OldProt);
}

void PatchCalls(
	const void** addresses,
	const void* newCall,
	int* count)
{
	const void** current = addresses;

	while (current && *current)
	{
		CallPatch(newCall, (void*)*current);

		if (count)
		{
			*count += 1;
		}

		current++;
	}
}

void Patch(GlobalState& global)
{
	int count = 0;

	printf("Patching...\n");

	MethodInfo* pInfo = global.pMethodInfoList;

	while (pInfo)
	{
		int thisCount = 0;

		printf("\t%s...\t", pInfo->methodName);

		PatchCalls(
			pInfo->callAddresses,
			pInfo->newAddress,
			&thisCount);

		printf("%i\n", thisCount);

		count += thisCount;
		pInfo = pInfo->next;
	}

	printf("Patched %i calls.\n", count);
}

void Unpatch(GlobalState& global)
{
	int count = 0;

	printf("Upatching...\n");

	MethodInfo* pInfo = global.pMethodInfoList;

	while (pInfo)
	{
		printf("\t%s\n", pInfo->methodName);
		PatchCalls(
			pInfo->callAddresses,
			pInfo->oldAddress,
			&count);

		MethodInfo* pOldInfo = pInfo;
		pInfo = pInfo->next;
		delete pOldInfo;
	}

	printf("Upatched %i calls.\n", count);
}

// Write NOP to a division instruction that
// causes a divide-by-zero exception on modern systems.

void PatchDivideCrash()
{
#if TITANIC
#elif LUNICUS
#else
	NOPPatch((void*)0x0042B459, 2);
#endif
}

// Write NOP to some calls to SetSysColor
// so we don't end up with messed up colors
// everywhere (e.g. black text boxes with black text).

void PatchSysColorCalls()
{
#if TITANIC
#elif LUNICUS
#else
	NOPPatch((void*)0x0042922D, 17);
	NOPPatch((void*)0x004291B0, 17);
#endif
}

BOOL WINAPI DllMain(
	_In_ HINSTANCE hinstDLL,
	_In_ DWORD     fdwReason,
	_In_ LPVOID    lpvReserved
)
{
	if (lpvReserved)
	{
		if (fdwReason == DLL_PROCESS_ATTACH || fdwReason == DLL_THREAD_ATTACH)
		{
			Global.dllInstance = hinstDLL;

			Global.mainWindowHandle = (HWND*)WINDOW_MAIN_HANDLE_ADDR;
			Global.numWindows = (DWORD*)WINDOW_NUM_ADDR;
			Global.windows = (DF_Window**)WINDOW_STRUCT_ADDR;
			Global.unknownWindowValues = (DWORD**)WINDOW_UNKNOWN_ADDR;

			Global.deviceContext = (HDC*)WIN_DEVICECONTRXT_ADDR;

			Global.clutbmih = (BITMAPINFO*)BITMAPINFO_ADDR;

			Global.isWinGFuncPtrAcquired = (DWORD*)WINGPOINTER_SET_ADDR;
			Global.isOSBuildNumberTwo = (DWORD*)IS_OS_BUILD_NUMBER_TWO_ADDR;

			Global.hGdi = (HMODULE*)GDI_MODULE_ADDR;

			Global.gdi32CreateDIBSection = (LpfnGdi32CreateDIBSection*)GDI32_CREATEDIBSECTION_ADDR;
			Global.gdi32SetDIBColorTable = (LpfnGdi32SetDIBColorTable*)GDI32_SETDIBCOLORTABLE_ADDR;

			Global.win32BitBlt = (LpfnWin32BitBlt*)WIN32_BITBLT_ADDR;
			Global.win32CreateBitmap = (LpfnWin32CreateBitmap*)WIN32_CREATEBITMAP_ADDR;
			Global.win32CreateDC = (LpfnWin32CreateDC*)WIN32_CREATEDC_ADDR;
			Global.win32SetDIBColorTable = (LpfnWin32SetDIBColorTable*)WIN32_SETDIBCOLORTABLE_ADDR;

			AllocConsole();
			freopen_s(&Global.console, "CONOUT$", "w", stdout);

			CalculateScreenBounds();

			InitializecustomStretchBlt();
			PatchBitBlt();

			InitializeScreenToClient();
			PatchScreenToClient();

			PatchSysColorCalls();
			PatchDivideCrash();

			Patch(Global);



			printf("Ready!\n");
		}
		else if (fdwReason == DLL_PROCESS_DETACH || fdwReason == DLL_THREAD_DETACH)
		{
			Unpatch(Global);

			if (Global.console)
			{
				fclose(Global.console);
				Global.console = NULL;
			}

			FreeConsole();
		}
	}

	return TRUE;
}