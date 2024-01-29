#pragma once
#include <Windows.h>
#include "SubWindow.h"

typedef struct Pixel //to record a pixel
{
	POINT position;
	COLORREF color;
}Pixel;


typedef class Layer
{
public:
	//constructor and destructor
	explicit Layer(SubWindow* parentWindow, LONG width, LONG height, LONG posX, LONG posY);
	explicit Layer(Layer& layer);
	Layer& operator=(Layer const& layer);
	~Layer();

	//getters
	SubWindow* getParentWindow();
	HANDLE getHandle();
	UINT64 getPriority();
	UINT64 getPixelNumber();
	COLORREF* getPixels();

	//getters and setters
	RECT getPosition();	//use Rect instead of const Rect* to prevent this->Rect from being changed without setter
	bool setPosition(RECT* position);
	COLORREF getColor(POINT position);
	bool setColor(POINT position, COLORREF color);
	bool setColor(Pixel* pixels, UINT64 pixelNumber);
	
	
private:
	SubWindow* parentWindow;
	HANDLE handle;
	RECT position;
	UINT64 pixelNumber;
	COLORREF* pixels;
}Layer;
