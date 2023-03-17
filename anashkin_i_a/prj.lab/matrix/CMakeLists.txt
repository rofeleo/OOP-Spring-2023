add_library(matrix matrix.cpp include/matrix/matrix.hpp)
set_property(TARGET matrix PROPERTY CXX_STANDARD 20)
target_include_directories(rational PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS matrix)