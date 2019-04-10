import sys
import ctypes


def popcount(N):
    if sys.platform.startswith('linux'):
        libc = ctypes.cdll.LoadLibrary('libc.so.6')
        return libc.__sched_cpucount(ctypes.sizeof(ctypes.c_long), (ctypes.c_long * 1)(N))
    elif sys.platform == 'darwin':
        libc = ctypes.cdll.LoadLibrary('libSystem.dylib')
        return libc.__popcountdi2(N)
    else:
        assert(False)
