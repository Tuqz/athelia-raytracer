e = Environment()
e.Append(CCFLAGS = ['-std=c99', '-Wall'])
e.Replace(LIBPREFIX = '')

e.SharedLibrary(target = 'athelia', source =
	[
		'src/vector.c',
		'src/test.c',
		'src/lua.c',
		'src/lua/test.c'
	]
)
