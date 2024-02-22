#pragma once
class cGizmo
{
private:
	vector<ST_PC_VERTEX>	m_vecVertex;
	D3DXMATRIXA16			m_matR;

public:
	cGizmo();
	~cGizmo();

public:
	void Setup(D3DCOLOR c, D3DXMATRIXA16& mat);
	void Render();
};

