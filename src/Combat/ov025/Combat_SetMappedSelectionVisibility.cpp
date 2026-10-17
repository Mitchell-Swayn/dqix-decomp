#include <globaldefs.h>
ARM
extern "C" { char* ReadOverlayControlSecondWord(); void Combat_UpdateSelectedObjectVisibility(char*,int,int); void Overlay_RefreshControlOnceForObject(void*); extern unsigned char* data_ov025_021ef988[]; }
// Original: arm9/ov025 @ 0x021E4450; symbol: func_ov025_021e4450; size: 0xAC.
extern "C" int Combat_SetMappedSelectionVisibility(unsigned char* command) {
 char* control=ReadOverlayControlSecondWord();
 int selection=command[8];
 if(selection==5) { Combat_UpdateSelectedObjectVisibility(control,4,command[9]==0); selection=0; }
 else if(selection==6) { Combat_UpdateSelectedObjectVisibility(control,4,command[9]==0); selection=1; }
 if(data_ov025_021ef988[3]) {
  Overlay_RefreshControlOnceForObject(data_ov025_021ef988[3]);
  *(unsigned*)(data_ov025_021ef988[3]+0x1c4)&=~0x40;
 }
 Combat_UpdateSelectedObjectVisibility(control,selection,command[9]);
 return 1;
}
