#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
//#define N 10
using namespace std;

void right_diagonal(int **ptrarray, int N);
void left_diagonal(int **ptrarray, int N);
void spiral_from_center(int *ptrarray[], int N);

int main(int argc, char *argv[])
{
    srand(time(0)); // ãåíåðàöèÿ ñëó÷àéíûõ ÷èñåë
    // äèíàìè÷åñêîå ñîçäàíèå äâóìåðíîãî ìàññèâà ÷èñåë íà 200 ýëåìåíòîâ
	int N;
	cout << "\nInpute size  of array: ";
	cin >> N;
	cout << endl;
    int **ptrarray = new int* [N]; 
    for (int count = 0; count < N; count++)
        ptrarray[count] = new int [N]; 
    // çàïîëíåíèå ìàññèâà
    for (int count_row = 0; count_row < N; count_row++)
        for (int count_column = 0; count_column < N; count_column++)
            ptrarray[count_row][count_column] = (rand() % 10 + 1); //çàïîëíåíèå ìàññèâà ñëó÷àéíûìè ÷èñëàìè
    // âûâîä ìàññèâà
    cout << "Array generated:"<< endl;
    for (int count_row = 0; count_row < N; count_row++)
    {
        for (int count_column = 0; count_column < N; count_column++)
            cout << setw(4)<< ptrarray[count_row][count_column] << "   ";
        cout << endl;
    }
    right_diagonal(ptrarray, N);
    left_diagonal(ptrarray, N);
    spiral_from_center(ptrarray, N);
    // delete first array
    for (int count = 0; count < 2; count++)
        delete []ptrarray[count];
    
    return 0;
}

void right_diagonal(int **ptrarray, int N){
    cout << "right diagonal" << endl;
	int *ptr_diagonal=new int[N*N];
    int g=0, k=0;
    while(g<N){
            for(int i=0, j=N-g-1; i<g+1; i++, j++, k++) ptr_diagonal[k]=ptrarray[i][j];
			g++;
    }
    for(int h=1;h<N;h++){
            for(int i=h, j=0; i<N; i++, j++, k++) ptr_diagonal[k]=ptrarray[i][j];
    }
    for(int h=0; h<N*N; h++)  cout << setw(4) << ptr_diagonal[h];
    delete ptr_diagonal;
}

void left_diagonal(int *ptrarray[], int N){
    cout << "\n left diagonal" << endl;
    int *ptr_diagonal=new int[N*N];
    int k=0;
    for(int g=0; g<N; g++){
            for(int i=g, j=0; i>=0; i--, j++, k++) ptr_diagonal[k]=ptrarray[i][j];
    }
    for(int h=1;h<N;h++){
            for(int i=N-1, j=h; j<N; i--, j++, k++) ptr_diagonal[k]=ptrarray[i][j];
    }
    for(int h=0; h<N*N; h++)  cout << setw(4) << ptr_diagonal[h];
    delete ptr_diagonal;
}

void spiral_from_center(int *ptrarray[], int N){
	cout << "\n center spiral" << endl;
    int *ptr=new int[N*N];
    cout << "\nСередина "<< N/2;
    for(int i=0, step=1, dir=1, x=N/2, y=N/2; (x<N) && (y<N); -dir, step++){
		int count_step=0;
		while(count_step++<step){
			ptr[i++]=ptrarray[x][y+dir];
		}
		count_step=0;
		while(count_step++<step){
			ptr[i++]=ptrarray[x+dir][y];
		}
	}
	for(int h=0; h<N*N; h++)  cout << setw(4) << ptr[h];
	delete ptr;
}
