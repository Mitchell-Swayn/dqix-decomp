#include <globaldefs.h>
#include <GameState/GameState.h>
#include <std_library_functions.h>
#pragma force_active on
ARM
extern "C" void* GameState_GetIndexList(GameState*);
extern "C" GameObject* GameState_GetObjectWithFlag100(GameState*,int);
extern "C" unsigned TextContext_GetSharedInstance();
extern "C" void Network_QueueCurrentPartyMemberState(int,int,int,int);
extern "C" void __clear(void*,unsigned);
extern "C" int sprintf(char*,const char*,...);
extern "C" void TextWindow_StartFormattedMessage(void*,const char*,int,int);
extern "C" int FieldMessage_TestAdvanceInputAndPlaySound();
// Original data: arm9/ov017 @ 0x021D783C; symbol: data_ov017_021d783c.
// Original 44-byte formatted notice naming the affected party member.
extern "C" char FieldMessageUpdatePartyHpReducedToOneNotice_TextHIRAGANALETTERNAHIRAGANALETTERNHIRAGANALETTERTOFULLWIDTHEXCLAMATIONMARKIDEOGRAPHICSPACEPERCENTSIGNLATINSM[44];
// Original data: arm9/ov017 @ 0x021D7868; symbol: data_ov017_021d7868.
// Original continuation markup "<ADD>" with trailing zero storage.
extern "C" char FieldMessage_UpdatePartyHpReducedToOneNotice_MarkupADD[8];
// Original: arm9/ov017 @ 0x021AA1AC; symbol: func_ov017_021aa1ac; size: 0x244.
// Reduces living party members to one HP and advances a notice for each affected member.
extern "C" void FieldMessage_UpdatePartyHpReducedToOneNotice(unsigned char* request)
{
    GameState* game=GameState::GetInstance();
    GameStateIndexList* list=(GameStateIndexList*)GameState_GetIndexList(game);
    unsigned char* text=(unsigned char*)TextContext_GetSharedInstance();
    int memberCount=list->count_;
    if(*(unsigned short*)(request+0x12)==0) {
        memset(request+8,-1,8);
        request[0x11]=0;
        request[0x10]=0;
        for(int i=0;i<memberCount;++i) {
            int index=(signed char)list->objectIndices_[i];
            GameObject* object=GameState_GetObjectWithFlag100(game,index);
            if(object) {
                unsigned char* state=*(unsigned char**)((unsigned char*)object+0x130);
                if(!(*(unsigned*)state&1)) {
                    *(short*)(state+4)=1;
                    Network_QueueCurrentPartyMemberState(index,1,0,1);
                    unsigned char count=request[0x10]++;
                    *(short*)(request+8+count*2)=index;
                }
            }
        }
        if(request[0x10]) {
            char buffer[256];
            __clear(buffer,256);
            GameObject* object=GameState_GetObjectWithFlag100(game,*(short*)(request+8));
            sprintf(buffer,FieldMessageUpdatePartyHpReducedToOneNotice_TextHIRAGANALETTERNAHIRAGANALETTERNHIRAGANALETTERTOFULLWIDTHEXCLAMATIONMARKIDEOGRAPHICSPACEPERCENTSIGNLATINSM,(const char*)object->baseStats_);
            ++request[0x11];
            if(request[0x11]>=request[0x10]) ++*(unsigned short*)(request+0x12);
            else strcat(buffer,FieldMessage_UpdatePartyHpReducedToOneNotice_MarkupADD);
            TextWindow_StartFormattedMessage(text,buffer,0,227);
            text[0x19b2]=0;
            *(int*)(text+0x998)=1;
        }
        ++*(unsigned short*)(request+0x12);
    } else if(*(unsigned short*)(request+0x12)==1) {
        if(FieldMessage_TestAdvanceInputAndPlaySound() && request[0x11]<request[0x10]) {
            char buffer[256];
            __clear(buffer,256);
            GameObject* object=GameState_GetObjectWithFlag100(game,*(short*)(request+8+request[0x11]*2));
            sprintf(buffer,FieldMessageUpdatePartyHpReducedToOneNotice_TextHIRAGANALETTERNAHIRAGANALETTERNHIRAGANALETTERTOFULLWIDTHEXCLAMATIONMARKIDEOGRAPHICSPACEPERCENTSIGNLATINSM,(const char*)object->baseStats_);
            ++request[0x11];
            if(request[0x11]>=request[0x10]) ++*(unsigned short*)(request+0x12);
            else strcat(buffer,FieldMessage_UpdatePartyHpReducedToOneNotice_MarkupADD);
            TextWindow_StartFormattedMessage(text,buffer,0,227);
            text[0x19b2]=0;
            *(int*)(text+0x998)=1;
        }
    } else if(*(unsigned short*)(request+0x12)==2) {
        if(FieldMessage_TestAdvanceInputAndPlaySound()) request[1]=1;
    }
}
