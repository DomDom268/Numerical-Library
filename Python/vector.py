import ctypes
import numpy as np
import random

lib = ctypes.CDLL("./vector.dll")

class Vector(ctypes.Structure):
    _fields_ = [
        ("rows", ctypes.c_int),
        ("data", ctypes.POINTER(ctypes.c_double))
    ]

lib.create_v.argtypes = [ctypes.c_int]
lib.create_v.restype = ctypes.POINTER(Vector)
lib.print_v.argtypes = [ctypes.POINTER(Vector)]
lib.print_v.restype = None
lib.free_v.argtypes = [ctypes.POINTER(ctypes.POINTER(Vector))]
lib.free_v.restype = None
lib.setVal_v.argtypes = [ctypes.POINTER(Vector), ctypes.c_int, ctypes.c_double]
lib.setVal_v.restype = ctypes.c_int
lib.getVal_v.argtypes = [
    ctypes.POINTER(Vector),
    ctypes.c_int,
    ctypes.POINTER(ctypes.c_double)
]
lib.getVal_v.restype = ctypes.c_int
lib.add_v.argtypes = [ctypes.POINTER(Vector), ctypes.POINTER(Vector)]
lib.add_v.restype = ctypes.POINTER(Vector)
lib.subtract_v.argtypes = [ctypes.POINTER(Vector), ctypes.POINTER(Vector)]
lib.subtract_v.restype = ctypes.POINTER(Vector)
lib.dot_v.argtypes = [ctypes.POINTER(Vector), ctypes.POINTER(Vector)]
lib.dot_v.restype = ctypes.c_double
lib.scale_v.argtypes = [ctypes.POINTER(Vector), ctypes.c_double]
lib.scale_v.restype = ctypes.POINTER(Vector)
lib.euclidean_distance.argtypes = [
    ctypes.POINTER(Vector),
    ctypes.POINTER(Vector)
]
lib.euclidean_distance.restype = ctypes.c_double
lib.manhattan_norm.argtypes = [ctypes.POINTER(Vector)]
lib.manhattan_norm.restype = ctypes.c_double
lib.euclidean_norm.argtypes = [ctypes.POINTER(Vector)]
lib.euclidean_norm.restype = ctypes.c_double
lib.norm_distance.argtypes = [
    ctypes.POINTER(Vector),
    ctypes.POINTER(Vector)
]
lib.norm_distance.restype = ctypes.c_double
lib.zeros.argtypes = [ctypes.c_int]
lib.zeros.restype = ctypes.POINTER(Vector)
lib.ones.argtypes = [ctypes.c_int]
lib.ones.restype = ctypes.POINTER(Vector)


def py_to_vec(arr):
    n = len(arr)
    v = lib.create_v(n)
    for i, val in enumerate(arr):
        lib.setVal_v(v,i,float(val))
    return v

def vec_to_py(v):
    return [v.contents.data[i] for i in range(v.contents.rows)]

def free(v):
    lib.free_v(ctypes.byref(v))

def test_dot():
    print("Testing dot product")
    a = np.random.randn(10)
    b = np.random.randn(10)

    va = py_to_vec(a)
    vb = py_to_vec(b)

    c_result = lib.dot_v(va,vb)
    np_result = float(np.dot(a,b))

    free(va)
    free(vb)

    return abs(c_result - np_result) < 1e-9

if __name__ == "__main__":
    tests = [("Dot Product", test_dot)]

    print("n=== Runing Vector Module Tests ===\n")

    passed = 0
    for name, fn in tests:
        ok = fn()
        print({f"{name}: {'PASS' if ok else 'FAIL'}"})
        if ok:
            passed += 1
    
    print(f"\n{passed}/{len(tests)} tests passed.")