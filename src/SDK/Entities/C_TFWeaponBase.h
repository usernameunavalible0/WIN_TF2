#pragma once
#include "C_BaseCombatWeapon.h"

class C_TFPlayer;

class IHasOwner
{
public:
	virtual C_BaseEntity* GetOwnerViaInterface(void) = 0;
};

class C_TFWeaponBase : public C_BaseCombatWeapon, public IHasOwner, CGameEventListener
{
public:
	virtual						~C_TFWeaponBase() = 0;

	virtual void				FallInit(void) = 0;
	virtual int					GetWeaponID(void) const = 0;
	virtual int					GetDamageType() const = 0;
	virtual int					GetCustomDamageType() const = 0;
	virtual bool				UsesPrimaryAmmo() = 0;
	virtual float				UberChargeAmmoPerShot(void) = 0;

private:
	virtual void*				GetPlayerPoseParamList(int& nUnknown) = 0;
	virtual void*				GetItemPoseParamList(int& nUnknown) = 0;

public:
	virtual void				StartHolsterAnim(void) = 0;
	virtual void				UpdateHands(void) = 0;
	virtual bool				OwnerCanTaunt(void) = 0;
	virtual bool				CanBeCritBoosted(void) = 0;

private:
	virtual void*				GetTauntItem(void) const = 0;

public:
	virtual void				RemoveExtraWearables(void) = 0;
	virtual void				Misfire(void) = 0;
	virtual void				FireFullClipAtOnce(void) = 0;
	virtual bool				CalcIsAttackCriticalHelper() = 0;
	virtual bool				CalcIsAttackCriticalHelperNoCrits() = 0;
	virtual ETFDmgCustom		GetPenetrateType() const = 0;
	virtual void				GetProjectileFireSetup(C_TFPlayer* pPlayer, Vector vecOffset, Vector* vecSrc, Vector* angForward, bool bHitTeammates = true, float flEndDist = 2000.f) = 0;
	virtual Vector				GetSpreadAngles(void) = 0;
	virtual bool				IsFiring(void) const = 0;
	virtual bool				AreRandomCritsEnabled(void) = 0;
	virtual bool				DefaultReload(int iClipSize1, int iClipSize2, int iActivity) = 0;
	virtual bool				IsReloading() const = 0;
	virtual float				GetReloadSpeedScale(void) const = 0;
	virtual bool				CheckReloadMisfire(void) = 0;
	virtual bool				CanDrop(void) = 0;
	virtual bool				AllowTaunts(void) = 0;
	virtual float				ApplyFireDelay(float flDelay) const = 0;
	virtual int					GetActivityWeaponRole() const = 0;
	virtual int					GetViewModelWeaponRole() = 0;
	virtual bool				ShouldPlayClientReloadSound() = 0;
	virtual bool				CanAttack() = 0;
	virtual int					GetCanAttackFlags() const = 0;
	virtual void				WeaponReset(void) = 0;
	virtual void				WeaponRegenerate(void) = 0;
	virtual const char*			GetMuzzleFlashEffectName_3rd(void) = 0;
	virtual const char*			GetMuzzleFlashEffectName_1st(void) = 0;
	virtual const char*			GetMuzzleFlashModel(void) = 0;
	virtual float				GetMuzzleFlashModelLifetime(void) = 0;
	virtual const char*			GetMuzzleFlashParticleEffect(void) = 0;
	virtual void				Operator_HandleAnimEvent(void* pEvent, C_BaseCombatCharacter* pOperator) = 0; //animevent_t
	virtual const char*			GetInventoryModel(void) = 0;
	virtual float				GetSpeedMod(void) = 0;
	virtual bool				CanFireCriticalShot(bool bIsHeadshot = false) = 0; //423
	virtual bool				CanFireRandomCriticalShot(float flCritChance) = 0;
	virtual void				OnControlStunned(void) = 0;
	virtual bool				HideWhileStunned(void) = 0;
	virtual bool				IsViewModelFlipped(void) = 0;
	virtual int					GetMaxHealthMod() = 0;
	virtual float				GetLastDeployTime(void) = 0;
	virtual bool				IsEnergyWeapon(void) const = 0;
	virtual bool				IsBlastImpactWeapon(void) const = 0;
	virtual float				Energy_GetShotCost(void) const = 0;
	virtual float				Energy_GetRechargeCost(void) const = 0;
	virtual Vector				GetParticleColor(int iColor) = 0;
	virtual bool				HasLastShotCritical(void) = 0;
	virtual bool				UseServerRandomSeed(void) const = 0;
	virtual bool				IsBroken(void) const = 0;
	virtual void				SetBroken(bool bState) = 0;
	virtual void				DispatchMuzzleFlash(const char* effectName, C_BaseEntity* pAttachEnt) = 0;
	virtual bool				ShouldEjectBrass() = 0;
	virtual const char*			GetEffectLabelText() = 0;
	virtual float				GetProgress() = 0;
	virtual float				GetEffectBarProgress(void) = 0;
	virtual bool				CanPickupOtherWeapon() const = 0;
	virtual bool				ShouldRemoveInvisibilityOnPrimaryAttack() const = 0;
	virtual int					GetEffectBarAmmo(void) = 0;
	virtual float				InternalGetEffectBarRechargeTime(void) = 0;
	virtual void				CreateMuzzleFlashEffects(C_BaseEntity* pAttachEnt, int nIndex) = 0;
	virtual void				UpdateExtraWearablesVisibility() = 0;
	virtual bool				CanInspect() const = 0;

private:
	virtual void*				HookAttributes(void) = 0;
	virtual void*				OnUpgraded(void) = 0;

public:
	NETVAR(m_bLowered, int, "CTFWeaponBase", "m_bLowered");
	NETVAR(m_iReloadMode, int, "CTFWeaponBase", "m_iReloadMode");
	NETVAR(m_bResetParity, int, "CTFWeaponBase", "m_bResetParity");
	NETVAR(m_bReloadedThroughAnimEvent, int, "CTFWeaponBase", "m_bReloadedThroughAnimEvent");
	NETVAR(m_bDisguiseWeapon, int, "CTFWeaponBase", "m_bDisguiseWeapon");
	NETVAR(m_flLastCritCheckTime, float, "CTFWeaponBase", "m_flLastCritCheckTime");
	NETVAR(m_flReloadPriorNextFire, float, "CTFWeaponBase", "m_flReloadPriorNextFire");
	NETVAR(m_flLastFireTime, float, "CTFWeaponBase", "m_flLastFireTime");
	NETVAR(m_flEffectBarRegenTime, float, "CTFWeaponBase", "m_flEffectBarRegenTime");
	NETVAR(m_flObservedCritChance, float, "CTFWeaponBase", "m_flObservedCritChance");
	NETVAR(m_flEnergy, float, "CTFWeaponBase", "m_flEnergy");
	NETVAR(m_hExtraWearable, int, "CTFWeaponBase", "m_hExtraWearable");
	NETVAR(m_hExtraWearableViewModel, int, "CTFWeaponBase", "m_hExtraWearableViewModel");
	NETVAR(m_bBeingRepurposedForTaunt, int, "CTFWeaponBase", "m_bBeingRepurposedForTaunt");
	NETVAR(m_nKillComboClass, int, "CTFWeaponBase", "m_nKillComboClass");
	NETVAR(m_nKillComboCount, int, "CTFWeaponBase", "m_nKillComboCount");
	NETVAR(m_flInspectAnimEndTime, float, "CTFWeaponBase", "m_flInspectAnimEndTime");
	NETVAR(m_nInspectStage, int, "CTFWeaponBase", "m_nInspectStage");
	NETVAR(m_iConsecutiveShots, int, "CTFWeaponBase", "m_iConsecutiveShots");
};