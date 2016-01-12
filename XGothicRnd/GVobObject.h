#pragma once
#include "GzObjectExtension.h"
#include "GBaseDrawable.h"

// Amount of drawables a GVobObject can cache renderinstances for
const size_t RENDERINSTANCECACHE_SIZE = 4;

class zCVob;
class zCVisual;
class GBaseDrawable;
class GVobObject : public GzObjectExtension<zCVob, GVobObject> 
{
public:
	GVobObject(zCVob* sourceObject);
	virtual ~GVobObject(void);

	/** Called when the underlaying vob moved, for example */
	void UpdateVob();

	/** Makes a new renderinstances and puts it into the given vector */
	void MakeRenderInstances(std::vector<RenderInstance>& instances);

	/** Sets the last time this was collected. Returns true if the timestamps mismatched */
	inline bool UpdateObjectCollectionState(unsigned int timestamp)
	{
		if(m_LastTimeCollected < timestamp)
		{
			m_LastTimeCollected = timestamp;
			return true;
		}

		return false;
	}

	/** Returns if this is vob was rendered before */
	inline bool VobWasRenderedBefore()
	{
		return m_LastTimeCollected != 0;
	}

	/** Returns the last known world-matrix */
	const Matrix& GetWorldMatrix() { return m_WorldMatrix; }

	/** Returns the last instance info passed to the drawables of this vob */
	const VobInstanceInfo& GetInstanceInfo() { return m_InstanceInfo; }

	/** Reaquires the list of drawables from the visual */
	void ReaquireDrawables();
protected:

	/** Updates the cache of the render-instances */
	void UpdateRenderInstanceCache();

	// Drawable of this vob
	std::vector<GBaseDrawable*> m_Drawables;

	// Caches the render-instances of the drawables
	// pair: informVisual | RenderInstance
	std::pair<bool, RenderInstance> m_RenderInstanceCache[GConstants::ERenderStage::RS_NUM_STAGES][RENDERINSTANCECACHE_SIZE];

	// Visual this object uses
	GVisual* m_Visual;

	// Instance-data of this vob
	VobInstanceInfo m_InstanceInfo;

	// World-Matrix of the current state
	Matrix m_WorldMatrix;

	// Last time this was collected in a search
	unsigned int m_LastTimeCollected;

#ifndef PUBLIC_RELEASE
	HANDLE hInvalidBreakpoint;
#endif
};

