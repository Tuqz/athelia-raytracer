e = Environment()
e.Append(CXXFLAGS = ['-std=c++11', '-Wall'])
e.Replace(LIBPREFIX = '')

e.SharedLibrary(target = 'athelia', source =
	[
		'src/vector.cpp',
		'src/ray.cpp'
	]
)
