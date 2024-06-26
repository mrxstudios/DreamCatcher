#include <dreamcatcher.hpp>
#include <internals.hpp>
#include <strings.hpp>

char* DF_INTERNAL_CharacterTable = (char*)0x0045EDF8;

void __cdecl DF_GetString(
	WORD a,
	WORD b,
	char* str
)
{
	char buffer[256];
	int charsCopied = LoadStringA(Global.appInstance, b + a, buffer, sizeof(buffer) / sizeof(char));

	*str = (char)charsCopied;

	if (charsCopied)
	{
#if DEBUG
		printf("Retrieved string \"%s\"", buffer);
#endif
		memcpy(str + 1, buffer, (char)charsCopied);
	}
}

BEGIN_CALL_PATCHES(DF_GetString)
	PATCH_CALL_IN_DUST(0x004195AA)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(0x0042F990, DF_GetString)

void __cdecl DF_CopyString(
	char* pPfxFrom,
	char* pPfxTo)
{
	char count = (char)*pPfxFrom;

	do
	{
		*pPfxTo++ = *pPfxFrom++;
	} while (count--);
}

BEGIN_CALL_PATCHES(DF_CopyString)
	PATCH_CALL_IN_DUST(0x00402E6D)
	PATCH_CALL_IN_DUST(0x00402EB1)
	PATCH_CALL_IN_DUST(0x00403AED)
	PATCH_CALL_IN_DUST(0x00403B47)
	PATCH_CALL_IN_DUST(0x00403C8F)
	PATCH_CALL_IN_DUST(0x00403CB6)
	PATCH_CALL_IN_DUST(0x00403D1A)
	PATCH_CALL_IN_DUST(0x00403D8E)
	PATCH_CALL_IN_DUST(0x00403E3D)
	PATCH_CALL_IN_DUST(0x00403ECC)
	PATCH_CALL_IN_DUST(0x0040819F)
	PATCH_CALL_IN_DUST(0x00408462)
	PATCH_CALL_IN_DUST(0x004084F2)
	PATCH_CALL_IN_DUST(0x0040860B)
	PATCH_CALL_IN_DUST(0x00408945)
	PATCH_CALL_IN_DUST(0x004089DE)
	PATCH_CALL_IN_DUST(0x004089F9)
	PATCH_CALL_IN_DUST(0x00408A14)
	PATCH_CALL_IN_DUST(0x00408B6A)
	PATCH_CALL_IN_DUST(0x00408B7C)
	PATCH_CALL_IN_DUST(0x00408B8E)
	PATCH_CALL_IN_DUST(0x00408C7C)
	PATCH_CALL_IN_DUST(0x00409270)
	PATCH_CALL_IN_DUST(0x0040A989)
	PATCH_CALL_IN_DUST(0x0040AAD7)
	PATCH_CALL_IN_DUST(0x0040AC5B)
	PATCH_CALL_IN_DUST(0x0040AE2B)
	PATCH_CALL_IN_DUST(0x0040B007)
	PATCH_CALL_IN_DUST(0x0040C354)
	PATCH_CALL_IN_DUST(0x0040C43A)
	PATCH_CALL_IN_DUST(0x0040C44D)
	PATCH_CALL_IN_DUST(0x0040C45A)
	PATCH_CALL_IN_DUST(0x0040C477)
	PATCH_CALL_IN_DUST(0x0040C4D6)
	PATCH_CALL_IN_DUST(0x0040C532)
	PATCH_CALL_IN_DUST(0x0040C5D6)
	PATCH_CALL_IN_DUST(0x0040C992)
	PATCH_CALL_IN_DUST(0x0040CA36)
	PATCH_CALL_IN_DUST(0x0040CB23)
	PATCH_CALL_IN_DUST(0x0040CBCA)
	PATCH_CALL_IN_DUST(0x0040CC6E)
	PATCH_CALL_IN_DUST(0x0040CC89)
	PATCH_CALL_IN_DUST(0x0040CCA4)
	PATCH_CALL_IN_DUST(0x0040CE16)
	PATCH_CALL_IN_DUST(0x0040CE2B)
	PATCH_CALL_IN_DUST(0x0040CE40)
	PATCH_CALL_IN_DUST(0x0040CEB1)
	PATCH_CALL_IN_DUST(0x0040CEC6)
	PATCH_CALL_IN_DUST(0x0040CEDE)
	PATCH_CALL_IN_DUST(0x0040CFCE)
	PATCH_CALL_IN_DUST(0x0040CFE9)
	PATCH_CALL_IN_DUST(0x0040D004)
	PATCH_CALL_IN_DUST(0x0040D149)
	PATCH_CALL_IN_DUST(0x0040D15B)
	PATCH_CALL_IN_DUST(0x0040D16D)
	PATCH_CALL_IN_DUST(0x0040D2FE)
	PATCH_CALL_IN_DUST(0x0040D5DE)
	PATCH_CALL_IN_DUST(0x0040E2CD)
	PATCH_CALL_IN_DUST(0x0040E58D)
	PATCH_CALL_IN_DUST(0x0040F394)
	PATCH_CALL_IN_DUST(0x0040F60A)
	PATCH_CALL_IN_DUST(0x0040FB85)
	PATCH_CALL_IN_DUST(0x0040FB9A)
	PATCH_CALL_IN_DUST(0x0040FCC6)
	PATCH_CALL_IN_DUST(0x0040FCD8)
	PATCH_CALL_IN_DUST(0x0040FD42)
	PATCH_CALL_IN_DUST(0x0040FEAC)
	PATCH_CALL_IN_DUST(0x0040FEBF)
	PATCH_CALL_IN_DUST(0x00410112)
	PATCH_CALL_IN_DUST(0x00410127)
	PATCH_CALL_IN_DUST(0x0041025A)
	PATCH_CALL_IN_DUST(0x00410344)
	PATCH_CALL_IN_DUST(0x0041041C)
	PATCH_CALL_IN_DUST(0x0041043A)
	PATCH_CALL_IN_DUST(0x0041044C)
	PATCH_CALL_IN_DUST(0x00410592)
	PATCH_CALL_IN_DUST(0x0041067A)
	PATCH_CALL_IN_DUST(0x004106BC)
	PATCH_CALL_IN_DUST(0x00410858)
	PATCH_CALL_IN_DUST(0x0041086A)
	PATCH_CALL_IN_DUST(0x00410A53)
	PATCH_CALL_IN_DUST(0x00410C14)
	PATCH_CALL_IN_DUST(0x00410E58)
	PATCH_CALL_IN_DUST(0x00410EC1)
	PATCH_CALL_IN_DUST(0x00410F13)
	PATCH_CALL_IN_DUST(0x00411014)
	PATCH_CALL_IN_DUST(0x00411328)
	PATCH_CALL_IN_DUST(0x0041133A)
	PATCH_CALL_IN_DUST(0x00411585)
	PATCH_CALL_IN_DUST(0x004115A1)
	PATCH_CALL_IN_DUST(0x004115BD)
	PATCH_CALL_IN_DUST(0x004115D9)
	PATCH_CALL_IN_DUST(0x004115F5)
	PATCH_CALL_IN_DUST(0x00411BD7)
	PATCH_CALL_IN_DUST(0x00411E55)
	PATCH_CALL_IN_DUST(0x00411F15)
	PATCH_CALL_IN_DUST(0x00412048)
	PATCH_CALL_IN_DUST(0x00412188)
	PATCH_CALL_IN_DUST(0x00412AAC)
	PATCH_CALL_IN_DUST(0x00412B6C)
	PATCH_CALL_IN_DUST(0x00412C6C)
	PATCH_CALL_IN_DUST(0x00412E13)
	PATCH_CALL_IN_DUST(0x00412E28)
	PATCH_CALL_IN_DUST(0x00412E3D)
	PATCH_CALL_IN_DUST(0x00412EA9)
	PATCH_CALL_IN_DUST(0x00412EBE)
	PATCH_CALL_IN_DUST(0x00412ED3)
	PATCH_CALL_IN_DUST(0x00412F44)
	PATCH_CALL_IN_DUST(0x00412F59)
	PATCH_CALL_IN_DUST(0x00412F6E)
	PATCH_CALL_IN_DUST(0x0041307E)
	PATCH_CALL_IN_DUST(0x00413099)
	PATCH_CALL_IN_DUST(0x004130B4)
	PATCH_CALL_IN_DUST(0x00413219)
	PATCH_CALL_IN_DUST(0x0041322B)
	PATCH_CALL_IN_DUST(0x0041323D)
	PATCH_CALL_IN_DUST(0x004132AF)
	PATCH_CALL_IN_DUST(0x004132C4)
	PATCH_CALL_IN_DUST(0x004132D9)
	PATCH_CALL_IN_DUST(0x004133CE)
	PATCH_CALL_IN_DUST(0x004133E9)
	PATCH_CALL_IN_DUST(0x00413404)
	PATCH_CALL_IN_DUST(0x004134DC)
	PATCH_CALL_IN_DUST(0x004134EE)
	PATCH_CALL_IN_DUST(0x00413500)
	PATCH_CALL_IN_DUST(0x00413624)
	PATCH_CALL_IN_DUST(0x004156CB)
	PATCH_CALL_IN_DUST(0x0041571C)
	PATCH_CALL_IN_DUST(0x004157AA)
	PATCH_CALL_IN_DUST(0x0041586A)
	PATCH_CALL_IN_DUST(0x0041589F)
	PATCH_CALL_IN_DUST(0x00415910)
	PATCH_CALL_IN_DUST(0x00417A31)
	PATCH_CALL_IN_DUST(0x00417AFE)
	PATCH_CALL_IN_DUST(0x00417B4C)
	PATCH_CALL_IN_DUST(0x00417CD9)
	PATCH_CALL_IN_DUST(0x00417D0A)
	PATCH_CALL_IN_DUST(0x004182AA)
	PATCH_CALL_IN_DUST(0x0041831D)
	PATCH_CALL_IN_DUST(0x0041834F)
	PATCH_CALL_IN_DUST(0x00418370)
	PATCH_CALL_IN_DUST(0x00418391)
	PATCH_CALL_IN_DUST(0x004183B2)
	PATCH_CALL_IN_DUST(0x0041842D)
	PATCH_CALL_IN_DUST(0x0041845F)
	PATCH_CALL_IN_DUST(0x00418480)
	PATCH_CALL_IN_DUST(0x004184A1)
	PATCH_CALL_IN_DUST(0x004184C2)
	PATCH_CALL_IN_DUST(0x00418539)
	PATCH_CALL_IN_DUST(0x0041862E)
	PATCH_CALL_IN_DUST(0x00418649)
	PATCH_CALL_IN_DUST(0x00418664)
	PATCH_CALL_IN_DUST(0x0041872B)
	PATCH_CALL_IN_DUST(0x00418746)
	PATCH_CALL_IN_DUST(0x00418761)
	PATCH_CALL_IN_DUST(0x00418BF3)
	PATCH_CALL_IN_DUST(0x00419171)
	PATCH_CALL_IN_DUST(0x004192EB)
	PATCH_CALL_IN_DUST(0x00419319)
	PATCH_CALL_IN_DUST(0x00419338)
	PATCH_CALL_IN_DUST(0x0041935F)
	PATCH_CALL_IN_DUST(0x004194F0)
	PATCH_CALL_IN_DUST(0x00419532)
	PATCH_CALL_IN_DUST(0x0041954D)
	PATCH_CALL_IN_DUST(0x00419568)
	PATCH_CALL_IN_DUST(0x004199F1)
	PATCH_CALL_IN_DUST(0x00419F0A)
	PATCH_CALL_IN_DUST(0x00419FBA)
	PATCH_CALL_IN_DUST(0x0041A184)
	PATCH_CALL_IN_DUST(0x0041A344)
	PATCH_CALL_IN_DUST(0x0041A3FE)
	PATCH_CALL_IN_DUST(0x0041A419)
	PATCH_CALL_IN_DUST(0x0041A434)
	PATCH_CALL_IN_DUST(0x0041A5CD)
	PATCH_CALL_IN_DUST(0x0041A5DF)
	PATCH_CALL_IN_DUST(0x0041A5F4)
	PATCH_CALL_IN_DUST(0x0041A64C)
	PATCH_CALL_IN_DUST(0x0041A670)
	PATCH_CALL_IN_DUST(0x0041A684)
	PATCH_CALL_IN_DUST(0x0041A6DA)
	PATCH_CALL_IN_DUST(0x0041A6EB)
	PATCH_CALL_IN_DUST(0x0041A6FC)
	PATCH_CALL_IN_DUST(0x0041A81E)
	PATCH_CALL_IN_DUST(0x0041A839)
	PATCH_CALL_IN_DUST(0x0041A854)
	PATCH_CALL_IN_DUST(0x0041A9D0)
	PATCH_CALL_IN_DUST(0x0041A9F6)
	PATCH_CALL_IN_DUST(0x0041AA08)
	PATCH_CALL_IN_DUST(0x0041AA6E)
	PATCH_CALL_IN_DUST(0x0041AA83)
	PATCH_CALL_IN_DUST(0x0041AA98)
	PATCH_CALL_IN_DUST(0x0041AB9E)
	PATCH_CALL_IN_DUST(0x0041ABB9)
	PATCH_CALL_IN_DUST(0x0041ABD4)
	PATCH_CALL_IN_DUST(0x0041ACAC)
	PATCH_CALL_IN_DUST(0x0041ACBE)
	PATCH_CALL_IN_DUST(0x0041ACD0)
	PATCH_CALL_IN_DUST(0x0041AD6C)
	PATCH_CALL_IN_DUST(0x0041ADF0)
	PATCH_CALL_IN_DUST(0x0041AF10)
	PATCH_CALL_IN_DUST(0x0041E0FB)
	PATCH_CALL_IN_DUST(0x0041E94D)
	PATCH_CALL_IN_DUST(0x0041ECC7)
	PATCH_CALL_IN_DUST(0x0041EE5B)
	PATCH_CALL_IN_DUST(0x0041EF8E)
	PATCH_CALL_IN_DUST(0x0041F3DB)
	PATCH_CALL_IN_DUST(0x0041F5BE)
	PATCH_CALL_IN_DUST(0x004206F4)
	PATCH_CALL_IN_DUST(0x004207CC)
	PATCH_CALL_IN_DUST(0x004207DF)
	PATCH_CALL_IN_DUST(0x004207EC)
	PATCH_CALL_IN_DUST(0x00420809)
	PATCH_CALL_IN_DUST(0x00420865)
	PATCH_CALL_IN_DUST(0x004208C2)
	PATCH_CALL_IN_DUST(0x00420969)
	PATCH_CALL_IN_DUST(0x00420D32)
	PATCH_CALL_IN_DUST(0x00420DD8)
	PATCH_CALL_IN_DUST(0x00420EC3)
	PATCH_CALL_IN_DUST(0x00420F6A)
	PATCH_CALL_IN_DUST(0x0042100E)
	PATCH_CALL_IN_DUST(0x00421029)
	PATCH_CALL_IN_DUST(0x00421044)
	PATCH_CALL_IN_DUST(0x004211B6)
	PATCH_CALL_IN_DUST(0x004211CB)
	PATCH_CALL_IN_DUST(0x004211E0)
	PATCH_CALL_IN_DUST(0x00421251)
	PATCH_CALL_IN_DUST(0x00421266)
	PATCH_CALL_IN_DUST(0x0042127E)
	PATCH_CALL_IN_DUST(0x0042136E)
	PATCH_CALL_IN_DUST(0x00421389)
	PATCH_CALL_IN_DUST(0x004213A4)
	PATCH_CALL_IN_DUST(0x004214E9)
	PATCH_CALL_IN_DUST(0x004214FB)
	PATCH_CALL_IN_DUST(0x0042150D)
	PATCH_CALL_IN_DUST(0x004216A8)
	PATCH_CALL_IN_DUST(0x0042219D)
	PATCH_CALL_IN_DUST(0x00422396)
	PATCH_CALL_IN_DUST(0x0042241F)
	PATCH_CALL_IN_DUST(0x0042245A)
	PATCH_CALL_IN_DUST(0x0042248A)
	PATCH_CALL_IN_DUST(0x00423147)
	PATCH_CALL_IN_DUST(0x004232D9)
	PATCH_CALL_IN_DUST(0x00423370)
	PATCH_CALL_IN_DUST(0x00424B6C)
	PATCH_CALL_IN_DUST(0x00424C3C)
	PATCH_CALL_IN_DUST(0x00424D33)
	PATCH_CALL_IN_DUST(0x004275E2)
	PATCH_CALL_IN_DUST(0x00427843)
	PATCH_CALL_IN_DUST(0x004278B9)
	PATCH_CALL_IN_DUST(0x00427ED3)
	PATCH_CALL_IN_DUST(0x00428306)
	PATCH_CALL_IN_DUST(0x0042D069)
	PATCH_CALL_IN_DUST(0x00435BF4)
	PATCH_CALL_IN_DUST(0x00435DA3)
	PATCH_CALL_IN_DUST(0x00435DD7)
	PATCH_CALL_IN_DUST(0x00435E23)
	PATCH_CALL_IN_DUST(0x00435E57)
	PATCH_CALL_IN_DUST(0x00435EA3)
	PATCH_CALL_IN_DUST(0x00435ED7)
	PATCH_CALL_IN_DUST(0x00435F23)
	PATCH_CALL_IN_DUST(0x00435F57)
	PATCH_CALL_IN_DUST(0x00436D20)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x0042F460, DF_CopyString)

