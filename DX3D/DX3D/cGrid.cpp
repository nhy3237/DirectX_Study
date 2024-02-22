#include "framework.h"
#include "cGizmo.h"
#include "cGrid.h"

cGrid::cGrid()
{
}

cGrid::~cGrid()
{
	for (auto p : m_vecGizmo)
		Safe_Delete(p);

	m_vecGizmo.clear();
}

void cGrid::Setup(int nNumHalfTile, float fInterval)
{
	// ũ�Ⱚ
	float fMax = nNumHalfTile * fInterval;
	float fMin = -nNumHalfTile * fInterval;

	// 1��°���� ����, 0��°�� �ٸ��ɷ� ǥ��
	ST_PC_VERTEX v;
	for (int i = 1; i <= nNumHalfTile; ++i)
	{
		// 5ĭ���� ��� ����, ������ ȸ������
		if (i % 5 == 0)
			v.c = D3DCOLOR_XRGB(255, 255, 255);
		else
			v.c = D3DCOLOR_XRGB(128, 128, 128);

		v.p = D3DXVECTOR3(fMin, 0.0f, i * fInterval); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0.0f, i * fInterval); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMin, 0.0f, -i * fInterval); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(fMax, 0.0f, -i * fInterval); m_vecVertex.push_back(v);

		v.p = D3DXVECTOR3(i * fInterval, 0.0f, fMin); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(i * fInterval, 0.0f, fMax); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-i * fInterval, 0.0f, fMin); m_vecVertex.push_back(v);
		v.p = D3DXVECTOR3(-i * fInterval, 0.0f, fMax); m_vecVertex.push_back(v);
	}

	// �� �࿡ ���� ���� �����ؼ� �׷��ش�
	v.c = D3DCOLOR_XRGB(255, 0, 0);	// R
	v.p = D3DXVECTOR3(fMin, 0.0f, 0.0f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(fMax, 0.0f, 0.0f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 255, 0);	// G
	v.p = D3DXVECTOR3(0.0f, fMin, 0.f); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.0f, fMax, 0.f); m_vecVertex.push_back(v);

	v.c = D3DCOLOR_XRGB(0, 0, 255);	// B
	v.p = D3DXVECTOR3(0.0f, 0.0f, fMin); m_vecVertex.push_back(v);
	v.p = D3DXVECTOR3(0.0f, 0.0f, fMax); m_vecVertex.push_back(v);

	// gizmos �׷��ֱ�
	cGizmo* pGizmo = NULL;
	D3DXMATRIXA16 matR;

	// X
	pGizmo = new cGizmo;
	D3DXMatrixRotationZ(&matR, D3DX_PI / 2.0f); // Z������ 90�� ȸ��
	pGizmo->Setup(D3DCOLOR_XRGB(255, 0, 0), matR);
	m_vecGizmo.push_back(pGizmo);

	// Y
	pGizmo = new cGizmo;
	D3DXMatrixRotationZ(&matR, D3DX_PI); // Z�� 180�� ȸ��, �ٵ� X������ 180�� �ص� ��
	pGizmo->Setup(D3DCOLOR_XRGB(0, 255, 0), matR);
	m_vecGizmo.push_back(pGizmo);

	// Z
	pGizmo = new cGizmo;
	D3DXMatrixRotationX(&matR, -D3DX_PI / 2.0f); // X������ 90�� ȸ��, Z�� X�� �ݴ�
	pGizmo->Setup(D3DCOLOR_XRGB(0, 0, 255), matR);
	m_vecGizmo.push_back(pGizmo);
}

void cGrid::Render()
{
	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST,
		m_vecVertex.size() / 2,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEX));

	for (auto p : m_vecGizmo)

		p->Render();
}
