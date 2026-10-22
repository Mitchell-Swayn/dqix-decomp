extern "C" {
struct Node { Node* next; unsigned char gap[0x16]; short index; };
struct Service { unsigned char pre[0x36]; short selected; };
struct VisualItem { unsigned char pre[4]; short x,y; unsigned char gap[0xd]; unsigned char flags; };
struct Owner { unsigned char pre[0x5c]; void* pageData; unsigned char gap0[0x38]; void* currentValues; unsigned char gap1[0x1c]; Node* head; Node* page; Service* service; unsigned char gap2[0xc]; short* selected; void* d4; void* visual; unsigned char gap3[0x1c]; unsigned char animation[0x6c]; int visualParameter; unsigned char gap4[8]; short category,choice,unused,count,previous; unsigned char state,phase; unsigned char gap5[6]; short values[8]; };
short FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(Service*,int);void TextCanvas_CreateAndConfigureDisplayPart(Service*,int);void BestiaryScreen_UpdateSelectedMonsterValue(Owner*,int);
void* TextCanvas_FindDisplayPartByKey(Service*,int);int TextCanvas_HasActiveTilemap();void TextCanvas_GetGroupEntryPixelPosition(Service*,int,int,short*,short*);void SpriteAnimation_StartTrack(void*, unsigned);VisualItem* SpriteAnimation_FindTrackByKey(void*,int);void SpriteAnimation_AdvanceAllTracks(void*,int);void SpriteAnimation_SubmitAllTrackFrames(void*);
// Original: arm9/ov014 @ 0x02186E2C; symbol: func_ov014_02186e2c; size: 0xE4.
void BestiaryScreen_DrawSelectionCursor(Owner* p) { if(p->selected && p->category>=0 && TextCanvas_FindDisplayPartByKey(p->service,p->category) && TextCanvas_HasActiveTilemap()){short x,y;TextCanvas_GetGroupEntryPixelPosition(p->service,p->category,*p->selected,&x,&y);x-=16;y-=3;SpriteAnimation_StartTrack(p->visual,0);VisualItem* item=SpriteAnimation_FindTrackByKey(p->visual,0);if(item)item->flags|=8;SpriteAnimation_AdvanceAllTracks(p->visual,p->visualParameter);short finalX;short finalY;finalY=y;finalX=x;item=SpriteAnimation_FindTrackByKey(p->visual,0);if(item){item->x=finalX;item->y=finalY;}SpriteAnimation_SubmitAllTrackFrames(p->animation);} }
}
