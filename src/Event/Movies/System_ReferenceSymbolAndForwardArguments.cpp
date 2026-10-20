#include <globaldefs.h>
ARM
extern "C" void OSi_ReferSymbol(const void *);
extern "C" void InitializeModsStreamBuffers(unsigned int, unsigned int, unsigned int);
// Original: arm9/ov016 @ 0x0218E528; symbol: System_ReferenceSymbolAndForwardArguments; size: 0x30.
// References fixed symbol 0x02000bdc for linkage, then forwards all arguments to the overlay helper.
extern "C" void System_ReferenceSymbolAndForwardArguments(unsigned int a, unsigned int b, unsigned int c) {
    OSi_ReferSymbol((const void *)0x02000bdc);
    InitializeModsStreamBuffers(a, b, c);
}
