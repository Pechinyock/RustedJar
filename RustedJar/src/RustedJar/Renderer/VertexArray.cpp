#include "rjpch.h"
#include "RustedJar/Renderer/VertexArray.h"
#include "Renderer.h"
#include "RustedJar/Platform/OpenGL/OpenGLVertexArray.h"


namespace RustedJar {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	RJ_CORE_ASSERT(false, "RendererAPI is none! HOW CAN I DRAW SOMETHING WITH NO API???"); return nullptr;
			case RendererAPI::API::OpenGL:	return new OpenGLVertexArray();
		}

		RJ_CORE_ASSERT(false, "Unknown rendererAPI!");
	}
}