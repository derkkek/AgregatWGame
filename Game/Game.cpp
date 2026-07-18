#include <iostream>
#include "Engine.h"

int main(int argc, const char* argv[]) {
    std::cout << "Hello, World!\n";
    Agregat::Engine engine;
    engine.resource.LoadSound("sounds/click.wav", "click");
    engine.RunGameLoop([&]() {

        });
    engine.Shutdown();
    return 0;
}