/* Initialize, advance and evaluate delayed sound modulation.
 * Phase retains an eight-bit fractional part and wraps at 128 sine steps. */
#pragma dont_inline on
#include "SoundVoice.h"
extern int ARM7_SoundSine(int);
void ARM7_InitializeSoundModulation(SoundModulation *mod)
{
 mod->unknown0=0;mod->depth=0;mod->range=1;mod->speed=16;mod->delay=0;
}
void ARM7_UpdateSoundModulation(SoundModulation *mod)
{
 unsigned int phase;
 if(mod->counter<mod->delay){mod->counter++;return;}
 phase=mod->phase; phase=(phase+(mod->speed<<6))>>8;
 while(phase>=128)phase-=128;
 mod->phase+=mod->speed<<6;
 mod->phase&=255;
 mod->phase|=phase<<8;
}
int ARM7_ReadSoundModulation(SoundModulation *mod)
{
 int sine;
 if(mod->depth==0)return 0;
 if(mod->counter<mod->delay)return 0;
 sine=ARM7_SoundSine((unsigned int)mod->phase>>8);
 return mod->depth*sine*mod->range;
}
