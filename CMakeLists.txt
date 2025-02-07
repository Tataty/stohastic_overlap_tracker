cmake_minimum_required(VERSION 3.10)
project(rusagot)

# Встановлюємо стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

# Вказуємо шлях до встановленого OpenCV та Знаходимо пакети OpenCV
set(OpenCV_DIR "/home/rusa/opencv/default_opencv_install/lib/cmake/opencv4")
find_package(OpenCV REQUIRED)

# Додаємо папку з заголовками
include_directories(include ${OpenCV_INCLUDE_DIRS})

# Піддиректорія з вихідним кодом
add_subdirectory(src)