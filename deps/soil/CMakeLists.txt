cmake_minimum_required(VERSION 3.5)

project(SOIL)

set(SOURCE_FILES src/image_DXT.c
                 src/image_helper.c
                 src/SOIL.c
                 src/stb_image_aug.c)

add_library(SOIL STATIC ${SOURCE_FILES})
