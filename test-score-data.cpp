#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

const int NUM_TESTS = 8;

void pressEnter();
void readTestScores (const string& fileName, int scores[][NUM_TESTS], int numStds);
void displayTestScores(const int scores[][NUM_TESTS], int numStds);
int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber);
int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber);
double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber);
int topStudent(const int scores[][NUM_TESTS], int numStds);
bool searchStudents(const int scores[][NUM_TESTS], int numStds, double average);
bool searchTests(const int scores[][NUM_TESTS], int numStds, double average);

//****************************************************************************************************

int main ()
{
    const int NUM_STDS = 10;

    int testScores[NUM_STDS][NUM_TESTS],
        totalTest1 = 1,
        totalTest2 = 5,
        totalStd1 = 3,
        totalStd2 = 8,
        avgTest1 = 5,
        avgTest2 = 8,
        avgStd1 = 5,
        avgStd2 = 9,
        highestStd = 2,
        topStd;

    bool resultStudent,
         resultTest;
    double stdAverage,
           testAverage;

    readTestScores("Assignment1Data.txt", testScores, NUM_STDS);
    
    displayTestScores(testScores, NUM_STDS);

    pressEnter();

    cout << "Total for Test #" << totalTest1 << " is: "
         << totalOneTest(testScores, NUM_STDS, totalTest1);
    pressEnter();

    cout << "Total for Test #" << totalTest2 << " is: "
         << totalOneTest(testScores, NUM_STDS, totalTest2);
    pressEnter();

    cout << "Total for Student #" << totalStd1 << " is: " 
         << totalOneStudent(testScores, NUM_STDS, totalStd1);
    pressEnter();

    cout << "Total for Student #" << totalStd2 << " is: " 
         << totalOneStudent(testScores, NUM_STDS, totalStd2);
    pressEnter();

    cout << "Average for Test #" << avgTest1 << " is: " 
         << fixed << setprecision(2) 
         << averageOneTest(testScores, NUM_STDS, avgTest1);
    pressEnter();

    cout << "Average for Test #" << avgTest2 << " is: " 
         << fixed << setprecision(2) 
         << averageOneTest(testScores, NUM_STDS, avgTest2);
    pressEnter();

    cout << "Average for Student #" << avgStd1 << " is: "
         << fixed << setprecision(2) 
         << averageOneStudent(testScores, NUM_STDS, avgStd1);
    pressEnter();

    cout << "Average for Student #" << avgStd2 << " is: "
         << fixed << setprecision(2) 
         << averageOneStudent(testScores, NUM_STDS, avgStd2);
    pressEnter();

    cout << "Highest test score for Student #" << highestStd << " is: "
         << fixed << setprecision(2) 
         << highestOneStudent(testScores, NUM_STDS, highestStd);
    pressEnter();

    topStd = topStudent(testScores, NUM_STDS);
    cout << "The top Student: " << topStd;
    pressEnter();

    cout << "Enter the student average score to search for: ";
    cin >> stdAverage;

    resultStudent = searchStudents(testScores, NUM_STDS, stdAverage);
    if (resultStudent)
    {
        cout << "A student does have an average score greater than: " << stdAverage;
    }
    else
    {
        cout << "A student does not have an average score greater than: " << stdAverage;
    }
    pressEnter();

    cout << "\nEnter the test average score to search for: ";
    cin >> testAverage;

    resultTest = searchTests(testScores, NUM_STDS, testAverage);
    if (resultTest)
    {
        cout << "A test does have an average score greater than: " << testAverage;
    }
    else
    {
        cout << "A test does not have an average score greater than: " << testAverage;
    }
    pressEnter();

    return 0;
}

//****************************************************************************************************

void pressEnter()
{
    cout << "\nPress Enter to Continue\n";
    cin.ignore();
}

void readTestScores(const string& fileName, int scores[][NUM_TESTS], int numStds)
{
    ifstream file(fileName);

    for (int i = 0; i < numStds; i++)
    {
        for (int j = 0; j < NUM_TESTS; j++)
        {
            if (!(file >> scores[i][j]))
            {
                cout << "Error \n";
            }
        }
    }

    file.close();
}

void displayTestScores(const int scores[][NUM_TESTS], int numStds)
{
    cout << "All Test scores:" << endl;

    for (int i = 0; i < numStds; i++)
    {
        for (int j = 0; j < NUM_TESTS; j++)
        {
            cout << setw(3) << scores[i][j];

            if (j < NUM_TESTS - 1)
            {
                cout << " ";
            }
        }

        cout << endl;
    }
}

int totalOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber)
{
    int totalTest = 0,
        testIndex = testNumber - 1;

    for (int i = 0; i < numStds; i++)
    {
        totalTest += scores[i][testIndex];
    }
    
    return totalTest;
}

int totalOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
    int totalStudent = 0,
        studentIndex = studentNumber - 1;

    for (int i = 0; i < NUM_TESTS; i++)
    {
        totalStudent += scores[studentIndex][i];
    }

    return totalStudent;
}

double averageOneTest(const int scores[][NUM_TESTS], int numStds, int testNumber)
{
    int totalTest = totalOneTest(scores, numStds, testNumber);

    double averageTest = static_cast<double>(totalTest) / numStds;

    return averageTest;
}

double averageOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
    int totalStudent = totalOneStudent(scores, numStds, studentNumber);

    double averageScore = static_cast<double>(totalStudent) / NUM_TESTS;

    return averageScore;
}

int highestOneStudent(const int scores[][NUM_TESTS], int numStds, int studentNumber)
{
        int highestScore = scores[studentNumber][0],
            studentIndex = studentNumber - 1;

        for (int i = 0; i < NUM_TESTS; i++)
        {
            if (scores[studentIndex][i] > highestScore)
            {
                highestScore = scores[studentIndex][i];
            }
        }

    return highestScore;
}

int topStudent(const int scores[][NUM_TESTS], int numStds)
{
    double highAverage = 0;
    int topStd = -1;

    for (int i = 0; i < numStds; i++)
    {
        double average = averageOneStudent(scores, numStds, i);

        if (average > highAverage)
        {
            highAverage = average;
            topStd = i;
        }
    }

    return topStd;
}

bool searchStudents(const int scores[][NUM_TESTS], int numStds, double average)
{
    bool found = false;

    for (int i = 0; i < numStds; i++)
    {
        double stdAverage = averageOneStudent(scores, numStds, i);
        
        if (stdAverage > average)
        {
            found = true;
        }
    }

    return found;
}

bool searchTests(const int scores[][NUM_TESTS], int numStds, double average)
{
    bool found = false;
    for (int i = 0; i < numStds; i++)
    {
        double testAverage = averageOneTest(scores, numStds, i);

        if (testAverage > average)
        {
            found = true;
        }
    }

    return found;
}