e = Environment()
e.Append(CXXFLAGS = ['-std=c++11', '-Wall'])
e.Append(SWIGFLAGS = ['-lua', '-c++'])
e.Replace(LIBPREFIX = '')

e.SharedLibrary(target = 'athelia', source =
	[
		'src/vector.cpp',
		'src/colour.cpp',
		'src/ray.cpp',
		'src/callback.cpp',
		'src/voxel.cpp',
		'src/octree.cpp',
		'src/athelia.i'
	]
)
