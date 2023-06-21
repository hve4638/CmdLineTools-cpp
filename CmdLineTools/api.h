#pragma once
#ifdef _CMDLINETOOLS_LIB
#define CMDLINETOOLS_API __declspec(dllexport)
#else
#define CMDLINETOOLS_API 
#endif