project('SimpleMusicVisualizer', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17']) # Was c++14

deps = [
  dependency('vulkan'),
  dependency('glfw3'),
  dependency('glm')
]

include = include_directories('src/include')

source_files = [
  'src/simplemusicvisualizer.cpp',
  'src/log.cpp',
  'src/MainApplication.cpp',
]

executable(
  'SimpleMusicVisualizer',
  sources : source_files,
  include_directories: include,
  dependencies: deps,
  install : true,
)
