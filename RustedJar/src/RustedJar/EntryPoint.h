#pragma once

#ifdef RJ_PLATFORM_WINDOWS
extern RustedJar::Application* RustedJar::CreateApplication();

int main(int argc, char ** argv) {
	RustedJar::Log::Init();
	LOG_RJ_INFO("Engine logger has been initialized!");
	LOG_INFO("Application logger has been initialized!");

	auto app = RustedJar::CreateApplication();
	app->Run();
	delete app;
	return 0;
}
#endif //RJ_PLATFORM_WINDOWS

