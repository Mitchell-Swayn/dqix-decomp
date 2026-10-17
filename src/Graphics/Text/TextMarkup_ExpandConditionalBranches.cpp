#include <globaldefs.h>
#include "GameState/GameState.h"
#include "std_library_functions.h"
struct ConditionalText { unsigned first,second,third,fourth; int (*evaluate)(GameState*,unsigned,unsigned); };
extern "C" {
void __clear(void*,unsigned);
extern const char data_020f08ff[];
extern ConditionalText data_020e833c[];
int TestCaseFoldedStringPrefix(const char*,const char*);
int FindUnpairedGreaterThanCharacter(const char*);
void Text_FormatUpToFourIndexedStringFragments(const unsigned*,char*);
char* RemoveTextBetweenOrderedMarkers(char*,const char*,const char*,const char*);
}
// Original: arm9/main @ 0x02068F40; symbol: func_02068f40; size: 0x1E0.
extern "C" void TextMarkup_ExpandConditionalBranches(unsigned context,char* input,char* output,unsigned parameter)
{
    char first[48],second[48],third[48],fourth[48];
    GameState* game=GameState::GetInstance();
    for(;;) {
        char character=*input;
        if(!character) break;
        if(character=='<' && TestCaseFoldedStringPrefix(input,data_020f08ff) && FindUnpairedGreaterThanCharacter(input)) {
            char* previous=input;
            ConditionalText* entry=data_020e833c;
            for(;entry->evaluate;entry++) {
                __clear(first,48);
                Text_FormatUpToFourIndexedStringFragments(&entry->first,first);
                if(!TestCaseFoldedStringPrefix(input,first)) continue;
                int value=entry->evaluate(game,context,parameter);
                __clear(second,48);__clear(third,48);__clear(fourth,48);
                Text_FormatUpToFourIndexedStringFragments(&entry->second,second);
                Text_FormatUpToFourIndexedStringFragments(&entry->third,third);
                Text_FormatUpToFourIndexedStringFragments(&entry->fourth,fourth);
                switch(value) {
                case 0: input=RemoveTextBetweenOrderedMarkers(input,first,second,fourth);break;
                case 1:
                    if(third[0]) input=RemoveTextBetweenOrderedMarkers(input,second,third,fourth);
                    else input=RemoveTextBetweenOrderedMarkers(input,second,fourth,fourth);
                    break;
                case 2: input=RemoveTextBetweenOrderedMarkers(input,third,fourth,fourth);break;
                default:input=RemoveTextBetweenOrderedMarkers(input,first,second,fourth);break;
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
