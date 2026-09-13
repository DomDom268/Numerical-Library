import ctypes 
import numpy as np

mat = ctypes.CDLL("Python/matrix.dll")

class Matrix(ctypes.Structure):
    _fields_ = [
        ("rows", ctypes.c_int),
        ("cols",ctypes.c_int),
        ("data",ctypes.POINTER(ctypes.POINTER(ctypes.c_double)))
    ]

mat.create.argtypes = [ctypes.c_int,ctypes.c_int]
mat.create.restype = ctypes.POINTER(Matrix)
mat.free_matrix.argtypes = [ctypes.POINTER(ctypes.POINTER(Matrix))]
mat.free_matrix.restype = None
mat.setVal.argtypes = [ctypes.POINTER(Matrix), ctypes.c_int, ctypes.c_int, ctypes.c_double]
mat.setVal.restype = ctypes.c_int
mat.getVal.argtypes = [
    ctypes.POINTER(Matrix),
    ctypes.c_int,
    ctypes.c_int,
    ctypes.POINTER(ctypes.c_double)
]
mat.getVal.restype = ctypes.c_int
mat.print_matrix.argtypes = [ctypes.POINTER(Matrix)]
mat.print_matrix.restype = None
mat.mat_add.argtypes = [ctypes.POINTER(Matrix),ctypes.POINTER(Matrix)]
mat.mat_add.restype = ctypes.POINTER(Matrix)
mat.mat_subtract.argtypes = [ctypes.POINTER(Matrix),ctypes.POINTER(Matrix)]
mat.mat_subtract.restype = ctypes.POINTER(Matrix)
mat.scalar_multiply.argtypes = [ctypes.POINTER(Matrix),ctypes.c_double]
mat.scalar_multiply.restype = ctypes.POINTER(Matrix)
mat.mat_multiply.argtypes = [ctypes.POINTER(Matrix),ctypes.POINTER(Matrix)]
mat.mat_multiply.restype = ctypes.POINTER(Matrix)
mat.mat_elm_multiply.argtypes = [ctypes.POINTER(Matrix),ctypes.POINTER(Matrix)]
mat.mat_elm_multiply.restype = ctypes.POINTER(Matrix)
mat.transpose.argtypes = [ctypes.POINTER(Matrix)]
mat.transpose.restype = ctypes.POINTER(Matrix)
mat.mat_identity.argtypes = [ctypes.c_int]
mat.mat_identity.restype = ctypes.POINTER(Matrix)
mat.ones.argtypes = [ctypes.c_int,ctypes.c_int]
mat.ones.restype = ctypes.POINTER(Matrix)

def py_to_mat(arr):
    rows = arr.shape[0]
    cols = arr.shape[1]
    matrix = mat.create(rows,cols)

    for i,row in enumerate(arr):
        for j,col in enumerate(row):
            mat.setVal(matrix,i,j,float(col))

    return matrix

def free(M):
    mat.free_matrix(ctypes.byref(M))

if __name__ == "__main__":
   a = py_to_mat(np.array([[12,13,4],[32,5,64],[435,7,6]]))
   b = np.array([[12,13,4],[32,5,64],[435,7,6]])

   print(f"a scaled by 5:\n")
   mat.print_matrix(mat.scalar_multiply(a,5.0))
   print(f"b scaled by 5:\n{b*5}")