char* __cdecl DF_SetStringLength(
	char* pPfxStr)
{
	char count = 0;
	char* c = pPfxStr + 1;

	while (*c != '\0')
	{
		c++;
		count++;
	}

	*pPfxStr = count;

	return pPfxStr;
}

BEGIN_CALL_PATCHES(DF_SetStringLength)
	PATCH_CALL_IN_DUST(0x00402F9E)
	PATCH_CALL_IN_DUST(0x00403087)
	PATCH_CALL_IN_DUST(0x00403806)
	PATCH_CALL_IN_DUST(0x00408459)
	PATCH_CALL_IN_DUST(0x00408493)
	PATCH_CALL_IN_DUST(0x004084E9)
	PATCH_CALL_IN_DUST(0x00408523)
	PATCH_CALL_IN_DUST(0x004089D5)
	PATCH_CALL_IN_DUST(0x004089F0)
	PATCH_CALL_IN_DUST(0x00408A0B)
	PATCH_CALL_IN_DUST(0x00408B61)
	PATCH_CALL_IN_DUST(0x00408C73)
	PATCH_CALL_IN_DUST(0x00408E4C)
	PATCH_CALL_IN_DUST(0x004093A6)
	PATCH_CALL_IN_DUST(0x0040959A)
	PATCH_CALL_IN_DUST(0x00409796)
	PATCH_CALL_IN_DUST(0x004097B9)
	PATCH_CALL_IN_DUST(0x004097DC)
	PATCH_CALL_IN_DUST(0x004097FF)
	PATCH_CALL_IN_DUST(0x0040A113)
	PATCH_CALL_IN_DUST(0x0040A12E)
	PATCH_CALL_IN_DUST(0x0040A149)
	PATCH_CALL_IN_DUST(0x0040A164)
	PATCH_CALL_IN_DUST(0x0040BE5E)
	PATCH_CALL_IN_DUST(0x0040BF56)
	PATCH_CALL_IN_DUST(0x0040C46E)
	PATCH_CALL_IN_DUST(0x0040C529)
	PATCH_CALL_IN_DUST(0x0040C556)
	PATCH_CALL_IN_DUST(0x0040C5CD)
	PATCH_CALL_IN_DUST(0x0040C5FD)
	PATCH_CALL_IN_DUST(0x0040C8B8)
	PATCH_CALL_IN_DUST(0x0040C989)
	PATCH_CALL_IN_DUST(0x0040C9B6)
	PATCH_CALL_IN_DUST(0x0040CA2D)
	PATCH_CALL_IN_DUST(0x0040CA5D)
	PATCH_CALL_IN_DUST(0x0040CB1A)
	PATCH_CALL_IN_DUST(0x0040CBC1)
	PATCH_CALL_IN_DUST(0x0040CC65)
	PATCH_CALL_IN_DUST(0x0040CC80)
	PATCH_CALL_IN_DUST(0x0040CC9B)
	PATCH_CALL_IN_DUST(0x0040CE0D)
	PATCH_CALL_IN_DUST(0x0040CEA8)
	PATCH_CALL_IN_DUST(0x0040CFC5)
	PATCH_CALL_IN_DUST(0x0040CFE0)
	PATCH_CALL_IN_DUST(0x0040CFFB)
	PATCH_CALL_IN_DUST(0x0040D140)
	PATCH_CALL_IN_DUST(0x0040F38B)
	PATCH_CALL_IN_DUST(0x0040F8AD)
	PATCH_CALL_IN_DUST(0x0040F95E)
	PATCH_CALL_IN_DUST(0x0040F9DD)
	PATCH_CALL_IN_DUST(0x0040FB7C)
	PATCH_CALL_IN_DUST(0x0040FD39)
	PATCH_CALL_IN_DUST(0x0040FD65)
	PATCH_CALL_IN_DUST(0x0040FD91)
	PATCH_CALL_IN_DUST(0x0040FEA3)
	PATCH_CALL_IN_DUST(0x0040FF4E)
	PATCH_CALL_IN_DUST(0x00410251)
	PATCH_CALL_IN_DUST(0x0041033B)
	PATCH_CALL_IN_DUST(0x00410413)
	PATCH_CALL_IN_DUST(0x00410589)
	PATCH_CALL_IN_DUST(0x004105B2)
	PATCH_CALL_IN_DUST(0x00410619)
	PATCH_CALL_IN_DUST(0x004106B3)
	PATCH_CALL_IN_DUST(0x004106DC)
	PATCH_CALL_IN_DUST(0x0041084F)
	PATCH_CALL_IN_DUST(0x004108DD)
	PATCH_CALL_IN_DUST(0x00410C0B)
	PATCH_CALL_IN_DUST(0x00410C37)
	PATCH_CALL_IN_DUST(0x00410E4F)
	PATCH_CALL_IN_DUST(0x00410E78)
	PATCH_CALL_IN_DUST(0x00410F0A)
	PATCH_CALL_IN_DUST(0x00410F33)
	PATCH_CALL_IN_DUST(0x00410F60)
	PATCH_CALL_IN_DUST(0x0041100B)
	PATCH_CALL_IN_DUST(0x00411034)
	PATCH_CALL_IN_DUST(0x0041131F)
	PATCH_CALL_IN_DUST(0x004113AD)
	PATCH_CALL_IN_DUST(0x004114C6)
	PATCH_CALL_IN_DUST(0x004114EC)
	PATCH_CALL_IN_DUST(0x0041150E)
	PATCH_CALL_IN_DUST(0x00411530)
	PATCH_CALL_IN_DUST(0x0041157C)
	PATCH_CALL_IN_DUST(0x00411598)
	PATCH_CALL_IN_DUST(0x004115B4)
	PATCH_CALL_IN_DUST(0x004115D0)
	PATCH_CALL_IN_DUST(0x004115EC)
	PATCH_CALL_IN_DUST(0x00411E4C)
	PATCH_CALL_IN_DUST(0x00411E79)
	PATCH_CALL_IN_DUST(0x00411F0C)
	PATCH_CALL_IN_DUST(0x00411F39)
	PATCH_CALL_IN_DUST(0x00411FDA)
	PATCH_CALL_IN_DUST(0x0041203F)
	PATCH_CALL_IN_DUST(0x0041206C)
	PATCH_CALL_IN_DUST(0x0041211A)
	PATCH_CALL_IN_DUST(0x0041217F)
	PATCH_CALL_IN_DUST(0x004121AC)
	PATCH_CALL_IN_DUST(0x004122BC)
	PATCH_CALL_IN_DUST(0x00412824)
	PATCH_CALL_IN_DUST(0x004128BC)
	PATCH_CALL_IN_DUST(0x00412AA3)
	PATCH_CALL_IN_DUST(0x00412B63)
	PATCH_CALL_IN_DUST(0x00412C63)
	PATCH_CALL_IN_DUST(0x00412E0A)
	PATCH_CALL_IN_DUST(0x00412EA0)
	PATCH_CALL_IN_DUST(0x00412F3B)
	PATCH_CALL_IN_DUST(0x00413075)
	PATCH_CALL_IN_DUST(0x00413090)
	PATCH_CALL_IN_DUST(0x004130AB)
	PATCH_CALL_IN_DUST(0x00413210)
	PATCH_CALL_IN_DUST(0x004132A6)
	PATCH_CALL_IN_DUST(0x004133C5)
	PATCH_CALL_IN_DUST(0x004133E0)
	PATCH_CALL_IN_DUST(0x004133FB)
	PATCH_CALL_IN_DUST(0x004134D3)
	PATCH_CALL_IN_DUST(0x004156C2)
	PATCH_CALL_IN_DUST(0x00415713)
	PATCH_CALL_IN_DUST(0x004157A1)
	PATCH_CALL_IN_DUST(0x00415861)
	PATCH_CALL_IN_DUST(0x00415896)
	PATCH_CALL_IN_DUST(0x00415907)
	PATCH_CALL_IN_DUST(0x00415925)
	PATCH_CALL_IN_DUST(0x00415BAB)
	PATCH_CALL_IN_DUST(0x00415D67)
	PATCH_CALL_IN_DUST(0x00415D83)
	PATCH_CALL_IN_DUST(0x00415D9F)
	PATCH_CALL_IN_DUST(0x00415DB6)
	PATCH_CALL_IN_DUST(0x004176C3)
	PATCH_CALL_IN_DUST(0x00417A28)
	PATCH_CALL_IN_DUST(0x0041806E)
	PATCH_CALL_IN_DUST(0x00418097)
	PATCH_CALL_IN_DUST(0x004180D7)
	PATCH_CALL_IN_DUST(0x004182A1)
	PATCH_CALL_IN_DUST(0x004182D1)
	PATCH_CALL_IN_DUST(0x00418314)
	PATCH_CALL_IN_DUST(0x00418346)
	PATCH_CALL_IN_DUST(0x00418367)
	PATCH_CALL_IN_DUST(0x00418388)
	PATCH_CALL_IN_DUST(0x004183A9)
	PATCH_CALL_IN_DUST(0x004183DC)
	PATCH_CALL_IN_DUST(0x00418424)
	PATCH_CALL_IN_DUST(0x00418456)
	PATCH_CALL_IN_DUST(0x00418477)
	PATCH_CALL_IN_DUST(0x00418498)
	PATCH_CALL_IN_DUST(0x004184B9)
	PATCH_CALL_IN_DUST(0x004184EC)
	PATCH_CALL_IN_DUST(0x00418530)
	PATCH_CALL_IN_DUST(0x00418578)
	PATCH_CALL_IN_DUST(0x004185B2)
	PATCH_CALL_IN_DUST(0x00418625)
	PATCH_CALL_IN_DUST(0x00418640)
	PATCH_CALL_IN_DUST(0x0041865B)
	PATCH_CALL_IN_DUST(0x00418722)
	PATCH_CALL_IN_DUST(0x0041873D)
	PATCH_CALL_IN_DUST(0x00418758)
	PATCH_CALL_IN_DUST(0x00418BEA)
	PATCH_CALL_IN_DUST(0x004192E2)
	PATCH_CALL_IN_DUST(0x00419310)
	PATCH_CALL_IN_DUST(0x0041932F)
	PATCH_CALL_IN_DUST(0x00419356)
	PATCH_CALL_IN_DUST(0x00419389)
	PATCH_CALL_IN_DUST(0x004194E7)
	PATCH_CALL_IN_DUST(0x00419529)
	PATCH_CALL_IN_DUST(0x00419544)
	PATCH_CALL_IN_DUST(0x0041955F)
	PATCH_CALL_IN_DUST(0x00419D24)
	PATCH_CALL_IN_DUST(0x00419D48)
	PATCH_CALL_IN_DUST(0x00419D6C)
	PATCH_CALL_IN_DUST(0x00419D90)
	PATCH_CALL_IN_DUST(0x00419F01)
	PATCH_CALL_IN_DUST(0x00419F2E)
	PATCH_CALL_IN_DUST(0x00419FB1)
	PATCH_CALL_IN_DUST(0x00419FDE)
	PATCH_CALL_IN_DUST(0x0041A071)
	PATCH_CALL_IN_DUST(0x0041A0F9)
	PATCH_CALL_IN_DUST(0x0041A17B)
	PATCH_CALL_IN_DUST(0x0041A1A8)
	PATCH_CALL_IN_DUST(0x0041A231)
	PATCH_CALL_IN_DUST(0x0041A2B9)
	PATCH_CALL_IN_DUST(0x0041A33B)
	PATCH_CALL_IN_DUST(0x0041A368)
	PATCH_CALL_IN_DUST(0x0041A3F5)
	PATCH_CALL_IN_DUST(0x0041A410)
	PATCH_CALL_IN_DUST(0x0041A42B)
	PATCH_CALL_IN_DUST(0x0041A5C4)
	PATCH_CALL_IN_DUST(0x0041A643)
	PATCH_CALL_IN_DUST(0x0041A6D1)
	PATCH_CALL_IN_DUST(0x0041A815)
	PATCH_CALL_IN_DUST(0x0041A830)
	PATCH_CALL_IN_DUST(0x0041A84B)
	PATCH_CALL_IN_DUST(0x0041A9C7)
	PATCH_CALL_IN_DUST(0x0041AA65)
	PATCH_CALL_IN_DUST(0x0041AB95)
	PATCH_CALL_IN_DUST(0x0041ABB0)
	PATCH_CALL_IN_DUST(0x0041ABCB)
	PATCH_CALL_IN_DUST(0x0041ACA3)
	PATCH_CALL_IN_DUST(0x0041AD63)
	PATCH_CALL_IN_DUST(0x0041ADE7)
	PATCH_CALL_IN_DUST(0x0041AF07)
	PATCH_CALL_IN_DUST(0x0041B04B)
	PATCH_CALL_IN_DUST(0x0041B06F)
	PATCH_CALL_IN_DUST(0x0041B093)
	PATCH_CALL_IN_DUST(0x0041B0B7)
	PATCH_CALL_IN_DUST(0x0041B38E)
	PATCH_CALL_IN_DUST(0x0041B3C7)
	PATCH_CALL_IN_DUST(0x0041B3ED)
	PATCH_CALL_IN_DUST(0x0041B404)
	PATCH_CALL_IN_DUST(0x0041B42A)
	PATCH_CALL_IN_DUST(0x0041B441)
	PATCH_CALL_IN_DUST(0x0041B467)
	PATCH_CALL_IN_DUST(0x0041B47E)
	PATCH_CALL_IN_DUST(0x0041B4A4)
	PATCH_CALL_IN_DUST(0x0041B4BB)
	PATCH_CALL_IN_DUST(0x0041B61C)
	PATCH_CALL_IN_DUST(0x0041B701)
	PATCH_CALL_IN_DUST(0x0041B9C6)
	PATCH_CALL_IN_DUST(0x0041BDD9)
	PATCH_CALL_IN_DUST(0x0041E046)
	PATCH_CALL_IN_DUST(0x00420800)
	PATCH_CALL_IN_DUST(0x004208B9)
	PATCH_CALL_IN_DUST(0x004208E6)
	PATCH_CALL_IN_DUST(0x00420960)
	PATCH_CALL_IN_DUST(0x00420990)
	PATCH_CALL_IN_DUST(0x00420C58)
	PATCH_CALL_IN_DUST(0x00420D29)
	PATCH_CALL_IN_DUST(0x00420D56)
	PATCH_CALL_IN_DUST(0x00420DCF)
	PATCH_CALL_IN_DUST(0x00420DFF)
	PATCH_CALL_IN_DUST(0x00420EBA)
	PATCH_CALL_IN_DUST(0x00420F61)
	PATCH_CALL_IN_DUST(0x00421005)
	PATCH_CALL_IN_DUST(0x00421020)
	PATCH_CALL_IN_DUST(0x0042103B)
	PATCH_CALL_IN_DUST(0x004211AD)
	PATCH_CALL_IN_DUST(0x00421248)
	PATCH_CALL_IN_DUST(0x00421365)
	PATCH_CALL_IN_DUST(0x00421380)
	PATCH_CALL_IN_DUST(0x0042139B)
	PATCH_CALL_IN_DUST(0x004214E0)
	PATCH_CALL_IN_DUST(0x0042313E)
	PATCH_CALL_IN_DUST(0x00423A4C)
	PATCH_CALL_IN_DUST(0x00423B54)
	PATCH_CALL_IN_DUST(0x0042675F)
	PATCH_CALL_IN_DUST(0x0042678C)
	PATCH_CALL_IN_DUST(0x00426EF1)
	PATCH_CALL_IN_DUST(0x00426FAA)
	PATCH_CALL_IN_DUST(0x0042706C)
	PATCH_CALL_IN_DUST(0x00427125)
	PATCH_CALL_IN_DUST(0x00427ECA)
	PATCH_CALL_IN_DUST(0x004281FB)
	PATCH_CALL_IN_DUST(0x0042D07B)
	PATCH_CALL_IN_DUST(0x0042EE85)
	PATCH_CALL_IN_DUST(0x0042EEB8)
	PATCH_CALL_IN_DUST(0x00435DCE)
	PATCH_CALL_IN_DUST(0x00435E4E)
	PATCH_CALL_IN_DUST(0x00435ECE)
	PATCH_CALL_IN_DUST(0x00435F4E)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x004284F0, DF_SetStringLength)

