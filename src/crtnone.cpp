/*
 * Copyright 2010-2017 Branimir Karadzic. All rights reserved.
 * License: https://github.com/bkaradzic/bx#license-bsd-2-clause
 */

#include <bx/debug.h>
#include <bx/sort.h>
#include <bx/readerwriter.h>

#if BX_CRT_NONE

extern "C" size_t strlen(const char* _str)
{
	return bx::strnlen(_str);
}

extern "C" size_t strnlen(const char* _str, size_t _max)
{
	return bx::strnlen(_str, _max);
}

extern "C" void* strcpy(char* _dst, const char* _src)
{
	bx::strlncpy(_dst, INT32_MAX, _src, INT32_MAX);
	return _dst;
}

extern "C" void* strncpy(char* _dst, const char* _src, size_t _num)
{
	bx::strlncpy(_dst, INT32_MAX, _src, _num);
	return _dst;
}

extern "C" char* strcat(char* _dst, const char* _src)
{
	bx::strlncat(_dst, INT32_MAX, _src, INT32_MAX);
	return _dst;
}

extern "C" const char* strchr(const char* _str, int _ch)
{
	return bx::strnchr(_str, _ch);
}

extern "C" int32_t strcmp(const char* _lhs, const char* _rhs)
{
	return bx::strncmp(_lhs, _rhs);
}

extern "C" int32_t strncmp(const char* _lhs, const char* _rhs, size_t _max)
{
	return bx::strncmp(_lhs, _rhs, _max);
}

extern "C" const char* strstr(const char* _str, const char* _find)
{
	return bx::strnstr(_str, _find);
}

extern "C" void qsort(void* _base, size_t _num, size_t _size, ComparisonFn _fn)
{
	BX_CHECK(_num <= UINT32_MAX && _size <= UINT32_MAX, "");
	return bx::quickSort(_base, _num, _size, _fn);
}

extern "C" int isprint(int _ch)
{
	return bx::isPrint(_ch);
}

extern "C" int toupper (int _ch)
{
	return bx::toUpper(_ch);
}

extern "C" size_t mbstowcs(wchar_t* _dst, const char* _src, size_t _max)
{
	BX_UNUSED(_dst, _src, _max);
	return 0;
}

extern "C" char* strdup(const char* _src)
{
	BX_UNUSED(_src);
	return NULL;
}

extern "C" long int strtol(const char* _str, char** _end, int _base)
{
	BX_UNUSED(_str, _end, _base);
	return -1;
}

extern "C" int abs(int _value)
{
	return _value >= 0 ? _value : -_value;
}

extern "C" float fabsf(float _value)
{
	return _value >= 0.0f ? _value : -_value;
}

extern "C" double fabs(double _value)
{
	return _value >= 0.0 ? _value : -_value;
}

extern "C" double ldexp(double _x, int _exp)
{
	BX_UNUSED(_x, _exp);
	return 0.0;
}

