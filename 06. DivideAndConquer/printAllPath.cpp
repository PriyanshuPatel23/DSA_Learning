#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int srcx, int srcy, int newx, int newy, int maze[][4], int row, int col, vector<vector<bool>>& visited){
   if (
    (newx >= 0 && newx < row) &&
    (newy >= 0 && newy < col) &&
    maze[newx][newy] == 1 &&
    visited[newx][newy] == false
)
        {
            return true;
        }
    else{
        return false;
    }
}

void printAllPath(int maze[][4], int row, int col, int srcx, int srcy, string& output, vector<vector<bool>>& visited){
    if(srcx == row-1 && srcy == col-1){
        cout << output << endl;
        return;
    }
    
    int newx = srcx-1;
    int newy = srcy;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        visited[newx][newy] = true;
        output.push_back('U');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    
    newx = srcx;
    newy = srcy + 1;
    if(isSafe(srcx, srcy, newx, newy, maze, row, col, visited)){
        visited[newx][newy] = true;
        output.push_back('R');
        printAllPath(maze, row, col, newx, newy, output, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    
    newx = srcx+1;
	 newy = srcy;
	if(isSafe(srcx, srcy, newx, newy,maze,row,col,visited )) {
		//mark visited
		visited[newx][newy] = true;
		//call recursion
		output.push_back('D');
		printAllPath(maze, row, col, newx, newy, output , visited );
		//backtracking
		output.pop_back();
		visited[newx][newy] = false;
	}
	
	newx = srcx;
	 newy = srcy-1;
	if(isSafe(srcx, srcy, newx, newy,maze,row,col,visited )) {
		//mark visited
		visited[newx][newy] = true;
		//call recursion
		output.push_back('L');
		printAllPath(maze, row, col, newx, newy, output , visited );
		//backtracking
		output.pop_back();
		visited[newx][newy] = false;
	}
}


int main() {
    int maze[4][4] = {
        {1,0,0,0},{1,1,0,0},{1,1,1,0},{1,1,1,1}
    };
    int row = 4;
    int col = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";
    vector<vector<bool>> visited(row, vector<bool>(col,false));
    if(maze[0][0] == 0){
        cout << "No path exists" << endl;
    }
    else{
        visited[srcx][srcy] = true;
        printAllPath(maze, row, col, srcx, srcy, output, visited);
    }
    return 0;
}