char* DF_INTERNAL_LoadStringBuffer = 
#if TITANIC
#elif LUNICUS
#else
	(char*)0x004468B0;
#endif

const char* __cdecl DF_LoadString(unsigned int id)
{
	const char* result = NULL;

	memset(
		DF_INTERNAL_LoadStringBuffer,
		'\0',
		DF_INTERNAL_LoadStringBuffer_Length * sizeof(char));

	int numChars = LoadStringA(
		Global.appInstance,
		id,
		DF_INTERNAL_LoadStringBuffer,
		DF_INTERNAL_LoadStringBuffer_Length);

	if (numChars)
	{
#if 1
		printf("LoadString(%u): %.*s\n",
			id, numChars, DF_INTERNAL_LoadStringBuffer);
#endif
		result = (const char*)DF_INTERNAL_LoadStringBuffer;
	}

	return result;
}

BEGIN_CALL_PATCHES(DF_LoadString)
	PATCH_CALL_IN_DUST(0x00429BDB)
	PATCH_CALL_IN_DUST(0x0042AE22)
	PATCH_CALL_IN_DUST(0x0042AE44)
	PATCH_CALL_IN_DUST(0x0042AECF)
	PATCH_CALL_IN_DUST(0x0042AEE7)
	PATCH_CALL_IN_DUST(0x0042AF25)
	PATCH_CALL_IN_DUST(0x0042AF81)
	PATCH_CALL_IN_DUST(0x0042AF99)
	PATCH_CALL_IN_DUST(0x0042AFD2)
	PATCH_CALL_IN_DUST(0x0042B010)
	PATCH_CALL_IN_DUST(0x0042B064)
	PATCH_CALL_IN_DUST(0x0042B081)
	PATCH_CALL_IN_DUST(0x0042B0BD)
	PATCH_CALL_IN_DUST(0x0042B0D5)
	PATCH_CALL_IN_DUST(0x0042B113)
	PATCH_CALL_IN_DUST(0x0042B170)
	PATCH_CALL_IN_DUST(0x0042B188)
	PATCH_CALL_IN_DUST(0x0042B1C6)
	PATCH_CALL_IN_DUST(0x0042BDB4)
	PATCH_CALL_IN_DUST(0x0042BE3A)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x004299C0, DF_LoadString);

