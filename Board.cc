#include "Board.h"


std::map <int, std::string> academic = {
    {1, "AL     "},
    {3, "ML     "},
    {6, "ECH    "},
    {8, "PAS    "},
    {9, "HH     "},
    {11, "RCH     "},
    {13, "DWE     "},
    {14, "CPH     "},
    {16, "LHI     "},
    {18, "BMH     "},
    {19, "OPT     "},
    {21, "EV1     "},
    {23, "EV2     "},
    {24, "EV3     "},
    {26, "PHYS    "},
    {27, "B1      "},
    {29, "B2      "},
    {31, "EIT     "},
    {32, "ESC     "},
    {34, "C2      "},
    {37, "MC      "},
    {39, "DC      "}
  };

std::map <int, std::vector<std::string>> longName = {
  {0, {"COLLECT", "OSAP   "}},
  {7, {"NEEDLES", "HALL   "}},
  {10, {"DC Tims", "Line   "}},
  {20, {"Goose  ", "Nesting"}},
  {0, {"COLLECT", "OSAP   "}},
  {22, {"NEEDLES", "HALL   "}},
  {30, {"GO TO  ", "TIMS   "}},
  {36, {"NEEDLES", "HALL   "}},
  {38, {"COOP   ", "FEE    "}}
};

std::map <int, std::string> other = {
  {2, "SLC    "},
  {4, "TUITION"},
  {5, "MKV    "},
  {12, "PAC    "},
  {15, "UMP    "},
  {17, "SLC    "},
  {25, "V1     "},
  {28, "CIF    "},
  {33, "SLC    "},
  {35, "REV    "}
};


Board::Board() {
	std::vector<std::string> piece(7, "");
	board = std::vector<std::vector<std::string>>(40, piece);
	for (int i = 0; i < 40; i++) {
		if (academic.count(i) == 1) {
			board[i][0] = " ------- ";
      			board[i][1] = "|       |";
      			board[i][2] = "|-------|";
      			board[i][3] = "|" + academic[i] + "|";
      			board[i][4] = "|       |";
      			board[i][5] = "|       |";
      			board[i][6] = " ------- ";
    		} else if (longName.count(i) == 1) {
      			board[i][0] = " ------- ";
      			board[i][1] = "|" + longName[i][0] + "|";
      			board[i][2] = "|" + longName[i][1] + "|";
      			board[i][3] = "|       |";
      			board[i][4] = "|       |";
      			board[i][5] = "|       |";
      			board[i][6] = " ------- ";
    		} else {
      			board[i][0] = " ------- ";
      			board[i][1] = "|" + other[i] + "|";
      			board[i][2] = "|       |";
      			board[i][3] = "|       |";
      			board[i][4] = "|       |";
      			board[i][5] = "|       |";
      			board[i][6] = " ------- ";
		}
	}
}

void Board::updateImprovement(int position, int improvementNumber) {
  std::string temp = "       ";
  for (int i = 0; i < improvementNumber; i++) {
    temp[i] = 'I';
  }
  board[position][1] = temp;
}

void Board::updatePlayer(int position, std::string playerName) {
  std::string temp = playerName;
  int length = 7 - playerName.length();
  for (int i = 0; i < length; i++) {
    temp += " ";
  }
  board[position][4] = temp;
}


void Board::drawBoard(std::ostream & out) {
  for (int h = 0; h < 7; h++) {
    for (int w = 20; w <= 30; w++) {
      out << board[w][h];
    }
    out << "\n";
  }
  
  for (int i = 19; i >= 10; i--) {
  	for (int h = 0; h < 7; h++) {
		out << board[i][h];
		out << std::setw(90);
		out << board[40 - i][h];
		out << "\n";
	}
  }


  
  for (int h = 0; h < 7; h++) {
    for (int w = 10; w >= 0; w--) {
      out << board[w][h];
    }
    out << "\n";
  }
}

