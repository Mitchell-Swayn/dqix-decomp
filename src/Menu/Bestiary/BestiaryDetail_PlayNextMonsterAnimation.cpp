extern "C" int strcmp(const char*,const char*);
struct Object3D{unsigned pre[3];void* animation;unsigned word;const char* name;bool SetAnimationByName(const char*,int);};
// Original data: arm9/ov014 @ 0x21895ce; symbol: data_ov014_021895ce.
// Source-defined character literal. Text: "run". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "run".
// Observed span: 7 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov014.md.
extern "C" { struct Entry{unsigned char pre[0xc];short index;}; struct Animation{unsigned char pre[0xc];unsigned char count;unsigned char gap[0x1f];const char** names;}; struct Owner{unsigned char pre[0xc];unsigned char archive[0x10];unsigned char gap[0x24];Object3D* object;unsigned word;Entry* entry;unsigned char gap2[0x28];int frame;};extern const char BestiaryDetail_PlayNextMonsterAnimation_TextStand[];extern const char BestiaryDetailPlayNextMonsterAnimation_TextRunWithAdjacentText[];Animation* BestiaryInfo_FindMonsterRecord(void*,int);
// Original: arm9/ov014 @ 0x02184E3C; symbol: func_ov014_02184e3c; size: 0xD4.
void BestiaryDetail_PlayNextMonsterAnimation(Owner* p){if(!p->object || !p->object->animation || !p->entry)return;Animation* animation=BestiaryInfo_FindMonsterRecord(p->archive,p->entry->index);if(!animation)return;const char* name=p->object->name;if(name && strcmp(BestiaryDetail_PlayNextMonsterAnimation_TextStand,name)!=0 && strcmp(BestiaryDetailPlayNextMonsterAnimation_TextRunWithAdjacentText,name)!=0)return;++p->frame;if(animation->count<=p->frame){p->frame=0;if(animation->count>1)p->frame=1;}const char* next=animation->names[p->frame];if(next && *(const signed char*)next)p->object->SetAnimationByName(next,0);}
}
