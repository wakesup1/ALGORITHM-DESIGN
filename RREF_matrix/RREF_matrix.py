import sympy
from sympy import Matrix
import numpy as np

# Define your matrix (example using a list of lists)
# You can also convert a NumPy array to a SymPy Matrix
matrix_list = [[0,-2,-1],
               [-2,0,1],
               [1,-1,2],
               [1,0,1]
               ]

# Convert to a SymPy Matrix object
M = Matrix(matrix_list)

# Get the RREF
# The rref() method returns a tuple (RREF_matrix, pivot_columns_indices)
RREF_matrix, pivot_cols = M.rref()

print("Original Matrix:")
print(np.array(M)) # Convert back to numpy array for a simple display
print("\nReduced Row Echelon Form (RREF):")
print(np.array(RREF_matrix)) # Convert back to numpy array for a simple display
print("\nPivot Columns Indices:")
print(pivot_cols)
