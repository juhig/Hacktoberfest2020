import zipfile,os ,shutil as s
imort time as t

newzpfile='C:\\New Folder\\Freedom Fighter') #add file path 

zfile= zzipfile.ZipFile("newzpfile",'w')
def newzpfile(folder):
    for foldern ,sbfoldern,filesn in os.walk(folder):
        zfile.write(foldern)
        
        
        
        for file in filesn:
            zfile.write(os.path.join(folder,file)
            
 
 print(zfile.namelist()
    
