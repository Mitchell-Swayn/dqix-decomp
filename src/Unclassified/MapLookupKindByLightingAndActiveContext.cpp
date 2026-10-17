#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
char *_ZN15LightingManager11GetInstanceEv();void *Object_GetGlobalConnectionState();int IsFirstWordNonzero(void *);extern signed char data_020e8ed8[];
// Original: arm9/main @ 0x0209CAF0; symbol: func_0209caf0; size: 0x78.
int MapLookupKindByLightingAndActiveContext(unsigned int i){if(i>=47)return -1;if(!*(int *)(_ZN15LightingManager11GetInstanceEv()+0x98)){int n=data_020e8ed8[i];if(n==3)return 4;if(n==5)return 6;}if(IsFirstWordNonzero(Object_GetGlobalConnectionState())&&data_020e8ed8[i]==14)return 16;return data_020e8ed8[i];}
}
