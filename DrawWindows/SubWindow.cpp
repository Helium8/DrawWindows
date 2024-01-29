#include "SubWindow.h"

bool SubWindow::registerLayer(Layer* layer, HANDLE* handle)
{
	if (layerNumber%LAYER_UNIT_NUMBER == 0)
	{
		INT64* tempPointer;
		tempPointer = (INT64*)realloc(layerPriorities, layerNumber += LAYER_UNIT_NUMBER);
		if (!tempPointer)
		{
			return false;
		}
		layerPriorities = tempPointer;
	}
	layers[layerNumber] = layer;
	layerPriorities[layerNumber] = getAvailableLayerPriority();
	if (layerPriorities[layerNumber] == GET_AVAILABLE_LAYER_PRIORITY_ERROR)
	{
		return false;
	}
	*handle = (HANDLE)layerNumber;
	layerNumber++;
}