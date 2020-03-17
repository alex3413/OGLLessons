#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char** argv) {
	const string str = "data.dat";
	const string file = "data.txt";
	const int N = 100;
	ofstream out;
	ifstream in;
	
	char *buf;
	buf = new char[N];
	buf = "hellow";
	out.open(file.c_str(), ios_base::app|ios_base::binary);
	out.write(buf,N);
	out.close();
	
	char *buf1;
	buf1=new char[N*2];
	in.open(file.c_str(), ios_base::binary);
	in.read(buf1,N*2);
	in.close();
	cout<<buf1;
	
	
	return 0;
}
