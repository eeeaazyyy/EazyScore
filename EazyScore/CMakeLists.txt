# CMakeList.txt: проект CMake для EazyScore; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_PREFIX_PATH "C:/Qt/6.6.0/msvc2019_64")
set(QT_PLUGINS_DIR "C:/Qt/6.6.0/msvc2019_64/plugins")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)




# Добавьте источник в исполняемый файл этого проекта.
add_executable (EazyScore "EazyScore.cpp"  "ESApp.h" "ESApp.cpp" "resource.qrc" "ESTableWidget.cpp")

find_package(Qt6 REQUIRED COMPONENTS Widgets)
target_link_libraries(EazyScore PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets)

add_custom_command(TARGET EazyScore POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${QT_PLUGINS_DIR}/platforms
                   $<TARGET_FILE_DIR:EazyScore>/platforms)
add_custom_command(TARGET EazyScore POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   $<TARGET_FILE:Qt6::Core> $<TARGET_FILE_DIR:EazyScore>)
add_custom_command(TARGET EazyScore POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   $<TARGET_FILE:Qt6::Gui> $<TARGET_FILE_DIR:EazyScore>)
add_custom_command(TARGET EazyScore POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_if_different
                   $<TARGET_FILE:Qt6::Widgets> $<TARGET_FILE_DIR:EazyScore>)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET EazyScore PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
