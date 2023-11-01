#pragma once

#ifdef LIBRARY_EXPORTS
#    define L4_API __declspec(dllexport)
#else
#    define L4_API __declspec(dllimport)
#endif
