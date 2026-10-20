#include <globaldefs.h>
#include <std_library_functions.h>
#include <GameState/GameState.h>
#include <Memory/SafeAllocator.h>
extern "C" {
// Original: arm9/main @ 0x020DA150; symbol: func_020da150; size: 0x5C.
char *Allocator_DuplicateTerminatedString(SafeAllocator *a,char *s){if(!s)return 0;unsigned int len=strlen(s);unsigned int size=len+1;char *p=(char *)a->Allocate(size);if(!p)return 0;strncpy(p,s,len);*(p+size-1)=0;return p;}
}
