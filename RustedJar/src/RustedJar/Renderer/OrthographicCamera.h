#pragma once
#include <glm/glm.hpp>

namespace RustedJar {
	class OrthographicCamera {
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		inline float GetRotation() const { return m_Rotation; }
		inline const glm::vec3& GetPosition() const { return m_Position; }

		inline void SetPosition(const glm::vec3& position) { m_Position = position; RecalculateViewMatrix(); }
		inline void SetRotation(float rotation) { m_Rotation = rotation; RecalculateViewMatrix(); }

		inline const glm::mat4 GetProjectionMatrix() const { return m_ProjectionMatrix; }
		inline const glm::mat4 GetViewMatrix() const { return m_ViewMatrix; }
		inline const glm::mat4 GetViewProjectionMatrix() const { return m_ViewProjectionMatrix; }

	private:
		void RecalculateViewMatrix();

	private:
		glm::mat4 m_ProjectionMatrix;
		glm::mat4 m_ViewMatrix;
		glm::mat4 m_ViewProjectionMatrix;

		glm::vec3 m_Position = { 0.f,0.f,0.f };
		float m_Rotation = 0.f;
	};
}