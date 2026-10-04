/* Select the hardware power LED mode and preserve its cached value. */
#pragma dont_inline on
extern void ARM7_SetPowerControlBits(unsigned int);
extern void ARM7_ClearPowerControlBits(unsigned int);
extern void ARM7_Panic(const char*,int,const char*,...);
extern const char ARM7_PowerUtilityFile[],ARM7_BadPowerLedMode[];
extern int ARM7_PowerLedMode;
void ARM7_SetPowerLedMode(int mode)
{
 switch(mode) {
 case 1:ARM7_ClearPowerControlBits(0x10);break;
 case 3:ARM7_SetPowerControlBits(0x30);break;
 case 2:ARM7_ClearPowerControlBits(0x20);ARM7_SetPowerControlBits(0x10);break;
 default:ARM7_Panic(ARM7_PowerUtilityFile,0xdf,ARM7_BadPowerLedMode);break;
 }
 ARM7_PowerLedMode=mode;
}
