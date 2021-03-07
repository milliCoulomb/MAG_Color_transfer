from PIL import Image
import numpy as np
M1 = np.array([[0.3811, 0.5783, 0.0402], [0.1967, 0.7244, 0.0782], [0.0241, 0.1288, 0.8444]])
M2 = np.array([[1 / np.sqrt(3), 0, 0], [0, 1 / np.sqrt(6), 0], [0, 0, 1 / np.sqrt(2)]])
M3 = np.array([[1, 1, 1], [1, 1, -2], [1, -1, 0]])
M4 = M3.T
M5 = M2
M6 = np.array([[4.4679, -3.5873, 0.1193], [-1.2186, 2.3809, -0.1624], [0.0497, -0.2439, 1.2045]])
img_cible = Image.open("mathis2.bmp")
img_source = Image.open("mathis1.bmp")
img_source_LMS = np.dot(img_source, M1)
img_cible_LMS = np.dot(img_cible, M1)
img_source_lab = np.dot(np.log(img_source_LMS),np.dot(M2, M3))
img_cible_lab = np.dot(np.log(img_cible_LMS),np.dot(M2, M3))
mean_source_lab, std_source_lab = np.mean(img_source_lab, axis=(0, 1)), np.std(img_source_lab, axis=(0, 1))
mean_cible_lab, std_cible_lab = np.mean(img_cible_lab, axis=(0, 1)), np.std(img_cible_lab, axis=(0, 1))
img_transfer_lab = (std_cible_lab / std_source_lab * (img_source_lab - mean_source_lab)) +mean_cible_lab
img_transfer_LMS = np.dot(img_transfer_lab, np.dot(M4, M5))
img_transfer = np.dot(np.exp(img_transfer_LMS), M6)
img_transfer[img_transfer > 255]=255
result = Image.fromarray(img_transfer.astype(np.uint8))
result.save('out_python.bmp')
