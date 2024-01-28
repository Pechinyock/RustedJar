#pragma once
#include "RustedJar/Layer.h"

#include "RustedJar/Events/KeyEvent.h"
#include "RustedJar/Events/MouseEvent.h"
#include "RustedJar/Events/ApplicationEvent.h"

namespace RustedJar {
	class RJ_API ImGuiLayer : public Layer {
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;		
		virtual void OnImGuiRender() override;

		void Begin();
		void End();

	private:
		float m_Time = 0.0f;
	};
}