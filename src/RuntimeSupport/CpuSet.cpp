// SDK support (community reconstruction): CpuSet.
/*---------------------------------------------------------------------------------

	Copyright (C) 2005
		Michael Noland (joat)
		Jason Rogers (dovoto)
		Dave Murphy (WinterMute)

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any
	damages arising from the use of this software.

	Permission is granted to anyone to use this software for any
	purpose, including commercial applications, and to alter it and
	redistribute it freely, subject to the following restrictions:

	1.	The origin of this software must not be misrepresented; you
		must not claim that you wrote the original software. If you use
		this software in a product, an acknowledgment in the product
		documentation would be appreciated but is not required.
	2.	Altered source versions must be plainly marked as such, and
		must not be misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source
		distribution.

---------------------------------------------------------------------------------*/
#include <globaldefs.h>
THUMB
// Original: arm9/main @ 0x020001C0; symbol: CpuSet; size: 0x4.
// Community BIOS assembly, adapted from devkitPro/libnds swiCopy:
// commit b83ba2aecb782d3540753badde6a5ad7428c5a09, source/common/biosCalls.s:76.
// Necessary SVC entry stub; count/control word in r2 follows the BIOS ABI.
// This is assembly support and does not earn ordinary C/C++ reconstruction credit.
extern "C" asm void CpuSet(const void* source,void* destination,unsigned countAndFlags)
{
 swi 0x0b
 bx lr
}
