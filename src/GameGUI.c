
#include"SDL/SDL.h"
#include"GameGUI.h"

#define GameMode_HvC 0
#define GameMode_HvH 1
#define GameMode_CvC 2

SDL_Surface *gui_screen;	//This pointer will reference the backbuffer

int gui_init_video()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	gui_screen = SDL_SetVideoMode(320, 240, 32, SDL_ANYFORMAT /*SDL_DOUBLEBUF | SDL_FULLSCREEN*/);
	if (gui_screen == NULL) {
		printf("Unable to set video mode: %s\n", SDL_GetError());
		return 1;
	}
	atexit(SDL_Quit);
}

void gui_init(Player player_arr[2])
{
	
	gui_init_video();
	int GameMode=gui_main_menu();
	switch(GameMode)
	{
		case GameMode_HvC:
			gui_player_HvC_menu(player_arr);
			break;
		case GameMode_HvH:
			gui_player_HvH_menu(player_arr);
			break;
		case GameMode_CvC:
			gui_player_CvC_menu(player_arr);
			break;
	}

	gui_gameplay_window();
}

void gui_gameplay_window()
{

}

void gui_quit_window()
{

}

int gui_main_menu()
{

}

void gui_player_HvC_menu(Player* player_arr)
{

}

void gui_player_HvH_menu(Player* player_arr)
{

}

void gui_player_CvC_menu(Player* player_arr)
{

}

int gui_play(Player player)
{

}

void gui_refresh()
{
	
}

int gui_example()
{
	SDL_Surface *image;	//This pointer will reference our bitmap sprite
    SDL_Surface *temp;	//This pointer will temporarily reference our bitmap sprite
	SDL_Rect src, dest;	//These rectangles will describe the source and destination regions of our blit
	int x;
	SDL_Event event;	/* Event structure */
	int Running;

	//Load the bitmap into a temporary surface, and check for success
	temp = SDL_LoadBMP("res/smiley.bmp");
	if (temp == NULL) {
		printf("Unable to load bitmap: %s\n", SDL_GetError());
		return 1;
	}
	
	//Convert the surface to the appropriate display format
	image = SDL_DisplayFormat(temp);
	
	//Release the temporary surface
	SDL_FreeSurface(temp);
	
	//Construct the source rectangle for our blit
	src.x = 0;
	src.y = 0;
	src.w = image->w;	//Use image->w to display the entire width of the image
	src.h = image->h;	//Use image->h to display the entire height of the image
	
	//Construct the destination rectangle for our blit
	dest.x = 0;		//Display the image at the (X,Y) coordinates (0,0)
	dest.y = 0;
	dest.w = image->w;	//Ensure the destination is large enough for the image's entire width/height
	dest.h = image->h;
	
	for(x=0; x<8; x++)	// print 8 smileys at top row
	{
		dest.x = x*image->w;
		//Blit the image to the backbuffer
		SDL_BlitSurface(image, &src, gui_screen, &dest);
	
		//Update the window at the modified region
		SDL_UpdateRect(gui_screen, dest.x, dest.y, dest.w, dest.h);
	}
	





	//Process events
	Running = 1;
	printf("Running!\n");
	while(Running && SDL_WaitEvent(&event))
	{
		printf("Received event.type = %d\n", event.type);
		switch(event.type)
		{ /* Process the appropriate event type */
			case SDL_KEYDOWN:  /* Handle a KEYDOWN event */
			{	printf("Oh! Key pressed!\n");
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{	printf("Oh! Mouse button %d pressed!\n",
					event.button.button);
				printf("Position is x=%d, y=%d.\n",
					event.button.x, event.button.y);
				// put a smiley there!
				dest.x = event.button.x;
				dest.y = event.button.y;
				SDL_BlitSurface(image, &src, gui_screen, &dest);
				SDL_UpdateRect(gui_screen, dest.x, dest.y, dest.w, dest.h);
				break;
			}
			case SDL_QUIT:
			{	printf("Quit event received!\n");
				Running = 0;
				break;
			}
			default: /* ignore any other events */
			{	printf("Oops, unknown event!\n");
				break;
			}
		} /* hctiws */
	} /* elihw */


	//Release the surface
	SDL_FreeSurface(image);
}



