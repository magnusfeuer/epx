//
// EPX window  managent
//

#include "epx_object.h"
#include "epx_dict.h"
#include "epx_window.h"

void EPX_WINDOW_TYPE_RELEASE(void* arg)
{
    epx_window_t* win = (epx_window_t*) arg;

    EPX_DBGFMT_MEM("EWINDOW_TYPE_RELEASE: %p", arg);
    if (win->detach) win->detach(win);
    if (win->on_heap) free(win);
}

void epx_window_destroy(epx_window_t* win)
{
    epx_object_unref(win);
}

int epx_window_init(epx_window_t* win, int x, int y, 
		    unsigned int width, unsigned int height)
{
    EPX_OBJECT_INIT(win, EPX_WINDOW_TYPE);
    win->backend = 0;
    win->detach  = 0;
    win->user    = 0;
    win->owner   = 0;
    win->opengl  = 0;
    win->mask    = 0;
    win->x = x;
    win->y = y;
    win->width = width;
    win->height = height;
    return 0;
}

epx_window_t* epx_window_create(int x, int y, 
				unsigned int width, unsigned int height)
{
    epx_window_t* win;

    if (!(win = (epx_window_t*) malloc(sizeof(epx_window_t))))
	return 0;
    epx_window_init(win, x, y, width, height);
    win->on_heap = 1;
    win->refc = 1;
    return win;
}

