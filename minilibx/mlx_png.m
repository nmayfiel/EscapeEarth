// nmayfiel 06/06/2017

#import <Cocoa/Cocoa.h>
#include "mlx_int.h"
#include <string.h>
#include <stdio.h>

static void normalize_color_format_alpha(uint8_t *buffer, int size)
{
     int i;
     int32_t *ptr;

     i = 0;
     while (i < size)
     {
	  if (i % 4 == 0)
	  {
	       ptr = (int32_t *)(buffer + i);
	       *ptr = ((*ptr & 0xFF00FF00)) |
		    ((*ptr & 0x000000FF) << 16) |
		    ((*ptr & 0x00FF0000) >> 16);
	  }
	  if ((i + 1) % 4 == 0)
	       buffer[i] = 0xFF - buffer[i];
	  ++i;
     }
}

void *png_data_to_image(mlx_ptr_t *xvar, const uint8_t *fileData, uint32_t size, int *w, int *h)
{
	mlx_img_list_t *img;
	uint8_t *data;
	uint8_t *buffer;
	NSData *imgData = [[NSData alloc] initWithBytes: fileData length: size];

	NSImage *ns_image = [[NSImage alloc] initWithData: imgData];
	NSImageRep *image_rep = [[ns_image representations] objectAtIndex:0];
	if (!(img = mlx_new_image(xvar, image_rep.pixelsWide, image_rep.pixelsHigh)))
	{
		*w = 0;
		*h = 0;
		return ((void *)0);
	}
	NSBitmapImageRep *rep = [
		[NSBitmapImageRep alloc]
				  initWithBitmapDataPlanes: NULL
						pixelsWide: image_rep.pixelsWide
						pixelsHigh: image_rep.pixelsHigh
					     bitsPerSample: 8
					   samplesPerPixel: 4
						  hasAlpha: YES
						  isPlanar: NO
					    colorSpaceName: NSDeviceRGBColorSpace
					       bytesPerRow: image_rep.pixelsWide * 4
					      bitsPerPixel: 32
		];
	NSGraphicsContext *ctx = [NSGraphicsContext graphicsContextWithBitmapImageRep: rep];
	[NSGraphicsContext saveGraphicsState];
	[NSGraphicsContext setCurrentContext: ctx];  
	[ns_image drawAtPoint: NSZeroPoint fromRect: NSZeroRect operation: NSCompositeCopy fraction: 1.0];
	[ctx flushGraphics];
	[NSGraphicsContext restoreGraphicsState];
	data = [rep bitmapData];
	buffer = (uint8_t *)img->buffer;
	memcpy(buffer, data, rep.bytesPerRow * rep.pixelsHigh);
	normalize_color_format_alpha(buffer, rep.bytesPerRow * rep.pixelsHigh);
	[imgData release];
	[ns_image release];
	[rep release];
	*w = image_rep.pixelsWide;
	*h = image_rep.pixelsHigh;
	return (img);
}

void *png_file_to_image(mlx_ptr_t *xvar, const char *filename, int *w, int *h)
{
     mlx_img_list_t *img;
     uint8_t *data;
     uint8_t *buffer;
     NSString *image_filename_string = [[NSString alloc] initWithCString: filename
							encoding: NSASCIIStringEncoding];
     NSURL *image_url = [[NSURL alloc] initFileURLWithPath: image_filename_string];
     NSImage *ns_image = [[NSImage alloc] initWithContentsOfURL: image_url];
     NSImageRep *image_rep = [[ns_image representations] objectAtIndex:0];
     if (!(img = mlx_new_image(xvar, image_rep.pixelsWide, image_rep.pixelsHigh)))
     {
	  *w = 0;
	  *h = 0;
	  return ((void *)0);
     }
     NSBitmapImageRep *rep = [
	  [NSBitmapImageRep alloc]
				  initWithBitmapDataPlanes: NULL
						pixelsWide: image_rep.pixelsWide
						pixelsHigh: image_rep.pixelsHigh
					     bitsPerSample: 8
					   samplesPerPixel: 4
						  hasAlpha: YES
						  isPlanar: NO
					    colorSpaceName: NSDeviceRGBColorSpace
					       bytesPerRow: image_rep.pixelsWide * 4
					      bitsPerPixel: 32
	  ];
     NSGraphicsContext *ctx = [NSGraphicsContext graphicsContextWithBitmapImageRep: rep];
     [NSGraphicsContext saveGraphicsState];
     [NSGraphicsContext setCurrentContext: ctx];  
     [ns_image drawAtPoint: NSZeroPoint fromRect: NSZeroRect operation: NSCompositeCopy fraction: 1.0];
     [ctx flushGraphics];
     [NSGraphicsContext restoreGraphicsState];
     data = [rep bitmapData];
     buffer = (uint8_t *)img->buffer;
     memcpy(buffer, data, rep.bytesPerRow * rep.pixelsHigh);
     normalize_color_format_alpha(buffer, rep.bytesPerRow * rep.pixelsHigh);
     [image_filename_string release];
     [image_url release];
     [ns_image release];
     [rep release];
     *w = image_rep.pixelsWide;
     *h = image_rep.pixelsHigh;
     return (img);
}
