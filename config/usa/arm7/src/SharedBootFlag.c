/* Test observed shared halfword bit 2; broader flag semantics remain unknown. */
// Original: arm7/wram @ 0x037FCAC0; symbol: ARM7_TestSharedBootFlag4.
int ARM7_TestSharedBootFlag4(void)
{
 return (*(volatile unsigned short*)0x027ffffa & 4) != 0;
}
