#pragma once

#ifdef RJ_PLATFORM_WINDOWS
#ifdef RJ_DYNAMIC_LINK
	#ifdef RJ_BUILD_DLL
		#define RJ_API __declspec(dllexport)
	#else
		#define RJ_API __declspec(dllimport)
	#endif // RJ_BUILD_DLL
#else
	#define RJ_API
#endif
#else
	#error RustedJar only suport Windows!
#endif // RJ_PLATFORM_WIN

#ifdef RJ_DEBUG
	#define RJ_ENABLE_ASSERTS
#endif

#ifdef RJ_ENABLE_ASSERTS
	#define RJ_ASSERT(x, ...) {if(!(x)) {LOG_ERROR("Assertion faild: {0}", __VA_ARGS__); __debugbreak();}}
	#define RJ_CORE_ASSERT(x, ...) {if(!(x)) {LOG_RJ_ERROR("Assertion faild: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define RJ_ASSERT(x, ...)
	#define RJ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT(fn) std::bind(&fn, this, std::placeholders::_1)
