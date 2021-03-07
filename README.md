# C++ project, color transfer, magistère de Physique d'Orsay.
C++ program to transfer color from an image to another using a target image (only works for BMP 24 images). The method is depicted in [Color Transfer between Images](https://www.cs.tau.ac.il/~turkel/imagepapers/ColorTransfer.pdf). We included two programs. Both one can be found in the ***color_transdfer_v2*** folder, under the name of transfert and color_transfer.py. 
To successfully use the scripts, compile ***transfer.cpp*** with ***matrix.cpp***, ***pixel.cpp***, ***image.cpp*** and ***bmp_io.cc*** (or use the bash script provided in the folder with `` $ sh transfert.sh``. 
Then, execute the executable with three arguments, the first one is **the source file**, the image that will be transfered. The second argument is the colorimetric **target** image. The third one is the name of the **output** file. The second program is a Python script which realises the same tasks using numpy and PIL.

Features provided in the repository:

* A matrix class, with a product method and a transpose method, as well as a display method.
* A pixel class, which inherits from the matrix class (each pixel is a 3x1 matrix). This class comes with four methods, **LMS**, **LAB**, **back_to_LMS_from_LAB** and **back_to_RGB_from_LMS** which allow to do transformations of the colorimetric space.
* A bmp_io class, with some various methods to manipulate Bitmap images, such as write methods, pixel_data to recover the data of the image, etc.
* A image class, which comes with a constructor based on the reading method of the bmp24 class, a **go_to_LAB** method to go to the $l \alpha \beta$ space. We also automated the relevant statistical methods such as the mean or the standard deviation on each canal with **mean** and **std** methods, which return a pixel object filled with the stats.
* A Python file, which realises the same task as the C++ file. It allowed us to compare the two outpouts. To use it, just put the **source.bmp** and **cible.bmp** in the Python folder and use the command line : `` $ python3 color_transfer.py ``. It will generate a **out.bmp** file (you can change these files by changing the Python script).


