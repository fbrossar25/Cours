include_directories (../include)

file(
	GLOB 
	CPP_FILES_LIST
	*.cpp
)

#debug version
if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
	if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
		add_executable(main ${CPP_FILES_LIST})
		add_definitions(-D_SYSTEM_LINUX)
	elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
		add_executable(main.exe ${CPP_FILES_LIST})
		add_definitions(\D_SYSTEM_WINDOWS)
	endif()
endif()

#release version
if(${CMAKE_BUILD_TYPE} STREQUAL Release)
	if(${CMAKE_SYSTEM_NAME} STREQUAL Linux)
		add_executable(main ${CPP_FILES_LIST})
		add_definitions(-D_SYSTEM_LINUX)
	elseif(${CMAKE_SYSTEM_NAME} STREQUAL Windows)
		add_executable(main.exe ${CPP_FILES_LIST})
		add_definitions(\D_SYSTEM_WINDOWS)
	endif()
endif()