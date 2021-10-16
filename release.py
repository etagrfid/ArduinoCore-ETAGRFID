import tarfile
import os
import glob

VERSION = "1.1.6"
fileNames = os.listdir("ArduinoCore-ETAGRFID")

fileList = glob.glob("*.tar.bz2")
print(fileList)
for efile in fileList:
    try:
        print("Removing file: " + efile)
        os.remove(efile)
    except:
        print("could not delete: " + efile)

print(fileNames)


tar = tarfile.open("ArduinoCoreETAGRFID_"+VERSION+".tar.bz2", "w:bz2")
for name in fileNames:
    tar.add("ArduinoCore-ETAGRFID/" + name)
tar.close()


import hashlib
BLOCKSIZE = 65536
hasher = hashlib.sha256()
with open('ArduinoCoreETAGRFID_'+VERSION+'.tar.bz2', 'rb') as afile:
    buf = afile.read(BLOCKSIZE)
    while len(buf) > 0:
        hasher.update(buf)
        buf = afile.read(BLOCKSIZE)
checksum = hasher.hexdigest()
print(checksum)

fileSize = os.path.getsize('ArduinoCoreETAGRFID_'+VERSION+'.tar.bz2')
print(fileSize)

JSONstring = '{\n'
JSONstring += '   "packages":[\n'
JSONstring += '      {\n'
JSONstring += '         "name":"ArduinoCore-ETAGRFID",\n'
JSONstring += '         "maintainer":"JayWilhelm",\n'
JSONstring += '         "websiteURL":"http://github.com/jaywilhelm",\n'
JSONstring += '         "email":"jwilhelm@ohio.edu",\n'
JSONstring += '         "help":{\n'
JSONstring += '            "online":"http://www.arduino.cc/en/Reference/HomePage"\n'
JSONstring += '         },\n'
JSONstring += '         "platforms":[\n'
JSONstring += '            {\n'
JSONstring += '               "boards":[\n'
JSONstring += '                  {\n'
JSONstring += '                     "name": "ETAGRFID"\n'
JSONstring += '                  },\n'
JSONstring += '                  {\n'
JSONstring += '                     "name": "ETAGRFID v2 D21J"\n'
JSONstring += '                  }\n'
JSONstring += '               ],\n'
JSONstring += '               "archiveFileName":"package_ETAGRFID_index_'+VERSION+'.tar.bz2",\n'
JSONstring += '               "name":"ArduinoETAGRFIDcore",\n'
JSONstring += '               "architecture":"samd",\n'
JSONstring += '               "category":"Arduino",\n'
JSONstring += '               "version":"'+VERSION+'",\n'
JSONstring += '               "url":"https://github.com/jaywilhelm/ArduinoCore-ETAGRFID/raw/master/ArduinoCoreETAGRFID_'+VERSION+'.tar.bz2",\n'
JSONstring += '               "checksum":"SHA-256:' + checksum + '",\n'
JSONstring += '               "size":"' + str(fileSize) + '",\n'
JSONstring += '               "toolsDependencies":[\n'
JSONstring += '                  {\n'
JSONstring += '                     "packager":"arduino",\n'
JSONstring += '                     "name":"arm-none-eabi-gcc",\n'
JSONstring += '                     "version":"4.8.3-2014q1"\n'
JSONstring += '                  },\n'
JSONstring += '                  {\n'
JSONstring += '                     "packager":"arduino",\n'
JSONstring += '                     "name":"bossac",\n'
JSONstring += '                     "version":"1.7.0"\n'
JSONstring += '                  },\n'
JSONstring += '                  {\n'
JSONstring += '                     "packager":"arduino",\n'
JSONstring += '                     "name":"openocd",\n'
JSONstring += '                     "version":"0.9.0-arduino6-static"\n'
JSONstring += '                  },\n'
JSONstring += '                  {\n'
JSONstring += '                     "packager":"arduino",\n'
JSONstring += '                     "name":"CMSIS",\n'
JSONstring += '                     "version":"4.5.0"\n'
JSONstring += '                  },\n'
JSONstring += '                  {\n'
JSONstring += '                     "packager":"arduino",\n'
JSONstring += '                     "name":"CMSIS-Atmel",\n'
JSONstring += '                     "version":"1.1.0"\n'
JSONstring += '                  },\n'
JSONstring += '                  {\n'
JSONstring += '                     "packager":"arduino",\n'
JSONstring += '                     "name":"arduinoOTA",\n'
JSONstring += '                     "version":"1.2.0"\n'
JSONstring += '                  }\n'
JSONstring += '               ]\n'
JSONstring += '            }\n'
JSONstring += '         ],\n'
JSONstring += '         "tools":[\n'
JSONstring += '\n'
JSONstring += '         ]\n'
JSONstring += '      }\n'
JSONstring += '   ]\n'
JSONstring += '}\n'

print(JSONstring)

f= open("package_ETAGRFID_index.json","w+")
f.write(JSONstring)
f.close()
