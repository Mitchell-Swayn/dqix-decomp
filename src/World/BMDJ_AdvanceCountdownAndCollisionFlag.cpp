#include "World/Zone3D.h"
#include "Resource/GameResources.h"
struct CountdownFeature { unsigned char kind,group,instance,unknown3,unknown4,enabled,unknown6,immediate,linkedGroup,linkedInstance; };
struct CountdownContext { unsigned char unknown0[3]; unsigned char immediate; };
extern "C" Zone3D* Zone3D_GetMainInstance();
// Original: arm9/main @ 0x020A88E8; symbol: func_020a88e8; size: 0x14C.
extern "C" void BMDJ_AdvanceCountdownAndCollisionFlag(CountdownFeature* feature) {
 Zone3D* zone=Zone3D_GetMainInstance();
 Zone3D_BMDJStruct::InstanceEntry* instance=zone->FindLastBMDJInstance(feature->group,feature->instance);
 Zone3D_BMDJStruct::InstanceEntry* linked=zone->FindLastBMDJInstance(feature->linkedGroup,feature->linkedInstance);
 if(!instance || !linked)return;
 SetBMDJUnknownHighFlag(instance,true);
 CountdownContext* context=(CountdownContext*)GameResources_GetInstance()->unknown_ptr_array_36fc[4];
 if(feature->enabled) {
  unsigned char count=instance->countdown;
  if(feature->immediate || context->immediate){feature->immediate=0;count=31;}
  else {count+=2;if(count>31)count=31;}
  instance->countdown=(signed char)count;
 } else {
  if(feature->immediate || context->immediate){instance->countdown=0;feature->immediate=0;}
  else if(instance->countdown<2)instance->countdown=0;
  else instance->countdown=(signed char)(instance->countdown-2);
 }
 if(instance->countdown>=10)linked->flags|=4;
 else linked->flags&=~4;
}
