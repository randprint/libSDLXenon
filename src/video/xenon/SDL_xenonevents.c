/* xbox 360 usb mouse "driver" v0.01 by Slasher King, and Cancerous1 */
#include "SDL.h"
#include "SDL_xenonvideo.h"
#include "SDL_xenonevents.h"
#include "SDL_timer.h"
#include "SDL_events.h"

#include <usb/usbmain.h>
#include <input/input.h>
 
void XENON_PumpEvents()
{
	struct mouse_data_s m;
	static struct mouse_data_s oldm;

	//printf("Pumping xenon events ");
	if(get_mouse_data(&m))
{
 
		if((m.mx != oldm.mx)||(m.my != oldm.my))
		{
			printf("Got mouse data x:%d y:%d                             \r", m.mx, m.my);
			SDL_PrivateMouseMotion(0, 1, (Sint16)m.mx, (Sint16)m.my);
		}
		
		if(m.mz != oldm.mz)
		{
			//this is my best guess at the wheel
			printf("wheel z:%d                                           \r", m.mz);
			if ((Sint16)m.mz > (Sint16)oldm.mz)
			{
				SDL_PrivateMouseButton(1, 4, 0, 0);
				SDL_PrivateMouseButton(0, 4, 0, 0);
			}
			
			if ((Sint16)m.mz < (Sint16)oldm.mz)
			{
				SDL_PrivateMouseButton(1, 5, 0, 0);
				SDL_PrivateMouseButton(0, 5, 0, 0);
			}

		}
		
		if(m.buttonstates != oldm.buttonstates)
		{
			int *mfx, *mfy;
			//get the cursor current position to pass through to the click event
			//some cases need this, others might not, please leave it in unless
			//it's replaced with something better that leaves the functionality.
			SDL_GetMouseState(mfx, mfy);
			printf("Button State : %d                                    \r", m.buttonstates);

			if ((m.buttonstates & 1)||(oldm.buttonstates & 1))
			{
				SDL_PrivateMouseButton((m.buttonstates & 1), 1, mfx, mfy);
			}

			if (((m.buttonstates & 2) == 2)||((oldm.buttonstates & 2) == 2))
			{
				SDL_PrivateMouseButton(((m.buttonstates & 2) == 2), 3, mfx, mfy);
			}

			if (((m.buttonstates & 4) == 4)||((oldm.buttonstates & 4) == 4))
			{
				SDL_PrivateMouseButton(((m.buttonstates & 4) == 4), 2, mfx, mfy);
			}

		}

		oldm = m;

	}
 
}

void XENON_InitOSKeymap(_THIS)
{


}
