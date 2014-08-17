e = Environment()
e.Append(CXXFLAGS = ['-std=c++11', '-Wall'])
e.Append(SWIGFLAGS = ['-lua', '-c++'])
e.Replace(LIBPREFIX = '')

e.SharedLibrary(target = 'athelia', source =
	[
		'src/vector.cpp',
		'src/athelia.i',
		'src/ray.cpp'
	]
)
