#include <globaldefs.h>
#include <GameState/GameState.h>
struct Fade {unsigned char active,pad;unsigned short id;unsigned char target;char pad2[3];int remaining;float value;int duration;};extern "C" void Graphics_DrawColoredAlphaGeometry(Fade*,unsigned short,int);
// Original: arm9/main @ 0x020707C8; symbol: func_020707c8; size: 0x100.
extern "C" void InterpolateValueToTargetByRemainingTime(Fade* self) {GameState* state=GameState::GetInstance();int delta=state->GetEffectiveDeltaTime();int remaining=self->remaining;if(remaining>0)self->value=self->value+(float)delta*(((float)(unsigned)self->target-self->value)/(float)remaining);self->remaining-=delta;if(self->remaining<=0) {self->value=(float)(unsigned)self->target;self->remaining=0;if(self->target==1)self->active=0;}Graphics_DrawColoredAlphaGeometry(self,self->id,(int)self->value);if(self->remaining>0)return;if(self->duration<=0)return;self->remaining=(int)(16.66699981689453f*(float)self->duration);self->target=1;self->duration=0;}
