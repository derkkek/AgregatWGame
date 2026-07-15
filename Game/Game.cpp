#include <iostream>
#include "Engine.h"

int main(int argc, const char* argv[]) {
    std::cout << "Hello, World!\n";
    Agregat::Engine engine;
    engine.RunGameLoop([&]() {
        if (engine.input.KeyIsPressed(Agregat::KEY_A))
        {
            std::cout << "a";
        }
        });
    engine.Shutdown();
    return 0;
}