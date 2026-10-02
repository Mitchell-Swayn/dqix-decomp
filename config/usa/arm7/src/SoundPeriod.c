/* Normalize signed pitch in 768-step octaves, apply the BIOS fractional ratio,
 * and clamp the resulting period to 16..65535 with left-shift overflow checks. */
#pragma dont_inline on
typedef unsigned long long U64;
extern unsigned int ARM7_BiosPitchTable(unsigned int);
unsigned int ARM7_GetSoundPitchTable(unsigned int);
unsigned short ARM7_ConvertSoundPeriod(int basePeriod,int pitch)
{
 int octave=0;
 int remainder=-pitch;
 U64 period;
 unsigned int fraction;
 while(remainder<0){octave--;remainder+=768;}
 while(remainder>=768){octave++;remainder-=768;}
 fraction=ARM7_GetSoundPitchTable(remainder);
 period=(fraction+0x10000ULL)*basePeriod;
 octave-=16;
 if(octave<=0)period>>=-octave;
 else if(octave<32){
  if(period & (~0ULL<<(32-octave)))return 65535;
  period<<=octave;
 }else return 65535;
 if(period<16)period=16;
 else if(period>65535)period=65535;
 return period;
}
unsigned int ARM7_GetSoundPitchTable(unsigned int index)
{
 return ARM7_BiosPitchTable(index);
}
