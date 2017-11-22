#include <iostream>
#include <GL/glew.h>
#include "display.h"
#include "shader.h"
#include "mesh.h"
#include "texture.h"
#include "transform.h"
#include "camera.h"

#define WIDTH 800
#define HEIGHT 600

int main()
{
    Display display(WIDTH, HEIGHT, "gltut");

    Shader shader("./res/basicShader");
    Vertex vertices[] = {
        Vertex(glm::vec3(-0.5, -0.5, 0), glm::vec2(0.0, 0.0)),
        Vertex(glm::vec3(0, 0.5, 0), glm::vec2(0.5, 1.0)),
        Vertex(glm::vec3(0.5, -0.5, 0), glm::vec2(1.0, 0.0)),
    };
    int indices[] = {
        0, 1, 2
    };

    Mesh mesh(vertices, sizeof(vertices) / sizeof(vertices[0]),
              indices, sizeof(indices) / sizeof(indices[0]));
    Mesh mesh2("./res/monkey3.obj");
    Texture texture("./res/checkers.png");
    Camera camera(glm::vec3(0, 0, -5),
                  70.0f,
                  (float)WIDTH / (float)HEIGHT,
                  0.01f,
                  1000.0f);
                  
    Transform transform;

    float counter = 0.0f;

    while(!display.IsClosed()) {
        display.Clear(0.0f, 0.25f, 0.50f, 1.0f);

        float sinCounter = sin(counter);
        float cosCounter = cos(counter);

        transform.GetPos().x = sinCounter;
        transform.GetPos().z = cosCounter;
        transform.GetRot().x = counter * 2.0f;
        transform.GetRot().y = counter * 2.0f;
        transform.GetRot().z = counter * 2.0f;
        //transform.SetScale(glm::vec3(cosCounter, cosCounter, cosCounter));

        shader.Bind();
        texture.Bind(0);
        shader.Update(transform, camera);
        mesh.Draw();
        mesh2.Draw();

        display.Update();

        counter += 0.01f;
    }
    return 0;
}

