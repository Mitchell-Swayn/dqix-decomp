#include <globaldefs.h>
#include <Resource/Script.h>
#include <Memory/SafeAllocator.h>
extern "C" char* strcpy(char*, const char*);
struct Message {
    short id;
    unsigned short type : 2;
    unsigned short index : 7;
    unsigned short group : 6;
    unsigned short flag : 1;
    char* text;
    Message* next;
};
struct MessageList { Message* head; short count; short padding; };
struct MessageContext { unsigned short* count; unsigned short* groups; MessageList* list; SafeAllocator* allocator; };
extern "C" MessageContext data_02108fd4;
extern "C" unsigned int String_CountBytesUntilTerminator(const char*);
extern "C" void WorldScriptRecordList_AllocateAndAppendNode(MessageList*,SafeAllocator*,const Message*);
// Original: arm9/main @ 0x0208DC84; symbol: func_0208dc84; size: 0x28C.
extern "C" int Script_AllocateAndAppendAllowedGroupedMessage(Script::Parameter* params) {
    Message message;
    message.id = -1;
    message.type = 0;
    message.index = 0;
    message.group = 0;
    message.flag = 0;
    message.text = 0;
    message.next = 0;
    if (data_02108fd4.groups) {
        message.id = params[0].ToInt();
        const char* text = params[1].ToString();
        message.type = (unsigned short)params[2].ToInt();
        message.group = (unsigned short)params[3].ToInt();
        message.index = (unsigned short)params[4].ToInt();
        message.flag = (unsigned short)params[5].ToInt();
        for (unsigned short i=0;i<*data_02108fd4.count;++i) {
            if (message.group == data_02108fd4.groups[i]) {
                if (text) {
                    message.text = (char*)data_02108fd4.allocator->Allocate(String_CountBytesUntilTerminator(text)+1);
                    if (message.text) strcpy(message.text,text);
                }
                WorldScriptRecordList_AllocateAndAppendNode(data_02108fd4.list,data_02108fd4.allocator,&message);
                break;
            }
        }
    } else {
        message.id = params[0].ToInt();
        const char* text = params[1].ToString();
        if (text) {
            message.text = (char*)data_02108fd4.allocator->Allocate(String_CountBytesUntilTerminator(text)+1);
            if (message.text) strcpy(message.text,text);
        }
        message.type = (unsigned short)params[2].ToInt();
        message.group = (unsigned short)params[3].ToInt();
        message.index = (unsigned short)params[4].ToInt();
        message.flag = (unsigned short)params[5].ToInt();
        WorldScriptRecordList_AllocateAndAppendNode(data_02108fd4.list,data_02108fd4.allocator,&message);
    }
    return 1;
}
