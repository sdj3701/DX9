#pragma once

//���� ����
class cCubePC;
class cCamera;
class cGrid;
class cCubeMan;

class cMainGame
{
public:
	cMainGame();
	~cMainGame();

private:
	std::vector<ST_PC_VERTEX>	m_vecLineVertex;
	std::vector<ST_PC_VERTEX>	m_vecTriangleVertex;

	cCubePC* m_pCubePC;
	cCamera* m_pCamera;
	cGrid*	 m_pGrid;
	cCubeMan* m_pCubeMan;

	LPDIRECT3DTEXTURE9			m_pTexture;
	std::vector<ST_PT_VERTEX>	m_vecVertex;

public:
	void SetUp();
	void Update();
	void Render();

	void SetUp_Line();
	void Draw_Line();

	void SetUp_Triangle();
	void Draw_Triangle();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Setup_Light();

	void Setup_Texture();
	void Draw_Texture();

};

