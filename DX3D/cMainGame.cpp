#include "framework.h"
#include "cMainGame.h"
#include "cCubePC.h"
#include "cCamera.h"
#include "cGrid.h"

cMainGame::cMainGame()
	: m_pCubePC(NULL), m_pCamera(NULL) , m_pGrid(NULL)
{
	srand(time(0));
}

cMainGame::~cMainGame()
{
	Safe_Delete(m_pCubePC);
	Safe_Delete(m_pCamera);
	Safe_Delete(m_pGrid);

	g_pDeviceManager->Destroy();
}

void cMainGame::SetUp()
{
	//SetUp_Line();
	//SetUp_Triangle();

	m_pCubePC = new cCubePC;
	m_pCubePC->Setup();

	m_pCamera = new cCamera;
	m_pCamera->Setup(&m_pCubePC->GetPosition());

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	//조명을 사용하지 않겠다.
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
}

void cMainGame::Update()
{

	if (m_pCubePC)
		m_pCubePC->Update();

	if (m_pCamera)
		m_pCamera->Update();


}

void cMainGame::Render()
{
	//배경 색깔
	g_pD3DDevice->Clear(NULL, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	g_pD3DDevice->BeginScene();

	//Draw_Line();
	//Draw_Triangle();

	if (m_pGrid)
		m_pGrid->Render();

	if (m_pCubePC)
		m_pCubePC->Render();

	g_pD3DDevice->EndScene();

	//설정할 것이 없으니 NULL
	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

void cMainGame::SetUp_Line()
{
	ST_PC_VERTEX	v;
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(0, 2, 0); m_vecLineVertex.push_back(v);
	v.p = D3DXVECTOR3(0, -2, 0); m_vecLineVertex.push_back(v);
}

void cMainGame::Draw_Line()
{
	D3DXMATRIXA16	matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	//이 단위로 짤라라
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST, m_vecLineVertex.size() / 2, &m_vecLineVertex[0], sizeof(ST_PC_VERTEX));
}

void cMainGame::SetUp_Triangle()
{
	ST_PC_VERTEX	v;
	v.c = D3DCOLOR_XRGB(255, 0, 0);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 0.0f); m_vecTriangleVertex.push_back(v);
	v.c = D3DCOLOR_XRGB(0, 255, 0);
	v.p = D3DXVECTOR3(-1.0f, 1.0f, 0.0f); m_vecTriangleVertex.push_back(v);
	v.c = D3DCOLOR_XRGB(0, 0, 255);
	v.p = D3DXVECTOR3(1.0f, 1.0f, 0.0f); m_vecTriangleVertex.push_back(v);
}

void cMainGame::Draw_Triangle()
{
	D3DXMATRIXA16	matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	//이 단위로 짤라라
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	//시계방향으로 상정해서 그림
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, m_vecTriangleVertex.size() / 3, &m_vecTriangleVertex[0], sizeof(ST_PC_VERTEX));
}

void cMainGame::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCamera)
		m_pCamera->WndProc(hWnd, message, wParam, lParam);
}
