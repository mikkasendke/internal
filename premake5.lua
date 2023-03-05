workspace "gta-internal"
    configurations { "Debug", "Release", "Dist" }


project "Rizeq"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    
    characterset ("MBCS")

    targetdir "bin/%{cfg.buildcfg}"

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
    language "C++"
    cppdialect "C++20"

    characterset ("MBCS")

    targetdir "bin/%{cfg.buildcfg}"

    files { "src/**.h", "src/**.cpp" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        optimize "On"
    
    filter "configurations:Dist"
        optimize "On"
