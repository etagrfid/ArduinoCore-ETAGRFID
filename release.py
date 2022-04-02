import tarfile
import os
import glob

VERSION = "1.2.2"

ROOT_PROJECT_DIRNAME = "ArduinoCore-ETAGRFID"
FILENAME = 'ArduinoCoreETAGRFID_'+VERSION+'.tar.bz2'

fileNames = os.listdir(ROOT_PROJECT_DIRNAME)

fileList = glob.glob("*.tar.bz2")
print(fileList)
for efile in fileList:
    try:
        print("Removing file: " + efile)
        os.remove(efile)
    except:
        print("could not delete: " + efile)

print(fileNames)


tar = tarfile.open(FILENAME, "w:bz2")
for name in fileNames:
    tar.add(ROOT_PROJECT_DIRNAME+"/" + name)
tar.close()


import hashlib
BLOCKSIZE = 65536
hasher = hashlib.sha256()
with open(FILENAME, 'rb') as afile:
    buf = afile.read(BLOCKSIZE)
    while len(buf) > 0:
        hasher.update(buf)
        buf = afile.read(BLOCKSIZE)
checksum = hasher.hexdigest()
print(checksum)

fileSize = os.path.getsize(FILENAME)
print(fileSize)

jtemp = open("template.json","r")
jtempstr = jtemp.read()
jtemp.close()
URL = "https://github.com/jaywilhelm/ArduinoCore-ETAGRFID/releases/download/etag-v"+VERSION+"/"+FILENAME
#https://github.com/jaywilhelm/ArduinoCore-ETAGRFID/releases/download/etag-v1.2.0/ArduinoCoreETAGRFID_1.2.0.tar.bz2

jtempstr = jtempstr.replace("$URL$",URL)
jtempstr = jtempstr.replace("$FILENAME$",FILENAME)
jtempstr = jtempstr.replace("$VERSION$",VERSION)
jtempstr = jtempstr.replace("$SHA$",checksum)
jtempstr = jtempstr.replace("$SIZE$",str(fileSize) )

print(jtempstr)

f= open("package_ETAGRFID_index.json","w+")
f.write(jtempstr)
f.close()
