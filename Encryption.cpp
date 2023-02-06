// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int findRand() {
    int n = ((int)rand() % 2);
    return n;
}

string RandDNA(int N) {
    string S = "";
    for (int i = 0; i < N; i++) 
        S += '0' + findRand();
    return S;
}

string DecToBin(int dec) {
	if (dec < 1) return "0";

	string binStr = "";
	while (dec > 0){
		binStr = binStr.insert(0, string(1, (char)((dec % 2) + 48)));

		dec /= 2;
	}
	return binStr;
}

string PlaintextToBin(string str) {
	string binary = "";
	int size = str.length();

	for (int i = 0; i < size; ++i)
	{
		string cBin = DecToBin(str[i] - 'a');
		int cBinLength = cBin.length();
        

		if (cBinLength < 5) {
			for (size_t i = 0; i < (5 - cBinLength); i++){
				cBin = cBin.insert(0, "0");
            }
		}

		binary += cBin;
	}
	return binary;
}

vector<string> Encrypt(string message, string key){
        vector<string> ans;
        key = PlaintextToBin(key);
        cout<<"Key: - "<<key<<endl;
        cout<<"Message: - "<<message<<endl;
        //adding key into the DNA binary strands of message
        char end = message.size()%2 + '0';
        //message strand including key sequence and end terminator
        message = key + message + end;
        ans.push_back(message);
        //Generating random DNA dummies
        int size = rand()%15 + 1;
        for(int i = 0;i<size;i++)
            ans.push_back(RandDNA(message.size()));
        //changing the index of message strands with random DNA
        int index = rand()%15;
        while(index>size)
            index/= 2;
        swap(ans[0], ans[index]);
        return ans;
}

int main() {
    // Use current time as seed for random generator
    srand(time(0));
    string message = "", uniqkey = "itdna";
    cout<<"Enter the message you want to transmit: - "<<endl;
    getline(cin, message);
    //convert Plain text into Binary
    string binary = PlaintextToBin(message);
    //Entryption: - 
    vector<string> Encryption = Encrypt(binary, uniqkey);
    cout<<endl<<"Encryption: - "<<endl;
    for(int i = 0;i<Encryption.size();i++)
        cout<<Encryption[i]<<endl;
    return 0;
}