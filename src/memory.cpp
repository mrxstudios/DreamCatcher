#include <dreamcatcher.hpp>
#include <memory.hpp>

void __cdecl DF_ClearMemory(
	void* ptr,
	DWORD length)
{
	ZeroMemory(ptr, length);
}

BEGIN_CALL_PATCHES(DF_ClearMemory)
	PATCH_CALL_IN_DUST(0x00402024)
	PATCH_CALL_IN_DUST(0x00402156)
	PATCH_CALL_IN_DUST(0x0040508B)
	PATCH_CALL_IN_DUST(0x0040523C)
	PATCH_CALL_IN_DUST(0x0040538C)
	PATCH_CALL_IN_DUST(0x004057DD)
	PATCH_CALL_IN_DUST(0x004057F6)
	PATCH_CALL_IN_DUST(0x00409B1E)
	PATCH_CALL_IN_DUST(0x00411C7F)
	PATCH_CALL_IN_DUST(0x004127D6)
	PATCH_CALL_IN_DUST(0x00428C65)
	PATCH_CALL_IN_DUST(0x0042BAB1)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(0x004283F0, DF_ClearMemory)