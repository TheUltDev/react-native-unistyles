#
# unistyles+autolinking.cmake
# This file was generated by nitrogen. DO NOT MODIFY THIS FILE.
# https://github.com/mrousavy/nitro
# Copyright © 2024 Marc Rousavy @ Margelo
#

# This is a CMake file that adds all files generated by Nitrogen
# to the current CMake project.
#
# To use it, add this to your CMakeLists.txt:
# ```cmake
# include(${CMAKE_SOURCE_DIR}/../nitrogen/generated/android/unistyles+autolinking.cmake)
# ```

# Add all headers that were generated by Nitrogen
include_directories(
  "../nitrogen/generated/shared/c++"
  "../nitrogen/generated/android/c++"
  "../nitrogen/generated/android/"
)

# Add all .cpp sources that were generated by Nitrogen
target_sources(
  # CMake project name (Android C++ library name)
  unistyles PRIVATE
  # Autolinking Setup
  ../nitrogen/generated/android/unistylesOnLoad.cpp
  # Shared Nitrogen C++ sources
  ../nitrogen/generated/shared/c++/HybridNativePlatformSpec.cpp
  ../nitrogen/generated/shared/c++/HybridUnistylesNavigationBarSpec.cpp
  ../nitrogen/generated/shared/c++/HybridUnistylesShadowRegistrySpec.cpp
  ../nitrogen/generated/shared/c++/HybridUnistylesStatusBarSpec.cpp
  ../nitrogen/generated/shared/c++/HybridUnistylesStyleSheetSpec.cpp
  ../nitrogen/generated/shared/c++/HybridUnistylesRuntimeSpec.cpp
  # Android-specific Nitrogen C++ sources
  ../nitrogen/generated/android/c++/JHybridNativePlatformSpec.cpp
)

# Add all libraries required by the generated specs
find_package(fbjni REQUIRED) # <-- Used for communication between Java <-> C++
find_package(ReactAndroid REQUIRED) # <-- Used to set up React Native bindings (e.g. CallInvoker/TurboModule)
find_package(react-native-nitro-modules REQUIRED) # <-- Used to create all HybridObjects and use the Nitro core library

# Link all libraries together
target_link_libraries(
        unistyles
        fbjni::fbjni                              # <-- Facebook C++ JNI helpers
        ReactAndroid::jsi                         # <-- RN: JSI
        react-native-nitro-modules::NitroModules  # <-- NitroModules Core :)
)

# Link react-native (different prefab between RN 0.75 and RN 0.76)
if(ReactAndroid_VERSION_MINOR GREATER_EQUAL 76)
    target_link_libraries(
        unistyles
        ReactAndroid::reactnative                 # <-- RN: Native Modules umbrella prefab
    )
else()
    target_link_libraries(
        unistyles
        ReactAndroid::react_nativemodule_core     # <-- RN: TurboModules Core
    )
endif()
