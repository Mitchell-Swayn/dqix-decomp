#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x0217F278; symbol: Object_ReadWordAtOffsetC_Ov003; size: 0x8.
// Reads the 32-bit word at object offset 0x0c. The object type remains unclear; module suffix temporarily disambiguates an equivalent getter in ov016.
extern "C" unsigned int Inn_GetServiceSceneController(void* self) { return *(unsigned int*)((unsigned char*)self + 0x0c); }
