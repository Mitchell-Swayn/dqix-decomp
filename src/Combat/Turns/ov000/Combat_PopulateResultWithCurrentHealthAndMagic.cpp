#include <globaldefs.h>
ARM
struct Record;
struct Descriptor { unsigned char pad[4]; unsigned short a,b; unsigned char p[12]; unsigned flags; unsigned char q[10]; unsigned short low:2; unsigned short nibble:4; unsigned short rest:10; };
struct Owner { unsigned char pad[0x138]; Descriptor* d; };
extern "C" void Combat_PopulateResultFromCombatantSnapshot(void*,Record*,Owner*,short,short,short,void*,void*,unsigned char);
// Original: arm9/ov000 @ 0x0215CD44; symbol: Combat_PopulateResultWithCurrentHealthAndMagic; size: 0x3C.
// Uses the descriptor's first two signed halfwords as record coordinates; their broader roles remain uncertain.
extern "C" void Combat_PopulateResultWithCurrentHealthAndMagic(void* self,Record* out,Owner* owner,short x,void* a,void* b,unsigned char flags)
{
    short z=*((volatile short*)owner->d+1);
    short y=*(volatile short*)owner->d;
    Combat_PopulateResultFromCombatantSnapshot(self,out,owner,x,y,z,a,b,flags);
}
