#include <globaldefs.h>
ARM
struct Object;
extern "C" void WfcUtility_QueueBackgroundPaletteBankCopy(unsigned,unsigned,unsigned);
extern "C" unsigned WfcUtility_GetConnectionProfileType(unsigned);
extern "C" void Graphics_SetObjectModeAndPalette(Object*,int,int,int);
extern "C" unsigned char WfcUtilityUpdateProfileSelectionAppearance_UnknownRoleInitializedBytes[];
extern "C" unsigned char ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02233178; symbol: WfcUtility_UpdateProfileSelectionAppearance; size: 0xD0.
// Applies coordinate lookup for modes zero through three and palette lookup for modes zero through two.
extern "C" void WfcUtility_UpdateProfileSelectionAppearance() {
 struct FourBytes {unsigned char a,b,c,d;};
 FourBytes coordinates=*(FourBytes*)WfcUtilityUpdateProfileSelectionAppearance_UnknownRoleInitializedBytes;
 FourBytes palettes=*(FourBytes*)(WfcUtilityUpdateProfileSelectionAppearance_UnknownRoleInitializedBytes+4);
 unsigned mode;
 mode=ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[0];
 if(mode>3)return;
 unsigned coordinate=((unsigned char*)&coordinates)[mode];
 WfcUtility_QueueBackgroundPaletteBankCopy(**(unsigned**)(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage+4),coordinate,coordinate);
 mode=ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[0];
 if(mode==3)return;
 int index=WfcUtility_GetConnectionProfileType(mode);
 if(index>2)index=3;
 Graphics_SetObjectModeAndPalette(*(Object**)(*(char**)(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage+4)+ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[0]*4+4),-1,0,((unsigned char*)&palettes)[index]);
}
