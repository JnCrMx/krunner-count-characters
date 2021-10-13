cmake_minimum_required(VERSION 3.21)
project(RunnerCountCharacters)

set(CMAKE_PROJECT_VERSION  "1.0.0")
set(CMAKE_PROJECT_AUTHOR "JCM")
set(CMAKE_PROJECT_AUTHOR_EMAIL "jacama2009@gmail.com")
set(CMAKE_PROJECT_HOMEPAGE_URL "github.com/JnCrMx/krunner-count-characters")

find_package(ECM 5.12.0 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} ${CMAKE_MODULE_PATH})

find_package(Qt5 ${QT_MIN_VERSION} REQUIRED CONFIG COMPONENTS Widgets Core Quick)
find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS I18n Service Runner TextWidgets PlasmaQuick)

set(CPACK_PACKAGE_NAME "krunner-count-characters")
set(CPACK_PACKAGE_VENDOR "${CMAKE_PROJECT_AUTHOR}")
set(CPACK_PACKAGE_CONTACT "${CMAKE_PROJECT_AUTHOR_EMAIL}")
set(CPACK_PACKAGE_VERSION "${CMAKE_PROJECT_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_WELCOME "${CMAKE_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "Plugin for Plasma 5 krunner to count the number of characters in a string")
set(CPACK_VERBATIM_VARIABLES true)

set(CPACK_GENERATOR "TGZ")

include(CPack)
include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings NO_POLICY_SCOPE)

set(SRCS count.cpp)
add_library(krunner_count_characters MODULE ${SRCS})
target_link_libraries(krunner_count_characters KF5::Runner Qt5::Widgets KF5::I18n KF5::Service KF5::Plasma)

configure_file(count.json.in count.json)

install(TARGETS krunner_count_characters DESTINATION ${KDE_INSTALL_QTPLUGINDIR}/kf5/krunner/)
