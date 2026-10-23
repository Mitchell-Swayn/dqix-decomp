#include <globaldefs.h>
#include <Resource/GameResources.h>
#include <Graphics/NSBXX/RenderConfig.h>
#include <Graphics/LightingManager.h>
#include <System/Timing.h>
typedef unsigned uint;
extern "C" {
void* SystemState_GetGlobalFlags();void* Network_GetConnectionManager();
void Graphics_InitializeGeometryAndDisplayState();void Graphics_ResetGeometryMatrixStackState();
unsigned GameResources_GetMaskedSecondaryFlags(int,unsigned);
void Field_DrawMarkedObjectsAndSceneCommands(int,unsigned);
void Camera_UpdateFromGameStateFlags(void*);
void SendQueuedDataToGeometryFifo();
bool SystemState_TestAnyFlags(const unsigned*,unsigned);
int GX_SetDefaultDMA(int);
void Field_DrawWorldGeometryAndActors(void*);
int LinkedQueue_GetFrontKindOrInvalid(char**);
bool Network_IsParentOrOffline(unsigned*);bool Network_IsClientSession(unsigned*);
void ProcessorContext_SleepOrYieldPriorityPeers(unsigned);
void Field_DrawOverlayWindowsAndInteractionIndicators(void*);
}
// Original: arm9/ov017 @ 0x02195A20; symbol: Field_RenderSceneFrame; size: 0x19C.
// Draw field geometry and overlays, synchronizing the render window with network timing.
extern "C" ARM void Field_RenderSceneFrame(GameResources* resources) {
GetCurrentTimestamp();const unsigned* flags=(const unsigned*)SystemState_GetGlobalFlags();unsigned* network=(unsigned*)Network_GetConnectionManager();
Graphics_InitializeGeometryAndDisplayState();Graphics_ResetGeometryMatrixStackState();RenderConfig::Reset();
volatile unsigned short* display=(volatile unsigned short*)0x04000060;
*display=(*display&~0x3000)|8;*display=(*display&~0x3000)|0x10;
if(GameResources_GetMaskedSecondaryFlags((int)resources,0x2000))*display=*display&0xcfdf;else *display=(*display&~0x3000)|0x20;
if(!((unsigned char*)resources->unknown_4420)[0x6a])Field_DrawMarkedObjectsAndSceneCommands((int)resources,1);
Camera_UpdateFromGameStateFlags(resources);RenderConfig::SubmitToFifo();SendQueuedDataToGeometryFifo();LightingManager::GetInstance()->SubmitToRenderConfig();
bool timing=SystemState_TestAnyFlags(flags,0x800000);if(timing)GX_SetDefaultDMA(-1);
Field_DrawWorldGeometryAndActors(resources);if(timing)GX_SetDefaultDMA(0);
if(LinkedQueue_GetFrontKindOrInvalid(*(char***)((char*)resources+0x36fc))==0x16)Field_DrawMarkedObjectsAndSceneCommands((int)resources,2);
if(timing){while(true){int line=*(volatile unsigned short*)0x04000006;if(Network_IsParentOrOffline(network)&&line<210)break;if(Network_IsClientSession(network)){if(line<190)break;if(line>240)break;}ProcessorContext_SleepOrYieldPriorityPeers(0);}}
Field_DrawOverlayWindowsAndInteractionIndicators(resources);if(((unsigned char*)resources->unknown_4420)[0x6a])Field_DrawMarkedObjectsAndSceneCommands((int)resources,1);
}
