# C++ project, color transfer, magistère de Physique d'Orsay.
C++ program to transfer color from an image to another using a target image (only works for BMP 24 images). The method is depicted in [Color Transfer between Images](https://www.cs.tau.ac.il/~turkel/imagepapers/ColorTransfer.pdf). We included two programs. The first one can be found in the transfer folder, under the name of transfer.cpp. To successfully use the files, compile transfer.cpp with matrix.cpp, pixel.cpp and bmp_io.cc. Then, execute the executable with three arguments, the first one is **the source file**, the image that will be transfered. The second argument is the colorimetric **target** image. The third one is the name of the **output** file.

Features provided in the repositery:

* A matrix class, with a product method and a transpose method, as well as a display method.
* A pixel class, which inherits from the matrix class (each pixel is a 3x1 matrix). This class comes with for methods, **LMS**, **LAB**, **back_to_LMS_from_LAB** and **back_to_RGB_from_LMS**.
* A bmp_io class, with some various methods to manipulate Bitmap images, such as write methods, pixel_data to recover the data of the image, etc.

# On ne mergera les branches vers la branche master que quand le code est fonctionnel.
Les commandes de base :

-git checkout <nom de la branche> (pour choisir sa branche de travail)
  
-git branch [nom de la branche] (pour créer une branche)
  
-git status (affiche la branche sur laquelle vous vous trouvez et les fichiers modifiés)

-git commit -m "message" (permet de prendre un instantané de votre travail)

-git push (permet de poster les modifications sur le repo)

-git merge [nom de la branche] (permet de faire une demande de fusion de votre travail dans la branche principale, on se placera dans la branche master pour effectuer cette commande).

Pour travailler plus efficacement, possibilité de créer des clés SSH pour authentification automatique :

https://docs.github.com/en/github/authenticating-to-github/connecting-to-github-with-ssh
