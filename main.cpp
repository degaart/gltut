#include <iostream>
#include <GL/glew.h>
#include "display.h"

int main()
{
    Display display(800, 600, "gltut");

    while(!display.IsClosed()) {
        display.Clear(0.0f, 0.25f, 0.50f, 1.0f);
        display.Update();
    }
    return 0;
}

