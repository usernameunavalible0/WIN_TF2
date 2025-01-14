#pragma once
#include "C_BaseCombatCharacter.h"

class CSteamID;
class IRagdoll;
class C_BaseViewModel;
class CSoundParameters;
class CHintSystem;
struct surfacedata_t;
enum PLAYER_ANIM;

class C_BasePlayer : public C_BaseCombatCharacter, public CGameEventListener
{
public:
	virtual						~C_BasePlayer() = 0;

	virtual void				SharedSpawn() = 0;
	virtual bool				GetSteamID(CSteamID* pID) = 0;
	virtual float				GetPlayerMaxSpeed() = 0;
	virtual void				CalcView(Vector& eyeOrigin, Vector& eyeAngles, float& zNear, float& zFar, float& fov) = 0;
	virtual void				CalcViewModelView(const Vector& eyeOrigin, const Vector& eyeAngles) = 0;
	virtual float				CalcRoll(const Vector& angles, const Vector& velocity, float rollangle, float rollspeed) = 0;
	virtual void				SetPlayerUnderwater(bool state) = 0;
	virtual Vector				Weapon_ShootPosition() = 0;
	virtual void				Weapon_DropPrimary(void) = 0;
	virtual Vector				GetAutoaimVector(float flScale) = 0;
	virtual bool				CreateMove(float flInputSampleTime, CUserCmd* pCmd) = 0;
	virtual void				AvoidPhysicsProps(CUserCmd* pCmd) = 0;
	virtual void				PlayerUse(void) = 0;
	virtual bool				IsUseableEntity(C_BaseEntity* pEntity, unsigned int requiredCaps) = 0;
	virtual int					GetObserverMode() const = 0;
	virtual C_BaseEntity*		GetObserverTarget() const = 0;
	virtual IRagdoll*			GetRepresentativeRagdoll() const = 0;
	virtual void				TeamChange(int iNewTeam) = 0;
	virtual bool				IsAllowedToSwitchWeapons(void) = 0;
	virtual C_BaseCombatWeapon* GetActiveWeaponForSelection(void) = 0;
	virtual C_BaseAnimating*	GetRenderedWeaponModel() = 0;
	virtual bool				IsOverridingViewmodel(void) = 0;
	virtual int					DrawOverriddenViewmodel(C_BaseViewModel* pViewmodel, int flags) = 0;
	virtual float				GetDefaultAnimSpeed(void) = 0;
	virtual void				ThirdPersonSwitch(bool bThirdperson) = 0;
	virtual bool				CanSetSoundMixer(void) = 0;
	virtual int					GetVisionFilterFlags(bool bWeaponsCheck = false) = 0;
	virtual void				CalculateVisionUsingCurrentFlags(void) = 0;
	virtual bool				ViewModel_IsTransparent(void) = 0;
	virtual bool				ViewModel_IsUsingFBTexture(void) = 0;
	virtual void				PreThink(void) = 0;
	virtual void				PostThink(void) = 0;
	virtual void				ItemPreFrame(void) = 0;
	virtual void				ItemPostFrame(void) = 0;
	virtual void				AbortReload(void) = 0;
	virtual void				SelectLastItem(void) = 0;
	virtual void				Weapon_SetLast(C_BaseCombatWeapon* pWeapon) = 0;
	virtual bool				Weapon_ShouldSetLast(C_BaseCombatWeapon* pOldWeapon, C_BaseCombatWeapon* pNewWeapon) = 0;
	virtual bool				Weapon_ShouldSelectItem(C_BaseCombatWeapon* pWeapon) = 0;
	virtual C_BaseCombatWeapon* GetLastWeapon(void) = 0;
	virtual void 				SelectItem(const char* pstr, int iSubType = 0) = 0;
	virtual void				UpdateClientData(void) = 0;
	virtual float				GetFOV(void) = 0;
	virtual bool				IsZooming(void) = 0;
	virtual void				ViewPunch(const Vector& angleOffset) = 0;
	virtual void				OverrideView(CViewSetup* pSetup) = 0;
	virtual const Vector		GetPlayerMins(void) const = 0;
	virtual const Vector		GetPlayerMaxs(void) const = 0;
	virtual void	            SetVehicleRole(int nRole) = 0;
	virtual void			    SetAnimation(PLAYER_ANIM playerAnim) = 0;
	virtual float				GetMinFOV() const = 0;
	virtual void				PlayPlayerJingle() = 0;
	virtual void				UpdateStepSound(surfacedata_t* psurface, const Vector& vecOrigin, const Vector& vecVelocity) = 0;
	virtual void				PlayStepSound(Vector& vecOrigin, surfacedata_t* psurface, float fvol, bool force) = 0;
	virtual surfacedata_t*		GetFootstepSurface(const Vector& origin, const char* surfaceName) = 0;
	virtual void				GetStepSoundVelocities(float* velwalk, float* velrun) = 0;
	virtual void				SetStepSoundTime(int iStepSoundTime, bool bWalking) = 0; //stepsoundtimes_t
	virtual const char*			GetOverrideStepSound(const char* pszBaseStepSoundName) = 0;
	virtual void				OnEmitFootstepSound(const CSoundParameters& params, const Vector& vecOrigin, float fVolume) = 0;
	virtual void				ExitLadder() = 0;
	virtual CHintSystem*		Hints(void) = 0;
	virtual	IMaterial*			GetHeadLabelMaterial(void) = 0;
	virtual void				OnAchievementAchieved(int iAchievement) = 0;
	virtual void			    UpdateWearables() = 0;
	virtual bool			    CanUseFirstPersonCommand(void) = 0;
	virtual void				CalcObserverView(Vector& eyeOrigin, Vector& eyeAngles, float& fov) = 0;
	virtual Vector				GetChaseCamViewOffset(C_BaseEntity* target) = 0;
	virtual void				CalcInEyeCamView(Vector& eyeOrigin, Vector& eyeAngles, float& fov) = 0;
	virtual float				GetDeathCamInterpolationTime() = 0;
	virtual void				CalcDeathCamView(Vector& eyeOrigin, Vector& eyeAngles, float& fov) = 0;
	virtual void				CalcFreezeCamView(Vector& eyeOrigin, Vector& eyeAngles, float& fov) = 0;
	virtual void				SetLocalViewAngles(const Vector& viewAngles) = 0;
	virtual void				SetViewAngles(const Vector& ang) = 0;
	virtual bool				IsDucked(void) const = 0;
	virtual bool				IsDucking(void) const = 0;
	virtual float				GetFallVelocity() = 0;

public:
	NETVAR(m_iHideHUD, int, "CBasePlayer", "m_iHideHUD");
	NETVAR(m_flFOVRate, float, "CBasePlayer", "m_flFOVRate");
	NETVAR(m_bDucked, int, "CBasePlayer", "m_bDucked");
	NETVAR(m_bDucking, int, "CBasePlayer", "m_bDucking");
	NETVAR(m_bInDuckJump, int, "CBasePlayer", "m_bInDuckJump");
	NETVAR(m_flDucktime, float, "CBasePlayer", "m_flDucktime");
	NETVAR(m_flDuckJumpTime, float, "CBasePlayer", "m_flDuckJumpTime");
	NETVAR(m_flJumpTime, float, "CBasePlayer", "m_flJumpTime");
	NETVAR(m_flFallVelocity, float, "CBasePlayer", "m_flFallVelocity");
	NETVAR(m_vecPunchAngle, Vector, "CBasePlayer", "m_vecPunchAngle");
	NETVAR(m_vecPunchAngleVel, Vector, "CBasePlayer", "m_vecPunchAngleVel");
	NETVAR(m_bDrawViewmodel, int, "CBasePlayer", "m_bDrawViewmodel");
	NETVAR(m_bWearingSuit, int, "CBasePlayer", "m_bWearingSuit");
	NETVAR(m_bPoisoned, int, "CBasePlayer", "m_bPoisoned");
	NETVAR(m_bForceLocalPlayerDraw, int, "CBasePlayer", "m_bForceLocalPlayerDraw");
	NETVAR(m_flStepSize, float, "CBasePlayer", "m_flStepSize");
	NETVAR(m_bAllowAutoMovement, int, "CBasePlayer", "m_bAllowAutoMovement");
	NETVAR(m_skybox3d_scale, int, "CBasePlayer", "m_skybox3d.scale");
	NETVAR(m_skybox3d_origin, Vector, "CBasePlayer", "m_skybox3d.origin");
	NETVAR(m_skybox3d_area, int, "CBasePlayer", "m_skybox3d.area");
	NETVAR(m_skybox3d_fog_enable, int, "CBasePlayer", "m_skybox3d.fog.enable");
	NETVAR(m_skybox3d_fog_blend, int, "CBasePlayer", "m_skybox3d.fog.blend");
	NETVAR(m_skybox3d_fog_dirPrimary, Vector, "CBasePlayer", "m_skybox3d.fog.dirPrimary");
	NETVAR(m_skybox3d_fog_colorPrimary, int, "CBasePlayer", "m_skybox3d.fog.colorPrimary");
	NETVAR(m_skybox3d_fog_colorSecondary, int, "CBasePlayer", "m_skybox3d.fog.colorSecondary");
	NETVAR(m_skybox3d_fog_start, float, "CBasePlayer", "m_skybox3d.fog.start");
	NETVAR(m_skybox3d_fog_end, float, "CBasePlayer", "m_skybox3d.fog.end");
	NETVAR(m_skybox3d_fog_maxdensity, float, "CBasePlayer", "m_skybox3d.fog.maxdensity");
	NETVAR(m_PlayerFog_m_hCtrl, int, "CBasePlayer", "m_PlayerFog.m_hCtrl");
	NETVAR(m_audio_localSound_0, Vector, "CBasePlayer", "m_audio.localSound[0]");
	NETVAR(m_audio_localSound_1, Vector, "CBasePlayer", "m_audio.localSound[1]");
	NETVAR(m_audio_localSound_2, Vector, "CBasePlayer", "m_audio.localSound[2]");
	NETVAR(m_audio_localSound_3, Vector, "CBasePlayer", "m_audio.localSound[3]");
	NETVAR(m_audio_localSound_4, Vector, "CBasePlayer", "m_audio.localSound[4]");
	NETVAR(m_audio_localSound_5, Vector, "CBasePlayer", "m_audio.localSound[5]");
	NETVAR(m_audio_localSound_6, Vector, "CBasePlayer", "m_audio.localSound[6]");
	NETVAR(m_audio_localSound_7, Vector, "CBasePlayer", "m_audio.localSound[7]");
	NETVAR(m_audio_soundscapeIndex, int, "CBasePlayer", "m_audio.soundscapeIndex");
	NETVAR(m_audio_localBits, int, "CBasePlayer", "m_audio.localBits");
	NETVAR(m_audio_entIndex, int, "CBasePlayer", "m_audio.entIndex");
	NETVAR(m_szScriptOverlayMaterial, const char*, "CBasePlayer", "m_szScriptOverlayMaterial");
	NETVAR(m_vecViewOffset, Vector, "CBasePlayer", "m_vecViewOffset[0]");
	NETVAR(m_flFriction, float, "CBasePlayer", "m_flFriction");
	NETVAR(m_fOnTarget, int, "CBasePlayer", "m_fOnTarget");
	NETVAR(m_nTickBase, int, "CBasePlayer", "m_nTickBase");
	NETVAR(m_nNextThinkTick, int, "CBasePlayer", "m_nNextThinkTick");
	NETVAR(m_hLastWeapon, int, "CBasePlayer", "m_hLastWeapon");
	NETVAR(m_hGroundEntity, int, "CBasePlayer", "m_hGroundEntity");
	NETVAR(m_vecVelocity, Vector, "CBasePlayer", "m_vecVelocity[0]");
	NETVAR(m_vecBaseVelocity, Vector, "CBasePlayer", "m_vecBaseVelocity");
	NETVAR(m_hConstraintEntity, int, "CBasePlayer", "m_hConstraintEntity");
	NETVAR(m_vecConstraintCenter, Vector, "CBasePlayer", "m_vecConstraintCenter");
	NETVAR(m_flConstraintRadius, float, "CBasePlayer", "m_flConstraintRadius");
	NETVAR(m_flConstraintWidth, float, "CBasePlayer", "m_flConstraintWidth");
	NETVAR(m_flConstraintSpeedFactor, float, "CBasePlayer", "m_flConstraintSpeedFactor");
	NETVAR(m_flDeathTime, float, "CBasePlayer", "m_flDeathTime");
	NETVAR(m_nWaterLevel, int, "CBasePlayer", "m_nWaterLevel");
	NETVAR(m_flLaggedMovementValue, float, "CBasePlayer", "m_flLaggedMovementValue");
	NETVAR(lengthprop20, int, "CBasePlayer", "lengthprop20");
	NETVAR(m_iAttributeDefinitionIndex, int, "CBasePlayer", "m_iAttributeDefinitionIndex");
	NETVAR(m_iRawValue32, int, "CBasePlayer", "m_iRawValue32");
	NETVAR(m_flValue, float, "CBasePlayer", "m_flValue");
	NETVAR(m_nRefundableCurrency, int, "CBasePlayer", "m_nRefundableCurrency");
	NETVAR(deadflag, int, "CBasePlayer", "deadflag");
	NETVAR(m_iFOV, int, "CBasePlayer", "m_iFOV");
	NETVAR(m_iFOVStart, int, "CBasePlayer", "m_iFOVStart");
	NETVAR(m_flFOVTime, float, "CBasePlayer", "m_flFOVTime");
	NETVAR(m_iDefaultFOV, int, "CBasePlayer", "m_iDefaultFOV");
	NETVAR(m_hZoomOwner, int, "CBasePlayer", "m_hZoomOwner");
	NETVAR(m_hVehicle, int, "CBasePlayer", "m_hVehicle");
	NETVAR(m_hUseEntity, int, "CBasePlayer", "m_hUseEntity");
	NETVAR(m_iHealth, int, "CBasePlayer", "m_iHealth");
	NETVAR(m_lifeState, int, "CBasePlayer", "m_lifeState");
	NETVAR(m_iBonusProgress, int, "CBasePlayer", "m_iBonusProgress");
	NETVAR(m_iBonusChallenge, int, "CBasePlayer", "m_iBonusChallenge");
	NETVAR(m_flMaxspeed, float, "CBasePlayer", "m_flMaxspeed");
	NETVAR(m_fFlags, int, "CBasePlayer", "m_fFlags");
	NETVAR(m_iObserverMode, int, "CBasePlayer", "m_iObserverMode");
	NETVAR(m_hObserverTarget, int, "CBasePlayer", "m_hObserverTarget");
	NETVAR(m_hViewModel, EHANDLE, "CBasePlayer", "m_hViewModel[0]");
	NETVAR(m_szLastPlaceName, const char*, "CBasePlayer", "m_szLastPlaceName");

public:
	inline CUserCmd*& m_pCurrentCommand()
	{
		static const int nOffset = (H::NetVar.Get("CBasePlayer", "m_hConstraintEntity") - sizeof(uintptr_t));
		return *reinterpret_cast<CUserCmd**>(reinterpret_cast<DWORD_PTR>(this) + nOffset);
	}

	inline int& m_nImpulse()
	{
		static const int nOffset = H::NetVar.Get("CBasePlayer", "m_iBonusChallenge") + (IsWin64() ? 0x68 : 0x44);
		return *reinterpret_cast<int*>(reinterpret_cast<DWORD_PTR>(this) + nOffset);
	}

	inline bool UsingStandardWeaponsInVehicle()
	{
		return reinterpret_cast<bool(__thiscall*)(void*)>(U::Offsets.m_dwC_BasePlayer_UsingStandardWeaponsInVehicle)(this);
	}

	inline void UpdateButtonState(int nUserCmdButtonMask)
	{
		reinterpret_cast<void(__thiscall*)(void*, int)>(U::Offsets.m_dwC_BasePlayer_UpdateButtonState)(this, nUserCmdButtonMask);
	}
};

namespace Util
{
	inline C_BasePlayer* PlayerByIndex(const int entindex)
	{
		IClientEntity* pEntity = EntityByIndex(entindex);

		return pEntity ? pEntity->As<C_BasePlayer*>() : nullptr;
	}
}