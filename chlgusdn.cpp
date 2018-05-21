#include<windows.h>
#include<iostream>
#define BoardSize 15 
#define PlayerNum 2
using namespace std;

class PlayOmok 
{
	int X = 0, Y = 0; 
	int OmokBoard[BoardSize][BoardSize];
	int Player = 1;
	int RankToPlayer1 = 0;
	int RankToPlayer2 = 0;
	public: 
	 PlayOmok()
	{
		for(int i=0; i < BoardSize; i++)
		{
			for(int j = 0; j < BoardSize; j++)
			{
				OmokBoard[i][j] = -1;
			}
		}
	}
	void ResetGame()
	{
		memset(OmokBoard, -1, sizeof(OmokBoard));
	}
	void DrawBoard()
	{
		system("cls");	
		cout << "*****오목 게임입니다*****" << endl; 
		cout << "9 다음 부터는 10의 자리수 입니다. " << endl;
		cout << " Player 1 의 랭킹 점수 : " << RankToPlayer1 << endl;
		cout << " Player 2  의 랭킹 점수 : " << RankToPlayer2 << endl;
		cout << endl;
		cout << "   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4" << endl;
		 cout << "┌";
		 for(int i=0; i < BoardSize; i++)
		 {
		 	cout << "┬";
		 }
		 cout << "┐"<<endl;
		 
		
		 for(int i = 0; i < BoardSize; i++)
		 {
		 	 cout << "├";
		 	for(int j = 0; j <BoardSize; j++)
		 	{
		 		if(OmokBoard[i][j] == -1)
		 		{
		 			cout << "┼";
				 }
				 else if (OmokBoard[i][j] == 1)
				 {
				 	cout << "○";
				  } 
				 else if (OmokBoard[i][j] == 2)
				 {
				 	cout << "●";
					} 
			 }
			 cout << "┤" << endl; 
		  } 
		  cout << "└";
		  for(int i = 0; i <BoardSize; i++)
		  {
		  	cout << "┴";
		  }
		  cout << "┘" << endl;
	}
	void Seting_Player1()
	{
		cout << "Player1 차례입니다." << endl;	
		cin >> X>>Y;
		
		if(OmokBoard[X][Y] == -1)
		{
			OmokBoard[X][Y] = 1;
				DrawBoard(); 
		}
		else if(X < -1 || X > BoardSize)
		{
			cout << "오목판의 범위를 벗어났습니다. 다시 입력하세요" <<endl;
			Seting_Player1(); 
		}
		else if (Y < -1 || Y > BoardSize)
		{
			cout << "오목판의 범위를 벗어났습니다. 다시 입력하세요" <<endl;
			Seting_Player1(); 
		}
		else if(OmokBoard[X][Y] != -1)
		{
			cout << "이미 알을 두었습니다 다시 입력하세요 " << endl;
			Seting_Player1(); 
		}
		
	 } 
	 void ChangePlayer() 
	 {
	 	if (Player > PlayerNum)
	 	{
	 		Player = 1;
		 }
	 }
	 
	 void Seting_Player2()
	 {
		 cout << "Player2 차례입니다" << endl;
	 	cin >> X >> Y;
	 	if(OmokBoard[X][Y] == -1)
		{
			OmokBoard[X][Y] = 2;
			DrawBoard();
		}
		else if(X < -1 || X >= BoardSize)
		{
			cout << "오목판의 범위를 벗어났습니다. 다시 입력하세요" <<endl;
			Seting_Player2(); 
		}
		else if(Y < -1 || Y >= BoardSize)
		{
			cout << "오목판의 범위를 벗어났습니다. 다시 입력하세요" <<endl;
			Seting_Player2(); 
		}	
		else if(OmokBoard[X][Y] != -1)
		{
			cout << "이미 알을 두었습니다 다시 입력하세요 " << endl;
			Seting_Player2(); 
		}
		
	 }
	 
