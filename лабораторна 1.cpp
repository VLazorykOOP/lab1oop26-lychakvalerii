#include <iostream>
#include <fstream> 
#include <vector>

using namespace std;
// 1. Task: Array C (2^i * a_i)
void Task_ArrayC() { 
	int n;               
	cout << "enter  n: "; cin >> n;
	double* a = new double[n], * c = new double[n];
	//	2. Task: Random & Binary File (NEW)
	ofstream f("task1.txt"); 
	for (int i = 0; i < n; i++) {
		cout << "a[" << i << "]="; cin >> a[i];

		double powerOfTwo = 1;
		for (int j = 0; j < i; j++) powerOfTwo *= 2;   

		c[i] = powerOfTwo * a[i];
		f << c[i] << " ";
		cout << "c[" << i << "]=" << c[i] << " ";
    }
	f.close();
	delete[] a; delete[] c;
	cout << "\nEntered in task1.txt" << endl;
}

  
void Task_BinaryRandom() {
	int n;
	cout << "n for random: "; cin >> n;
	int* a = new int[n];

	long long seed = 12345; 
	cout << "Generated: ";
	for (int i = 0; i < n; i++) {  
		seed = (seed * 1103515245 + 12345) % 2147483647;
		a[i] = seed % 100;
		cout << a[i] << " ";
    }
	//	Save to binary file
	ofstream bf("data.bin", ios::binary);
	bf.write((char*)a, sizeof(int) * n);
	bf.close();

	delete[] a;
	cout << "\nSaved to data.bin (binary)" << endl;
}

void Task_LastMax() {
	int n, c, d, firstEvenIdx = -1;
	cout << "n, range [c, d]: "; cin >> n >> c >> d;
	int* a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0 && firstEvenIdx == -1) firstEvenIdx = i;
    }

	int maxVal = -2147483647, lastIdx = -1;
	int limit = (firstEvenIdx == -1) ? n : firstEvenIdx;

	for (int i = 0; i < limit; i++) {
		if (a[i] >= c && a[i] <= d) {
			maxVal = a[i];
			lastIdx = i;
        }
    }
	
	if (lastIdx != -1) cout << "Last max index: " << lastIdx << " (:value " << maxVal << ")" << endl;
	else cout << "not found" << endl;
	delete[] a;
}
//	4. Task: Sum repeats / Prod unique
void Task_SumProd() {
	int n; cout << "n: "; cin >> n;
	double* a = new double[n], s = 0, p = 1;
	bool hasUnique = false;

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) if (a[i] == a[j]) count++;

		if (count > 1) s += a[i];
        else { p *= a[i]; hasUnique = true; }
    }

	cout << "Summary of repeation: " << s << endl;
	cout << "product of unique: " << (hasUnique ? p : 0) << endl;
	delete[] a;
}

void Task_ReadVector() {
	ifstream f("task1.txt");
	vector<double> v;
	double val;
	while (f >> val) v.push_back(val);
	f.close();

	cout << "the content of the vector (iz failu): ";
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

int main() {
	int choice;
	do {
		cout << "\n--- LABORATORY WORK ---" << endl;
		cout << "1. Task: Array C (2^i * a_i)" << endl;	
        cout << "2. Task: Random & Binary File " << endl;
        cout << "3. Task: Last Max in [c, d] before even" << endl;
        cout << "4. Task: Sum repeats / Prod unique" << endl;
        cout << "5. Show results from file (Vector)" << endl;
        cout << "0. Exit" << endl;
		cout << "Your choice : "; cin >> choice;

		if (choice == 1) Task_ArrayC();
		else if (choice == 2) Task_BinaryRandom();
        else if (choice == 3) Task_LastMax();
        else if (choice == 4) Task_SumProd();
        else if (choice == 5) Task_ReadVector();

	} while (choice != 0);
	return 0;
}