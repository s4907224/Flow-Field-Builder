from PIL import Image
import sys
i = Image.open("test.png")

pixels = i.load() # this is not a list, nor is it list()'able
width, height = i.size

all_pixels = []
for x in range(width):
    for y in range(height):
        cpixel = pixels[x, y]
        all_pixels.append(cpixel)

print len(all_pixels)

x = 0
y = 0
for i in range(len(all_pixels)):
  x = i % width
  if (i != 0 and x == 0):
    y += 1
    sys.stdout.write('\n')
  string = str(all_pixels[i][0] / 16)
  sys.stdout.write(string + " ")