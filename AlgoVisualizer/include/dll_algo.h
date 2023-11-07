#pragma once

#ifdef LIBRARY_EXPORTS
#    define AV_API __declspec(dllexport)
#else
#    define AV_API __declspec(dllimport)
#endif
