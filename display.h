#pragma once

#include <string>
#include <SDL2/SDL.h>

class Display {
    public:
        Display(int width, int height, std::string title);
        virtual ~Display();

        Display(const Display&) = delete;
        Display& operator=(const Display&) = delete;

        void Clear(float r, float g, float b, float a);
        void Update();
        bool IsClosed();
    private:
        SDL_Window* m_window;
        SDL_GLContext m_glContext;
        bool m_isClosed;
};

