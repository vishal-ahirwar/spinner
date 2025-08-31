from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
class MyProjectConan(ConanFile):
    name = "spinner"
    version = "0.1.0"
    settings = "os", "compiler", "build_type", "arch"

    def requirements(self):
        self.requires("fmt/11.2.0")

    # Optional metadata
    license = "<Put the package license here>"
    author = "<Put your name here> <And your email here>"
    url = "<Package recipe repository url here, for issues about the package>"
    description = "<Description of hello package here>"
    topics = ("<Put some tag here>", "<here>", "<and here>")

    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "config/*", "spinner/*"

    def generate(self):
        # Generate dependencies
        deps = CMakeDeps(self)
        deps.generate()

        # Generate toolchain
        tc = CMakeToolchain(self)

        # Map your presets to Conan variables
        if self.settings.os == "Windows":
            # clang-msvc equivalent
            tc.variables["CMAKE_CXX_COMPILER"] = "clang-cl"
            tc.variables["CMAKE_C_COMPILER"] = "clang-cl"
            tc.variables["BUILD_SHARED_LIBS"] = False
            tc.variables["CRT_STATIC_LINK"] = False
            tc.variables["CMAKE_BUILD_TYPE"] = str(self.settings.build_type)
        else:
            # clang-posix equivalent
            tc.variables["CMAKE_CXX_COMPILER"] = "clang++"
            tc.variables["CMAKE_C_COMPILER"] = "clang"
            tc.variables["BUILD_SHARED_LIBS"] = False
            tc.variables["CRT_STATIC_LINK"] = False
            tc.variables["CMAKE_BUILD_TYPE"] = str(self.settings.build_type)

        tc.generate()
    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def layout(self):
        cmake_layout(self)


    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["spinner"]