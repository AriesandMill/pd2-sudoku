#include"Sudoku.h"
int main()
{
	Sudoku su;
	su.giveQuestion();
	su.readIn();
	//su.solve();
	su.transform();
	su.solve();

}
