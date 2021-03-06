#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	int row = atoi(argv[1]);
	cout << "Number of rows: " << row << endl;
	
	int column= atoi(argv[2]);
	cout << "Number of columns: " << column << endl;
 	
	// Create a vector of vector with size equal to row.
	vector <vector<int>> vec(row); 
	int increment = 1;
	for (int i = 0; i < row; i++)
		{
		vec[i] = vector <int>(column);
		for (int j = 0; j < column; j++)
			{
			vec[i][j] = increment;
			increment ++;
			}
		}
	
	for (int i = 0; i < column; i++)
		{
		cout << i << "\t";
		}
	cout << endl << endl;
	for (unsigned int i = 0; i < vec.size(); i++) 
		{
		for (unsigned int j = 0; j < vec[i].size(); j++)
			{
			cout << vec[i][j] << "\t";
			}
		cout << endl;
		}
    return 0;
}
