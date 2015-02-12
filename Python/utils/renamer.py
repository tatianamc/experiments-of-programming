import os

path = raw_input("Enter path to folder: ")
listOfFiles = os.listdir(path)
countOfFiles = len(listOfFiles)
os.chdir(path)
for i in range(0, countOfFiles):
	newname = "pop"+str(i+1)+".mp3"
	print(path+"\\"+listOfFiles[i])
	os.rename(listOfFiles[i], newname)
