#include "stdafx.h"
#include "BaseWindow.h"

CBaseWindow::CBaseWindow(void) : m_bIsGameRun(SDL_TRUE)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	DEVMODE devMode;
	originW					= (int)GetSystemMetrics(SM_CXSCREEN);
	originH					= (int)GetSystemMetrics(SM_CYSCREEN);

	ZeroMemory(&devMode, sizeof(DEVMODE));
	devMode.dmSize			= sizeof(DEVMODE);
	devMode.dmBitsPerPel	= 32;
	devMode.dmPelsWidth		= SCREEN_WIDTH;
	devMode.dmPelsHeight	= SCREEN_HEIGHT;
	devMode.dmFields		= DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

	ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);
}

CBaseWindow::~CBaseWindow(void)
{
	DEVMODE devMode;
	ZeroMemory(&devMode, sizeof(DEVMODE));
	devMode.dmSize			= sizeof(DEVMODE);
	devMode.dmBitsPerPel	= 32;
	devMode.dmPelsWidth		= originW;
	devMode.dmPelsHeight	= originH;
	devMode.dmFields		= DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

	ChangeDisplaySettings(&devMode, CDS_FULLSCREEN);

	SDL_Quit();
}

bool CBaseWindow::Initialize()
{
	m_pWnd = SDL_CreateWindow("Miracle Boys!", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN);
	m_pRender = SDL_CreateRenderer(m_pWnd, -1, 0);

	return true;
}

void CBaseWindow::Terminate()
{
	SDL_DestroyRenderer(m_pRender);
	SDL_DestroyWindow(m_pWnd);
}