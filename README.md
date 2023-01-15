![Ubuntu | GCC12 | x64 | Debug](https://github.com/kevinchannon/wite-cmake-example/actions/workflows/build_and_test_ubuntu_gcc12_x64_debug.yml/badge.svg)<br>
![Ubuntu | GCC12 | x64 | Release](https://github.com/kevinchannon/wite-cmake-example/actions/workflows/build_and_test_ubuntu_gcc12_x64_release.yml/badge.svg)<br>
![Windows | MSVC++ | x64 | Debug](https://github.com/kevinchannon/wite-cmake-example/actions/workflows/build_and_test_windows_msvc_x64_debug.yml/badge.svg)<br>
![Windows | MSVC++ | x64 | Release](https://github.com/kevinchannon/wite-cmake-example/actions/workflows/build_and_test_windows_msvc_x64_release.yml/badge.svg)

# wite-cmake-example

This is a really small project that demonstrates how to include [Wite](https://github.com/kevinchannon/wite) in your CMake project. The action is all in [wite-cmake-example/CMakeLists.txt](https://github.com/kevinchannon/wite-cmake-example/blob/master/wite-cmake-example/CMakeLists.txt).

The work is all done in `$/wite-cmake-example/CMakeLists.txt`, this has some lines like this in it
```cmake
include(FetchContent)

FetchContent_Declare(wite
	URL https://github.com/kevinchannon/wite/releases/download/<VERSION>/wite-src.zip
	DOWNLOAD_EXTRACT_TIMESTAMP true
)

FetchContent_MakeAvailable(wite)
```

* The `include(FetchContent)` line tells CMake that you want to use the `FetchContent` module and makes it available for use in the subsequent commands
* The `FetchContent_Declare` command uses FetchContent to pull the zip file from the stated URL and makes it available to use in your project as a project named "wite". This means that you will include the files from Wite in your code with a statement that begins `#include <wite/.....`. The `DOWNLOAD_EXTRACT_TIMESTAMP true` part means that the timestamps on the downloaded files will be altered to the time that they were extracted and built for the first time on your machine, rather than maintaining the timestamps that they have from their original commits in Git. This helps prevent lots of things being re-built all the time when they haven't actually changed.
* The `FetchContent_MakeAvailable` command actually brings the named content into the project for use by CMake, somehow.

The actual C++ code in the project barely uses Wite, since this project is just about demonstrating how to use CMake FetchContent to pull Wite into your project. For more examples of using Wite, see the [**examples**](https://github.com/kevinchannon/wite/blob/master/examples) in the main Wite repo.