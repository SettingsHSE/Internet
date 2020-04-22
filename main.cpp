#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

const int N = 31;

int countMinSum(int seconds, vector<int>& values)
{
    int result = 0;

    vector<long long> val;
    val.reserve(values.size());
    for(int value : values)
        val.push_back(value);

    for (int i = 1; i < N; i++)
    {
        if(val[i] < val[i - 1] || val[i] < (val[i - 1] * 2))
            val[i] = val[i - 1] * 2;
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (seconds >= val[i])
        {
            seconds -= val[i];
            result += (1 << i);
        }
    }
    if (seconds > 0)
        result++;

    return result;
}


int main()
{
    vector<int> values;
    int value = 0, seconds = 0;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open())
    {
        fin >> seconds;
        for (int i = 0; i < N; i++)
        {
            fin>>value;
            values.push_back(value);
        }
        fin.close();
    }

    int res = countMinSum(seconds, values);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}
