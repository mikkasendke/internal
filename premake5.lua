output_template = "%{cfg.system}/%{cfg.architecture}-%{cfg.buildcfg}"

workspace "gta-internal"
    architecture ("x64")
    configurations { "Debug", "Release", "Dist" }
    startproject "Rizeq"


project "Rizeq"
    location "src/%{prj.name}"
    files { "%{prj.location}/**.h", "%{prj.location}/**.cpp" }

    kind "ConsoleApp"

    language "C++"
    cppdialect "C++20"
    
    targetdir ("bin/" .. output_template)
    objdir ("bin-intermediates/" .. output_template .. "/%{prj.name}")
    
    characterset ("MBCS")
    
    filter "configurations:Debug"
        defines { "RZ_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "RZ_RELEASE" }
        optimize "On"
    
    filter "configurations:Dist"
        optimize "On"
    
project "Injected"
    location "src/%{prj.name}"
    files { "%{prj.location}/**.h", "%{prj.location}/**.cpp" }

    kind "SharedLib"

    language "C++"
    cppdialect "C++20"

    pchheader "pch.h"
    pchsource "%{prj.location}/src/pch.cpp"

    includedirs { "%{prj.location}/src" }

    targetdir ("bin/" .. output_template)
    objdir ("bin-intermediates/" .. output_template .. "/%{prj.name}")
    
    characterset ("MBCS")

    filter "configurations:Debug"
        defines { "IJ_DEBUG" }
        symbols "On"
        
    filter "configurations:Release"
        defines { "IJ_RELEASE" }
        optimize "On"
    
    filter "configurations:Dist"
        optimize "On"
