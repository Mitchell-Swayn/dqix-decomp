#include <globaldefs.h>
ARM
extern "C" unsigned short* Zone3D_GetMainInstance();
extern "C" void Zone3D_SetBMDJInstanceVisibilityFlag(int,int,unsigned char);
// Original data: arm9/main @ 0x20e9148; symbol: data_020e9148.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 02.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e9149; symbol: data_020e9149.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0f.
// Observed span: 1 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x20e914a; symbol: data_020e914a.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 100311120413140515161e2a26202b27222c28242d29.
// Observed span: 22 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Zone3DUpdateThreeIndexedInstancesInMatchingZone_UnknownRoleInitializedBytes[],Zone3DUpdateThreeIndexedInstancesInMatchingZone_UnknownRoleInitializedBytes_Variant2[],Zone3DUpdateThreeIndexedInstancesInMatchingZone_UnknownRoleInitializedBytes_Variant3[];
// Original: arm9/main @ 0x020AEA40; symbol: func_020aea40; size: 0xF4.
extern "C" void Zone3D_UpdateThreeIndexedInstancesInMatchingZone(unsigned index,int mode) {
 if(index<=3){if(*Zone3D_GetMainInstance()!=0x164a)return;}
 else {if(index<4)return;if(index>7)return;if(*Zone3D_GetMainInstance()!=0x21ff)return;}
 if(mode==0){int offset=index*3;Zone3D_SetBMDJInstanceVisibilityFlag(1,0,Zone3DUpdateThreeIndexedInstancesInMatchingZone_UnknownRoleInitializedBytes[offset]);Zone3D_SetBMDJInstanceVisibilityFlag(1,0,Zone3DUpdateThreeIndexedInstancesInMatchingZone_UnknownRoleInitializedBytes_Variant2[offset]);Zone3D_SetBMDJInstanceVisibilityFlag(1,0,Zone3DUpdateThreeIndexedInstancesInMatchingZone_UnknownRoleInitializedBytes_Variant3[offset]);}
 else {int offset=index*3;Zone3D_SetBMDJInstanceVisibilityFlag(0,0,Zone3DUpdateThreeIndexedInstancesInMatchingZone_UnknownRoleInitializedBytes[offset]);Zone3D_SetBMDJInstanceVisibilityFlag(0,0,Zone3DUpdateThreeIndexedInstancesInMatchingZone_UnknownRoleInitializedBytes_Variant2[offset]);Zone3D_SetBMDJInstanceVisibilityFlag(0,0,Zone3DUpdateThreeIndexedInstancesInMatchingZone_UnknownRoleInitializedBytes_Variant3[offset]);}
}
