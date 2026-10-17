/* Initialize the three ARM7-owned arena bounds once. The guard and shared
 * arena boundary storage remain externally owned startup BSS/data. */
#pragma dont_inline on
extern int ARM7_ArenasInitialized;
extern void ARM7_InitializeArena(int);
// Original: arm7/wram @ 0x037FCE4C; symbol: ARM7_InitializeArenas.
void ARM7_InitializeArenas(void)
{
 if(!ARM7_ArenasInitialized) {
  ARM7_ArenasInitialized=1;
  ARM7_InitializeArena(1);
  ARM7_InitializeArena(7);
  ARM7_InitializeArena(8);
 }
}
