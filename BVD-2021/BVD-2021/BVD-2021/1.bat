@ECHO OFF
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Auxiliary\Build\vcvarsall.bat" x86
call D:\3sem\kp\BVD-2021\Debug\BVD-2021.exe -in:D:\3sem\kp\BVD-2021\BVD-2021\in.txt 
ml /c /coff /Zi D:\3sem\kp\BVD-2021\MASMStaticLib\MASMLib.asm
lib /DEF MASMLib.obj
ml /c /coff /Zi D:\3sem\kp\BVD-2021\GenCode\GeneratedAsm.asm
link /OPT:NOREF /DEBUG /SUBSYSTEM:CONSOLE MASMLib.lib GeneratedAsm.obj 
call GeneratedAsm.exe
pause