extern "C" float expf(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" float logf(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" float log10f(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" float powf(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" double pow(double _x)
{
	BX_UNUSED(_x);
	return 0.0;
}

extern "C" float sinf(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" float cosf(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" float tanf(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" float atan2f(float _y, float _x)
{
	BX_UNUSED(_y, _x);
	return 0.0f;
}

extern "C" float sqrtf(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" double sqrt(double _x)
{
	BX_UNUSED(_x);
	return 0.0;
}

extern "C" float ceilf(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" double ceil(double _x)
{
	BX_UNUSED(_x);
	return 0.0;
}

extern "C" float floorf(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" double floor(double _x)
{
	BX_UNUSED(_x);
	return 0.0;
}

extern "C" float acosf(float _x)
{
	BX_UNUSED(_x);
	return 0.0f;
}

extern "C" float fmodf(float _numer, float _denom)
{
	BX_UNUSED(_numer, _denom);
	return 0.0f;
}

extern "C" int atoi(const char* _str)
{
	BX_UNUSED(_str);
	return 0;
}

extern "C" double atof(const char* _str)
{
	BX_UNUSED(_str);
	return 0.0;
}

extern "C" struct DIR* opendir(const char* dirname)
{
	BX_UNUSED(dirname);
	return NULL;
}

extern "C" struct dirent* readdir(struct DIR* dirp)
{
	BX_UNUSED(dirp);
	return NULL;
}

extern "C" int closedir (struct DIR* dirp)
{
	BX_UNUSED(dirp);
	return 0;
}

extern "C" int vsnprintf(char* _out, size_t _max, const char* _format, va_list _argList)
{
	return bx::vsnprintf(_out, _max, _format, _argList);
}

extern "C" int sprintf(char* _out, const char* _format, ...)
{
	va_list argList;
	va_start(argList, _format);
	int32_t len = bx::vsnprintf(_out, INT32_MAX, _format, argList);
	va_end(argList);
	return len;
}

extern "C" int snprintf(char* _out, size_t _max, const char* _format, ...)
{
	va_list argList;
	va_start(argList, _format);
	int32_t len = bx::vsnprintf(_out, _max, _format, argList);
	va_end(argList);
	return len;
}

extern "C" int printf(const char* _format, ...)
{
	BX_UNUSED(_format);
	return -1;
}

extern "C" int fprintf(FILE* _stream, const char* _format, ...)
{
	BX_UNUSED(_stream, _format);
	return -1;
}

extern "C" int vfprintf(FILE* _stream, const char* _format, va_list _argList)
{
	BX_UNUSED(_stream, _format, _argList);
	return -1;
}

extern "C" int sscanf(const char* _str, const char* _format, ...)
{
	BX_UNUSED(_str, _format);
	return -1;
}

extern "C" int fscanf(FILE* _stream, const char* _format, ...)
{
	BX_UNUSED(_stream, _format);
	return -1;
}

FILE * stdout;

extern "C" FILE* fopen(const char* _filename, const char* _mode)
{
	BX_UNUSED(_filename, _mode);
	return NULL;
}

extern "C" int fclose(FILE* _stream)
{
	BX_UNUSED(_stream);
	return -1;
}

extern "C" size_t fread(void* _ptr, size_t _size, size_t _count, FILE* _stream)
{
	BX_UNUSED(_ptr, _size, _count, _stream);
	return -1;
}

extern "C" size_t fwrite(const void* _ptr, size_t _size, size_t _count, FILE* _stream)
{
	BX_UNUSED(_ptr, _size, _count, _stream);
	return -1;
}

extern "C" int fseek(FILE* _stream, long int _offset, int _origin)
{
	BX_UNUSED(_stream, _offset, _origin);
	return -1;
}

extern "C" int fseeko64(FILE* _stream, off64_t _offset, int _whence)
{
	BX_UNUSED(_stream, _offset, _whence);
	return -1;
}

extern "C" long int ftell(FILE* _stream)
{
	BX_UNUSED(_stream);
	return -1;
}

extern "C" off64_t ftello64(FILE* _stream)
{
	BX_UNUSED(_stream);
	return -1;
}

extern "C" int feof(FILE* _stream)
{
	BX_UNUSED(_stream);
	return -1;
}

extern "C" int ferror(FILE* _stream)
{
	BX_UNUSED(_stream);
	return -1;
}

extern "C" FILE* popen(const char* _command, const char* _type)
{
	BX_UNUSED(_command, _type);
	return NULL;
}void*   __dso_handle = (void*) &__dso_handle;

extern "C" int pclose(FILE* _stream)
{
	BX_UNUSED(_stream);
	return -1;
}

extern "C" int execvp(const char* _file, char* const _argv[])
{
	BX_UNUSED(_file, _argv);
	return -1;
}

extern "C" long syscall(long _num, ...)
{
	BX_UNUSED(_num);
	return -1;
}

extern "C" long sysconf(int name)
{
	BX_UNUSED(name);
	return -1;
}

extern "C" pid_t fork()
{
	return -1;
}

extern "C" int sched_yield()
{
	return -1;
}

extern "C" int prctl(int _option, unsigned long _arg2, unsigned long _arg3, unsigned long _arg4, unsigned long _arg5)
{
	BX_UNUSED(_option, _arg2, _arg3, _arg4, _arg5);
	return -1;
}

extern "C" int chdir(const char* _path)
{
	BX_UNUSED(_path);
	return -1;
}

extern "C" char* getcwd(char* _buf, size_t _size)
{
	BX_UNUSED(_buf, _size);
	return NULL;
}

extern "C" char* getenv(const char* _name)
{
	BX_UNUSED(_name);
	return NULL;
}

extern "C" int setenv(const char* _name, const char* _value, int _overwrite)
{
	BX_UNUSED(_name, _value, _overwrite);
	return -1;
}

extern "C" int unsetenv(const char* _name)
{
	BX_UNUSED(_name);
	return -1;
}

extern "C" time_t time(time_t* _arg)
{
	BX_UNUSED(_arg);
	return -1;
}

extern "C" int gettimeofday(struct timeval* _tv, struct timezone* _tz)
{
	BX_UNUSED(_tv, _tz);
	return -1;
}

extern "C" void* realloc(void* _ptr, size_t _size)
{
	BX_UNUSED(_ptr, _size);
	return NULL;
}

extern "C" void* malloc(size_t _size)
{
	return ::realloc(NULL, _size);
}

extern "C" void free(void* _ptr)
{
	BX_UNUSED(_ptr);
}

extern "C" void abort()
{
	while (true) {};
}

extern "C" void __assert_fail(const char* _assertion, const char* _file, uint32_t _line, const char* _function)
{
	BX_UNUSED(_assertion, _file, _line, _function);
	abort();
}

void* __dso_handle = (void*)&__dso_handle;

void operator delete(void*)
{
}

extern "C" void __cxa_pure_virtual()
{
}

extern "C" int __cxa_atexit(void (*_dtorFn)(void*), void* _arg, void* _dsoHandle)
{
	BX_UNUSED(_dtorFn, _arg, _dsoHandle);
	return 0;
}

extern "C" void __gxx_personality_v0()
{
}

extern "C" void _Unwind_Resume(void*)
{
}

extern "C" int __gcc_personality_v0(int _version, ...)
{
	BX_UNUSED(_version);
	return 0;
}

namespace __cxxabiv1
{
	class __class_type_info
	{
	public:
		virtual ~__class_type_info();

		const char* m_name;
	};

	__class_type_info::~__class_type_info()
	{
	}

	class __si_class_type_info : public __class_type_info
	{
	public:
		virtual ~__si_class_type_info();
	};

	__si_class_type_info::~__si_class_type_info()
	{
	}

	class __vmi_class_type_info : public __class_type_info
	{
	public:
		virtual ~__vmi_class_type_info();
	};

	__vmi_class_type_info::~__vmi_class_type_info()
	{
	}

	__extension__ typedef int __guard __attribute__( (mode(__DI__) ) );

	extern "C" int __cxa_guard_acquire (__guard* _g)
	{
		return !*(char*)(_g);
	}

	extern "C" void __cxa_guard_release (__guard* _g)
	{
		*(char*)_g = 1;
	}

	extern "C" void __cxa_guard_abort (__guard* _g)
	{
		BX_UNUSED(_g);
	}

} // namespace __cxxabiv1

#endif // BX_CRT_NONE