WORD __cdecl DF_StringsAreEqual(char* pPfxA, char* pPfxB)
{
	WORD result = 0;
	char count = *pPfxA;

#if 0
	char countB = *pPfxB;

	char* p1 = pPfxA;
	char* p2 = pPfxB;
#endif

	if (*pPfxA == *pPfxB)
	{
		do
		{
			pPfxA++;
			pPfxB++;

			if (!count--)
			{
				result = 1;
				break;
			}
		} while (
			DF_INTERNAL_CharacterTable[*pPfxA] == 
			DF_INTERNAL_CharacterTable[*pPfxB]);
	}

#if 0
	if (result)
		printf("\"%.*s\" == \"%.*s\"\n", count, p1 + 1, countB, p2 + 1);
	else
		printf("\"%.*s\" != \"%.*s\"\n", count, p1 + 1, countB, p2 + 1);
#endif

	return result;
}

BEGIN_CALL_PATCHES(DF_StringsAreEqual)
	PATCH_CALL_IN_DUST(0x00401965)
	PATCH_CALL_IN_DUST(0x004019AB)
	PATCH_CALL_IN_DUST(0x004092DD)
	PATCH_CALL_IN_DUST(0x004097A0)
	PATCH_CALL_IN_DUST(0x004097C3)
	PATCH_CALL_IN_DUST(0x004097E6)
	PATCH_CALL_IN_DUST(0x00409809)
	PATCH_CALL_IN_DUST(0x00409CBE)
	PATCH_CALL_IN_DUST(0x00409CD8)
	PATCH_CALL_IN_DUST(0x00409D94)
	PATCH_CALL_IN_DUST(0x00409DAE)
	PATCH_CALL_IN_DUST(0x0040AC70)
	PATCH_CALL_IN_DUST(0x0040AE40)
	PATCH_CALL_IN_DUST(0x0040BE67)
	PATCH_CALL_IN_DUST(0x0040BF5F)
	PATCH_CALL_IN_DUST(0x0040C485)
	PATCH_CALL_IN_DUST(0x0040D914)
	PATCH_CALL_IN_DUST(0x0040D953)
	PATCH_CALL_IN_DUST(0x0040DA45)
	PATCH_CALL_IN_DUST(0x0040DB91)
	PATCH_CALL_IN_DUST(0x0040DD85)
	PATCH_CALL_IN_DUST(0x0040E0BB)
	PATCH_CALL_IN_DUST(0x0040E237)
	PATCH_CALL_IN_DUST(0x0040F479)
	PATCH_CALL_IN_DUST(0x0040F505)
	PATCH_CALL_IN_DUST(0x0040F8BB)
	PATCH_CALL_IN_DUST(0x0040F900)
	PATCH_CALL_IN_DUST(0x0040F96C)
	PATCH_CALL_IN_DUST(0x0040F9A8)
	PATCH_CALL_IN_DUST(0x0040F9EB)
	PATCH_CALL_IN_DUST(0x0040FA1A)
	PATCH_CALL_IN_DUST(0x0040FA5A)
	PATCH_CALL_IN_DUST(0x0040FAC1)
	PATCH_CALL_IN_DUST(0x0040FB0A)
	PATCH_CALL_IN_DUST(0x0040FB5A)
	PATCH_CALL_IN_DUST(0x0040FF01)
	PATCH_CALL_IN_DUST(0x0040FF5C)
	PATCH_CALL_IN_DUST(0x0040FFB5)
	PATCH_CALL_IN_DUST(0x004100EA)
	PATCH_CALL_IN_DUST(0x0041020E)
	PATCH_CALL_IN_DUST(0x004105FF)
	PATCH_CALL_IN_DUST(0x00410622)
	PATCH_CALL_IN_DUST(0x0041089A)
	PATCH_CALL_IN_DUST(0x004108EB)
	PATCH_CALL_IN_DUST(0x00410937)
	PATCH_CALL_IN_DUST(0x00411099)
	PATCH_CALL_IN_DUST(0x0041136A)
	PATCH_CALL_IN_DUST(0x004113BB)
	PATCH_CALL_IN_DUST(0x00411407)
	PATCH_CALL_IN_DUST(0x004114D4)
	PATCH_CALL_IN_DUST(0x004114F6)
	PATCH_CALL_IN_DUST(0x00411518)
	PATCH_CALL_IN_DUST(0x0041153A)
	PATCH_CALL_IN_DUST(0x0041383F)
	PATCH_CALL_IN_DUST(0x004139C7)
	PATCH_CALL_IN_DUST(0x00419D32)
	PATCH_CALL_IN_DUST(0x00419D56)
	PATCH_CALL_IN_DUST(0x00419D7A)
	PATCH_CALL_IN_DUST(0x00419D9E)
	PATCH_CALL_IN_DUST(0x0041B054)
	PATCH_CALL_IN_DUST(0x0041B078)
	PATCH_CALL_IN_DUST(0x0041B09C)
	PATCH_CALL_IN_DUST(0x0041B0C0)
	PATCH_CALL_IN_DUST(0x0041BB3F)
	PATCH_CALL_IN_DUST(0x0041BBC7)
	PATCH_CALL_IN_DUST(0x0041BBE0)
	PATCH_CALL_IN_DUST(0x0041BDE2)
	PATCH_CALL_IN_DUST(0x0041BE36)
	PATCH_CALL_IN_DUST(0x0041BE4B)
	PATCH_CALL_IN_DUST(0x0041BE64)
	PATCH_CALL_IN_DUST(0x0041BE79)
	PATCH_CALL_IN_DUST(0x0041BF3C)
	PATCH_CALL_IN_DUST(0x0041BF55)
	PATCH_CALL_IN_DUST(0x0041CE2E)
	PATCH_CALL_IN_DUST(0x0041DDE0)
	PATCH_CALL_IN_DUST(0x0041DFD7)
	PATCH_CALL_IN_DUST(0x0041EB92)
	PATCH_CALL_IN_DUST(0x0041EE70)
	PATCH_CALL_IN_DUST(0x0041F3F0)
	PATCH_CALL_IN_DUST(0x00420817)
	PATCH_CALL_IN_DUST(0x004217C4)
	PATCH_CALL_IN_DUST(0x00421805)
	PATCH_CALL_IN_DUST(0x00421905)
	PATCH_CALL_IN_DUST(0x00421A51)
	PATCH_CALL_IN_DUST(0x00421C45)
	PATCH_CALL_IN_DUST(0x00421F88)
	PATCH_CALL_IN_DUST(0x00422107)
	PATCH_CALL_IN_DUST(0x0042299B)
	PATCH_CALL_IN_DUST(0x00422A5F)
	PATCH_CALL_IN_DUST(0x00423B09)
	PATCH_CALL_IN_DUST(0x00424ACF)
	PATCH_CALL_IN_DUST(0x00426768)
	PATCH_CALL_IN_DUST(0x00426795)
	PATCH_CALL_IN_DUST(0x00426EFF)
	PATCH_CALL_IN_DUST(0x00426FB8)
	PATCH_CALL_IN_DUST(0x0042707A)
	PATCH_CALL_IN_DUST(0x00427133)
	PATCH_CALL_IN_DUST(0x00427758)
	PATCH_CALL_IN_DUST(0x00427790)
	PATCH_CALL_IN_DUST(0x00436C20)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x0042F350, DF_StringsAreEqual)

