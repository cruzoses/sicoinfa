cd \fw195\gestool\

taskkill /F /IM gestool.exe

\BCC55\BIN\MAKE -S -fHB.MAK -D__GST__

cd \fw195\gestool\bin\

if "%1"=="" goto NOPASSWORD

   gestool.exe %1
   goto EXIT

:NOPASSWORD
   gestool.exe /NOPASSWORD

:EXIT

cd \fw195\gestool\

