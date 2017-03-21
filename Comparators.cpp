 #include <algorithm>
  
bool byArrival(const Process* lhs,const Process* rhs){
	if(lhs->arrival == rhs->arrival){
		return lhs->priority > rhs->priority;
	}
	return lhs->arrival <= rhs->arrival;
}

bool byBurst(const Process* lhs,const Process* rhs){
	if(lhs->burst == rhs->burst){
		return lhs->priority > rhs->priority;
	}
	return lhs->burst <= rhs->burst;
}