extern "C" int func_ov000_02153c0c(void* object)
{
	void* state = *(void**)((char*)object + 0x138);
	unsigned int flags = *(unsigned int*)((char*)state + 0x18);
	return (flags & 0x2000) != 0;
}
