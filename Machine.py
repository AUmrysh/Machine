from buildit import *

libs = ['sfml-graphics', 'sfml-window', 'sfml-system']

#build for Unix
machine = Unix("Machine")

#Set the compiler
machine.compiler = CXX()

#add our source directorys
machine.add('src', True)

#libraries
machine.add_library(libs)
machine.build_directory='bin'

#buildit
machine.run();

#post build steps
data = Content()
data.add('data')
data.build_directory = machine.build_directory
