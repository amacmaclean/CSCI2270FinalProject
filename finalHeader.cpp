//Final Project Header File

#include "hash.hpp"
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

	//input file declarations OUTSIDE else loop to avoid error
    string dataFileA = "";
    string dataFileC = "";

    //if incorrect number of command line args
    if (argc != 3) {
        cout << "Usage: FinalProject <dataSetA.csv> <dataSetC.csv>" << endl;
    }
    else {
    	//input initializations from command line
        dataFileA = argv[1];
        dataFileC = argv[2];
    }

    ifstream fs; //filestream
    fs.open
    
    //Sample Code Given
    int startTime, endTime;
    double execTime;
    startTime = clock();
    /*
    EVALUATION CODE GOES HERE
    */
    endTime = clock();
    execTime = (double)(endTime-startTime)/CLOCKS_PER_SEC;
    cout << "execution time: " << execTime << endl;
    return 0;
}