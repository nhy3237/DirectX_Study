#include "framework.h"
#include "cGizmo.h"

cGizmo::cGizmo()
{
	D3DXMatrixIdentity(&m_matR);	// 행렬 변환
}

cGizmo::~cGizmo()
{
}

void cGizmo::Setup(D3DCOLOR c, D3DXMATRIXA16& mat)
{
	m_matR = mat;
	ST_PC_VERTEX v;
	v.c = c;

	// : front
	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	// : right
	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);

	// : back
	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);

	// : left
	v.p = D3DXVECTOR3(0.0f, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);

	// : bottom
	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);

	v.p = D3DXVECTOR3(-1.0f, -1.0f, -1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(-1.0f, -1.0f, 1.0f); m_vecVertex.push_back(v);
}

void cGizmo::Render()
{
	// 렌더링마다 설정하지 말고 미리 설정해놓는것이 좋음
	D3DXMATRIXA16 matWorld, matS;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixScaling(&matS, 0.1f, 2.0f, 0.1f);		// 뾰족한 점 모양의 표시선이 생길것

	matWorld = matS * m_matR;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEX));
}
