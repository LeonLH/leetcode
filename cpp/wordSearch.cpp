#include<iostream>
#include<vector>
#include<string>
using namespace std;

// 60ms, There is a faster method.(12ms).
class Solution{
public:
	vector<vector<char>> state;
	vector<vector<char>> board;
	string left;
	int row;
	int col;

public:
	void initState(){
		for(unsigned int i = 0; i < state.size(); ++i)
			for(unsigned int j = 0; j < state[i].size(); ++j)
				state[i][j] = '#';
	}
	
	bool init(){
		for(unsigned int i = 0; i < board.size(); ++i)
			for(unsigned int j = 0; j < board[i].size(); ++j){
				if(board[i][j] == left[0]){
					state[i][j] = left[0];
					left = left.substr(1);
					row = i;
					col = j;
					return true;
				}
			}
		return false;
	}


	bool makeMove(int i){
		if(i == 1){
			if(col+1 < board[0].size() && board[row][col+1] == left[0] && state[row][col+1] == '#'){
				state[row][col+1] = left[0];
				left = left.substr(1);
				col++;
				return true;
			}
			else
				return false;
		}
		else if(i == 2){
			if(row+1 < board.size() && board[row+1][col] == left[0] && state[row+1][col] == '#'){
				state[row+1][col] = left[0];
				left = left.substr(1);
				row++;
				return true;
			}
			else
				return false;

		}
		else if(i == 3){
			if(col-1 >= 0 && board[row][col-1] == left[0] && state[row][col-1] == '#'){
				state[row][col-1] = left[0];
				left = left.substr(1);
				col--;
				return true;
			}
			else
				return false;
		}
		else if(i == 4){
			if(row-1 >= 0 && board[row-1][col] == left[0] && state[row-1][col] == '#'){
				state[row-1][col] = left[0];
				left = left.substr(1);
				row--;
				return true;
			}
			else
				return false;

		}
		return false;
	}

	void moveBack(int i){
		if(i == 1){
			left = state[row][col] + left;
			state[row][col] = '#';
			col--;
		}
		else if(i == 2){
			left = state[row][col] + left;
			state[row][col] = '#';
			row--;
		}
		else if(i == 3){
			left = state[row][col] + left;
			state[row][col] = '#';
			col++;
		}
		else if(i == 4){
			left = state[row][col] + left;
			state[row][col] = '#';
			row++;
		}
	}

	bool isEmpty(vector<vector<char>> &vec){
		for(unsigned int i = 0; i < vec.size(); ++i)
			for(unsigned int j = 0; j < vec[i].size(); ++j)
				if(vec[i][j] != '#')
					return false;
		return true;
	}

	bool solve(){
		if(!left.size())
			return true;
		else{	// 1:right, 2:down, 3:left, 4:up
			if(isEmpty(state)){
				for(unsigned int i = 0; i < board.size(); ++i)
					for(unsigned int j = 0; j < board[i].size(); ++j){
						if(board[i][j] == left[0]){
							state[i][j] = left[0];
							row = i, col = j;
							left = left.substr(1);
							if(solve())
								return true;
							left = state[i][j] + left;
							state[i][j] = '#';
							row = 0;
							col = 0;
						}
					}
			}
			else{
				for(int i = 1; i <= 4; i++){
					// change the state
					bool btmp = makeMove(i);
					if(btmp){
						if(solve())
							return true;
					}
					if(btmp)
						moveBack(i);
				}
			}
			//只有把它所有的孩子都尝试完才可以总结出当前状态是false的
			return false;			
		}
	}

	bool exist(vector<vector<char>> &brd, string word){
		board = brd;
		state = board;
		left = word;
		initState();
		if(word.size() > (brd.size() * brd[0].size()))
			return false;
	//	if(!init())
	//		return false;

		bool res = solve();
		return res;
	}
};

void printBoard(vector<vector<char>> &board){
	cout << "[\n";
	for(unsigned int i = 0; i < board.size(); ++i){
		cout << "  [ ";
		for(unsigned int j = 0; j < board[i].size(); ++j){
			cout << board[i][j] << " ";
		}
		cout << "]" << endl;
	}
	cout << "]\n";
		
}

int main(){
	vector<vector<char>> board;
	vector<char> row1 = {'C', 'A', 'A'};// {'A', 'B', 'C', 'E'};
	vector<char> row2 = {'A', 'A', 'A'};// {'S', 'F', 'C', 'S'};
	vector<char> row3 = {'B', 'C', 'D'};// {'A', 'D', 'E', 'E'};
	board.push_back(row1);
	board.push_back(row2);
	board.push_back(row3);
	printBoard(board);
	
	string str = "AAB";//"ABCB";//"SEE";//"ABCCED";//
	Solution A;
	if(A.exist(board, str))
		cout << "Yes, It exists" << endl;
	else 
		cout << "No, It doesn't exist." << endl;
	printBoard(A.state);
	return 0;
}
