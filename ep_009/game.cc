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
    img_x = img_y = 50.0;
    img_vx = img_vy = 0.0;

    m_keys = SDL_GetKeyboardState(NULL);
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
	int mouseX, mouseY;
	Uint32 mouseState;

    switch(m_evento.type)
    {
    case SDL_QUIT:
        m_running = false;
        break;
    case SDL_KEYDOWN:
    	if(m_evento.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
    		mouseState = SDL_GetMouseState(&mouseX, &mouseY);
    		std::cout << "(" << mouseX << "," << mouseY << ") " << std::endl;
    		if(mouseState & 0x01) {
    			std::cout << "Tienes pulsado el botón izquierdo." << std::endl;
    		}
    		if(mouseState & 0x02) {
				std::cout << "Tienes pulsado el botón del medio." << std::endl;
			}
    		if(mouseState & 0x04) {
				std::cout << "Tienes pulsado el botón de la derecha." << std::endl;
			}
    		std::cout << SDL_ShowCursor(-1) << std::endl;
    	}

    	if(m_evento.key.keysym.scancode == SDL_SCANCODE_F1) {
			SDL_WarpMouseInWindow(m_window, 200, 200);
		}

    	if(m_evento.key.keysym.scancode == SDL_SCANCODE_F2) {
    		std::cout << SDL_ShowCursor(0) << std::endl;
		}

    	if(m_evento.key.keysym.scancode == SDL_SCANCODE_F3) {
    		std::cout << SDL_ShowCursor(1) << std::endl;
		}
    }
}

void Game::Update()
{

}

void Game::Render()
{
    SDL_RenderClear(m_renderer);
    m_hola->Render((int) img_x, (int) img_y);
    SDL_RenderPresent(m_renderer);
}
