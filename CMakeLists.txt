cmake_minimum_required (VERSION 3.31)

include($ENV{ARIEO_BUILD_ENV_PACKAGES_OUTPUT_DIR}/cmake/build_environment.cmake)

ARIEO_PACKAGE(
    Arieo-Interface-FileLoader
    CATEGORY 02_engine
    URL https://github.com/BigElderK/Arieo-Interface-FileLoader.git
    DEPENDS
        https://github.com/BigElderK/Arieo-Core.git@main
        https://github.com/BigElderK/Arieo-Interface-RHI.git@main
)

ARIEO_ENGINE_PROJECT(
    arieo_file_loader_interface

    PROJECT_TYPE interface

    DEPENDENCIES
        ARIEO_PACKAGES
            Arieo-Core
            Arieo-Interface-RHI
        INTERFACES
            Arieo-Interface-RHI::arieo_rhi_interface
            Arieo-Core::arieo_core

    SOURCES
        INTERFACE_INCLUDE_FOLDERS
            ${CMAKE_CURRENT_LIST_DIR}/public/include

    INTERFACE_CODE_GENERATION
        ROOT_NAMESPACE Arieo::Interface::FileLoader
        SCRIPT_PACKAGE_NAME arieo:file-loader

        GENERATE_ROOT_FOLDER
            $ENV{ARIEO_PACKAGES_BUILD_OUTPUT_DIR}/${ARIEO_PACKAGE_CATEGORY}/${ARIEO_PACKAGE_NAME}/${ARIEO_BUILD_CONFIGURE_PRESET}/interface

        AST_GENERATE_FOLDER
            ${GENERATE_ROOT_FOLDER}/ast
        NATIVE_CODE_GENERATE_FOLDER
            ${GENERATE_ROOT_FOLDER}/native
        WASM_WIT_GENERATE_FOLDER
            ${GENERATE_ROOT_FOLDER}/wasm/wit
        WASM_CXX_SCRIPT_GENERATE_FOLDER
            ${GENERATE_ROOT_FOLDER}/wasm/cxx
        WASM_CSHARP_SCRIPT_GENERATE_FOLDER
            ${GENERATE_ROOT_FOLDER}/wasm/csharp
        WASM_RUST_SCRIPT_GENERATE_FOLDER
            ${GENERATE_ROOT_FOLDER}/wasm/rust
)
