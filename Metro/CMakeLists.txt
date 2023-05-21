 set(HEADER_FILES
	src/MetroUtil.h
	src/MetroApp.h
	src/GameWindow.h
	src/WindowImplementation.h
	src/GLFWcode/GLFWimplementation.h
	src/Renderer.h
	src/ImplRenderer.h
	src/OpenGLCode/OpenGLRenderer.h
	src/RendererTypes.h
	src/Shader.h
	src/ImplShader.h
	src/OpenGLCode/OpenGLShader.h
	src/Image.h
	src/ImplImage.h
	src/OpenGLCode/OpenGLImage.h
	src/Unit.h
	src/RendererTypes.h
	src/MetroEvents.h
	src/MetroKeys.h	
)

set(SOURCE_FILES
	src/MetroApp.cpp
	src/GameWindow.cpp
	src/GLFWcode/GLFWimplementation.cpp
	src/Shader.cpp
	src/OpenGLCode/OpenGLShader.cpp
	src/Renderer.cpp
	src/OpenGLCode/OpenGLRenderer.cpp
	src/Image.cpp
	src/OpenGLCode/OpenGLImage.cpp
	src/Unit.cpp
	src/MetroEvents.cpp	
)

add_library(Metro SHARED ${HEADER_FILES} ${SOURCE_FILES})

include_directories(src)
include_directories(../glad/include)
include_directories(../stbi)
include_directories(../glfw/include)

target_precompile_headers(Metro PRIVATE src/pch.h)

target_link_libraries(Metro glfw glad stbi)

add_definitions(-DMETRO_LIB)
add_definitions(-DMETRO_GLFW)
add_definitions(-DMETRO_OPENGL)
add_definitions(-DMETRO_WINDOWS)
add_definitions(-DMETRO_DEBUG=2)