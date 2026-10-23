#include <globaldefs.h>
ARM
#pragma force_active on
struct Ipv4EditorResources { void* unused; void* sprite; };
extern "C" {
// Original data: arm9/ov031 @ 0x02290c98; symbol: data_ov031_02290c98; mutable pointer, initially zero.
extern Ipv4EditorResources* WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x0224badc; symbol: data_ov031_0224badc; localized palette path.
extern const char WfcUtility_ReleaseIpv4Editor_PathCharYbObjMainNclL[];
void Overlay_ProcessPendingFlag();
void WfcUtility_ReleaseOamSprite(void*);
void Graphics_ClearIndexedMainBackgroundCharacterData(unsigned);
void WfcUtility_LoadLocalizedResourceAndApply(const char*,void (*)(const void*,unsigned,unsigned));
void LoadToMainObjStandardPalette(const void*,unsigned,unsigned);
void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);
void WfcUtility_GetScreenOperationArguments(unsigned*,unsigned*);
void WfcUtility_SetNavigationContext(unsigned,unsigned);
void WfcUtility_SetScreenOperationArguments(unsigned,unsigned);
void WfcUtility_SetMainLoopCallback(void (*)());
void WfcSettingsList_InitializeScreen();
void WfcUtility_FreeAllocationAndClearPointer(void*);
}
namespace ContextStorageAddress { extern "C" Ipv4EditorResources* WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x0222dee0; symbol: func_ov031_0222dee0; size: 0xa4.
// Releases the IPv4 editor sprite and resources, restores the palette, and selects the settings-list callback.
extern "C" void WfcUtility_ReleaseIpv4Editor()
{
    Overlay_ProcessPendingFlag();
    WfcUtility_ReleaseOamSprite(WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage->sprite);
    Graphics_ClearIndexedMainBackgroundCharacterData(0);
    WfcUtility_LoadLocalizedResourceAndApply(WfcUtility_ReleaseIpv4Editor_PathCharYbObjMainNclL,LoadToMainObjStandardPalette);
    WfcUtility_DisableDisplayPlanes(1,1);
    WfcUtility_DisableDisplayPlanes(0,0x15);
    unsigned selected;
    WfcUtility_GetScreenOperationArguments(&selected,0);
    if ((int)selected >= 3) ++selected;
    WfcUtility_SetNavigationContext(2,1);
    WfcUtility_SetScreenOperationArguments(0,selected+3);
    WfcUtility_SetMainLoopCallback(WfcSettingsList_InitializeScreen);
    WfcUtility_FreeAllocationAndClearPointer(&ContextStorageAddress::WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage);
}

#pragma force_active reset
