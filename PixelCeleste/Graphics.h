#pragma once
#include "AdapterReader.h"
#include "Shaders.h"
#include "Vertex.h"
#include <SpriteBatch.h>
#include "SpriteFont.h"
#include "WICTextureLoader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "ConstantBufferType.h"
#include "ConstantBuffer.h"
#include "Camera.h"


class Graphics
{
public:

    Graphics() {}
    bool Initialize(HWND hwnd, int width, int height);
    void RenderFrame();
private:
    bool InitializeDirectX(HWND hwnd);
    bool InitializeShaders();
    bool InitializeScene();

    Microsoft::WRL::ComPtr<ID3D11Device> device;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;
    Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView> renderTargetView;

    VertexShader vertexShader;
    PixelShader pixelShader;

    ConstantBuffer<CB_VS_vertexshader> constantBuffer;

    VertexBuffer<Vertex> vertexBuffer;
    IndexBuffer indicesBuffer;

    Microsoft::WRL::ComPtr<ID3D11DepthStencilState> depthStencilState;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView> depthStencilView;
    Microsoft::WRL::ComPtr<ID3D11Texture2D> depthStencilBuffer;

    Microsoft::WRL::ComPtr<ID3D11RasterizerState> rasterizerState;

    std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
    std::unique_ptr<DirectX::SpriteFont> spriteFont;

    Microsoft::WRL::ComPtr<ID3D11SamplerState> samplerState;
    Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> myTexture;

    int windowWidth = 0;
    int windowHeight = 0;

public:                                                                        
    Camera camera;

};
