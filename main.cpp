#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"

int main()
{
    Display display(800, 600, "gltut");

    Shader shader("./res/basicShader");

    while(!display.IsClosed()) {
        display.Clear(0.0f, 0.25f, 0.50f, 1.0f);
        shader.Bind();

        display.Update();
    }
    return 0;
}

