#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
void Bgm_ResetZoneOverrideTable(void *);
// Original: arm9/main @ 0x0209CE00; symbol: func_0209ce00; size: 0x14.
void *Bgm_InitializeZoneOverrideTable(void *p){Bgm_ResetZoneOverrideTable(p);return p;}
}
