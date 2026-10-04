/* Test observed shared halfword bit 2; broader flag semantics remain unknown. */
int ARM7_TestSharedBootFlag4(void)
{
 return (*(volatile unsigned short*)0x027ffffa & 4) != 0;
}
