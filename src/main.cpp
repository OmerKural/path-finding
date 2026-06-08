#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include "Engine.h"

int main()
{
    SetProcessDPIAware();
    Engine engine;
    engine.run();
}