#pragma once

namespace RustedJar {
	class Timestep {
	public:
		Timestep(float time = 0.f)
			: m_Time(time)
		{}

		inline float GetTime() const { return m_Time; }
		inline float GetMiliseconds() const { return m_Time * 1000.f; }

		operator float() const { return m_Time; }

	private:
		float m_Time;
	};
}