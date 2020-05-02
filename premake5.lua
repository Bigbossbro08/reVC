--[[
    GTA_reversed Build Script
    Use 'premake5 --help' for help
--]]


--[[
    Options and Actions
--]]

newoption {
    trigger     = "outdir",
    value       = "path",
    description = "Output directory for the build files"
}
if not _OPTIONS["outdir"] then
    _OPTIONS["outdir"] = "Build"
end


--[[
    The Solution
--]]
solution "reVC"

    configurations { "Release", "Debug" }

    location( _OPTIONS["outdir"] )
    targetprefix "" -- no 'lib' prefix on gcc
    targetdir "Bin"
    implibdir "Bin"

    flags {
        characterset ("MBCS"), --fix strings
        staticruntime("On"),
        "NoImportLib",
        rtti ("Off"),
        "NoBufferSecurityCheck"
    }
    vpaths {
        ["Headers/*"] = {"source/**.h*",},
        ["Sources/*"] = {"source/**.c*",},
        ["*"] = {"premake5.lua", "CMakeLists.txt"}
    }
    defines {
            "NOMINMAX" 
    }
    defines {
        "_CRT_SECURE_NO_WARNINGS",
    "_SCL_SECURE_NO_WARNINGS",
    }

    includedirs {
       "source",
       "source/**"
    }
    libdirs {"source"}
    
    configuration "Debug*"
        flags { symbols ("On") }
        
    configuration "Release*"
        defines { "NDEBUG" }
    flags { symbols ("Off") }
        optimize "Full"

    configuration "vs*"
         linkoptions   { "/ignore:4099" }      
         buildoptions {"/EHsc"}
    project "reVC"
        language "C++"
        kind "SharedLib"
        targetname "reVC"
        targetextension ".asi"         
        flags { }
       
        files {
        "source/**.h*",
        "source/**.c*"
        }
        
        excludes{
        "source/**/errcom.def", --bugfix for premake5
        "source/**/errcore.def"
        }
        

