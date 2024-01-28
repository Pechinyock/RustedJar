#pragma once
#include "Core.h"
#include "Events/Event.h"
#include "LayerStack.h"
#include "Window.h"
#include "RustedJar/Core/Timestep.h"

#include <ImGui/ImGuiLayer.h>

namespace RustedJar {
	class RJ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
		bool OnCloseWindowEvent(class WindowCloseEvent& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);		
		inline static Application& Get() { return *s_Instance; }
		inline Window& GetWindow() { return *m_Window; }

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;

		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.f;

	private:
		static Application* s_Instance;

	};

	Application* CreateApplication();
}


