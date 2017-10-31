import numpy as np

test = np.arange(200).reshape(10, 20)
np.savez("example.npz", test)