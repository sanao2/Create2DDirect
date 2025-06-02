#pragma once
#include <windows.h>
#include <assert.h>
#include <wrl.h>  // ComPtr ����� ���� ���
#include <d3d11.h>
#pragma comment(lib, "d3d11.lib")
#include <d2d1_3.h> //ID2D1Factory8,ID2D1DeviceContext7
#pragma comment(lib, "d2d1.lib")

#include <dxgi1_6.h> // IDXGIFactory7
#pragma comment(lib, "dxgi.lib")

#include <wincodec.h>
#pragma comment(lib,"windowscodecs.lib")

using namespace Microsoft::WRL;

class SwapChain
{
private : 
	ComPtr<IDXGISwapChain1> g_dxgiSwapChain; // SwapChain�� �����ϱ� ���� DXGI ���� ü��. 
	ComPtr<IDXGIFactory7> dxgiFactory;		 // SwapChain�� �����ϱ� ���� DXGI ���丮
	static ComPtr<IDXGISurface> backBuffer;  // ����� �� ���� ���߿� �̿ܿ����� ��� �� �� �ֵ���. extern ���� ��ȯ�� ���ɼ� ����. 

public : 
	SwapChain() : g_dxgiSwapChain(nullptr), dxgiFactory(nullptr) {}
	// �ʱ�ȭ 
	~SwapChain() {

		Realease(); // �Ҹ��ڿ��� ���ҽ� ���� �Լ� ȣ�� 
		//if (g_dxgiSwapChain) {
		//	g_dxgiSwapChain.Reset(); // SwapChain ����
		//}
		//if (dxgiFactory) {
		//	dxgiFactory.Reset(); // DXGI ���丮 ����
		//}
		//if (backBuffer) {
		//	backBuffer.Reset(); // �� ���� ����
		//} 
	} 

	// SwapChin���� ���� ���� �ΰ��� ��ȯ�ϸ鼭, ������۸��� ����Ѵٴ� ��. 
	// ���° ���۸� ����� ���� ���� �ε����� �޾Ƽ�, �� �ε����� �´� ���۸� ��ȯ ���Ѽ�, 
	// �� ���۸� ����Ͽ��� ������ �� �� �ְ� �ϴ� �� ���? 
	void Initialize(); 
	void Render(HWND hwnd); 
	void Realease();  // ���ҽ� ���� �Լ� 

	// ���� �ʺ�� ����, ������ �ڵ��� �޾Ƽ� �� ������ �ڵ��� ũ�⿡ �´� ���۸� �����Ѵ�. 
	// �������� ���� ��𼭵� �ܺο����� ������ �� �ֵ��� �Ѵ�. 
	// ��� ���۸� ����� �� ���� ���� ���� ���ڵ� �޴´�. 
	static DXGI_SWAP_CHAIN_DESC1 CreateSwapChain(HWND hWnd, UINT width, UINT height, int bufferCount);
	void CreateSwapChainFactory(HWND hWnd,
								ComPtr<ID3D11Device> g_d3dDevice,
								ComPtr<IDXGIFactory7>& dxgiFactory,
								DXGI_SWAP_CHAIN_DESC1& scDesc,
								ComPtr<IDXGISwapChain1> dxgiSwapChain);
	// �� ���۸� ������ �� �ֵ��� �ϴ� ��. 
	static const ComPtr<IDXGISurface> GetBackBuffer() 
	{
		assert(backBuffer != nullptr && "BackBuffer is not initialized.");
		return backBuffer;
	}


};

