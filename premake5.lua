workspace "VulkanTutorial"
    configurations {"Debug", "Release"}
    platforms {"Win64"}

project "VulkanTutorial"
    kind "ConsoleApp"
    language "C++"
    targetdir "bin/%{cfg.buildcfg}"
    includedirs {
        "C:/VulkanSDK/1.2.198.1/Include",
        "lib/glm",
        "lib/glfw-3.3.6.bin.WIN64/include"
    }
    libdirs {
        "C:/VulkanSDK/1.2.198.1/Lib",
        "lib/glfw-3.3.6.bin.WIN64/lib-vc2022"
    }

    links {
        "vulkan-1",
        "glfw3"
    }

    files {"src/*.h", "src/*.cpp"}

    filter "configurations:Debug"
        defines {"DEBUG"}
        symbols "On"

    filter "configurations:Release"
        defines {"NDEBUG"}
        optimize "On"

    filter "platforms:Win64"
        system "Windows"
        architecture "x64"