#include "framework.h"
#include "cCubeMan.h"
#include "cCubeNode.h"

#include "cBody.h"
#include "cHead.h"
#include "cRightArm.h"
#include "cLeftArm.h"
#include "cRightLeg.h"
#include "cLeftLeg.h"

cCubeMan::cCubeMan()
	: m_pRoot(NULL)
{
}

cCubeMan::~cCubeMan()
{
	if (m_pRoot)
		m_pRoot->Destroy();
}

void cCubeMan::Setup()
{
	cCharacter::Setup();

	// : material
	ZeroMemory(&m_stMtl, sizeof(D3DMATERIAL9));
	m_stMtl.Ambient		= D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Diffuse		= D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	m_stMtl.Specular	= D3DXCOLOR(0.7f, 0.7f, 0.7f, 1.0f);
	
	// : body, head, arm, leg 보류

	cBody* pBody = new cBody;
	pBody->Setup();
	pBody->SetParentWorldTM(&m_matWorld);
	m_pRoot = pBody;

	cHead* pHead = new cHead;
	pHead->Setup();
	//몸통이 루트
	m_pRoot->AddChild(pHead);

	cLeftArm* pLeftArm = new cLeftArm;
	pLeftArm->Setup();
	pLeftArm->SetRotDeltaX(0.1f);
	m_pRoot->AddChild(pLeftArm);

	cRightArm* pRightArm = new cRightArm;
	pRightArm->Setup();
	pRightArm->SetRotDeltaX(-0.1f);
	m_pRoot->AddChild(pRightArm);

	cLeftLeg* pLeftLeg = new cLeftLeg;
	pLeftLeg->Setup();
	pLeftLeg->SetRotDeltaX(-0.1f);
	m_pRoot->AddChild(pLeftLeg);

	cRightLeg* pRightLeg = new cRightLeg;
	pRightLeg->Setup();
	pRightLeg->SetRotDeltaX(0.1f);
	m_pRoot->AddChild(pRightLeg);


}

void cCubeMan::Update()
{
	cCharacter::Update();
	if (m_pRoot)
	{
		m_pRoot->Update();
	}
}

void cCubeMan::Render()
{
	if (g_pD3DDevice)
	{
		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
		g_pD3DDevice->SetMaterial(&m_stMtl);

		cCharacter::Render();

		D3DXMATRIXA16 matWorld;
		D3DXMatrixIdentity(&matWorld);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

		if (m_pRoot)
			m_pRoot->Render();

		g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	}
}
