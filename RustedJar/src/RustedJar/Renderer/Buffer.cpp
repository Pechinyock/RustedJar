#include "rjpch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "RustedJar/Platform/OpenGL/OpenGLBuffer.h"

namespace RustedJar {
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	RJ_CORE_ASSERT(false, "RendererAPI is none! HOW CAN I DRAW SOMETHING WITH NO API???"); return nullptr;
			case RendererAPI::API::OpenGL:	return new OpenGLVertexBuffer(vertices, size);
		}

		RJ_CORE_ASSERT(false, "Unknown rendererAPI!");
	}


	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:	RJ_CORE_ASSERT(false, "RendererAPI is none!"); return nullptr;
			case RendererAPI::API::OpenGL:	return new OpenGLIndexBuffer(indices, size);
		}

		RJ_CORE_ASSERT(false, "Unknown rendererAPI!");
	}

}