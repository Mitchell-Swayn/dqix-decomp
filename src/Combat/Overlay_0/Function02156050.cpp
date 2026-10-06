extern "C" int func_ov000_02156050(void* object)
{
	void* state = *(void**)((char*)object + 0x138);
	unsigned int flags = *(unsigned int*)((char*)state + 0x14);
	return (flags & 0x80000) != 0;
}
