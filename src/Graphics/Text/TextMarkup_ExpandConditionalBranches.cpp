#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
struct ConditionalText { unsigned first,second,third,fourth; int (*evaluate)(GameState*,unsigned,unsigned); };
extern "C" {
void __clear(void*,unsigned);
extern const char TextMarkup_ExpandConditionalBranches_TextIF[];
// Original data: arm9/main @ 0x20e833c; symbol: data_020e833c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 112cffff031b2cffffffffff042cffff2c850602110d15ff030d1b15ffffffff040d15ff58850602113015ff03301b15ffffffff043015ff80850602110c15ff ...; full span in module reference.
// Observed span: 1144 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern ConditionalText TextMarkupExpandConditionalBranches_UnknownRoleProcedureReferenceRecords[];
int String_HasCaseInsensitivePrefix(const char*,const char*);
int TextMarkup_FindClosingAngleBracket(const char*);
void Text_FormatUpToFourIndexedStringFragments(const unsigned*,char*);
char* TextMarkup_RemoveUnselectedBranchThroughClosingMarker(char*,const char*,const char*,const char*);
}
// Original: arm9/main @ 0x02068F40; symbol: func_02068f40; size: 0x1E0.
extern "C" void TextMarkup_ExpandConditionalBranches(unsigned context,char* input,char* output,unsigned parameter)
{
    char first[48],second[48],third[48],fourth[48];
    GameState* game=GameState::GetInstance();
    for(;;) {
        char character=*input;
        if(!character) break;
        if(character=='<' && String_HasCaseInsensitivePrefix(input,TextMarkup_ExpandConditionalBranches_TextIF) && TextMarkup_FindClosingAngleBracket(input)) {
            char* previous=input;
            ConditionalText* entry=TextMarkupExpandConditionalBranches_UnknownRoleProcedureReferenceRecords;
            for(;entry->evaluate;entry++) {
                __clear(first,48);
                Text_FormatUpToFourIndexedStringFragments(&entry->first,first);
                if(!String_HasCaseInsensitivePrefix(input,first)) continue;
                int value=entry->evaluate(game,context,parameter);
                __clear(second,48);__clear(third,48);__clear(fourth,48);
                Text_FormatUpToFourIndexedStringFragments(&entry->second,second);
                Text_FormatUpToFourIndexedStringFragments(&entry->third,third);
                Text_FormatUpToFourIndexedStringFragments(&entry->fourth,fourth);
                switch(value) {
                case 0: input=TextMarkup_RemoveUnselectedBranchThroughClosingMarker(input,first,second,fourth);break;
                case 1:
                    if(third[0]) input=TextMarkup_RemoveUnselectedBranchThroughClosingMarker(input,second,third,fourth);
                    else input=TextMarkup_RemoveUnselectedBranchThroughClosingMarker(input,second,fourth,fourth);
                    break;
                case 2: input=TextMarkup_RemoveUnselectedBranchThroughClosingMarker(input,third,fourth,fourth);break;
                default:input=TextMarkup_RemoveUnselectedBranchThroughClosingMarker(input,first,second,fourth);break;
                }
                break;
            }
            if(input!=previous) continue;
        }
        *output++=character;
        ++input;
    }
    *output=0;
}
