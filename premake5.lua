workspace "gta-internal"
    configurations { "Debug", "Release", "Dist" }
    startproject "Rizeq"

    project "Rizeq"
        kind "ConsoleApp"
        architecture ("x64")
        location "src/Rizeq"
        language "C++"
        cppdialect "C++20"
        
        characterset ("MBCS")
    
        targetdir "bin/%{cfg.buildcfg}"
        objdir ("bin/%{cfg.buildcfg}/intermediates")
    
        files { "%{prj.location}/**.h", "%{prj.location}/**.cpp" }
    
        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"
    
        filter "configurations:Release"
            optimize "On"
        
        filter "configurations:Dist"
            optimize "On"
    
    project "Injected"
        kind "SharedLib"
        architecture ("x64")
        location "src/Injected"
        language "C++"
        cppdialect "C++20"
    
        pchheader "pch.h"
        pchsource "%{prj.location}/pch.cpp"
    
        characterset ("MBCS")
    
        targetdir "bin/%{cfg.buildcfg}"
        objdir ("bin/%{cfg.buildcfg}/intermediates")
    
        files { "%{prj.location}/**.h", "%{prj.location}/**.cpp" }
    
        filter "configurations:Debug"
            defines { "DEBUG" }
            symbols "On"
    
        filter "configurations:Release"
            optimize "On"
        
        filter "configurations:Dist"
            optimize "On"
    