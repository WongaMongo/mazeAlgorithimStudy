default:
	MSBuild.exe .\build\mazeAlgorithmStudy.sln
	.\build\Debug\mazeAlgorithmStudy.exe images/bluish_colors-wren_@_sleeprealms.jfif
	.\build\Debug\mazeAlgorithmStudy.exe images/bluish_colors-wren_@_sleeprealms.jpg
	.\build\Debug\mazeAlgorithmStudy.exe images/bluish_colors-wren_@_sleeprealms.png

test:
	g++ .\main.cpp
	.\a.exe .\images\bluish_colors-wren_@_sleeprealms.jpg