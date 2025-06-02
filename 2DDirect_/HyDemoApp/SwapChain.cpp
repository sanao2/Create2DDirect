#include "SwapChain.h"

DXGI_SWAP_CHAIN_DESC1 SwapChain::CreateSwapChain(HWND hWnd, UINT width, UINT height, int bufferCount)
{
	DXGI_SWAP_CHAIN_DESC1 scDesc = {}; 
	scDesc.Width = width; // ���� ü���� �ʺ�
	scDesc.Height = height; // ���� ü���� ����
	scDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM; // ���� ü���� �ȼ� ���� 
	scDesc.SampleDesc.Count = 1; // ��Ƽ ���ø��� ������� ���� 
	scDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT; // ���� Ÿ������ ��� 
	scDesc.BufferCount = bufferCount; // ������ ���� 
	scDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD; // ���۸� ��ü�ϴ� ��� 

	return scDesc; 
}

// �Ķ������ ���� ���� �� �ִ� ����� ������? 
// ���� �̰� �ּ��ϱ�? 
// get �Լ��� Ȱ���ؼ� ���� �� �ִ� �����? 
void SwapChain::CreateSwapChainFactory(HWND hWnd,
									   ComPtr<ID3D11Device> g_d3dDevice, 
									   ComPtr<IDXGIFactory7>& dxgiFactory, 
									   DXGI_SWAP_CHAIN_DESC1& scDesc, 
									   ComPtr<IDXGISwapChain1> dxgiSwapChain)
{
	dxgiFactory->CreateSwapChainForHwnd(g_d3dDevice.Get(), hWnd, &scDesc, nullptr, nullptr, g_dxgiSwapChain.GetAddressOf());
}
