cmake_minimum_required(VERSION 3.0)

project(ProjectTemplate VERSION 1.0) # set the project name

# configure_file(ProjectTemplateConfig.h.in ProjectTemplateConfig.h)

# target_include_directories(ProjectTemplate PUBLIC
#                            "${PROJECT_BINARY_DIR}"
#                            )

include_directories()

# include files
include_directories( ./include ./src)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
find_package( OpenCV REQUIRED )
set(CMAKE_MODULE_PATH "/usr/share/SFML/cmake/Modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.4 REQUIRED system window graphics audio)

include_directories(${SFML_INCLUDE_DIR}
                    ${EIGEN_INCLUDE_DIR}
                    ${OpenCV_INCLUDE_DIRS}
)

# add the executable
add_executable("${PROJECT_NAME}" ./src/main.cpp) 

target_link_libraries("${PROJECT_NAME}"
    sfml-system
    sfml-window
    sfml-graphics 
    sfml-audio
    # sfml-network
    # imgui
    # imgui-sfml
    Eigen3::Eigen
    ${OpenCV_LIBS}
    )

# add_dependencies("${PROJECT_NAME}"
#     imgui
#     imgui-sfml
# )

# install(TARGETS "${PROJECT_NAME}" DESTINATION bin) #${CMAKE_INSTALL_PREFIX}/bin 
# install(FILES "main.cpp" DESTINATION src)           #${CMAKE_INSTALL_PREFIX}/bin 