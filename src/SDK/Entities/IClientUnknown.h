#pragma once
#include "../Helpers/NetVarManager/NetVarManager.h"

class C_BaseEntity;
class IClientThinkable;
class ICollideable;

class IClientUnknown : public IHandleEntity
{
public:
	virtual ICollideable*		GetCollideable() = 0;
	virtual IClientNetworkable* GetClientNetworkable() = 0;
	virtual IClientRenderable*	GetClientRenderable() = 0;
	virtual IClientEntity*		GetIClientEntity() = 0;
	virtual C_BaseEntity*		GetBaseEntity() = 0;
	virtual IClientThinkable*	GetClientThinkable() = 0;
};