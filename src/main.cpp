#include <iostream>

#include <Engine/Engine.h>

int main()
{
    shen3::Engine engine;
    engine.Initialize();
    engine.Run();
    engine.Destroy();

    return 0;
}
