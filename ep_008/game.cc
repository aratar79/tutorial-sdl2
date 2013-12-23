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
	int button;

    switch(m_evento.type)
    {
    case SDL_QUIT:
        m_running = false;
        break;
    case SDL_MOUSEMOTION:
    	std::cout << "Has movido el ratón al punto (" << m_evento.motion.x
    		<< "," << m_evento.motion.y << ")." << std::endl;
    	break;
    case SDL_MOUSEBUTTONDOWN:
    	button = m_evento.button.button;
    	switch(button) {
    	case SDL_BUTTON_LEFT:
    		std::cout << "Has pulsado el botón izquierdo." << std::endl;
    		break;
    	case SDL_BUTTON_MIDDLE:
    		std::cout << "Has pulsado el botón del medio." << std::endl;
    		break;
    	case SDL_BUTTON_RIGHT:
    		std::cout << "Has pulsado el botón derecho." << std::endl;
    		break;
    	case SDL_BUTTON_X1:
    		std::cout << "Has pulsado X1." << std::endl;
    		break;
    	case SDL_BUTTON_X2:
    		std::cout << "Has pulsado X2." << std::endl;
    		break;
    	default:
    		std::cout << "Se ha pulsado el botón " << button << std::endl;
    	 	break;
    	}
    	break;
	case SDL_MOUSEBUTTONUP:
		button = m_evento.button.button;
		switch(button) {
		case SDL_BUTTON_LEFT:
			std::cout << "Has levantado el botón izquierdo." << std::endl;
			break;
		case SDL_BUTTON_MIDDLE:
			std::cout << "Has levantado el botón del medio." << std::endl;
			break;
		case SDL_BUTTON_RIGHT:
			std::cout << "Has levantado el botón derecho." << std::endl;
			break;
		case SDL_BUTTON_X1:
			std::cout << "Has levantado X1." << std::endl;
			break;
		case SDL_BUTTON_X2:
			std::cout << "Has levantado X2." << std::endl;
			break;
		default:
			std::cout << "Se ha levantado el botón " << button << std::endl;
			break;
		}
		break;
	case SDL_MOUSEWHEEL:
		std::cout << "Se ha movido la rueda del ratón. Desplazamiento: (" <<
			m_evento.wheel.x << "," << m_evento.wheel.y << ")." << std::endl;
		break;
    }
}

void Game::Update()
{
    if(m_keys[SDL_SCANCODE_UP]) {
        img_vy = -1;
    } else if(m_keys[SDL_SCANCODE_DOWN]) {
        img_vy = 1;
    } else {
        img_vy = 0;
    }

    if(m_keys[SDL_SCANCODE_LEFT]) {
        img_vx = -1;
    } else if(m_keys[SDL_SCANCODE_RIGHT]) {
        img_vx = 1;
    } else {
        img_vx = 0;
    }

    img_x += img_vx;
    img_y += img_vy;
}

void Game::Render()
{
    SDL_RenderClear(m_renderer);
    m_hola->Render((int) img_x, (int) img_y);
    SDL_RenderPresent(m_renderer);
}
