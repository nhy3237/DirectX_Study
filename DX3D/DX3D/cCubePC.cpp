#include "framework.h"
#include "cCubePC.h"

cCubePC::cCubePC()
	: m_vDirection(0,0,1)
	,m_vPosition(0,0,0)
	, m_fRotY(0.0f)
{
	D3DXMatrixIdentity(&m_matWorld);
}

cCubePC::~cCubePC()
{
}

void cCubePC::Setup()
{
	ST_PC_VERTEX v;

	//front
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3( 1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);

	//back
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3( 1.0F,  1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F,  1.0F, 1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3( 1.0F, -1.0F, 1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3( 1.0F,  1.0F, 1.0F); m_vecVertex.push_back(v);

	// left
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0F, -1.0F,  1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F,  1.0F,  1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F,  1.0F, -1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0F, -1.0F,  1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F,  1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);

	// right
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F,  1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F,  1.0F,  1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F,  1.0F,  1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0F, -1.0F,  1.0F); m_vecVertex.push_back(v);

	// top
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0F, 1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, 1.0F,  1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3( 1.0F, 1.0F,  1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0F,  1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3( 1.0F,  1.0F,  1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3 (1.0F,  1.0F, -1.0F); m_vecVertex.push_back(v);

	// bottom
	v.c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
	v.p = D3DXVECTOR3(-1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3( 1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3( 1.0F, -1.0F,  1.0F); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0F, -1.0F, -1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3( 1.0F, -1.0F,  1.0F); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0F, -1.0F,  1.0F); m_vecVertex.push_back(v);


}

void cCubePC::Update()
{
	float fSpeed = 0.05f;
	float fRot = 0.03;

	if (GetKeyState('A') & 0x8000)
		m_fRotY -= fRot;
	if (GetKeyState('D') & 0x8000)
		m_fRotY += fRot;
	if (GetKeyState('W') & 0x8000)
		m_vPosition += (m_vDirection * fSpeed);
	if (GetKeyState('S') & 0x8000)
		m_vPosition -= (m_vDirection * fSpeed);

	D3DXMATRIXA16 matR, matT;
	D3DXMatrixRotationY(&matR, m_fRotY);

	m_vDirection = D3DXVECTOR3(0.f, 0.f, 1.f);
	D3DXVec3TransformNormal(&m_vDirection, &m_vDirection, &matR);	// 방향벡터가 바뀜
	D3DXMatrixTranslation(&matT, m_vPosition.x, m_vPosition.y, m_vPosition.z);
	// S R T
	m_matWorld = matR * matT; // 매트릭스 변환 완료

}

void cCubePC::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEX));

}

D3DXVECTOR3& cCubePC::GetPosition()
{
	return m_vDirection;

}
