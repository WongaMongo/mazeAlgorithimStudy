default:
	MSBuild.exe .\build\mazeAlgorithmStudy.sln
	.\build\Debug\mazeAlgorithmStudy.exe images/bluish_colors-wren_@_sleeprealms.jfif 1 1 1 1
	.\build\Debug\mazeAlgorithmStudy.exe images/bluish_colors-wren_@_sleeprealms.jpg 2 2 2 2
	.\build\Debug\mazeAlgorithmStudy.exe images/20_by_20_orthogonal_maze.png 0 150 321 169

test20:
	g++ .\main.cpp
	.\a.exe .\images\20_by_20_orthogonal_maze.png 0 150 321 169

test50:
	g++ .\main.cpp
	.\a.exe .\images\50_by_50_orthogonal_maze.png 0 393 801 408

test100:
	g++ .\main.cpp
	.\a.exe .\images\100_by_100_orthogonal_maze.png 0 793 1601 808

test200:
	g++ .\main.cpp
	.\a.exe .\images\200_by_200_orthogonal_maze.png 0 1592 3201 1608


smallTest:
	g++ .\main.cpp
	.\a.exe .\images\20_by_20_orthogonal_maze.png 0 150 321 169
	.\a.exe .\images\50_by_50_orthogonal_maze.png 0 393 801 408

bigTest:
	g++ .\main.cpp
	.\a.exe .\images\100_by_100_orthogonal_maze.png 0 793 1601 808
	.\a.exe .\images\200_by_200_orthogonal_maze.png 0 1592 3201 1608

theseus:
	g++ .\main.cpp
	.\a.exe .\images\Maze_of_Theseus.png 739 510 416 510

fullTest:
	g++ .\main.cpp
	.\a.exe .\images\20_by_20_orthogonal_maze.png 0 150 321 169
	.\a.exe .\images\50_by_50_orthogonal_maze.png 0 393 801 408
	.\a.exe .\images\100_by_100_orthogonal_maze.png 0 793 1601 808
	.\a.exe .\images\200_by_200_orthogonal_maze.png 0 1592 3201 1608