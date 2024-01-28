#pragma once
#include "RustedJar/Renderer/Buffer.h"

namespace RustedJar {
	class OpenGLVertexBuffer : public VertexBuffer {
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);

		inline virtual const BufferLayout& GetLayout() const override { return m_Layout; }
		inline virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual ~OpenGLVertexBuffer();
	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;
	};

	class OpenGLIndexBuffer : public IndexBuffer {
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual void Bind() const override;
		virtual void Unbind() const override;
		virtual uint32_t GetCount() const override { return m_Count; }
		virtual ~OpenGLIndexBuffer();
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};
}