from PIL import Image

lemur = Image.open("lemur.png")
flag = Image.open("flag.png")

pixels_lemur = lemur.load() # create the pixel map
pixels_flag = flag.load()

for i in range(lemur.size[0]): # for every pixel:
    for j in range(lemur.size[1]):
        # Gather each pixel
        l = pixels_lemur[i,j]
        f = pixels_flag[i,j]

        # XOR each part of the pixel tuple
        r = l[0] ^ f[0]
        g = l[1] ^ f[1]
        b = l[2] ^ f[2]

        # Store the resulatant tuple back into an image
        pixels_flag[i,j] = (r, g, b)

flag.save("lemur_xor_flag.png")