#include <SDL2/SDL.h>
#include <iostream>
#include "game.h"
#include "imagen.h"

Game::Game(const char* title, int width, int height)
{
    m_window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    m_hola = new Imagen(m_renderer, "hola.bmp");
    m_running = false;
}

Game::~Game()
{
    delete m_hola;
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
}

void Game::Run()
{
    m_running = true;
    while(m_running)
    {
        Input();
        Update();
        Render();
    }
}

void Game::Input()
{
    while(SDL_PollEvent(&m_evento))
    {
        HandleEvent();
    }
}

void Game::HandleEvent()
{
    switch(m_evento.type)
    {
    case SDL_QUIT:
        m_running = false;
        break;
    }
}

void Game::Update()
{
}

void Game::Render()
{
    SDL_RenderClear(m_renderer);
    m_hola->Render(50, 50);
    SDL_RenderPresent(m_renderer);
}
