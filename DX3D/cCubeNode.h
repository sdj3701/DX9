#pragma once
#include "cCubePNT.h"
class cCubeNode : public cCubePNT
{
public:
	cCubeNode();
	virtual ~cCubeNode();

protected:
	D3DXVECTOR3		m_vLocalPos;
	D3DXMATRIXA16	m_matLocalTM;
	D3DXMATRIXA16	m_matWorldTM;
	//머리 팔 다리는 몸통의 자식들로 할 것이다
	std::vector<cCubeNode*>		m_vecChild;
	//,변수, 자동으로 Get,Set이 생성됨
	Synthesize(D3DXMATRIXA16*, m_pParentWorldTM, ParentWorldTM);
	Synthesize(float, m_fRotDeltax, RotDeltaX);
	float m_fRotX;

public:
	virtual void AddChild(cCubeNode* pChild);
	virtual void Destroy();

	virtual void Setup() override;
	virtual void Update() override;
	virtual void Render() override;

};

