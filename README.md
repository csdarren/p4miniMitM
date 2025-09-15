# p4miniMitM

This project is a Man in the Middle (MitM) for a R56 MINI Cooper S.

Its main goal is to take OEM CAN Bus signals from the D-CAN in a R56 and convert them to a new bus / format for the purpose of being displayed on a gauge(s)

Notes:
If faced with xtensa elf related clangd warnings, make sure you are setting the target device properly, and have ran reconfigure atleast once.
[
idf.py set-target esp32p4
idf.py reconfigure -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

]
