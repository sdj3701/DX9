#include "framework.h"
#include "cHead.h"

cHead::cHead()
{
}

cHead::~cHead()
{
}

void cHead::Setup()
{
	cCubeNode::Setup();

	D3DXMATRIXA16 matS, matT, mat;
	D3DXMatrixScaling(&matS, 0.4f, 0.4f, 0.4f);
	//��ǥ�� �ٲٴ� ��
	D3DXMatrixTranslation(&matT, 0.0f, 0.0f, 0.0f);
	mat = matS * matT;

	for (size_t i = 0; i < m_vecVertex.size(); ++i)
	{
		D3DXVec3TransformCoord(&m_vecVertex[i].p, &m_vecVertex[i].p, &mat);
	}
	//������ �ٲٴ� ��
	m_vLocalPos.y = 0.5f;
}
