#pragma once
#include <windows.h> 

class RenderManager
{
public : 
	virtual ~RenderManager() = default; 

	virtual void Initialize(HWND hwnd) = 0; 
	virtual void Render() = 0; 
	//���� �Լ��� ���ؼ� RenderManager�� ��� ���� Ŭ�������� 
	// Initialize�� Render�� ������ �� �ֵ��� �Ѵ�. 
};

