workspace "RustedJar"
	architecture "x64"
	startproject "Sandbox"
	configurations{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDir = {}
IncludeDir["GLFW"] = "RustedJar/vendor/GLFW/include"
IncludeDir["Glad"] = "RustedJar/vendor/Glad/include"
IncludeDir["ImGui"] = "RustedJar/vendor/imgui"
IncludeDir["glm"] = "RustedJar/vendor/glm"

include "RustedJar/vendor/GLFW"
include "RustedJar/vendor/Glad"
include "RustedJar/vendor/ImGui"



project "RustedJar"
	location "RustedJar"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rjpch.h"
	pchsource "RustedJar/src/rjpch.cpp"

	defines{
		"_CRT_SECURE_NOWARNINGS",
	}

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines{
			"RJ_PLATFORM_WINDOWS",
			"RJ_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
		}

	filter "configurations:Debug"
		defines "RJ_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "RJ_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "RJ_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"		
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs{
		"RustedJar/vendor/spdlog/include",
		"RustedJar/src",
		"%{IncludeDir.glm}"
	}

	links{
		"RustedJar"
	}

	filter "system:windows"		
		systemversion "latest"

		defines{
			"RJ_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "RJ_DEBUG"
		symbols "on"
	
	filter "configurations:Release"
		defines "RJ_RELEASE"
		optimize "on"

	filter "configurations:Dist"
		defines "RJ_DIST"
		optimize "on"