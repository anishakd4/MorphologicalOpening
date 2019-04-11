import cv2
import sys

#Read the image on which opening needs to be applied
image = cv2.imread("../assets/opening.png")

#check if image exista
if image is None:
    print("Can not find image")
    sys.exit()

#Create structuring element/kernel. Here we are creating a elliptical kernel
kernelSize = 3
element = cv2.getStructuringElement(cv2.MORPH_ELLIPSE, (2*kernelSize + 1, 2*kernelSize + 1), (kernelSize, kernelSize))

#Apply erosion on the image followed by dilation.
result = cv2.morphologyEx(image, cv2.MORPH_OPEN, element, iterations=1)

#create windows to display images
cv2.namedWindow("input image", cv2.WINDOW_NORMAL)
cv2.namedWindow("opened image", cv2.WINDOW_NORMAL)

cv2.imshow("input image", image)
cv2.imshow("opened image", result)

#Press esc on keyboard to exit the program
cv2.waitKey(0)

#close all the opened windows
cv2.destroyAllWindows()