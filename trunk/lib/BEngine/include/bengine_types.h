#ifndef _BENGINE_TYPES_H_
#define _BENGINE_TYPES_H_

typedef unsigned long long	__UINT64;
typedef long long			__INT64;
typedef int					__INT32;
typedef unsigned int		__UINT32;
typedef signed short		__INT16;
typedef unsigned short		__UINT16;
typedef signed char			__INT8;
typedef unsigned char		__UINT8;
typedef float				__FLOAT;
typedef double				__DOUBLE;
typedef char				__CHAR;
typedef char*				__PCHAR;
typedef bool				__BOOL;
typedef std::string			__STRING;

//struct use for color
struct SColor4f
{
	__FLOAT R;
	__FLOAT G;
	__FLOAT B;
	__FLOAT A;

	SColor4f()
	{
		R = 0.0f;
		G = 0.0f;
		B = 0.0f;
		A = 0.0f;
	}
};

struct SColor4i
{
	__INT32 R;
	__INT32 G;
	__INT32 B;
	__INT32 A;

	SColor4i()
	{
		R = 0;
		G = 0;
		B = 0;
		A = 0;
	}
};

//struct use for 2d point
struct SPoint3f
{
	__FLOAT X;
	__FLOAT Y;
	__FLOAT Z;
};

struct SPoint3i
{
	__INT32 X;
	__INT32 Y;
	__INT32 Z;
};

struct SPoint2f
{
	__FLOAT X;
	__FLOAT Y;
};

struct SPoint2i
{
	__INT32 X;
	__INT32 Y;
};

//struct for rect
struct SRect
{
	__FLOAT X;
	__FLOAT Y;
	__FLOAT W;
	__FLOAT H;
};

#endif