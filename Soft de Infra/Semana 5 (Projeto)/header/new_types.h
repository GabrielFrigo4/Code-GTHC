#include <stdint.h>
#include <wchar.h>

typedef uint64_t uint64;
typedef int64_t sint64;
typedef uint32_t uint32;
typedef int32_t sint32;
typedef uint16_t uint16;
typedef int16_t sint16;
typedef uint8_t uint8;
typedef int8_t sint8;
typedef uint32 bool;
typedef wchar_t wchar;

#define TRUE 1
#define true TRUE
#define FALSE 0
#define false FALSE

#ifndef NULL
#define NULL 0
#endif