
# Zellia Libamp

>Zellia Libamp is a powerful, modular C library for advanced hall effect keyboard firmware development, supporting analog keys, dynamic layers, mouse, joystick, MIDI, RGB lighting, and more. Forked from [zhangqili/libamp](https://github.com/zhangqili/), it is designed for custom hall effect keyboards.

## Features
- **Advanced Key Handling**: Digital, analog, rapid, and speed modes for keys
- **Layer System**: Dynamic and momentary layers
- **Mouse & Joystick**: Integrated mouse and joystick event handling
- **MIDI Support**: Embedded MIDI device and function support
- **RGB Lighting**: Lamp array and per-key RGB control
- **Storage**: Persistent configuration storage
- **Extensible**: Modular design for easy feature addition

## Directory Structure
```
src/
    advanced_key.*      # Analog & advanced key logic
    keyboard.*          # Main keyboard logic
    mouse.*             # Mouse event handling
    joystick.*          # Joystick event handling
    layer.*             # Layer management
    midi/               # MIDI device and protocol
    lamp_array/         # RGB lamp array support
    ...                 # Other modules (extra_key, dynamic_key, etc.)
test/                 # Unit tests (GoogleTest)
lib/                  # Third-party libraries (LUFA, littlefs, googletest)
usb/                  # USB descriptors and utilities
CMakeLists.txt        # Build configuration
LICENSE               # GPL-3.0-or-later
```

## Getting Started
### Add to Your Project
```bash
git submodule add https://github.com/Zellia-Keyboards/zellia_libamp.git
git submodule update --init --recursive
```

Add your custom `keyboard_conf.h` and include it in your build:
```cmake
add_subdirectory(libamp)
target_include_directories(libamp PUBLIC ./libamp_user/)
target_link_libraries(${CMAKE_PROJECT_NAME} libamp)
```

### Example Usage
See `src/keyboard.c` for main event handling and integration examples. For analog key configuration, refer to `src/advanced_key.c` and `src/advanced_key.h`.

## Testing
Build and run unit tests:
```bash
git clone https://github.com/Zellia-Keyboards/zellia_libamp.git --recursive
cd zellia_libamp
mkdir build
cd build
cmake .. -DLIBAMP_BUILD_TESTS=ON
make
make test
```

## Contributing
Pull requests and issues are welcome! Please follow the coding style and document your changes. See the source files for module-specific guidelines.

## License
This project is licensed under the [GNU GPL v3.0 or later](LICENSE).

---
Maintained by Zellia-Keyboards. Original author: Zhangqi Li (@zhangqili).
