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
set(DOXYGEN_GENERATE_HTML NO)

doxygen_add_docs(
  doxygen
  ${PROJECT_SOURCE_DIR}
)

set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile.doxygen)

add_custom_target(doc_doxygen ALL
  COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Generating API documentation with Doxygen"
  VERBATIM )


install(TARGETS test_app DESTINATION bin)

install(DIRECTORY data DESTINATION .)  
install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/rtf DESTINATION .)