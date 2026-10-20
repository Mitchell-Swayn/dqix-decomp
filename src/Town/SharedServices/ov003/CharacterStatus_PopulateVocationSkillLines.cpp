#include <globaldefs.h>
ARM
extern "C" {
void TextCanvas_SetEntryTextAlignmentMode(char*,int,int);
void TextCanvas_HideEntry(unsigned char*,int);
void TextCanvas_ShowEntry(unsigned char*,int);
void TextCanvas_SetEntryTextColor(char*,int,unsigned);
void TextCanvas_SetEntryNumericValue(char*,int,int);
void TextCanvas_SetEntryMessageKey(char*,int,short);
unsigned char Vocation_GetSkillLineId(unsigned,unsigned);
}
// Original: arm9/ov003 @ 0x02167FA4; symbol: CharacterStatus_PopulateVocationSkillLines; size: 0xE4.
// Updates five paired display parts from a thirteen-by-five lookup and byte values, or disables each pair for mode zero.
extern "C" void CharacterStatus_PopulateVocationSkillLines(void* self,unsigned mode,const unsigned char* values)
{
    unsigned char* display=*(unsigned char**)((char*)self+0x10);
    short first=31,second=36;
    unsigned char i=0;
    for(;i<5;first++,second++,i++) {
        if(mode==0) {
            TextCanvas_HideEntry(display,first);
            TextCanvas_HideEntry(display,second);
        } else {
            TextCanvas_ShowEntry(display,first);
            TextCanvas_ShowEntry(display,second);
            unsigned index=Vocation_GetSkillLineId(mode,i);
            short resource=index+38;
            unsigned char value=values[index];
            unsigned style=15;
            if(value==100)style=13;
            TextCanvas_SetEntryTextColor((char*)display,second,style);
            TextCanvas_SetEntryMessageKey((char*)display,first,resource);
            TextCanvas_SetEntryTextAlignmentMode((char*)display,first,1);
            TextCanvas_SetEntryNumericValue((char*)display,second,value);
        }
    }
}
