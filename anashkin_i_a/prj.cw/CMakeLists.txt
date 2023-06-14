find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS program_options REQUIRED)
find_package(Doxygen)

add_executable(test_app "main.cpp")

add_subdirectory("lib")

target_link_libraries(test_app PRIVATE color_transfer Boost::program_options)

set(DOXYGEN_RECURSIVE YES)
set(DOXYGEN_EXCLUDE_PATTERNS "*/_deps/*")
set(DOXYGEN_GENERATE_RTF YES)
set(DOXYGEN_OUTPUT_LANGUAGE "Russian")

doxygen_add_docs(
  doxygen
  ${PROJECT_SOURCE_DIR}
)

install(TARGETS test_app DESTINATION bin)
install(DIRECTORY pictures DESTINATION data)  
