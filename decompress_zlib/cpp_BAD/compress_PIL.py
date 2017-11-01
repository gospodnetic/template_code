import numpy
from PIL import Image
import zlib

im = Image.open("/home/petra/Desktop/SampleBasedReconstruction/data/Cone.cdb/image/phi=0/theta=1/vis=0/colorCone1=1.png")
filename = "zwrite_test.Z"

with open(filename, mode='wb') as file:
            file.write(zlib.compress(numpy.array(im)))

filename = "zwrite_test_numpy_arange.Z"
arr = numpy.arange(0,200)
with open(filename, mode='wb') as file:
            file.write(zlib.compress(arr))

filename = "zwrite_test_numpy_reshape.Z"
arr = numpy.arange(0,200).reshape(10,20)
with open(filename, mode='wb') as file:
            file.write(zlib.compress(arr))

filename = "zwrite_test_single_scalar.Z"
arr = numpy.arange(0,200).reshape(10,20)
with open(filename, mode='wb') as file:
            file.write(zlib.compress(numpy.array(5)))
