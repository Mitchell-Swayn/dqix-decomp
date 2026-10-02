/* Initialize the shared SPI power-task state and its sixteen halfword slots. */
#pragma dont_inline on
typedef struct {
 unsigned int unknown0[9],operation;
} PowerState;
extern volatile PowerState ARM7_PowerState;
void ARM7_InitializePowerState(void)
{
 int i;
 ARM7_PowerState.unknown0[0]=1;
 ARM7_PowerState.operation=0;
 i=0;
 do {
  ((volatile unsigned short*)((unsigned int)&ARM7_PowerState+4))[i]=0;
  i++;
 } while(i<16);
}
