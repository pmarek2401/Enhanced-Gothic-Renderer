#pragma once
#include <RBufferCollection.h>

/** 
 * Generic indexed mesh structure.
 * V: Vertex-Type, I: Index-Type
 */
class GMeshIndexed
{
public:
	GMeshIndexed(RAPI::RBuffer* meshVertexBuffer, 
				 RAPI::RBuffer* meshIndexBuffer,
				 unsigned int numIndices,
				 unsigned int meshVertexStart,
				 unsigned int meshIndexStart);

	
	GMeshIndexed(void){}
	~GMeshIndexed(void);

	/**
	 * Getters
	 */
	RAPI::RBuffer* GetMeshVertexBuffer()const{return m_MeshVertexBuffer;} 
	RAPI::RBuffer* GetMeshIndexBuffer()const{return m_MeshIndexBuffer;}
	unsigned int GetMeshVertexStart()const{return m_MeshVertexStart;}
	unsigned int GetMeshIndexStart()const{return m_MeshIndexStart;}
	unsigned int  GetNumIndices()const{return m_NumIndices;}

	/**
	 * Setters
	 */
	void SetMeshVertexBuffer(RAPI::RBuffer* buffer){m_MeshVertexBuffer = buffer;}
	void SetMeshIndexBuffer(RAPI::RBuffer* buffer){m_MeshIndexBuffer = buffer;}
	void SetMeshVertexStart(unsigned int meshVertexStart){m_MeshVertexStart = meshVertexStart;}
	void SetMeshIndexStart(unsigned int meshIndexStart){m_MeshIndexStart = meshIndexStart;}
	void SetNumIndices(unsigned int numIndices){m_NumIndices = numIndices;}
private:
	RAPI::RBuffer* m_MeshVertexBuffer;
	RAPI::RBuffer* m_MeshIndexBuffer;
	unsigned int m_MeshVertexStart;
	unsigned int m_MeshIndexStart;
	unsigned int m_NumIndices;
};

