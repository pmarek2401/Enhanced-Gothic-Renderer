#pragma once
#include "zDefinitions.h"
#include "zCArray.h"
#include <vector>
#include "zCPolygon.h"

struct zCBspNode;
struct zCBspLeaf;
struct zCBspBase;
class zCMesh;
class zCPolygon;
class zCVob;
class zCVobLight;
class zCBspSector;


struct zCBspBase
{
	zCBspNode* m_Parent;
	zTBBox3D m_BBox3D;							
	zCPolygon** m_PolyList;
	unsigned int m_NumPolys;						
	zTBspNodeType m_NodeType;
};

struct zCBspLeaf : public zCBspBase
{
	int LastTimeLighted;
	zCArray<zCVob*>	LeafVobList;
	zCArray<zCVobLight*> LightVobList;
};

struct zCBspNode : public zCBspBase
{
	/** Returns only the polygons used in LOD0 of the world */
	void GetLOD0Polygons(std::vector<zCPolygon *>& target)
	{
		for(int i=0;i<m_NumLeafs;i++)
		{
			zCBspLeaf* leaf = &m_LeafList[i];

			for(unsigned int j=0;j<leaf->m_NumPolys;j++)
			{
				target.push_back(leaf->m_PolyList[j]);
			}
		}
	}

	Plane	m_Plane;
	zCBspBase* m_Front;			
	zCBspBase* m_Back;		
	zCBspLeaf* m_LeafList;
	int m_NumLeafs;
	char m_PlaneSignbits;
};




class zCBspTree
{
public:
	/** Returns only the polygons used in LOD0 of the world */
	void GetLOD0Polygons(std::vector<zCPolygon *>& target)
	{
		for(int i=0;i<m_NumLeafs;i++)
		{
			zCBspLeaf* leaf = &m_LeafList[i];

			for(unsigned int j=0;j<leaf->m_NumPolys;j++)
			{
				target.push_back(leaf->m_PolyList[j]);
			}
		}
	}

	/** Returns the root-node of this tree */
	zCBspBase* GetRootNode()
	{
		return m_BSPRoot;
	}

	/** Returns how many nodes this tree contains. This also contains leafs. */
	unsigned int GetNumNodes()
	{
		return m_NumNodes;
	}

private:
	zCBspNode* m_ActiveNodePtr;
	zCBspLeaf* m_ActiveLeafPtr;
	zCBspBase* m_BSPRoot;
	zCMesh* m_Mesh;
	zCPolygon** m_TreePolyList;
	zCBspNode* m_NodeList;				
	zCBspLeaf* m_LeafList;				
	int	m_NumNodes;				
	int	m_NumLeafs;				
	int	m_NumPolys;				
	zCArray<zCVob*>	m_RenderVobList;
	zCArray<zCVobLight*> m_RenderLightList;
	zCArray<zCBspSector*> m_SectorList;
	zCArray<zCPolygon*>	m_PortalList;
	zTBspTreeMode m_BspTreeMode;
	zTWld_RenderMode m_WorldRenderMode;
	float m_VobFarClipZ;
	zTPlane	m_VobFarPlane;
	int	m_VobFarPlaneSignbits;		
	zBOOL m_DrawVobBBox3D;	
	int	m_LeafsRendered;
	int	m_VobsRendered;
};

