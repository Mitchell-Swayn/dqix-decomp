/* Read the controller's basic touch-state response over SPI. */
#pragma dont_inline on
extern void ARM7_SetGPIOControlMode(unsigned int);
extern void ARM7_ClockTouchCommandByte(void);
extern unsigned short ARM7_TouchControllerStatus;
#define TOUCH_SPI_CONTROL (*(volatile unsigned short*)0x040001c0)
#define TOUCH_SPI_DATA (*(volatile unsigned short*)0x040001c2)
#define TOUCH_GPIO (*(volatile unsigned short*)0x04000136)
int ARM7_ReadTouchControllerStatus(void)
{
 int result;
 ARM7_SetGPIOControlMode(0x8000);
 while(TOUCH_SPI_CONTROL&0x80) {}
 TOUCH_SPI_CONTROL=0x8a01;
 TOUCH_SPI_DATA=0x84;
 while(TOUCH_SPI_CONTROL&0x80) {}
 ARM7_ClockTouchCommandByte();
 TOUCH_SPI_CONTROL=0x8201;
 ARM7_ClockTouchCommandByte();
 if(ARM7_TouchControllerStatus==0) {
  result=(TOUCH_GPIO&0x40)?0:1;
 } else if(!(TOUCH_GPIO&0x40)) {
  result=1;
 } else {
  *(volatile unsigned short*)((unsigned int)&TOUCH_GPIO+0x8a)=0x8a01;
  *(volatile unsigned short*)((unsigned int)&TOUCH_GPIO+0x8c)=0x84;
  while(*(volatile unsigned short*)((unsigned int)&TOUCH_GPIO+0x8a)&0x80) {}
  ARM7_ClockTouchCommandByte();
  *(volatile unsigned short*)((unsigned int)&TOUCH_GPIO+0x8a)=0x8201;
  ARM7_ClockTouchCommandByte();
  result=(TOUCH_GPIO&0x40)?0:2;
 }
 return result;
}
