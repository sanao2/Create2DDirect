#include "SwapChain.h"

DXGI_SWAP_CHAIN_DESC1 SwapChain::CreateSwapChain(HWND hWnd, UINT width, UINT height, int bufferCount)
{
	DXGI_SWAP_CHAIN_DESC1 scDesc = {}; 
	scDesc.Width = width; // 스왑 체인의 너비
	scDesc.Height = height; // 스왑 체인의 높이
	scDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM; // 스왑 체인의 픽셀 형식 
	scDesc.SampleDesc.Count = 1; // 멀티 샘플링을 사용하지 않음 
	scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // 렌더 타겟으로 사용 
	scDesc.BufferCount = bufferCount; // 버퍼의 개수 
	scDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD; // 버퍼를 교체하는 방식 

	return scDesc; 
}

// 파라메터의 수를 줄일 수 있는 방법은 없을까? 
// 정말 이게 최선일까? 
// get 함수를 활용해서 줄일 수 있는 방법은? 
void SwapChain::CreateSwapChainFactory(HWND hWnd,
									   ComPtr<ID3D11Device> g_d3dDevice, 
									   ComPtr<IDXGIFactory7>& dxgiFactory, 
									   DXGI_SWAP_CHAIN_DESC1& scDesc, 
									   ComPtr<IDXGISwapChain1> dxgiSwapChain)
{
	dxgiFactory->CreateSwapChainForHwnd(g_d3dDevice.Get(), hWnd, &scDesc, nullptr, nullptr, g_dxgiSwapChain.GetAddressOf());
}
