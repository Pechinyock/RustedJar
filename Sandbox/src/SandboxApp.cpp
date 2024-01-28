#include <RustedJar.h>
#include <glm/ext/matrix_transform.hpp>

class ExampleLayer : public RustedJar::Layer {
public:
	ExampleLayer()
		: Layer("Example layer"), m_Camera(-1.f, 1.f, -1.f, 1.f), m_CameraPosition(0.f)
	{
		m_VertexArray.reset(RustedJar::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 1.f, 0.f, 1.f, 1.f,
			 0.5f, -0.5f, 0.0f, 0.f, 0.f, 1.f, 1.f,
			 0.0f,  0.5f, 0.0f, 1.f, 1.f, 0.f, 1.f,
		};
		std::shared_ptr<RustedJar::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(RustedJar::VertexBuffer::Create(vertices, sizeof(vertices)));

		RustedJar::BufferLayout layout = {
			{ RustedJar::ShaderDataType::Float3, "a_Position" },
			{ RustedJar::ShaderDataType::Float4, "a_Color" }
		};

		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };

		std::shared_ptr<RustedJar::IndexBuffer> indexBuffer;
		indexBuffer.reset(RustedJar::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);


		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;			

			void main()
			{				
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
			
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;		

			uniform vec4 u_Color;							

			void main(){
				color = u_Color;				
			}
			
		)";		
		m_FlatColorShader.reset(new RustedJar::Shader(vertexSrc, fragmentSrc));		
	}


	void OnUpdate(RustedJar::Timestep timestep) override {

		RustedJar::RenderCommand::SetClearColor(glm::vec4(0.1f, .1f, .1f, 1.f));
		RustedJar::RenderCommand::Clear();

		if (RustedJar::Input::IsKeyPressed(RJ_KEY_LEFT)) {
			m_CameraPosition.x -= m_CameraSpeed * timestep;
		}
		if (RustedJar::Input::IsKeyPressed(RJ_KEY_RIGHT)) {
			m_CameraPosition.x += m_CameraSpeed * timestep;
		}
		if (RustedJar::Input::IsKeyPressed(RJ_KEY_UP)) {
			m_CameraPosition.y += m_CameraSpeed * timestep;
		}
		if (RustedJar::Input::IsKeyPressed(RJ_KEY_DOWN)) {
			m_CameraPosition.y -= m_CameraSpeed * timestep;
		}

		if (RustedJar::Input::IsKeyPressed(RJ_KEY_A)) {
			m_CameraRotation += m_CameraRotationSpeed * timestep;
		}
		if (RustedJar::Input::IsKeyPressed(RJ_KEY_D)) {
			m_CameraRotation -= m_CameraRotationSpeed * timestep;
		}

		m_Camera.SetRotation(m_CameraRotation);
		m_Camera.SetPosition(m_CameraPosition);
		RustedJar::Renderer::BeginScene(m_Camera);
				
		m_FlatColorShader->UploadUniformFloat4("u_Color", glm::vec4(.8f, .3f, .2f, 1.f));
		RustedJar::Renderer::Submit(m_FlatColorShader, m_VertexArray);
		RustedJar::Renderer::EndScene();
	}

	void OnEvent(RustedJar::Event& event) {
		
	}

private:
	std::shared_ptr<RustedJar::Shader> m_FlatColorShader;
	std::shared_ptr<RustedJar::VertexArray> m_VertexArray;

	RustedJar::OrthographicCamera m_Camera;
	float m_CameraSpeed = 0.1f;
	glm::vec3 m_CameraPosition;

	float m_CameraRotation = 0.f;
	float m_CameraRotationSpeed = 2.f;
};

class Sandbox : public RustedJar::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
};

RustedJar::Application* RustedJar::CreateApplication() {
	return new Sandbox();
}