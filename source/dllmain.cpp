// dllmain.cpp : Defines the entry point for the DLL application.
#include "dllmain.h"

void DisplayConsole(void)
{
    if (AllocConsole())
    {
        freopen("CONIN$", "r", stdin);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        printf("DLL inject worked :D\n");
    }
}

void InjectHooksMain(void)
{
    printf("Started hooking functions\n");
    CWanted::InjectHooks();
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisplayConsole();
        InjectHooksMain();
        break;
    }
    case DLL_THREAD_ATTACH:
        break;
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

