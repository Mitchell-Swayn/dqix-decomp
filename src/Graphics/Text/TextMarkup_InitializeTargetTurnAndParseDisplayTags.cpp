#include "GameState/GameState.h"
#include "System/Matrix.h"
#pragma always_inline on
// Known UI command fields; intervening storage remains uncharacterized.
struct UiCommandState {
    unsigned char unknown0000[0x9a4]; int lineCount;
    unsigned char unknown09a8[0x1838-0x9a8]; unsigned targetId;
    int originalAngle; unsigned unknown1840; int angle;
    unsigned char unknown1848[0x1860-0x1848]; int charWidth, charHeight;
    unsigned char unknown1868[0x187c-0x1868]; unsigned short color;
    unsigned char unknown187e[0x1959-0x187e]; unsigned char delay;
    unsigned char unknown195a[2]; unsigned char question;
    unsigned char unknown195d[0x19b1-0x195d]; unsigned char window;
    unsigned char unknown19b2[4]; unsigned char turn, mark, center;
    unsigned char unknown19b9[2]; unsigned char skip;
};
struct CommandPosition { int x,y,z; };
struct CommandWords { int words[3]; };
extern "C" {
void* Object_GetGlobalThirtyTwoEntryContainer();
void* GetBoundedSlotUnlessFlag8000(void*, unsigned);
void ReadFirstAvailableVectorOrZero(CommandPosition*, void*);
int fix32ReduceAngle0To2Pi(int);
int String_TestSecondIsPrefixOfFirst(const char*,const char*);
int TestCaseFoldedStringPrefix(const char*,const char*);
int Runtime_ParseStringAsBaseTenInteger(const char*);
void SetRectangleCoordinatesAndDerivedCenter(UiCommandState*,int,int,int,int);
void DispatchStoredHalfwordIndexWithTwoArguments(void*,int,int);
extern unsigned char data_02108760[];
extern const char data_020f0934[],data_020f093d[],data_020f0943[],data_020f0949[],data_020f0950[],data_020f0956[],data_020f095c[],data_020f0963[],data_020f096a[],data_020f0972[];
}
// Original: arm9/main @ 0x0206A3C0; symbol: func_0206a3c0; size: 0x5B4.
extern "C" const char* TextMarkup_InitializeTargetTurnAndParseDisplayTags(UiCommandState* state, const char* text) {
    bool scan = true;
    state->turn = 1;
    GameObject* object = GameState::GetInstance()->GetUnknownGameObject();
    void* target = GetBoundedSlotUnlessFlag8000(Object_GetGlobalThirtyTwoEntryContainer(), state->targetId);
    if (object && target) {
        CommandPosition origin, destination, temporary;
        *(CommandWords*)&origin = *(CommandWords*)((unsigned char*)object + 0x44);
        ReadFirstAvailableVectorOrZero(&temporary, target);
        *(CommandWords*)&destination = *(CommandWords*)&temporary;
        state->angle = fix32ReduceAngle0To2Pi(fix32_Atan2(origin.x-destination.x, origin.z-destination.z));
        state->turn = 1;
    }
    state->delay = 0;
    state->mark = 0;
    while (scan) {
        if (String_TestSecondIsPrefixOfFirst(text,data_020f0934)) {
            state->angle = state->originalAngle; state->turn=0; text+=8;
        } else if (String_TestSecondIsPrefixOfFirst(text,data_020f093d)) {
            state->delay=60; state->mark=1; state->question=0; text+=5;
            DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,6,0);
        } else if (String_TestSecondIsPrefixOfFirst(text,data_020f0943)) {
            state->delay=60; state->mark=1; state->question=1; text+=5;
            DispatchStoredHalfwordIndexWithTwoArguments(data_02108760,28,0);
        } else if (TestCaseFoldedStringPrefix(text,data_020f0949)) {
            bool done=false; int index=6;
            int end=index;
            for (;text[end]!='>'; ++end) if (text[end]==0) return text+end;
            int x=Runtime_ParseStringAsBaseTenInteger(text+6);
            for (;text[index]!=','; ++index) if (text[index]=='>') {text+=index+1; done=true; break;}
            if (done) return text;
            ++index; int y=Runtime_ParseStringAsBaseTenInteger(text+index);
            for (;text[index]!=','; ++index) if (text[index]=='>') {text+=index+1; done=true; break;}
            if (done) return text;
            ++index; int width=Runtime_ParseStringAsBaseTenInteger(text+index);
            for (;text[index]!=','; ++index) if (text[index]=='>') {text+=index+1; done=true; break;}
            if (done) return text;
            int height=Runtime_ParseStringAsBaseTenInteger(text+(index+1));
            if(x<0)x=0; if(x>256)x=256;
            if(y<0)y=0; if(y>192)y=192;
            if(width<0)width=256-x; if(width>256)width=256-x;
            if(height<0)height=192-y; if(height>192)height=192-y;
            SetRectangleCoordinatesAndDerivedCenter(state,x,y,width,height);
            text+=end+1;
        } else if (TestCaseFoldedStringPrefix(text,data_020f0950)) {
            state->window=0; text+=5;
        } else if (TestCaseFoldedStringPrefix(text,data_020f0956)) {
            state->center=1; text+=5;
        } else if (TestCaseFoldedStringPrefix(text,data_020f095c)) {
            int end=6;
            int count=Runtime_ParseStringAsBaseTenInteger(text+end);
            for(;text[end]!='>'; ++end)if(text[end]==0)return text+end;
            if(count<1)count=1;
            state->lineCount=count; text+=end+1;
        } else if (TestCaseFoldedStringPrefix(text,data_020f0963)) {
            int index=6,end=6;
            for(;text[end]!='>'; ++end)if(text[end]==0)return text+end;
            int width=Runtime_ParseStringAsBaseTenInteger(text+6);
            if(width<=0)width=12;
            for(;text[index]!=','; ++index)if(text[index]=='>'){text+=index+1;break;}
            int height=Runtime_ParseStringAsBaseTenInteger(text+(index+1));
            if(height<=0)height=16;
            state->charWidth=width; state->charHeight=height; text+=end+1;
        } else if (TestCaseFoldedStringPrefix(text,data_020f096a)) {
            int index=7,end=7;
            for(;text[end]!='>'; ++end)if(text[end]==0)return text+end;
            bool done=false;
            int red=Runtime_ParseStringAsBaseTenInteger(text+7);
            if(red<0)red=255; if(red>255)red=255;
            for(;text[index]!=','; ++index)if(text[index]=='>'){text+=index+1;done=true;break;}
            if(!done){
                ++index; int green=Runtime_ParseStringAsBaseTenInteger(text+index);
                if(green<0)green=255; if(green>255)green=255;
                for(;text[index]!=','; ++index)if(text[index]=='>'){text+=index+1;done=true;break;}
                if(!done){
                    int blue=Runtime_ParseStringAsBaseTenInteger(text+(index+1));
                    if(blue<0)blue=255; if(blue>255)blue=255;
                    state->color=(red>>3) | ((green>>3)<<5) | ((blue>>3)<<10);
                    text+=end+1;
                }
            }
        } else if (TestCaseFoldedStringPrefix(text,data_020f0972)) {
            state->skip=0; text+=6;
        } else scan=false;
    }
    return text;
}
