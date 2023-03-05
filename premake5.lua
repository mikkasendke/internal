workspace "gta-internal"
    architecture ("x64")
    configurations { "Debug", "Release", "Dist" }
    startproject "Rizeq"

    
project "Rizeq"
    location "src/Rizeq"
    files { "%{prj.location}/**.h", "%{prj.location}/**.cpp" }

    kind "ConsoleApp"

    language "C++"
    cppdialect "C++20"
    
    targetdir "bin/%{cfg.buildcfg}"
    objdir ("bin/%{cfg.buildcfg}/intermediates")
    
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
    location "src/Injected"
    files { "%{prj.location}/**.h", "%{prj.location}/**.cpp" }

    kind "SharedLib"

    language "C++"
    cppdialect "C++20"

    pchheader "pch.h"
    pchsource "%{prj.location}/pch.cpp"

    targetdir "bin/%{cfg.buildcfg}"
    objdir ("bin/%{cfg.buildcfg}/intermediates")
    
    characterset ("MBCS")

    filter "configurations:Debug"
        defines { "IJ_DEBUG" }
        symbols "On"
        
    filter "configurations:Release"
        defines { "IJ_RELEASE" }
        optimize "On"
    
    filter "configurations:Dist"
        optimize "On"
