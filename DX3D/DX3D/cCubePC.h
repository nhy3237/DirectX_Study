#pragma once
class cCubePC
{
public:
	cCubePC();
	~cCubePC();

private:
	float m_fRotY;
	D3DXVECTOR3 m_vDirection;
	D3DXVECTOR3 m_vPosition;
	D3DXMATRIXA16 m_matWorld;

	vector<ST_PC_VERTEX> m_vecVertex;

public:
	void Setup();
	void Update();
	void Render();

	D3DXVECTOR3& GetPosition();

};

