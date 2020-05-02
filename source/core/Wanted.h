#include "Base.h"

class CWanted
{
    int chaos;
    int field_4;
    int field_8;
    int updateTime;
    int field_10;
    int crimeSensitivity;
    int currentNumberOfCops;
    char maxcops;
    char nhelis;
    char field_1B;
    char field_1C;
    char ignored;
    char gap_1F;
    char wantedLevel;
    int minWantedLevel;
    char field_28[0x1c0];
    char cops[0x28];
private:
    static int &MaximumWantedLevel;
    static int &nMaximumWantedLevel;

public:
    static void InjectHooks();
    static void SetMaximumWantedLevel(int level);
};

VALIDATE_SIZE(CWanted, 0x210);