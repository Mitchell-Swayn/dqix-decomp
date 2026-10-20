#include <globaldefs.h>
struct Descriptor { unsigned char pad[4]; unsigned short a,b; unsigned char p[12]; unsigned flags; unsigned char q[10]; unsigned short low:2; unsigned short nibble:4; unsigned short rest:10; };
struct Owner { unsigned char pad[0x138]; Descriptor* d; };
struct Record { void* a; void* b; unsigned char p[4]; short x,y,z; unsigned short d,e; unsigned char q[2]; unsigned flags; unsigned char flagsByte, nibble, lowBits; };
#pragma force_active on
// Original: arm9/ov000 @ 0x0215CCBC; symbol: func_ov000_0215ccbc; size: 0x88.
// Describes observed operations; underlying field roles remain uncertain.
extern "C" void Combat_PopulateResultFromCombatantSnapshot(void*, Record* out, Owner* owner, short x, short y, short z, void* a, void* b, unsigned char flags)
{
    if (!out) return; out->x=x; out->y=y; out->z=z; out->d=owner->d->a; out->e=owner->d->b; out->flags=owner->d->flags; out->nibble=owner->d->nibble; out->lowBits=owner->d->low; out->a=a; out->b=b; out->flagsByte=flags;
}
