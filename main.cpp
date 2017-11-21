#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"

int main()
{
    Display display(800, 600, "gltut");

    Shader shader("./res/basicShader");
    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
        Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
        Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
    };
    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]));
    Texture texture("./res/clouds.png");
    Transform transform;

    float counter = 0.0f;

    while(!display.IsClosed()) {
        display.Clear(0.0f, 0.25f, 0.50f, 1.0f);

        float sinCounter = sin(counter);
        float cosCounter = cos(counter);

        transform.GetPos().x = sinCounter;
        transform.GetRot().z = counter * 10.0f;
        transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

        shader.Bind();
        texture.Bind(0);
        shader.Update(transform);
        mesh.Draw();

        display.Update();

        counter += 0.01f;
    }
    return 0;
}

