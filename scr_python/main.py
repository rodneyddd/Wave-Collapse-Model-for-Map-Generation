import sys
from PIL import Image

file = open("./data/wave_collapse.txt")

row = sum(1 for line in file if line.rstrip())

file.close
file = open("./data/wave_collapse.txt")

col = 0
for line in file.readline():
    if(line.isdigit()):
        col = col + 1

file.close
file = open("./data/wave_collapse.txt")

images = [Image.open(x) for x in ['data/1.png', 'data/2.png','data/3.png','data/4.png','data/5.png',]]

total_width = row * 20
total_height = col * 20

new_im = Image.new('RGB', (total_width, total_height))

x_offset = 0
y_offset= 0
while 1:
    char = file.read(1)         
    if not char:
        break
    
    if char.isdigit():
        img_file = 'data/' + str(char) + '.png'
        img = Image.open(img_file)
        new_im.paste(img, (x_offset,y_offset))
        x_offset += img.size[0]
        if(x_offset == total_width):
            x_offset = 0
            y_offset += img.size[1]
        
print("Map generated!")    
new_im.save('map.jpg')