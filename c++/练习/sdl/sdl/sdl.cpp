#include <SDL.h>

#undef main
int main()
{
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		SDL_Log("Init failed:%s", SDL_GetError);
		return -1;
	}
	SDL_Window* win = SDL_CreateWindow("Hello", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, 0);
	if (NULL == win)
	{
		SDL_Log("SDL_CreatWIndow failed:%", SDL_GetError);
		return -1;
	}

	// 暂停一段时间，事件监听事件
	SDL_Event event;
	while (true)
	{
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				break;
			}
		}
	}

	SDL_DestroyWindow(win);

	SDL_Quit();
	return 0;
}