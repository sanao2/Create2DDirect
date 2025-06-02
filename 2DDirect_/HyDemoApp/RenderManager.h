#pragma once
#include <windows.h> 

class RenderManager
{
public : 
	virtual ~RenderManager() = default; 

	virtual void Initialize(HWND hwnd) = 0; 
	virtual void Render() = 0; 
	//가상 함수를 통해서 RenderManager를 상속 받은 클래스에서 
	// Initialize와 Render를 구현할 수 있도록 한다. 
};

