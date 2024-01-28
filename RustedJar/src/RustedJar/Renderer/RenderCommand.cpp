#include "rjpch.h"
#include "RenderCommand.h"
#include "RustedJar/Platform/OpenGL/OpenGLRendererAPI.h"
namespace RustedJar {
	RendererAPI* RenderCommand::m_RendererAPI = new OpenGLRendererAPI();
}