import os



file='C:\\Program Files (x86)\\Microsoft Visual Studio\\2017\\Community\\Common7\\IDE\\devenv'



os.system('"' + file + '"' + " gomoku.sln /Build")

os.system("move x64\\Debug\\gomoku.exe pbrain-PARIS-Debout.Dorian.exe")
