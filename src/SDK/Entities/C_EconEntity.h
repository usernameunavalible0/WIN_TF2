#pragma once
#include "C_BaseAnimating.h"

class CAttributeManager;
class CAttributeContainer;
class CAttributeList;
class C_BaseViewModel;
class CMaterialReference;
enum Activity;

class IHasAttributes
{
public:
	virtual CAttributeManager* GetAttributeManager(void) = 0;
	virtual CAttributeContainer* GetAttributeContainer(void) = 0;
	virtual C_BaseEntity* GetAttributeOwner(void) = 0;
	virtual CAttributeList* GetAttributeList(void) = 0;
	virtual void				 ReapplyProvision(void) = 0;
};

class C_EconEntity : public C_BaseAnimating, public IHasAttributes
{
public:
	virtual					~C_EconEntity() = 0;

	virtual bool			ShouldShowToolTip(void) = 0;
	virtual bool			OnFireEvent(C_BaseViewModel* pViewModel, const Vector& origin, const Vector& angles, int evnt, const char* options) = 0;
	virtual bool			ShouldDrawParticleSystems(void) = 0;
	virtual void			UpdateAttachmentModels(void) = 0;
	virtual bool			ViewModel_IsTransparent(void) = 0;
	virtual bool			ViewModel_IsUsingFBTexture(void) = 0;
	virtual bool			IsOverridingViewmodel(void) = 0;
	virtual int				DrawOverriddenViewmodel(C_BaseViewModel* pViewmodel, int flags) = 0;
	virtual bool			GetAttachment(const char* szName, Vector& absOrigin) = 0;
	virtual bool			GetAttachment(const char* szName, Vector& absOrigin, Vector& absAngles) = 0;
	virtual void			ViewModelAttachmentBlending(CStudioHdr* hdr, Vector pos[], Quaternion q[], float currentTime, int boneMask) = 0;
	virtual void			SetMaterialOverride(int team, const char* pszMaterial) = 0;
	virtual void			SetMaterialOverride(int team, CMaterialReference& ref) = 0;
	virtual bool			UpdateBodygroups(C_BaseCombatCharacter* pOwner, int iState) = 0;
	virtual Activity		TranslateViewmodelHandActivityInternal(Activity actBase) = 0;

public:
	NETVAR(m_hOuter, int, "CEconEntity", "m_hOuter");
	NETVAR(m_ProviderType, int, "CEconEntity", "m_ProviderType");
	NETVAR(m_iReapplyProvisionParity, int, "CEconEntity", "m_iReapplyProvisionParity");
	NETVAR(m_iItemDefinitionIndex, int, "CEconEntity", "m_iItemDefinitionIndex");
	NETVAR(m_iEntityLevel, int, "CEconEntity", "m_iEntityLevel");
	NETVAR(m_iItemIDHigh, int, "CEconEntity", "m_iItemIDHigh");
	NETVAR(m_iItemIDLow, int, "CEconEntity", "m_iItemIDLow");
	NETVAR(m_iAccountID, int, "CEconEntity", "m_iAccountID");
	NETVAR(m_iEntityQuality, int, "CEconEntity", "m_iEntityQuality");
	NETVAR(m_bInitialized, int, "CEconEntity", "m_bInitialized");
	NETVAR(m_bOnlyIterateItemViewAttributes, int, "CEconEntity", "m_bOnlyIterateItemViewAttributes");
	NETVAR(m_iAttributeDefinitionIndex, int, "CEconEntity", "m_iAttributeDefinitionIndex");
	NETVAR(m_iRawValue32, int, "CEconEntity", "m_iRawValue32");
	NETVAR(m_flValue, float, "CEconEntity", "m_flValue");
	NETVAR(m_nRefundableCurrency, int, "CEconEntity", "m_nRefundableCurrency");
};