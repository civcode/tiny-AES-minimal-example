project('aes-128', 'c', 'cpp',
        default_options : ['cpp_std=c++17',
                           'warning_level=0',
                           'buildtype=debug'])

incdir = include_directories('include', 'lib/tiny-AES-c')

aes_src = files('lib/tiny-AES-c/aes.c')

executable('aes-128', 'src/main.cpp', aes_src, include_directories : incdir)