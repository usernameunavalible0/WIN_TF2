#pragma once

template <class T>
class CVar
{
public:
	CVar(const T Var, const char* const szDisplayName)
	{
		m_Var = Var;
		m_szDisplayName = szDisplayName;
	}

	CVar(const T Var, const T Step, const T Min, const T Max, const char* const szDisplayName)
	{
		m_Var = Var;
		m_Step = Step;
		m_Min = Min;
		m_Max = Max;
		m_szDisplayName = szDisplayName;
	}

public:
	inline T Get() const
	{
		return m_Var;
	}

	inline void Set(const T Var)
	{
		m_Var = Var;
	}

	inline const char* GetName() const
	{
		return m_szDisplayName;
	}

	inline T GetStep() const
	{
		return m_Step;
	}

	inline T GetMin() const
	{
		return m_Min;
	}

	inline T GetMax() const
	{
		return m_Max;
	}

private:
	T m_Var;
	T m_Min;
	T m_Max;
	T m_Step;

	const char* m_szDisplayName;
};

namespace Vars
{
	void Save();
	void Load();

	namespace ESP
	{
		inline CVar<bool> Enabled{ true, "Enabled" };

		namespace Players
		{
			inline CVar<bool> Enabled{ true, "Enabled" };
			inline CVar<bool> Name{ true, "Name" };
			inline CVar<bool> Class{ true, "Class" };
			inline CVar<bool> HealthBar{ true, "Health Bar" };
		}

		namespace Buildings
		{
			inline CVar<bool> Enabled{ true, "Enabled" };
			inline CVar<bool> Type{ true, "Type" };
			inline CVar<bool> HealthBar{ true, "Health Bar" };
		}
	}

	namespace Misc
	{
		inline CVar<bool> Bunnyhop{ true, "Bunnyhop" };
		inline CVar<bool> PureBypass{ true, "Bypass sv_pure" };
		inline CVar<bool> AvoidPushaway{ true, "Avoid Pushaway" };
	}
}