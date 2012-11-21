/*
    SDL - Simple DirectMedia Layer
    Copyright (C) 1997, 1998, 1999, 2000, 2001, 2002  Sam Lantinga

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    Sam Lantinga
    slouken@libsdl.org
*/

#include <ppc/timebase.h>
#include <time/time.h>
#include <threads/threads.h>
 
#include "SDL_timer.h"
#include "../SDL_timer_c.h"
#include "SDL_error.h"

#define TIMEBASE 1000

void SDL_StartTicks(void)
{
	/* Set first ticks value */ 
 
}

Uint32 SDL_GetTicks(void)
{
	return mftb() / (PPC_TIMEBASE_FREQ / TIMEBASE );	
}

void SDL_Delay(Uint32 ms)
{
	thread_sleep(ms);
}

int SDL_SYS_TimerInit(void)
{
	return(0);
}

void SDL_SYS_TimerQuit(void)
{
	return;
}

/* Forward declaration because this is called by the timer callback */
int SDL_SYS_StartTimer(void);

int SDL_SYS_StartTimer(void)
{
	 
	return 0;
}

void SDL_SYS_StopTimer(void)
{
	 
}



