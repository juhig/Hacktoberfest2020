
## code for image Resize
#requirements 
pip install pillow

import os
from PIL import Image

f = r'C:\Users\SMART\Desktop\scrpeer\images\ant_man'      #Enter the location of your Image Folder
    
new_d = 500

for file in os.listdir(f):
    f_img = f+'/'+file
    try:
        img = Image.open(f_img)
        img = img.resize((new_d, new_d))
        img.save(f_img)
    except IOError:
        pass
      
      
## code for image rename

import os
path = os.chdir("C:\\Users\\SMART\\Desktop\\scrpeer\\images\\ant_man")
i=1
for file in os.listdir(path):
    new_name="ant{}.jpg".format(i)
    i=i+1
    os.rename(file,new_name)
    print("done")
    
    
 ## code for data augmentation(used for CV projects to increse size of dataset)

#requirements
pip install tensorflow
pip install keras


from keras.preprocessing.image import ImageDataGenerator,array_to_img,img_to_array,load_img

datagen=ImageDataGenerator(rotation_range=40,
                          width_shift_range=0.2,
                          height_shift_range=0.2,
                          shear_range=0.2,
                          zoom_range=0.2,
                           horizontal_flip=True,
                           fill_mode='nearest'
                        )

img=load_img('C:/Users/SMART/Desktop/scrpeer/images/spiderman_face/ab5.jpg')
x=img_to_array(img)
x=x.reshape((1,)+ x.shape)


i=0
for batch in datagen.flow(x,batch_size=1,save_to_dir='F:/internship proj/one_shot_simence/superhero_background/spiderman',save_prefix='spm',save_format='jpg'):
    
    i+=1
    if i>10:
        
        break
