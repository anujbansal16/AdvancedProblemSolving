#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the stockmax function below.
long stockmax(vector<int> prices) {
    long mx=0;
    long count=0;
    for(long i=prices.size()-1;i>=0;i--){
        if(mx<prices[i])
            mx=prices[i];
        count+=(mx-prices[i]);
    }    
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string prices_temp_temp;
        getline(cin, prices_temp_temp);

        vector<string> prices_temp = split_string(prices_temp_temp);

        vector<int> prices(n);

        for (int i = 0; i < n; i++) {
            int prices_item = stoi(prices_temp[i]);

            prices[i] = prices_item;
        }

        long result = stockmax(prices);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