void __cdecl DF_ConcatStrings(const char* pFrom, char* pTo)
{
	WORD combined = ((WORD)*pFrom + (WORD)*pTo);

	if (combined > 0xFF)
	{
		DF_FatalError(0x006E, 0x0325);
	}
	else
	{
#if 0
		printf("\"%.*s\" + \"%.*s\"\n", *pFrom, pFrom + 1, *pTo, pTo + 1);
#endif

		char count = *pFrom;

		const char* src = &pFrom[1];
		char* dst = &pTo[*pTo + 1];

		while (count--)
		{
			*dst++ = *src++;
		}

		*pTo = (char)combined;
	}
}

BEGIN_CALL_PATCHES(DF_ConcatStrings)
	PATCH_CALL_IN_DUST(0x00408481)
	PATCH_CALL_IN_DUST(0x0040849C)
	PATCH_CALL_IN_DUST(0x00408511)
	PATCH_CALL_IN_DUST(0x0040852C)
	PATCH_CALL_IN_DUST(0x00408C8E)
	PATCH_CALL_IN_DUST(0x0040C544)
	PATCH_CALL_IN_DUST(0x0040C55F)
	PATCH_CALL_IN_DUST(0x0040C5EB)
	PATCH_CALL_IN_DUST(0x0040C606)
	PATCH_CALL_IN_DUST(0x0040C9A4)
	PATCH_CALL_IN_DUST(0x0040C9BF)
	PATCH_CALL_IN_DUST(0x0040CA4B)
	PATCH_CALL_IN_DUST(0x0040CA66)
	PATCH_CALL_IN_DUST(0x0040CB35)
	PATCH_CALL_IN_DUST(0x0040CBDC)
	PATCH_CALL_IN_DUST(0x0040FD53)
	PATCH_CALL_IN_DUST(0x0040FD6E)
	PATCH_CALL_IN_DUST(0x0040FD7F)
	PATCH_CALL_IN_DUST(0x0040FD9A)
	PATCH_CALL_IN_DUST(0x004105A0)
	PATCH_CALL_IN_DUST(0x004105BB)
	PATCH_CALL_IN_DUST(0x004106CA)
	PATCH_CALL_IN_DUST(0x004106E5)
	PATCH_CALL_IN_DUST(0x00410C25)
	PATCH_CALL_IN_DUST(0x00410C40)
	PATCH_CALL_IN_DUST(0x00410E66)
	PATCH_CALL_IN_DUST(0x00410E81)
	PATCH_CALL_IN_DUST(0x00410F21)
	PATCH_CALL_IN_DUST(0x00410F3C)
	PATCH_CALL_IN_DUST(0x00410F4E)
	PATCH_CALL_IN_DUST(0x00410F69)
	PATCH_CALL_IN_DUST(0x00411022)
	PATCH_CALL_IN_DUST(0x0041103D)
	PATCH_CALL_IN_DUST(0x00411E67)
	PATCH_CALL_IN_DUST(0x00411E82)
	PATCH_CALL_IN_DUST(0x00411F27)
	PATCH_CALL_IN_DUST(0x00411F42)
	PATCH_CALL_IN_DUST(0x0041205A)
	PATCH_CALL_IN_DUST(0x00412075)
	PATCH_CALL_IN_DUST(0x0041219A)
	PATCH_CALL_IN_DUST(0x004121B5)
	PATCH_CALL_IN_DUST(0x00412ABE)
	PATCH_CALL_IN_DUST(0x00412B7E)
	PATCH_CALL_IN_DUST(0x00412C7E)
	PATCH_CALL_IN_DUST(0x00415A3D)
	PATCH_CALL_IN_DUST(0x00416C4B)
	PATCH_CALL_IN_DUST(0x00416E05)
	PATCH_CALL_IN_DUST(0x004176CC)
	PATCH_CALL_IN_DUST(0x00417C82)
	PATCH_CALL_IN_DUST(0x004182BF)
	PATCH_CALL_IN_DUST(0x004182DA)
	PATCH_CALL_IN_DUST(0x004183C7)
	PATCH_CALL_IN_DUST(0x004183E5)
	PATCH_CALL_IN_DUST(0x004184D7)
	PATCH_CALL_IN_DUST(0x004184F5)
	PATCH_CALL_IN_DUST(0x00418566)
	PATCH_CALL_IN_DUST(0x00418581)
	PATCH_CALL_IN_DUST(0x0041937B)
	PATCH_CALL_IN_DUST(0x00419392)
	PATCH_CALL_IN_DUST(0x00419F1C)
	PATCH_CALL_IN_DUST(0x00419F37)
	PATCH_CALL_IN_DUST(0x00419FCC)
	PATCH_CALL_IN_DUST(0x00419FE7)
	PATCH_CALL_IN_DUST(0x0041A102)
	PATCH_CALL_IN_DUST(0x0041A196)
	PATCH_CALL_IN_DUST(0x0041A1B1)
	PATCH_CALL_IN_DUST(0x0041A2C2)
	PATCH_CALL_IN_DUST(0x0041A356)
	PATCH_CALL_IN_DUST(0x0041A371)
	PATCH_CALL_IN_DUST(0x0041AD7E)
	PATCH_CALL_IN_DUST(0x0041AE02)
	PATCH_CALL_IN_DUST(0x0041AF34)
	PATCH_CALL_IN_DUST(0x0041E04F)
	PATCH_CALL_IN_DUST(0x0041E90A)
	PATCH_CALL_IN_DUST(0x004208D4)
	PATCH_CALL_IN_DUST(0x004208EF)
	PATCH_CALL_IN_DUST(0x0042097E)
	PATCH_CALL_IN_DUST(0x00420999)
	PATCH_CALL_IN_DUST(0x00420D44)
	PATCH_CALL_IN_DUST(0x00420D5F)
	PATCH_CALL_IN_DUST(0x00420DED)
	PATCH_CALL_IN_DUST(0x00420E08)
	PATCH_CALL_IN_DUST(0x00420ED5)
	PATCH_CALL_IN_DUST(0x00420F7C)
	PATCH_CALL_IN_DUST(0x004228FB)
	PATCH_CALL_IN_DUST(0x00424D25)
	PATCH_CALL_IN_DUST(0x0042831E)
	PATCH_CALL_IN_DUST(0x0042D084)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x0042F400, DF_ConcatStrings)

