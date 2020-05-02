#include "HookSystem.h"
#include "Wanted.h"
#include <iostream>

int& CWanted::MaximumWantedLevel = *(int*)0x006910D8;
int& CWanted::nMaximumWantedLevel = *(int*)0x006910DC;

void CWanted::InjectHooks()
{
    HookInstall(0x004D1E90, &CWanted::SetMaximumWantedLevel, 7);
}

void CWanted::SetMaximumWantedLevel(int level)
{
#ifdef USE_DEFAULT_FUNCTIONS
    plugin::Call<0x004D1E90, int>(level);
#else
    switch (level)
    {
    case 0:
        nMaximumWantedLevel = 0;
        MaximumWantedLevel = 0;
        break;
    case 1:
        nMaximumWantedLevel = 115;
        MaximumWantedLevel = 1;
        break;
    case 2:
        nMaximumWantedLevel = 365;
        MaximumWantedLevel = 2;
        break;
    case 3:
        nMaximumWantedLevel = 875;
        MaximumWantedLevel = 3;
        break;
    case 4:
        nMaximumWantedLevel = 1800;
        MaximumWantedLevel = 4;
        break;
    case 5:
        nMaximumWantedLevel = 3600;
        MaximumWantedLevel = 5;
        break;
    case 6:
        nMaximumWantedLevel = 7200;
        MaximumWantedLevel = 6;
        break;
    default:
        return;
    }
#endif
}