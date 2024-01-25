#pragma once

//전방 선언
class cCubePC;
class cCamera;
class cGrid;

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

public:
	void SetUp();
	void Update();
	void Render();

	void SetUp_Line();
	void Draw_Line();

	void SetUp_Triangle();
	void Draw_Triangle();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};

