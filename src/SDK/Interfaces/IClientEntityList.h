#pragma once
#include "CGlobalVarsBase.h"

class IClientUnknown;
class IClientEntity;

class IClientEntityList
{
public:
	virtual IClientNetworkable* GetClientNetworkable(int entnum) = 0;
	virtual IClientNetworkable* GetClientNetworkableFromHandle(CBaseHandle hEnt) = 0;
	virtual IClientUnknown* GetClientUnknownFromHandle(CBaseHandle hEnt) = 0;
	virtual IClientEntity* GetClientEntity(int entnum) = 0;
	virtual IClientEntity* GetClientEntityFromHandle(CBaseHandle hEnt) = 0;
	virtual int					NumberOfEntities(bool bIncludeNonNetworkable) = 0;
	virtual int					GetHighestEntityIndex(void) = 0;
	virtual void				SetMaxEntities(int maxents) = 0;
	virtual int					GetMaxEntities() = 0;
};

namespace I { inline IClientEntityList* ClientEntityList = nullptr; }

inline IHandleEntity* CBaseHandle::Get() const
{
	return reinterpret_cast<IHandleEntity*>(I::ClientEntityList->GetClientEntityFromHandle(m_Index));
}