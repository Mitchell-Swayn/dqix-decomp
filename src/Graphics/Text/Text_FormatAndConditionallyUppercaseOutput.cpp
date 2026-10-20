#include <globaldefs.h>
#include <std_library_functions.h>
extern "C" {
    struct Entry{
        char pad[5];
        signed char mode:6;
        unsigned char unused:1;
        signed char enabled:1;
    };
    Entry *TextLookup_FindMatchingByteKeyEntry(const char *,int);
    void Text_UppercaseBoundedASCIICharacters(char *,int);
// Original: arm9/main @ 0x0206819C; symbol: func_0206819c; size: 0x64.
    void Text_FormatAndConditionallyUppercaseOutput(const char *format,char *out,int id){
        if(!format)return;
        sprintf(out,format);
        if(!*format)return;
        Entry *p=TextLookup_FindMatchingByteKeyEntry(format,id);
        if(!p)return;
        if(!p->enabled)return;
        Text_UppercaseBoundedASCIICharacters(out,p->mode);
    }
}
