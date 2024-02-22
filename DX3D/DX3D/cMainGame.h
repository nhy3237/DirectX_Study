#pragma once

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
	LPDIRECT3D9			m_pD3D;
	LPDIRECT3DDEVICE9	m_pD3DDevice;

	vector<ST_PC_VERTEX> m_vecLineVertex;
	vector<ST_PC_VERTEX> m_vecTriangleVertex;
	
	//cCubePC* m_pCubePC;
	cCubeMan* m_pCubeMan;
	cCamera* m_pCamera;
	cGrid* m_pGrid;

	LPDIRECT3DTEXTURE9 m_pTexture;
	vector<ST_PT_VERTEX> m_vecVertex;

public:
	void Setup();
	void Update();
	void Render();

	void Setup_Line();
	void Draw_Line();
	void Setup_Triangle();
	void Draw_Triangle();

	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void Setup_Light();

	void Setup_Texture();
	void Draw_Texture();
};

