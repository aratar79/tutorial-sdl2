#include <SDL2/SDL.h>

int main(int argc, char* argv)
{
    SDL_Window* window = NULL;

    // 1. INICIAR EL JUEGO
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("Hola, juego", 50, 50, 640, 360, SDL_WINDOW_SHOWN);
    if(window == NULL)
    {
        perror("Error al crear la ventana.");
        SDL_Quit();
        return 1;
    }

    // BUCLE [serie de códigos que se repite de forma continua]
        
        // 2. PROCESA LA ENTRADA

        // 3. ACTUALIZAR EL ESTADO DEL JUEGO

        // 4. RENDERIZAR EL JUEGO.

    // CONDICIÓN DE SALIDA DEL BUCLE: el juego termine de funcionar

    // 5. FINALIZA EL JUEGO
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
