#include "Layer.h"
#include "SubWindow.h"

Layer::Layer(SubWindow* parentWindow, LONG width, LONG height, LONG posX, LONG posY)
{
	this->parentWindow = parentWindow;
	pixelNumber = width * height;
	pixels = (COLORREF*)malloc(pixelNumber * sizeof(COLORREF));
	position.top = posY;
	position.left = posX;
	position.bottom = posY + height - 1;
	position.right = posX + width - 1;
	parentWindow->registerLayer(this, &handle);
}