void __cdecl DF_ConvertString(char* pStr)
{
	char* base = pStr;
	int count = 0;

	while (*base++ != '\0')
	{
		count++;
	}

	memcpy(&pStr[1], pStr, sizeof(char) * count);

	*pStr = (char)count;

#if 1
	if (count)
	{
		printf("Converted string \"%.*s\"\n", count, pStr + 1);
	}
#endif
}

BEGIN_CALL_PATCHES(DF_ConvertString)
	PATCH_CALL_IN_DUST(0x0041CBA1)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x0041CBB0, DF_ConvertString)


char __cdecl DF_StringContainsString(
	const char* pHaystack,
	const char* pNeedle,
	char numChars)
{
	char result = !numChars ? 1 : 0;

#if 1
	printf("Check if \"%.*s\" contains \"%.*s\"\n", numChars, pHaystack, numChars, pNeedle);
#endif

	if (!result)
	{
		do
		{
			if (!numChars)
			{
				result = 1;
				break;
			}

			pHaystack++;
			pNeedle++;

			numChars--;
		} while (DF_INTERNAL_CharacterTable[*pHaystack] ==
				 DF_INTERNAL_CharacterTable[*pNeedle]);
	}
/*
Check if "appl:" contains "dust:"
Check if "ppl:l" contains "dust:"
Check if "pl:lo" contains "dust:"
Check if "l:loc" contains "dust:"
Check if ":loca" contains "dust:"
Check if "local" contains "dust:"
Check if "ocal:" contains "dust:"
*/
/*
undefined4 MaybeStringsAreEqualUpToN(byte *param_1,byte *param_2,short param_3)

{
  byte bVar1;
  uint in_EAX;

  do {
	if (param_3 == 0) {
	  return CONCAT22((short)(in_EAX >> 0x10),1);
	}
	in_EAX = (uint)*param_1;
	bVar1 = *param_2;
	param_1 = param_1 + 1;
	param_2 = param_2 + 1;
	param_3 = param_3 + -1;
  } while (g_pCharacterTable[in_EAX] == g_pCharacterTable[bVar1]);
  return 0;
}
*/

	return result;
}

BEGIN_CALL_PATCHES(DF_StringContainsString)
	PATCH_CALL_IN_DUST(0x00416980)
	PATCH_CALL_IN_DUST(0x00416AF7)
	PATCH_CALL_IN_DUST(0x00416C8D)
	PATCH_CALL_IN_DUST(0x00424CE2)
END_CALL_PATCHES

DECLARE_DF_FUNCTION_IN_DUST(
	0x0042F3B0, DF_StringContainsString)