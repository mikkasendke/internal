workspace "gta-internal"
    configurations { "Debug", "Release", "Dist" }
    startproject "Rizeq"
    architecture ("x64")

project "Rizeq"
    kind "ConsoleApp"
    location "src/Rizeq"
    language "C++"
    cppdialect "C++20"
    
    characterset ("MBCS")

    targetdir "bin/%{cfg.buildcfg}"
    objdir ("bin/%{cfg.buildcfg}/intermediates")

    files { "src/**.h", "src/**.cpp" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        optimize "On"
    
    filter "configurations:Dist"
        optimize "On"

project "Injected"
    kind "SharedLib"
    location "src/Injected"
    language "C++"
    cppdialect "C++20"

    pchheader "pch.h"
    pchsource "pch.cpp"

    characterset ("MBCS")

    targetdir "bin/%{cfg.buildcfg}"
    objdir ("bin/%{cfg.buildcfg}/intermediates")

    files { "src/**.h", "src/**.cpp" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        optimize "On"
    
    filter "configurations:Dist"
        optimize "On"
