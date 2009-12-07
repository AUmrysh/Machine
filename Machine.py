from buildit import *

libs = [
	'sfml-graphics',
	'sfml-window',
	'sfml-system'
]

compiler_flags = [
	'-Wall',
	'-Wextra',
	'-g'
]

#build for Unix
machine = Unix("Machine")
machine.compiler = CXX()

#add our source directorys
machine.add('src', True)

#add some compiler flags
machine.add_flag(compiler_flags)

#libraries
machine.add_library(libs)
machine.build_directory = 'bin'

# Copy stuff from the data folder
data = Content()
data.add('data', True)
data.build_directory = machine.build_directory

#buildit
machine.run()
data.run()