	 void CheckFromOmok()
	 {
	 	//Player1 의  승리일 경우 
	 	for(int i = 0; i < BoardSize; i++)
	 	{
	 		for(int j = 0; j < BoardSize; j++)
	 		{
	 			if(OmokBoard[i][j] == 1 && OmokBoard[i][j+1] == 1&&OmokBoard[i][j+2] == 1 && OmokBoard[i][j+3] == 1 && OmokBoard[i][j+4] == 1)
	 			{
	 				cout << "Player1이 승리하였습니다. " << endl;
					ResetGame();
				 }
				 else if(OmokBoard[i][j] == 1 && OmokBoard[i+1][j] == 1&&OmokBoard[i+2][j]== 1 && OmokBoard[i+3][j] == 1 && OmokBoard[i+4][j]==1)
				 {
				 	cout << "Player1이 승리하였습니다. " << endl;
				 	ResetGame();	
				 }
				 else if(OmokBoard[i][j] == 1 && OmokBoard[i+1][j+1] == 1&&OmokBoard[i+2][j+2] == 1 && OmokBoard[i+3][j+3]==1 && OmokBoard[i+4][j+4] == 1)
				 {
				 	cout <<"Player1이 승리하였습니다. " << endl;
				 	ResetGame();
				 }
				 else if (OmokBoard[i][j] == 1 && OmokBoard[i+1][j-1] == 1&&OmokBoard[i+2][j-2] == 1 && OmokBoard[i+3][j-3]== 1 && OmokBoard[i+4][j-4] == 1)
				 {
				 	cout <<"Player1이 승리하였습니다. " << endl;
				 	ResetGame();
				 }
				 
			 } //end to Player 1
			 //Player2가 승리할 경우 
			 for(int i = 0; i < BoardSize; i++)
			 {
			 	for(int j= 0; j < BoardSize; j++)
			 	{
			 		if(OmokBoard[i][j] == 2 && OmokBoard[i][j+1] == 2 &&OmokBoard[i][j+2] == 2 && OmokBoard[i][j+3] == 2 && OmokBoard[i][j+4] == 2)
	 				{
	 					cout << "Player2이 승리하였습니다. " << endl;
	 					
	 					Message();
						ResetGame();
				 	}
				 else if(OmokBoard[i][j] == 2 && OmokBoard[i+1][j] == 2 &&OmokBoard[i+2][j]== 2 && OmokBoard[i+3][j] == 2 && OmokBoard[i+4][j]==2)
				 	{
				 		cout << "Player2이 승리하였습니다. " << endl;
				 		
				 		Message();
				 		ResetGame();	
				 	}
				 else if(OmokBoard[i][j] == 2 && OmokBoard[i+1][j+1] == 2 &&OmokBoard[i+2][j+2] == 2 && OmokBoard[i+3][j+3]==2 && OmokBoard[i+4][j+4] == 2)
					{
				 		cout <<"Player2이 승리하였습니다. " << endl;
				 	
				 		Message();
				 		ResetGame();
				 	}
				 else if (OmokBoard[i][j] == 2 && OmokBoard[i+1][j-1] == 2 &&OmokBoard[i+2][j-2] == 2 && OmokBoard[i+3][j-3]== 2 && OmokBoard[i+4][j-4] == 2)
					 {
				 		cout <<"Player2이 승리하였습니다. " << endl;
				 		
				 		Message();
				 		ResetGame();
				 	}	
				}
			 } // end to Player2
		 }
	 }	 
	 void Message()
		 {
		 	cout << "랭킹점수가 올랐습니다." <<endl;
		 }
		 
	 void Run()
	 {
	 	while(1)
	 	{
	 	DrawBoard();
	 	Seting_Player1();
	 	CheckFromOmok();
	 	ChangePlayer();
	 	Seting_Player2();
	 	CheckFromOmok();
	 	ChangePlayer();
		 }
	 }
};

int main()
{
	PlayOmok game;
	game.Run();
}
