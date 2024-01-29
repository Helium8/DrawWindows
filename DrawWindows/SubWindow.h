#pragma once
#include <malloc.h>
#include <Windows.h>
#include "Layer.h"

enum WindowStatus{NORMAL, MAXIMIZE};

const int LAYER_UNIT_NUMBER = 64;
const INT64 GET_AVAILABLE_LAYER_PRIORITY_ERROR = 0xFFFFFFFFFFFFFFFF;

typedef  class SubWindow
{
	friend class Layer;
public:
	explicit SubWindow(){}
	explicit SubWindow(UINT64 width, UINT64 height) {}
	explicit SubWindow(UINT64 width, UINT64 height, UINT64 posX, UINT64 posY) {}
	explicit SubWindow(UINT64 width, UINT64 height, UINT64 posX, UINT64 posY, WindowStatus status) {}
	explicit SubWindow(UINT64 width, UINT64 height, UINT64 posX, UINT64 posY, WindowStatus status, COLORREF backgroundColor){}

	bool isLayerPriorityExist(UINT64 priority);


	bool drawWindow();

	RECT getPosition();
	bool moveWindow();

	WindowStatus getWindowStatus();
	bool setWindowStatus(WindowStatus status);

	COLORREF getBackgroundColor();
	bool setBackgroundColor(COLORREF* color);

	INT64 getPriority();

	bool newLayer(LONG width, LONG height, LONG posX, LONG posY);
	bool newLayer(Layer& layer);
	bool deleteLayer(HANDLE handle);
	HANDLE getLayerHandle(INT64 layerPriority);
	HANDLE getLayerHandle(Layer* layerPointer);
	
private:

	bool registerLayer(
		IN Layer* layer,
		OUT HANDLE* handle);
	INT64 getAvailableLayerPriority();		//GET_AVAILABLE_LAYER_PRIORITY_ERROR means an error occured
	INT64 getAvailableLayerPriority(UINT64 minimum);

	static HANDLE** handles;	//the position of every handle is stored in this field
	static INT64 handleNumber;
	HANDLE handle;				//handle of this window

	RECT position;				//position and size
	WindowStatus status;
	COLORREF backgroundColor;
	INT64 priority;			//priority of this window

	Layer** layers;
	UINT64 layerNumber;
	INT64* layerPriorities;	//layerPriorities[HANDLE] is the priority of layer whose handle is the HANDLE, and the size of layerPriorities is the times of 64
}SubWindow;