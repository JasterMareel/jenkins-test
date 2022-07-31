from conans import ConanFile


class TestConan(ConanFile):
    generators = "cmake"
    settings = "os", "compiler", "arch", "build_type"

    def requirements(self):
        self.requires("boost/1.78.0")
