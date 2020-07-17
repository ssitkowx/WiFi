# Template

# I. Description:
Template for projects and packages.

# II. Assumption:
The code stored here is a generic code, which means:
- The code should be dependent only on C/C++ language libraries,
- The code should work in various environments (Linux, Windows, Embedded) and be independent of them,
- The code can use only generic external libraries.

# III. Structure:
The solution project has been divided into three parts:
- Project,
- Project library,
- Tests which uses the project, gtest and/or gmock libraries.

# IV. Configuration:
- Python 2.7.16 with required packages,
- Git 2.23.0.widnows.1,
- CMake 3.17.0-rc2,
- Visual Studio 2019,
- GTest and GMock tooked from https://bintray.com/bincrafters/public-conan/gtest%3Abincrafters/1.8.1%3Astable#
- Remotes should be updated with 'conan remote add bincrafters https://api.bintray.com/conan/bincrafters/public-conan'
- Conanfile.py should be updated according to the example below:
  - name        = "Template"                                          -> Display
  - Packages    = ["packageName/version@owner/channel", next package] -> ["Logger/1.0@ssitkowx/stable", "Utils/1.0@ssitkowx/testing"]
  - description = "Template for projects and packages"                -> "General class for display"

# V. Builidng:
- Go to 'Conan' folder and open git bash console,
- Type 'conan install .',
- Type 'conan source .',
- Type 'conan build .',
- Got to 'Build' folder and open Visual Studio solution.

# VI. Tips:
- It is unacceptable if the package calls the package (recursion),
- The first time you start the program after entering 'conan install .' python packages can be missing.
  Please follow the python suggestion to install them,
- The first time you start the program after entering 'conan build .' CMakeLists is updated with current project name and packages names.
  Remove Build folder and try again with updated CMakeLists.txt,
- To install gtest and gmock packages for specified options and settings type 'conan install . --build gtest'.