#include <iostream>
#include <map>
#include <vector>
using namespace std;

class Process{
 	public:
 	int id, arrival, burst, priority;
 	Process(int* id,int* arrival, int* burst, int* priority){
 		this->id = *id;
 		this->arrival = *arrival;
 		this->burst = *burst;
 		this->priority = *priority;
 	}
};

#include "Comparators.cpp"
#include "Algorithms.cpp"

int main(){
	typedef void (*Algorithm)(vector<Process*>&,int*,int*);
	map<string, Algorithm> algoMap;
	algoMap["FCFS"] = &FCFS;
	algoMap["SJF"] = &SJF;
	algoMap["SRTF"] = &SRTF;
	algoMap["P"] = &P;
	algoMap["RR"] = &RR;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int numProcess, q = 0;
		string algorithm;
		cin >> numProcess >> algorithm;
		if(algorithm == "RR")
			cin >> q;
		vector<Process*> processes;
		for(int j = 1; j <= numProcess; j++){
			int arrival, burst, priority;
			cin >> arrival >> burst >> priority;
			Process* p = new Process(&j,&arrival,&burst,&priority);
			auto it = upper_bound(processes.begin(), processes.end(), p, byArrival);
			processes.insert(it, p);
		}
		algoMap[algorithm](processes,&numProcess,&q);
	}
}