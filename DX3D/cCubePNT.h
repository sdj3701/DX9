#pragma once
class cCubePNT
{
public:
	cCubePNT();
	virtual ~cCubePNT(void);

protected:
	std::vector<ST_PNT_VERTEX> m_vecVertex;
public:
	virtual void Setup();
	virtual void Update();
	virtual void Render();

};

