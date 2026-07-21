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
lib.slice.argtypes = [
    ctypes.POINTER(Vector),
    ctypes.c_int,
    ctypes.c_int,
    ctypes.c_int
    ]
lib.slice.restype = ctypes.POINTER(Vector)


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
    # print("Testing dot product")
    a = np.random.randn(10)
    b = np.random.randn(10)

    va = py_to_vec(a)
    vb = py_to_vec(b)

    c_result = lib.dot_v(va,vb)
    np_result = float(np.dot(a,b))

    free(va)
    free(vb)

    return abs(c_result - np_result) < 1e-9

def test_add():
    # print("Testing vector addition function")
    a = np.random.randn(10)
    b = np.random.randn(10)

    va = py_to_vec(a)
    vb = py_to_vec(b)

    c_result = lib.add_v(va,vb)
    np_result = np.add(a,b)

    free(va)
    free(vb)

    return np.array_equal(vec_to_py(c_result),np_result)

def test_sub():
    # print("Testing vector subtraction function")
    a = np.random.randn(10)
    b = np.random.randn(10)

    va = py_to_vec(a)
    vb = py_to_vec(b)

    c_result = lib.subtract_v(va,vb)
    np_result = np.subtract(a,b)

    free(va)
    free(vb)

    return np.array_equal(vec_to_py(c_result),np_result)

def test_scale():
    # print("Testing vector addition function")
    a = np.random.randn(10)
    scalar = np.random.random()

    va = py_to_vec(a)
   

    c_result = lib.scale_v(va,float(scalar))
    np_result = a * float(scalar)

    free(va)
    
    return np.array_equal(vec_to_py(c_result),np_result)

def test_norm_distance():
    # print("Testing vector euclidean distance utilizing the norm function")
    a = np.random.randn(10)
    b = np.random.randn(10)

    va = py_to_vec(a)
    vb = py_to_vec(b)

    c_result = lib.norm_distance(va,vb)
    np_result = np.linalg.norm(a-b) 

    free(va)
    free(vb)

    return abs(c_result - np_result) < 1e-9

def test_manhattan():
    # print("Testing vector manhattan norm function")
    a = np.random.randn(10)
    
    va = py_to_vec(a)
   
    c_result = lib.manhattan_norm(va)
    np_result = np.linalg.norm(a,ord=1)

    free(va)
    
    return abs(c_result - np_result) < 1e-9

def test_euclidean():
    # print("Testing vector euclidean norm function")
    a = np.random.randn(10)
    
    va = py_to_vec(a)
   
    c_result = lib.euclidean_norm(va)
    np_result = np.linalg.norm(a)

    free(va)
    
    return abs(c_result - np_result) < 1e-9

def test_slice():
    a = np.random.randn(10)
    
    va = py_to_vec(a)
   
    c_result = lib.slice(va,2,5,1)
    np_result = a[2:6]

    free(va)

    return np.array_equal(vec_to_py(c_result),np_result)



if __name__ == "__main__":
    tests = [
        ("Dot Product", test_dot),
        ("Vector Addition", test_add),
        ("Vector Subtraction",test_sub),
        ("Vector Scalar Multiplication", test_scale),
        ("Distance", test_norm_distance),
        ("Manhattan Norm", test_manhattan),
        ("Euclidean Norm", test_euclidean),
        ("Vector Slice", test_slice)
        ]

    print("n=== Runing Vector Module Tests ===\n")

    passed = 0
    for name, fn in tests:
        ok = fn()
        print(f"{name}:{'PASS' if ok else 'FAIL'}")
        if ok:
             passed += 1
    
    print(f"\n{passed}/{len(tests)} tests passed")
        