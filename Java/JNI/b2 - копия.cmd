g++ -c -DBUILD_DLL TestJNI.cpp -I "C:\Program Files (x86)\Java\jdk1.7.0_21\include" -I "C:\Program Files (x86)\Java\jdk1.7.0_21\include\win32"
g++ -shared -o TestJNI.dll -Wl,--out-implib,libtstdll.a TestJNI.o
pause