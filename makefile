default:
	MSBuild.exe .\build\mazeAlgorithmStudy.sln
	.\build\Debug\mazeAlgorithmStudy.exe images/bluish_colors-wren_@_sleeprealms.jfif 1 1 1 1
	.\build\Debug\mazeAlgorithmStudy.exe images/bluish_colors-wren_@_sleeprealms.jpg 2 2 2 2
	.\build\Debug\mazeAlgorithmStudy.exe images/20_by_20_orthogonal_maze.png 0 150 321 169

test:
	g++ .\main.cpp
	.\a.exe .\images\20_by_20_orthogonal_maze.png 0 150 321 169