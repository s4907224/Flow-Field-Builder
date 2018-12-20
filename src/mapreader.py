from PIL import Image
import sys
import os

if len(sys.argv) > 1:
  if sys.argv[1].endswith(('.png', '.jpg')):
    if os.path.isfile("images/" + sys.argv[1]):
      i = Image.open("images/" + sys.argv[1])
    else:
      print 'The file "' + sys.argv[1] + '" does not exist.'
      sys.exit(1)
  else:
    print 'The file "' + sys.argv[1] + '" is not a .png or .jpg.'
    sys.exit(1)
else:
  print 'No file given for map.'
  sys.exit(1)

pixels = i.load()
width, height = i.size

if width != 256 and height != 256:
  print 'The file "' + sys.argv[1] + '" does not have dimensions of 256 * 256.'
  sys.exit(1)

allPixels = []
for x in range(width):
    for y in range(height):
        cpixel = pixels[x, y]
        allPixels.append(cpixel)

mapGrid = []
for i in range(len(allPixels)):
    if allPixels[i][0] < 128:
      mapGrid.append(1)
      continue
    elif 128 <= allPixels[i][0]:
      mapGrid.append(0)
      continue

x = 0
y = 0
mapString = "#include <array>\nstd::array<int, "+str(len(mapGrid))+"> mapGrid = {"
for i in range(len(allPixels)):
  x = i % width
  if (i != 0 and x == 0):
    y += 1
    mapString += '\n'
  mapString += str(mapGrid[i])
  if (i != len(allPixels)):
    mapString += ", "
mapString += "\n};"

f = open("include/map.h", "w+")
f.write(mapString)
f.close()