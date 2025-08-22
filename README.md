# zellia_libamp

Zellia libamp is a forked library from [Zhangqili](https://github.com/zhangqili/)

## Add to your project

```bash
git submodule add https://github.com/Zellia-Keyboards/zellia_libamp.git
git submodule update --init --recursive
```

Make sure you have provided the keyboard_conf.h
```cmake
add_subdirectory(libamp)
# Add user defined header
target_include_directories(libamp PUBLIC
    # This folder contains keyboard_conf.h
    ./libamp_user/
)
# Add linked libraries
target_link_libraries(${CMAKE_PROJECT_NAME}
    libamp
)
```

## Test

```bash
git clone https://github.com/Zellia-Keyboards/zellia_libamp.git --recursive
cd zellia_libamp
mkdir build
cd build
cmake .. -DLIBAMP_BUILD_TESTS=ON
make
make test
```
