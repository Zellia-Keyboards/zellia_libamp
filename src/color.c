/*
 * Copyright (c) 2025 Zellia-Keyboards
 * Original Author: Zhangqi Li (@zhangqili)
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */
#include "color.h"
#include "string.h"

void rgb_to_hsv(ColorHSV * restrict hsv, const ColorRGB * restrict rgb)
{
	float max;
	float min;
	max=rgb->r;
	min=rgb->r;
	max=rgb->g>max?rgb->g:max;
	min=rgb->g<min?rgb->g:min;
	max=rgb->b>max?rgb->b:max;
	min=rgb->b<min?rgb->b:min;
	if(max==min)
	{
		hsv->h=0;
	}
	if(max==rgb->r&&rgb->g>=rgb->b)
	{
		hsv->h=60*(rgb->g-rgb->b)/(max-min);
	}
	else
	{
		hsv->h=60*(rgb->g-rgb->b)/(max-min)+360;
	}
	if(max==rgb->g)
	{
		hsv->h=60*(rgb->b-rgb->r)/(max-min)+120;
	}
	if(max==rgb->b)
	{
		hsv->h=60*(rgb->r-rgb->g)/(max-min)+240;
	}
	if(max==0)
	{
		hsv->s=0;
	}
	else
	{
		hsv->s=100*(1-min/max);
	}
	hsv->v=max*100/255;
}

void hsv_to_rgb(ColorRGB * restrict rgb, const ColorHSV * restrict hsv)
{
    float c = 0;
    float x = 0;
    float y = 0;
    float z = 0;
    float h = (float)(hsv->h);
    float s = ((float)(hsv->s))/100.0;
    float v = ((float)(hsv->v))/100.0;
    if(s < 1e-6)
    {
        rgb->r=hsv->v*255.0/100.0;
        rgb->g=hsv->v*255.0/100.0;
        rgb->b=hsv->v*255.0/100.0;
    }
    else
    {
        h=h/60;
        c=h-(int)h;

        x = v*(1-s);
        y = v*(1-s*c);
        z = v*(1-s*(1-c));
        switch (hsv->h/60)
        {
            case 0:
                rgb->r = hsv->v*255.0/100.0;
                rgb->g = z*255;
                rgb->b = x*255;
                break;
            case 1:
                rgb->r = y*255;
                rgb->g = hsv->v*255.0/100.0;
                rgb->b = x*255;
                break;
            case 2:
                rgb->r = x*255;
                rgb->g = hsv->v*255.0/100.0;
                rgb->b = z*255;
                break;
            case 3:
                rgb->r = x*255;
                rgb->g = y*255;
                rgb->b = hsv->v*255.0/100.0;
                break;
            case 4:
                rgb->r = z*255;
                rgb->g = x*255;
                rgb->b = hsv->v*255.0/100.0;
                break;
            case 5:
                rgb->r = hsv->v*255.0/100.0;
                rgb->g = x*255;
                rgb->b = y*255;
                break;
            default:
                break;
        }
    }
}

void color_get_rgb(const Color* restrict color, ColorRGB* restrict rgb)
{
    memcpy(rgb,color,sizeof(Color));
}
void color_set_rgb(Color* restrict  color, const ColorRGB* restrict rgb)
{
    memcpy(color,rgb,sizeof(Color));
}

void colorf_set_rgb(ColorFloat * restrict color, const ColorRGB * restrict rgb)
{
	color->r = rgb->r;
	color->g = rgb->g;
	color->b = rgb->b;
}

void colorf_set_hsv(ColorFloat * restrict color, const ColorHSV * restrict rgb)
{
	ColorRGB temp_rgb = {0,0,0};
	hsv_to_rgb(&temp_rgb, rgb);
	colorf_set_rgb(color, &temp_rgb);
}

void color_get_hsv(const Color* restrict color, ColorHSV* restrict hsv)
{
    rgb_to_hsv(hsv, color);
}
void color_set_hsv(Color* restrict color, const ColorHSV* restrict hsv)
{
    hsv_to_rgb(color, hsv);
}

void color_mix(Color *dest, const Color *source)
{
	if (dest->r + source->r < 256)
	{
		dest->r += source->r;
	}
	else
	{
		dest->r = 255;
	}
	if (dest->g + source->g < 256)
	{
		dest->g += source->g;
	}
	else
	{
		dest->g = 255;
	}
	if (dest->b + source->b < 256)
	{
		dest->b += source->b;
	}
	else
	{
		dest->b = 255;
	}
}

void colorf_mix(ColorFloat *dest, const ColorFloat *source)
{
	if (dest->r + source->r < 256)
	{
		dest->r += source->r;
	}
	else
	{
		dest->r = 255;
	}
	if (dest->g + source->g < 256)
	{
		dest->g += source->g;
	}
	else
	{
		dest->g = 255;
	}
	if (dest->b + source->b < 256)
	{
		dest->b += source->b;
	}
	else
	{
		dest->b = 255;
	}
}