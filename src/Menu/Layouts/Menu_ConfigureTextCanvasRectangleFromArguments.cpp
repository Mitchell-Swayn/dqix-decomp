#include <globaldefs.h>
extern "C" unsigned Menu_ReadScriptArgumentAsInteger(void*);
extern "C" void* Resource_GetSharedLoadState();
extern "C" void* Menu_GetDisplayRecordRegistry(void*);
extern "C" void* MenuRecordList_LocateByKey(void*,unsigned);
extern "C" unsigned MenuRecord_GetType(void*);
extern "C" void MenuTextCanvas_ConfigureFrameRenderContentsAndTransfer(void*,void*,unsigned,int,int,int,int,unsigned,unsigned,bool);
extern "C" void Menu_RequestSelectionRefresh(void*);
// Original: arm9/ov011 @ 0x02185418; symbol: func_ov011_02185418; size: 0xEC.
extern "C" unsigned Menu_ConfigureTextCanvasRectangleFromArguments(void* self) {
 unsigned value;
 unsigned id=Menu_ReadScriptArgumentAsInteger(self);
 value=Menu_ReadScriptArgumentAsInteger((char*)self+8);
 short a=Menu_ReadScriptArgumentAsInteger((char*)self+16);
 short b=Menu_ReadScriptArgumentAsInteger((char*)self+24);
 short c=Menu_ReadScriptArgumentAsInteger((char*)self+32);
 short d=Menu_ReadScriptArgumentAsInteger((char*)self+40);
 unsigned char e=Menu_ReadScriptArgumentAsInteger((char*)self+48);
 unsigned char f=Menu_ReadScriptArgumentAsInteger((char*)self+56);
 bool enabled=Menu_ReadScriptArgumentAsInteger((char*)self+64)!=0;
 void* owner=Resource_GetSharedLoadState();
 void* item=MenuRecordList_LocateByKey(Menu_GetDisplayRecordRegistry(owner),id);
 if(!item) return 0;
 if(MenuRecord_GetType(item)!=6) return 0;
 MenuTextCanvas_ConfigureFrameRenderContentsAndTransfer(item,owner,value,a,b,c,d,e,f,enabled);
 Menu_RequestSelectionRefresh(owner);
 return 1;
}
