#ifndef SOMA_API_H
#define SOMA_API_H

#if defined(_WIN32)
    #ifdef BUILDING_DLL
        #define API_EXPORT __declspec(dllexport)
    #else
        #define API_EXPORT __declspec(dllimport)
    #endif
#else
    #define API_EXPORT __attribute__((visibility("default")))
#endif

#ifdef __cplusplus
extern "C" {
#endif

API_EXPORT int soma(int a, int b);

#ifdef __cplusplus
}
#endif

#endif // SOMA_API_H