import os

# unix, linux, mac  : 'clear'
# microsoft windows : 'CLS'
os.system('clear' if os.name is 'posix' else 'CLS')

BASEPATH = Dir('.').abspath

print '-----------------------------------------------------------------'
print ' all solutions build and run,'
print '-----------------------------------------------------------------'

CPPPATH = [
    'googletest/googletest/googletest/include',
  ]

env = Environment(CPPPATH=CPPPATH, CXXFLAGS=['-std=c++11',])

sources = Glob('leetcode.com/*.cpp')

LIBS = [
    'gtest', 
  ]

LIBPATH = [
    'googletest',
  ]

if os.name == 'posix':
  env.Append(LINKFLAGS=['-pthread'])
test = env.Program(target='all', source=sources, LIBS=LIBS, LIBPATH=LIBPATH)

Command(
  'solutions', 
  test, 
  lambda env, target, source: os.system(source[0].abspath))
