/* Inspect capture-enable bit 7 in the selected byte-wide capture register. */
#pragma dont_inline on
int ARM7_IsSoundCaptureActive(int capture)
{
 return (*(volatile unsigned char*)(0x04000508+capture)&0x80)!=0;
}
