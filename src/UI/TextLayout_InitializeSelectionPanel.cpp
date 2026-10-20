#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" void TextLayout_InitializePanelControlDefaults(void*);extern "C" void Selection_InitializeTouchAndDirectionalControls(void*);extern "C" void WindowFrame_ResetTransitionRecord(void*);
// Original: arm9/main @ 0x0205C790; symbol: func_0205c790; size: 0xB0.
extern "C" ARM void TextLayout_InitializeSelectionPanel(unsigned char* p){TextLayout_InitializePanelControlDefaults(p+4);Selection_InitializeTouchAndDirectionalControls(p+28);WindowFrame_ResetTransitionRecord(p+180);*(unsigned*)(p+208)=0;*(unsigned*)(p+212)=52;*(unsigned*)(p+216)=16;*(unsigned*)(p+220)=0;memset(p+224,0,16);memset(p+240,0,16);memset(p+256,0,16);memset(p+272,0,16);memset(p+288,0,256);memset(p+544,0,16);*(unsigned short*)(p+560)=0;p[562]=0;p[563]=0;p[564]=0;}
