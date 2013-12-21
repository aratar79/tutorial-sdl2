#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(int argc, char** argv) {

	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Event		event;
	SDL_Rect		rectangulo;

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "No se puede inicializar SDL." << std::endl;
		return 1;
	}

	if(!IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG)) {
		std::cerr << "No se puede inicializar SDL_Image." << std::endl;
		SDL_Quit();
		return 1;
	}

	if(SDL_CreateWindowAndRenderer(640, 360,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL,
			&window, &renderer) < 0) {
		std::cerr << "No se puede inicializar la interfaz." << std::endl;
		SDL_Quit();
		return 1;
	}
	SDL_SetWindowTitle(window, "Hola, SDL");

	texture = IMG_LoadTexture(renderer, "madera.jpg");
	rectangulo.x = rectangulo.y = 50;
	SDL_QueryTexture(texture, NULL, NULL, &rectangulo.w, &rectangulo.h);

	for(;;) {
		if(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT)
				break;
		}

		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, &rectangulo);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	IMG_Quit();
	SDL_Quit();
	return 0;
}
