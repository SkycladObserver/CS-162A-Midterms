#include <array>
#include <iterator>
void FCFS(vector<Process*> &processes,int* numProcess,int* q){
	cout << "FCFS" << endl;
	for(int j = 0; j < *numProcess; j++){
			cout << "id: " << processes[j]->id << " arrival: " << processes[j]->arrival << " burst: " << processes[j]->burst << " priority: " << processes[j]->priority << endl;
	}
}
void SJF(vector<Process*> &processes,int* numProcess,int* q){
	cout << "SJF" << endl;
	int end;
	for(int start = 0; start < *numProcess; start += end){
		end = 1;
		int j = start + 1;
		while(j < *numProcess && processes[start]->arrival == processes[j]->arrival){
			end+=1;
			j+=1;
		}
		sort(processes.begin() + start,processes.begin() + start + end, byBurst);
	}
	for(int j = 0; j < *numProcess; j++){
			cout << "id: " << processes[j]->id << " arrival: " << processes[j]->arrival << " burst: " << processes[j]->burst << " priority: " << processes[j]->priority << endl;
	}
}
void SRTF(vector<Process*> &processes,int* numProcess,int* q){
	cout << "SRTF" << endl;
	vector<Process*> queue;
	int t = processes[0]->arrival; //time of first process
	int start = 0; 
	queue.push_back(processes[start]);
	while(true){
		int j = start + 1;
		cout << "processes.at(" << j <<") " <<processes.at(j)->arrival;
		while(j < *numProcess && processes.at(start)->arrival == processes.at(j)->arrival){
			j+=1;
			auto it = upper_bound(queue.begin(), queue.end(), processes[j], byBurst);
			queue.insert(it, processes[j]);
		}
		cout << "Contents of Queue" << endl;
		for(int j = 0; j < *numProcess; j++){
			cout << "id: " << queue[j]->id << " arrival: " << queue[j]->arrival << " burst: " << queue[j]->burst << " priority: " << queue[j]->priority << endl;
		}
		start = j;
		if(start==*numProcess-1)
			break;
	}
}
void P(vector<Process*> &processes,int* numProcess,int* q){
	cout << "P" << endl;
}
void RR(vector<Process*> &processes,int* numProcess,int* q){
	cout << "RR" << endl;
	int processI = 0;
	int clk = processes[0]->arrival;
	while(true){
		if(processes.empty())
			break;
		Process* p = processes[processI%*numProcess];
		if(p->burst!=0){
			//cout << "enter while loop" << endl;
			//cout << processI%*numProcess << endl;
			cout << clk << " " << p->id << " ";
			if(p->burst - *q < 0){
				cout << p->burst << "X" << endl;
				clk+=p->burst;
				p->burst = 0;
				//processes.erase(processes.begin() + processI);
				//processI -= 1;
			}else{
				cout << *q << endl;
				clk+= *q;
				p->burst -= *q;
			}
		}
		processI+=1;
	}	
}

/*bool love = true;
	while(love==true){
		love = pagtaya();
		if(love!=true){
			break;
		}
	}*/