#pragma once
#include <windows.h>
#include <assert.h>
#include <wrl.h>  // ComPtr 사용을 위한 헤더
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
	ComPtr<IDXGISwapChain1> g_dxgiSwapChain; // SwapChain을 생성하기 위한 DXGI 스왑 체인. 
	ComPtr<IDXGIFactory7> dxgiFactory;		 // SwapChain을 생성하기 위한 DXGI 팩토리
	static ComPtr<IDXGISurface> backBuffer;  // 사용할 백 버퍼 나중에 이외에서도 사용 할 수 있도록. extern 으로 전환할 가능성 있음. 

public : 
	SwapChain() : g_dxgiSwapChain(nullptr), dxgiFactory(nullptr) {}
	// 초기화 
	~SwapChain() {

		Realease(); // 소멸자에서 리소스 해제 함수 호출 
		//if (g_dxgiSwapChain) {
		//	g_dxgiSwapChain.Reset(); // SwapChain 리셋
		//}
		//if (dxgiFactory) {
		//	dxgiFactory.Reset(); // DXGI 팩토리 리셋
		//}
		//if (backBuffer) {
		//	backBuffer.Reset(); // 백 버퍼 리셋
		//} 
	} 

	// SwapChin으로 만든 버퍼 두개를 순환하면서, 더블버퍼링을 사용한다는 것. 
	// 몇번째 버퍼를 사용할 지에 대한 인덱스를 받아서, 그 인덱스에 맞는 버퍼를 반환 시켜서, 
	// 그 버퍼를 사용하여서 렌더링 할 수 있게 하는 건 어떨까? 
	void Initialize(); 
	void Render(HWND hwnd); 
	void Realease();  // 리소스 해제 함수 

	// 버퍼 너비와 높이, 윈도우 핸들을 받아서 그 윈도우 핸들의 크기에 맞는 버퍼를 생성한다. 
	// 정적으로 만들어서 어디서든 외부에서든 접근할 수 있도록 한다. 
	// 몇개의 버퍼를 사용할 수 있을 지에 대한 인자도 받는다. 
	static DXGI_SWAP_CHAIN_DESC1 CreateSwapChain(HWND hWnd, UINT width, UINT height, int bufferCount);
	void CreateSwapChainFactory(HWND hWnd,
								ComPtr<ID3D11Device> g_d3dDevice,
								ComPtr<IDXGIFactory7>& dxgiFactory,
								DXGI_SWAP_CHAIN_DESC1& scDesc,
								ComPtr<IDXGISwapChain1> dxgiSwapChain);
	// 백 버퍼를 가져올 수 있도록 하는 것. 
	static const ComPtr<IDXGISurface> GetBackBuffer() 
	{
		assert(backBuffer != nullptr && "BackBuffer is not initialized.");
		return backBuffer;
	}


};

