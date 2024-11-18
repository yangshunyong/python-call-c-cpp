import ctypes

libs = ctypes.CDLL('./lib/liblibs.so')

print("multiply test:" + str(libs.multiply(1, 2)))

cstring = ctypes.c_char_p(b"hello")
libs.to_uppercase(cstring)
print("to upper:" + str(cstring.value))
