/* Stop a channel by clearing control bit 31; flag bit 0 additionally sets
 * control bit 15. Channel register stride is 16 bytes. */
#pragma dont_inline on
void ARM7_StopSoundChannel(int channel,unsigned int flags)
{
 volatile unsigned int *control=(volatile unsigned int*)(0x04000400+16*channel);
 unsigned int value=*control & ~0x80000000;
 if(flags&1)value|=0x8000;
 *control=value;
}
